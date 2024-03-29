 /******************************************************************************
 *
 *
 *
 * File Name: main.c
 *
 * Description: main file for the PWM drawer application.
 *
 * Author: OMAR MOHAMED
 *
 *******************************************************************************/

#include "pwm_drawer.h"
#include <avr/io.h>
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include "gpio.h"
#include <util/delay.h>


static void prvSetupHardware( void );
void vtask1(void *pvParameters);
void vtask2(void *pvParameters);
xSemaphoreHandle xBinarySemaphore;



int main(void){



prvSetupHardware();

xTaskCreate(vtask1, "measure & draw signal", 256, NULL, 2, NULL);
xTaskCreate(vtask2, "check condition", 256, NULL, 1, NULL);


 xBinarySemaphore=xSemaphoreCreateBinary();



vTaskStartScheduler();

   for(;;);



}

static void prvSetupHardware( void )
{
	/* Place here any needed HW initialization such as GPIO, UART, etc.  */
	SREG |=(1<<7);
  pwmdrawer_init();
}

void vtask1(void *pvParameters){


	for(;;){
	if (xSemaphoreTake(xBinarySemaphore, portMAX_DELAY) == pdTRUE){
		pwmdrawer_measuresginal();
		pwmdrawer_drawsignal();
_delay_ms(10);

	}


	}


}

void vtask2(void *pvParameters){
	for(;;){
		if(g_edgeCount==4){
			xSemaphoreGive(xBinarySemaphore);
			g_edgeCount=0;
		}

	}
}






