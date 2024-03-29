/*
 * pwm_drawer.c
 *
 *
 *   Author: omar mohamed
 */

#include "glcd.h"
#include "icu.h"
#include <util/delay.h>
#include "pwm_drawer.h"



/*******************************************************************************
 *                      GLOBAL VARIABLES                                   *
 *******************************************************************************/

 uint32 frequency=0;
 uint32 duty_cycle=0;
 uint32 period=0;
 uint8 g_edgeCount = 0;
 static uint32 g_timeHigh = 0;
 static uint32 g_timePeriod = 0;
static uint32 g_timePeriodPlusHigh = 0;

Icu_ConfigType icu_config={F_CPU_CLOCK,RISING};



void APP_edgeProcessing(void)
{
	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		Icu_clearTimerValue();
		/* Detect falling edge */
		Icu_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		/* Store the High time value */
		g_timeHigh = Icu_getInputCaptureValue();
		/* Detect rising edge */
		Icu_setEdgeDetectionType(RISING);
	}
	else if(g_edgeCount == 3)
	{
		/* Store the Period time value */
		g_timePeriod = Icu_getInputCaptureValue();
		/* Detect falling edge */
		Icu_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 4)
	{
		/* Store the Period time value + High time value */
		g_timePeriodPlusHigh = Icu_getInputCaptureValue();
		/* Clear the timer counter register to start measurements again */
		Icu_clearTimerValue();
		/* Detect rising edge */
		Icu_setEdgeDetectionType(RISING);

	}
}

/*******************************************************************************
 *                      Functions Function                                  *
 *******************************************************************************/

void pwmdrawer_init(void){
	GLCD_init();
	Icu_setCallBack(APP_edgeProcessing);
	Icu_init(&icu_config);
}

void pwmdrawer_measuresginal(void){


	Icu_DeInit();
	period = ((g_timePeriodPlusHigh - g_timeHigh) / 1000);
	frequency= _F_CPU/(g_timePeriodPlusHigh - g_timeHigh);
	duty_cycle=((float)(g_timePeriodPlusHigh-g_timePeriod) / (g_timePeriodPlusHigh - g_timeHigh)) * 100;


}


void pwmdrawer_drawsignal(void){
	GLCD_String(0, 1, "frequency=");
	GLCD_String(1, 1, "duty cycle=");
	GLCD_number(0, 2, frequency);
	GLCD_number(1, 2, duty_cycle);




	GLCD_line(6);

	uint8 pixel_width=0;
	uint8 scale_ms=period/5;


	 while(pixel_width<GLCD_MAX_LINE_PIXEL-8){
		 GLCD_DisplaySpecialPattern(PWM_DRAWER_GLCD_RISING_EDGE);
		 pixel_width+=5;

		 for(uint8 i=0; i<(uint8)((float)(g_timeHigh/1000)/scale_ms);i++){
			 GLCD_DisplaySpecialPattern(PWM_DRAWER_GLCD_HIGH_LINE);
			 pixel_width+=5;
		 }
		 GLCD_DisplaySpecialPattern(PWM_DRAWER_GLCD_FALLING_EDGE);
				 pixel_width+=5;
				 for(uint8 i=0; i<(uint8)((float)((g_timePeriod-g_timeHigh)/1000)/scale_ms);i++){
					 GLCD_DisplaySpecialPattern(PWM_DRAWER_GLCD_LOW_LINE);
					 pixel_width+=5;
				 }
	 }
_delay_ms(1000);

	 GLCD_ClearDisplay();
	 Icu_init(&icu_config);


}


