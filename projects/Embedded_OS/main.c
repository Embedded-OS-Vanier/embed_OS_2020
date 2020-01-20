/* ***************************************************************************
 * File: main.c
 * Description: Main source file for all Embedded Operating Systems labs.
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author        	Date      		Comments on this revision
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * SH               Jan 2019        V1.0.0    
 * SH               17 Dec 2019     V1.1.0  Add i2c and console libraries                             
 *****************************************************************************/

/* Standard includes. */
#include <stdio.h>
/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "croutine.h"

//Library includes
#include "include/console.h"
#include "include/adc.h"
#include "include/public.h"
#include "include/initBoard.h"
#include "include/Tick4.h"   
#include "include/i2c1.h"

/* Prototypes for the standard FreeRTOS callback/hook functions implemented within this file. */
void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName );

int main( void )
{
    /* CLK config. at 16MHz*/
    OSCILLATOR_Initialize();
    initIO();

    // LCD test
    //LCDInit();
    //fprintf2(_LCD, "Hello LCD\n");
    
    // Uart1 test
    initUart1();
    fprintf2(_UART1, "Hello UART1\n");
    
   /* Tasks creation */

     
	/* Finally start the scheduler. */
	vTaskStartScheduler();

	/* Will only reach here if there is insufficient heap available to start the scheduler. */
    while(1);
	return 0;
}
/*-----------------------------------------------------------*/


void vApplicationIdleHook( void )
{
}

void vApplicationStackOverflowHook( TaskHandle_t pxTask, char *pcTaskName )
{
    pxTask= pxTask;
    pcTaskName = pcTaskName;
		for( ;; );
}
