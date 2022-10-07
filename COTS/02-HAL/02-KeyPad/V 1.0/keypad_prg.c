/******************************************************/
/******************************************************/
/*****************Author: Baraa Adel********************/
/**************File: keypad_prg.c*******************/
/******************Date:10th Sep 2022******************/
/*********************Version: V1**********************/
/***********Desc:functions'definitions ****************/
/******************************************************/
/******************************************************/


#include "STD_TYPES.h"
#include"Error_state.h"
#include "DIO_interface.h"
#include "keypad_private.h"
#include "avr/delay.h"
#define KPD_PORT 0 ///in .cfg file

u8 keypad_U8GetPressed()
{
	u8 key = 50;
	u8 Pressed;
	for(u8 c=4; c<8; c++)
	{
		DIO_VidSetPinValue(KPD_PORT,c,LOW);
		for(u8 Row =0; Row<4; Row++)
		{
			Pressed = DIO_U8GetPinValue(KPD_PORT,Row);
			if(LOW == Pressed)
			{
				key = (Row * 4) + (c-4);
				while(LOW == Pressed)
				{
					Pressed =  DIO_U8GetPinValue(KPD_PORT,Row);
				}
				_delay_ms(5);
			}
		}
		DIO_VidSetPinValue(KPD_PORT,c,HIGH);
	}
	return key;
}

void keypad_init()
{
	DIO_VidSetPortDirection(KPD_PORT,0b11110000);
	DIO_VidSetPortValue(KPD_PORT,0b11111111);
}
