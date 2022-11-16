/*
 * myApp.c
 *
 *  Created on: Nov 16, 2022
 *      Author: clego
 */

#include "stm32f7xx_hal.h"
#include "stm32f723e_discovery_lcd.h"
#include "stdlib.h"

#define ARRAY_SIZE 30000

void myHelloWorld()
{
	BSP_LCD_Init();
	BSP_LCD_Clear(LCD_COLOR_BLACK);
	BSP_LCD_SetFont(&Font24);
	BSP_LCD_SetTextColor(LCD_COLOR_RED);
	BSP_LCD_SetBackColor(LCD_COLOR_BLACK);
	BSP_LCD_DisplayOn();
	BSP_LCD_DisplayStringAtLine(1, (uint8_t *) "Hello World");
	BSP_LCD_DisplayStringAtLine(2, (uint8_t *) "ZEBI");
}

uint32_t cmpfunc(const void * a, const void *b)
{
	return (*(uint32_t *)a - *(uint32_t*)b);
}

void mySort()
{
	uint32_t tickStart = 0, tickStop = 0, executionTime = 0;

	tickStart = HAL_GetTick();

	uint32_t myArray[ARRAY_SIZE];
	for(uint32_t i = 0; i < ARRAY_SIZE; i++)
	{
		myArray[i] = ARRAY_SIZE - i;
	}
	qsort(&myArray, sizeof(myArray), sizeof(uint32_t), cmpfunc);

	tickStop = HAL_GetTick();
	executionTime = tickStop - tickStart;

	BSP_LCD_DisplayStringAtLine(3, (uint8_t *) "Temps d'execution : %d", executionTime);
}
