/******************************************************/
/******************************************************/
/*****************Author: Baraa Adel********************/
/******************File: main.c*************************/
/******************Date:6th Oct 2022******************/
/*********************Version: V1**********************/
/****************Desc:SNAKE_APP ***********************/
/******************************************************/
/******************************************************/


#include <avr/delay.h>
#include"STD_TYPES.h"
#include"Error_state.h"
#include "DIO_interface.h"
#include "Lcd_interface.h"
#include "keypad_interface.h"
#include "Snake2nd_interface.h"

#define F_CPU 8000000UL
#define  step_time   50


u8 main(void)
{
    u8 x;
    LCD_VidInit();
    LCD_VidCursorHide();
	keypad_init();
	while(1)
	{
		//Here we begin Snake game
		if (Snake2nd_Status()==1)
		Snake2nd_Beginning();
		Snake2nd_Print();
		Snake2nd_push();
		_delay_ms(step_time);


        x=keypad_U8GetPressed();

		if(x!=50)
			switch(x){
			case 2:
				if(Snake2nd_GetHead()!=down)
					Snake2nd_EditHead(up);
			break;

			case 10:
				if(Snake2nd_GetHead()!=up)
					Snake2nd_EditHead(down);
			break;

			case 5:
				if(Snake2nd_GetHead()!=left)
					Snake2nd_EditHead(right);
			break;

			case 4:
				if(Snake2nd_GetHead()!=right)
					Snake2nd_EditHead(left);
			break;

			default:break;
			}


	 }

return 0;
}
