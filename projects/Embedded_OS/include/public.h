/* ***************************************************************************
 * File: public.h
 * Description: contains public prototypes and shared macros
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author        	Date      		Comments on this revision
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *                                  - v1
 *****************************************************************************/

#ifndef PUBLIC_H
#define PUBLIC_H

#define 	_ISR_NO_PSV 	__attribute__((__interrupt__, no_auto_psv))

#define     BTN0    _RD6              // S3
#define     BTN1    _RD7             // S6
#define     BTN2    _RA7            // S5
#define     BTN3    _RD13           // S4

#define     D3      _LATA0
#define     D4      _LATA1

    
void vStartTaskBlink1(void);
void vStartTaskBlink2(void);
#endif /* PUBLIC_H */