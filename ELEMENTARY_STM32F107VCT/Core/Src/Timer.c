/*
 * Timer.c
 *
 *  Created on: Feb 19, 2022
 *      Author: kimsanggil
 */

#include "Timer.h"

#if HAL_TIMER_EXTI
 void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	 if(htim->Instance == TIM1){
		 timer1_count++;
		 if(timer1_count == 100){
			 HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_8);
			 HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_9);
			 HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_10);
			 HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_11);
			 timer1_count = 0;
		 }
	 }
	 if(htim->Instance == TIM2){
		 timer2_count++;
		 if(timer2_count == 1000){
			 HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_12);
			 HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_13);
			 HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_14);
			 HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_15);
			 timer2_count = 0;
		 }
	 }
}
#endif
