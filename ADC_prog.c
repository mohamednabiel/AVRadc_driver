/*
 * ADC_prog.c
 *
 *  Created on: Sep 17, 2018
 *      Author: nabil
 */


#include "std_types.h"

#include "utils.h"

#include "AVR_DIOReg.h"

#include "ADC.int.h"

u8 AdcU8GetConversion(u8 AdcChannelNoCpy,u8* Pu8AdcChannelError);
void AdcVidIni(void);

void main()
{


}

/*
!Comment:
Description: this Function Sets The Adc
Input: Nothing
Output:Nothing
*/
void AdcVidIni(void)
{
	u8 u8AdcRiLOC;  //The Right Register .
	u8 u8AdcLeLOC;  //  The Left Register.
	u8 u8AdcVoReLOC;//Choose The Voltage Reference {VREF , AVCC ,2.56}
	u8 u8AdcChaLOC; //Choose The CHANNEL .
 	u8 u8AdcENLOC;  //The Enable For Adc .
	u8 u8ADCDISLOC; //The Disable For ADC.
	u8 u8PreDIVLOC; //ADC Prescaler Selections { _{2,4,8,16,32,64,128}_CLK}
	u8 u8IntEnLOC;  //The Enable For Interrupt
	u8 u8IntDisLOC; //The Disable For Interrupt

	u8AdcRiLOC   = ADCRIGHTR;
	u8AdcLeLOC   = ADCLEFTR;
	u8AdcVoReLOC = AREF;
	u8AdcChaLOC  = ADC0 ;
	u8AdcENLOC   = ADC_ENABLE;
	u8ADCDISLOC  = ADC_DISABLE;
	u8PreDIVLOC  = _2_CLK;
	u8IntEnLOC   = INTERRUPT_ENABLE;
	u8IntDisLOC  = INTERRUPT_DISABLE;

	ADMUX =( u8AdcVoReLOC | u8AdcLeLOC |u8AdcChaLOC); // Set The ADMUX Register

	ADCSRA =(u8PreDIVLOC | u8IntDisLOC |u8AdcENLOC); // Set The ADCSRA Register
}
/*
!Comment:
Description: this function starts the conversion of the analog signal
Input: The Channel Number
Output:Nothing
*/
u8 AdcU8GetConversion(u8 AdcChannelNoCpy ,  u8* Pu8AdcChannelError)
{
	(*Pu8AdcChannelError) = DIO_u8OK;
	if((AdcChannelNoCpy > ADC_CHANNELHIGH) || (AdcChannelNoCpy<ADC_CHANNELLOW) )
	{
		/*Set the error State of the function*/
		(*Pu8AdcChannelError) = DIO_u8NOK;
	}
	else
	{
		Set_Bit(ADCSRA, 6); // start conversion
		switch(AdcChannelNoCpy)
		{
		case 0 :
			while(! (Get_Bit(ADCSRA , 4)) )
			{}
			Set_Bit(ADCSRA, 4);
			break;
		case 1 :
			while(! (Get_Bit(ADCSRA , 4)) )
			{}
			Set_Bit(ADCSRA, 4);
			break;
		case 2 :
			while(! (Get_Bit(ADCSRA , 4)) )
			{}
			Set_Bit(ADCSRA, 4);
			break;
		case 3 :
			while(! (Get_Bit(ADCSRA , 4)) )
			{}
			Set_Bit(ADCSRA, 4);
			break;
		case 4 :
			while(! (Get_Bit(ADCSRA , 4)) )
			{}
			Set_Bit(ADCSRA, 4);
			break;
		case 5 :
			while(! (Get_Bit(ADCSRA , 4)) )
			{}
			Set_Bit(ADCSRA, 4);
			break;
		case 6 :
			while(! (Get_Bit(ADCSRA , 4)) )
			{}
			Set_Bit(ADCSRA, 4);
			break;
		case 7 :
			while(! (Get_Bit(ADCSRA , 4)) )
			{}
			Set_Bit(ADCSRA, 4);
			break;
		}
		return ADCH ;
	}




}


