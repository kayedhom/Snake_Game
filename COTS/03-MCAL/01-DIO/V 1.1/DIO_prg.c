/******************************************************/
/******************************************************/
/*****************Author: Baraa Adel********************/
/*****************File: DIO_prg.c**********************/
/******************Date: 8th Sep 2022*****************/
/*********************Version: V1.1**********************/
/***********Desc:functions'definitions ****************/
/******************************************************/
/******************************************************/


#include"STD_TYPES.h"
#include "bit_math.h"
#include "Error_state.h"
#include"DIO_private.h"

error_state DIO_VidSetPinDirection (u8 Copy_U8Port , u8 Copy_U8Pin , u8 Copy_U8Dir){
	error_state state;
	state=Not_okay;
	if(Copy_U8Port<4 && Copy_U8Port>=0){
		if(Copy_U8Pin<10 && Copy_U8Pin>=0)
		{ state=okay;
	switch(Copy_U8Dir){
		case LOW:
		{
			switch(Copy_U8Port){
				case PORTA:
				CLEAR(DDRA_REG,Copy_U8Pin);
				break;
				case PORTB:
				CLEAR(DDRB_REG,Copy_U8Pin);
				break;
				case PORTC:
				CLEAR(DDRC_REG,Copy_U8Pin);
				break;
				case PORTD:
				CLEAR(DDRD_REG,Copy_U8Pin);
				break;
				
				default:
				break;
			}
			break;
		}
		case HIGH:
		{
			switch(Copy_U8Port){
				case PORTA:
				SET(DDRA_REG,Copy_U8Pin);
				break;
				case PORTB:
				SET(DDRB_REG,Copy_U8Pin);
				break;
				case PORTC:
				SET(DDRC_REG,Copy_U8Pin);
				break;
				case PORTD:
				SET(DDRD_REG,Copy_U8Pin);
				break;
				
				default:
				break;
			}
			break;
		}
		default:
		break;
	}}
	else
	state=OutOfRange;
		}
		else
	state=OutOfRange;
return state;
	}
	

error_state DIO_VidSetPinValue(u8 Copy_U8Port , u8 Copy_U8Pin , u8 Copy_U8Val){
	error_state state;
	state=Not_okay;
	if(Copy_U8Port<4 && Copy_U8Port>=0){
		if(Copy_U8Pin<10 && Copy_U8Pin>=0)
		{ state=okay;
	switch(Copy_U8Val){
		case LOW:

			switch(Copy_U8Port){
				case PORTA:
				CLEAR(PORTA_REG,Copy_U8Pin);
				break;
				case PORTB:
				CLEAR(PORTB_REG,Copy_U8Pin);
				break;
				case PORTC:
				CLEAR(PORTC_REG,Copy_U8Pin);
				break;
				case PORTD:
				CLEAR(PORTD_REG,Copy_U8Pin);
				break;

				default:
				break;
			}
			break;

		case HIGH:

			switch(Copy_U8Port){
				case PORTA:
				SET(PORTA_REG,Copy_U8Pin);
				break;
				case PORTB:
				SET(PORTB_REG,Copy_U8Pin);
				break;
				case PORTC:
				SET(PORTC_REG,Copy_U8Pin);
				break;
				case PORTD:
				SET(PORTD_REG,Copy_U8Pin);
				break;
				
				default:
				break;
			}
			break;

		default:
		break;
	}
}
else
state=OutOfRange;
	}
	else
state=OutOfRange;
return state;
}

error_state DIO_VidSetPortDirection(u8 Copy_U8Port , u8 Copy_U8Dir){
	error_state state;
	state=Not_okay;
	if(Copy_U8Port<4 && Copy_U8Port>=0)
		{ state=okay;
	switch(Copy_U8Port){
		case PORTA:
		DDRA_REG=Copy_U8Dir;
		break;
		case PORTB:
		DDRB_REG=Copy_U8Dir;
		break;
		case PORTC:
		DDRC_REG=Copy_U8Dir;
		break;
		case PORTD:
		DDRD_REG=Copy_U8Dir;
		break;
		default:
		break;
	}
	
}else state=OutOfRange;
return state;
}
error_state DIO_VidSetPortValue(u8 Copy_U8Port , u8 Copy_U8Val){
	error_state state;
	state=Not_okay;
	if(Copy_U8Port<4 && Copy_U8Port>=0)
		{ state=okay;
	switch(Copy_U8Port){
		case PORTA:
		PORTA_REG=Copy_U8Val;
		break;
		case PORTB:
		PORTB_REG=Copy_U8Val;
		break;
		case PORTC:
		PORTC_REG=Copy_U8Val;
		break;
		case PORTD:
		PORTD_REG=Copy_U8Val;
		break;
		default:
		break;
}}else state=OutOfRange;
	return state;
	}

u8 DIO_U8GetPortValue(u8 Copy_U8Port){
	u8 num ;
	switch(Copy_U8Port){
		case PORTA:
			num=PINA_REG;
			break;
		case PORTB:
			num=PINB_REG;
			break;
		case PORTC:
			num=PINC_REG;
			break;
		case PORTD:
			num=PIND_REG;
			break;
		default:
			break;
	}



return num;

}

error_state DIO_VidTogglePinValue(u8 Copy_U8Port , u8 Copy_U8Pin){
	error_state state;
	state=Not_okay;
	if(Copy_U8Port<4 && Copy_U8Port>=0){
		if(Copy_U8Pin<10 && Copy_U8Pin>=0)
		{ state=okay;
	switch(Copy_U8Port){
		case PORTA:
		TOGGLE(PORTA_REG,Copy_U8Pin);
		break;
		case PORTB:
		TOGGLE(PORTB_REG,Copy_U8Pin);
		break;
		case PORTC:
		TOGGLE(PORTC_REG,Copy_U8Pin);
		break;
		case PORTD:
		TOGGLE(PORTD_REG,Copy_U8Pin);
		break;
		default:
		break;
}
}else
	state=OutOfRange;
		}
		else
	state=OutOfRange;
	return state;
	}

u8 DIO_U8GetPinValue(u8 Copy_U8Port , u8 Copy_U8Pin){
u8 Value;
	if(Copy_U8Port<4 && Copy_U8Port>=0){
		if(Copy_U8Pin<10 && Copy_U8Pin>=0)
		{
	switch(Copy_U8Port){
		case PORTA:
		Value=GET(PINA_REG,Copy_U8Pin);
		break;
		case PORTB:
		Value=GET(PINB_REG,Copy_U8Pin);
		break;
		case PORTC:
		Value=GET(PINC_REG,Copy_U8Pin);
		break;
		case PORTD:
		Value=GET(PIND_REG,Copy_U8Pin);
		break;
		default:
		break;
}}}

	return Value;
	}
