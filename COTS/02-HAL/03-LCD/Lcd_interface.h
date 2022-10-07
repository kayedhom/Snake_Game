/******************************************************/
/******************************************************/
/*****************Author: Baraa Adel********************/
/**************File: Lcd_interface.h*******************/
/******************Date:10th Sep 2022******************/
/*********************Version: V1**********************/
/***********Desc:functions'declrations ****************/
/******************************************************/
/******************************************************/
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

#define HIGH   1
#define LOW    0
void LCD_VidInit(void);
void LCD_SendCommand(u8 Copy_u8Comnd);
void LCD_SendData(u8 Copy_u8Char);
void LCD_StringWrite(u8 *Copy_pu8String);
void LCD_WriteInteger(u32 Copy_u8Number);
void LCD_Position(u8 Copy_u8Location,u8 Copy_u8LineNum);
void LCD_WriteCGRAM(u8 Copy_u8PatternNumper,u8* Copy_u8Patterns);
void LCD_VidClear(void);
void LCD_VidCursorHide(void);


#endif
