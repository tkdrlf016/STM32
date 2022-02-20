/*
 * asd.c
 *
 *  Created on: Feb 20, 2022
 *      Author: kimsanggil
 */
#include "PWM_Example.h"

void Check_LED_Example(TIM_HandleTypeDef * htim){
	HAL_Delay(20);
	htim->Instance->CCR4 = duty;
	duty++;
	if(duty == 1000)
	{
		duty = 0;
	}
}
