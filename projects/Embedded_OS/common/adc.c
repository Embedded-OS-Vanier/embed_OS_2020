/* File: adc.c
 * 
 * ADC converter functions
 *		
 *   *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Author        	Date      			Comments on this revision		
 *~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 * Serge Hould		December 15 2016     								-v1.1
 *
 *  
 *
 **********************************************************************/

#include "include/adc.h"

/* initialize the ADC for single conversion, select Analog input pins */
void initADC(void) 
{
    //AD1PCFGL = amask;    // select analog input pins
    
    /* AD1CON1 setting                                              */
    /* auto convert after end of sampling                           */
    /* e.g. 0b0000 0000 1110 0000 (0x00E0)  for 10 bits unsigned    */
    /*      0b0000 0101 1110 0000  for 12 bits signed               */
    AD1CON1 = 0b0000010011100000;
    AD1CSSL = 0;        // no scanning required 
    AD1CON3 = 0x1F02;   // max sample time = 31Tad, Tad = 2 x Tcy = 125ns >75ns
    AD1CON2 = 0;        // use MUXA, AVss and AVdd are used as Vref+/-
    AD1CON1bits.ADON = 1; // turn on the ADC
} //initADC

/**
  Prototype:        int readADC( int ch)
  Input:            Channel to read
  Output:           returns the conversion result
  Description:      Select the specified input channel, samples the channel 
                    and then returns the converted value.
  Comment:          
  Usage:           
*/
int readADC( int ch)
{
    AD1CHS  = ch;               // select analog input channel
    AD1CON1bits.SAMP = 1;       // start sampling, automatic conversion will follow
     while (!AD1CON1bits.DONE);   // wait to complete the conversion
    return ADC1BUF0;            // read the conversion result
} // readADC

