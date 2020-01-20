/* ***************************************************************************
 * File: vTaskBlink2.c
 * Description: to complete
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author        	Date      		Comments on this revision
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *                                  - v1
 *****************************************************************************/
#include <string.h>
#include <stdio.h>
/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"
#include "include/public.h"
#include "include/Tick4.h"

/* Private static function declarations */
static void vTaskBlink2( void *pvParameters )
{

   pvParameters = pvParameters ;    // This is to get rid of annoying warnings

}

/* Public function declarations */
void vStartTaskBlink2(void){
      xTaskCreate( vTaskBlink2, ( char * ) "Task 2", 240, NULL, 1, NULL );
}






