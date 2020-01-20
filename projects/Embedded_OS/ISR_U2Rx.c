/* ISR receiver
 *		
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author        	Date      			Comments on this revision		
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Serge Hould      20 Jan. 2020		v1.0.0
 *
 **********************************************************************/
/* Scheduler includes. */
#include "FreeRTOS.h"
#include "queue.h"
#include "semphr.h"
#include "include/console.h"
#include "include/public.h"


void _ISR_NO_PSV _U2RXInterrupt( void )
{
    char cChar;

	/* Get the character and post it on the queue of Rxed characters.
	If the post causes a task to wake force a context switch as the woken task
	may have a higher priority than the task we have interrupted. */
	IFS1bits.U2RXIF = 0;
	while( U2STAbits.URXDA )
	{
		cChar = U2RXREG;
	}

}

 