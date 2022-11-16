/*
 * myApp.c
 *
 *  Created on: Nov 16, 2022
 *      Author: clego
 */

#include "stm32f7xx_hal.h"
#include "stm32f723e_discovery_lcd.h"
#include "stdlib.h"

#include "myApp.h"

#define INTERNAL_BUFFER_START_ADDRESS 0x60000000
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

int cmpfunc(const void * a, const void *b)
{
	return (int)(*(uint32_t *)a - *(uint32_t*)b);
}

void mySort()
{
	uint32_t tickStart = 0, tickStop = 0, executionTime = 0;
	char executionTimeString[30];

	uint32_t myArray[ARRAY_SIZE];
	uwInternalBuffer = (uint32_t *)myArray;
#else
	uwInternalBuffer = (uint32_t *)INTERNAL_BUFFER_START_ADDRESS;
#endif

	for(uint32_t i = 0; i < ARRAY_SIZE; i++)
	{
		uwInternalBuffer[i] = ARRAY_SIZE - i;
	}

	tickStart = HAL_GetTick();
	qsort(uwInternalBuffer, ARRAY_SIZE, sizeof(uint32_t), cmpfunc);
	tickStop = HAL_GetTick();
	executionTime = tickStop - tickStart;
	//Internal Mem :
	//Time with double cache : 19ms
	//Time with instruction cache : 34ms
	//Time with data cache : 76ms
	//Time without cache : 77ms

	//External Mem:
	//Time with double cache : 415ms
	//Time with instruction cache : 1194ms
	//Time with data cache : 427ms
	//Time without cache : 1228ms

	snprintf(executionTimeString, 10000, "tps : %d ms", executionTime);
	BSP_LCD_DisplayStringAtLine(3, (uint8_t *) executionTimeString);
}
