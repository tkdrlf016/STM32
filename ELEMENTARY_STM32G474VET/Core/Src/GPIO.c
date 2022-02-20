/*
 * GPIO.c
 *
 *  Created on: Feb 20, 2022
 *      Author: kimsanggil
 */
#include "GPIO.h"

void HAL_GPIO_Write(){
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_15,GPIO_PIN_SET);
	HAL_Delay(1000);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_12,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_15,GPIO_PIN_RESET);
	HAL_Delay(1000);
}


void HAL_GPIO_Read(){
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_10,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_11,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_12,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_13,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_14,GPIO_PIN_SET);
	HAL_GPIO_WritePin(GPIOE,GPIO_PIN_15,GPIO_PIN_SET);

	if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==GPIO_PIN_RESET)
	{
		HAL_Delay(50);
		if(HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_4)==GPIO_PIN_RESET)
		{
			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,GPIO_PIN_RESET);
		}
	}else{
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_8,GPIO_PIN_SET);
	}

	if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==GPIO_PIN_SET)
	{
		HAL_Delay(50);
		if(HAL_GPIO_ReadPin(GPIOA, GPIO_PIN_7)==GPIO_PIN_SET)
		{
			HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,GPIO_PIN_RESET);
		}
	}else{
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_9,GPIO_PIN_SET);
	}

}

#if HAL_GPIO_EXTI
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{

	if(GPIO_Pin == GPIO_PIN_1) // pull-down switch
	{
		for(int i =0; i<1000;i++){}
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_1) == 0){
		}else{
			HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_8);
		}
	}
	if(GPIO_Pin == GPIO_PIN_2) // pull-up switch
	{
		for(int i =0; i<1000;i++){}
		if(HAL_GPIO_ReadPin(GPIOA,GPIO_PIN_2) == 1){
		}else{
			HAL_GPIO_TogglePin(GPIOE, GPIO_PIN_9);
		}
	}
}
#endif


