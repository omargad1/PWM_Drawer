/*
 * pwm_drawer.h
 *
 *      Author: omar mohamed
 */

#ifndef PWM_DRAWER_H_
#define PWM_DRAWER_H_

#include "std_types.h"

#define _F_CPU           1000000
/*******************************************************************************
 *                       PWM WAVE GLCD COMMANDS                                   *
 *******************************************************************************/

#define PWM_DRAWER_GLCD_HIGH_LINE					(0x0202020202UL)
#define PWM_DRAWER_GLCD_LOW_LINE					(0x4040404040UL)
#define PWM_DRAWER_GLCD_RISING_EDGE					(0x02027E4040UL)
#define PWM_DRAWER_GLCD_FALLING_EDGE				(0x40407E0202UL)
#define PWM_DRAWER_GLCD_RIGHT_ARROW_HEAD			(0x003E081C2AUL)
#define PWM_DRAWER_GLCD_LEFT_ARROW_HEAD				(0x2A1C083E00UL)
#define PWM_DRAWER_GLCD_ARROW_MIDDLE_BODY			(0x0808080808UL)


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


void pwmdrawer_init(void);
void pwmdrawer_measuresginal(void);
void pwmdrawer_drawsignal(void);

/*
 *  extern global variables
 */

extern  uint32 frequency;
extern uint32 duty_cycle;
extern  uint8 g_edgeCount ;


#endif /* PWM_DRAWER_H_ */
