/*
 * ADC.int.h
 *
 *  Created on: Sep 17, 2018
 *      Author: nabil
 */



#include "std_types.h"

#ifndef ADC_INT_H_
#define ADC_INT_H_

#define DIO_u8OK  0
#define DIO_u8NOK 1

//register at Memory
#define ADCH   *((u8*)0x25) //ADC HIGH REGISTER
#define ADCL   *((u8*)0x24) //ADC LOW  REGISTER
#define ADCSRA *((u8*)0x26) //ADC CONTROL STATUS REGISTER
#define ADMUX  *((u8*)0x27) //ADC MULTIPLEXER REGISTER

//the two registers for 10 BIT ADC
#define ADCRIGHTR 0b00000000    //the bit 5 is 0 for right adjust
#define ADCLEFTR  0b00100000    //the bit 5 is 1 for left adjust

//referrence voltage
#define AREF     0b00000000 //Here i choose the internal 5 volts
#define VCC      0b01000000 // Here i choose to connect out side
#define internal 0b11000000 //here i choose to connect internal half the volts (50%)2.56.

//channels selection
#define ADC0     0b00000000 //choosing the channel 0 at ADMUX
#define ADC1	 0b00000001 //choosing the channel 1 at ADMUX
#define ADC2	 0b00000010 //choosing the channel 2 at ADMUX
#define ADC3	 0b00000011 //choosing the channel 3 at ADMUX
#define ADC4	 0b00000100 //choosing the channel 4 at ADMUX
#define ADC5	 0b00000101 //choosing the channel 5 at ADMUX
#define ADC6	 0b00000110 //choosing the channel 6 at ADMUX
#define ADC7	 0b00000111 //choosing the channel 7 at ADMUX

//ADC ENABLE and DISAPLE
#define ADC_ENABLE  0b10000000 //enable ADC at ADCSRA
#define ADC_DISABLE 0b00000000 //disable ADC at ADCSRA

//ADC Prescaler values (ADPS2:0 in ADCSRA register)
#define _2_CLK		0x01	//division factor = XTAL/2 Hz
#define _4_CLK		0x02	//division factor = XTAL/4 Hz
#define _8_CLK		0x03	//division factor = XTAL/8 Hz
#define _16_CLK		0x04	//division factor = XTAL/16 Hz
#define _32_CLK		0x05	//division factor = XTAL/32 Hz
#define _64_CLK		0x06	//division factor = XTAL/64 Hz
#define _128_CLK	0x07	//division factor = XTAL/128 Hz

//Interrupt enable and disable
#define INTERRUPT_ENABLE	0b00001000	//set 1 to ADIE pin in ADCSRA register
#define INTERRUPT_DISABLE	0b00000000	//set 0 to ADIE pin in ADCSRA register

#define ADC_CHANNELLOW 0
#define ADC_CHANNELHIGH 7


/*
!Comment:
Description: this Function Sets The Adc
Input: Nothing
Output:Nothing
*/
void AdcVidIni(void);

/*
!Comment:
Description: this function starts the conversion of the analog signal
Input: The Channel Number
Output:Nothing
*/
u8 AdcU8GetConversion(u8 AdcChannelNoCpy ,u8* Pu8AdcChannelError );

#endif /* ADC_INT_H_ */
