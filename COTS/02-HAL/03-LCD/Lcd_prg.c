/******************************************************/
/******************************************************/
/*****************Author: Baraa Adel********************/
/**************File: Lcd_prg.c*******************/
/******************Date:10th Sep 2022******************/
/*********************Version: V1**********************/
/***********Desc:functions'definitions ****************/
/******************************************************/
/******************************************************/

#define F_CPU 8000000UL
#include <util/delay.h>
#include"STD_TYPES.h"
#include"bit_math.h"
#include"Lcd_cfg.h"
#include"Lcd_private.h"




void LCD_SendCommand(u8 Copy_u8Comnd)
{
	DIO_VidSetPinValue(CONTROL_PORT,RS,LOW);
	DIO_VidSetPinValue(CONTROL_PORT,RW,LOW);
	DIO_VidSetPortValue(DATA_PORT,Copy_u8Comnd);
	DIO_VidSetPinValue(CONTROL_PORT,EN,HIGH);
	_delay_us(1);
	DIO_VidSetPinValue(CONTROL_PORT,EN,LOW);
}


void LCD_VidInit(void)
{
	DIO_VidSetPortDirection(DATA_PORT,OUTPUT);
	DIO_VidSetPinDirection(CONTROL_PORT,RS,HIGH);
	DIO_VidSetPinDirection(CONTROL_PORT,RW,HIGH);
	DIO_VidSetPinDirection(CONTROL_PORT,EN,HIGH);

	_delay_ms(35);
    LCD_SendCommand(FUNSET);
	_delay_ms(1);
	LCD_SendCommand(ON_OFF);
	_delay_ms(1);
	LCD_SendCommand(CLEAR);
	_delay_ms(2);
}



void LCD_SendData(u8 Copy_u8Char)
{
	DIO_VidSetPinValue(CONTROL_PORT,RS,HIGH);
	DIO_VidSetPinValue(CONTROL_PORT,RW,LOW);
	DIO_VidSetPortValue(DATA_PORT,Copy_u8Char);
	DIO_VidSetPinValue(CONTROL_PORT,EN,HIGH);
	_delay_us(1);
	DIO_VidSetPinValue(CONTROL_PORT,EN,LOW);
}
void LCD_StringWrite(u8 *Copy_pu8String)
{
	for(int i=0; Copy_pu8String[i] != '\0' ; i++)
		  LCD_SendData(Copy_pu8String[i]);

}




void LCD_WriteInteger(u32 Number){
	u32 reminder=0,revers=0,temp=0,count,n=Number;
if (Number==0)LCD_SendData('0');
			else{
			for(count=-1;0==temp;count++)
			{temp=n%10;n/=10;}
			while(Number!=0)
			{reminder=Number %10;revers=revers*10+reminder;Number/=10;}
			temp=0;
			while (revers!=0)
			{temp=revers%10;LCD_SendData(temp+'0');revers/=10;}
			while(0 != count)
			{LCD_SendData('0');count--;}
	}}


void LCD_Position(u8 pos, u8 row){
	if (row == 0 && pos<16)
	LCD_SendCommand((pos & 0x0F)|0x80);
	else if (row == 1 && pos<16)
	LCD_SendCommand((pos & 0x0F)|0xC0);
}

void LCD_WriteCGRAM(u8 CGRAM_Count,u8* arr)
{
	u8 Count=0,i;
	Count=CGRAM_Count*8;
	LCD_SendCommand(Count+64);
	for(i=0;i<8;i++)
	{
		LCD_SendData(arr[i]);
	}

}

void LCD_VidClear(void)
{
	  LCD_SendCommand(CLEAR);
	  _delay_ms(2);

}
void LCD_VidCursorHide(void)
{
	LCD_SendCommand(CURSER_HIDE);
	_delay_ms(1);

}




