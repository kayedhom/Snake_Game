/******************************************************/
/******************************************************/
/*****************Author: Baraa Adel********************/
/**************File: DIO_interface.h*******************/
/******************Date: 8th Sep 2022*****************/
/*********************Version: V1.1**********************/
/***********Desc:functions'declarations ****************/
/******************************************************/
/******************************************************/


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#define LOW 0
#define HIGH 1

#define INPUT 0
#define OUTPUT 1

error_state DIO_VidSetPinDirection(u8 Copy_U8Port , u8 Copy_U8Pin , u8 Copy_U8Dir);
error_state DIO_VidSetPinValue(u8 Copy_U8Port , u8 Copy_U8Pin , u8 Copy_U8Val);

error_state DIO_VidSetPortDirection(u8 Copy_U8Port , u8 Copy_U8Dir);
error_state DIO_VidSetPortValue(u8 Copy_U8Port , u8 Copy_U8Val);

error_state PinDIO_VidTogglePinValue(u8 Copy_U8Port , u8 Copy_U8Pin);

u8 DIO_U8GetPinValue(u8 Copy_U8Port , u8 Copy_U8Pin);
u8 DIO_U8GetPortValue(u8 Copy_U8Port);
#endif
