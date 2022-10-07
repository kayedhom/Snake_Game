/******************************************************/
/******************************************************/
/*****************Author: Baraa Adel********************/
/*****************File: DIO_private.h******************/
/******************Date: 26th Aug 2022*****************/
/*********************Version: V1**********************/
/***************Desc:Naming & Addresses****************/
/******************************************************/
/******************************************************/



#define DDRA_REG *((u8*)0x3A)
#define DDRB_REG *((u8*)0x37)
#define DDRC_REG *((u8*)0x34)
#define DDRD_REG *((u8*)0x31)

#define PORTA_REG *((u8*)0x3B)
#define PORTB_REG *((u8*)0x38)
#define PORTC_REG *((u8*)0x35)
#define PORTD_REG *((u8*)0x32)

#define PINA_REG *((volatile u8*)0x39)
#define PINB_REG *((volatile u8*)0x36)
#define PINC_REG *((volatile u8*)0x33)
#define PIND_REG *((volatile u8*)0x30)

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3


#define LOW 0
#define HIGH 1

#define INPUT 0
#define OUTPUT 1

/*
#define PINA_REG  (*(volatile u8*)(0x19))+0x20
#define PINB_REG  (*(volatile u8*)(0x16))+0x20
#define PINC_REG  (*(volatile u8*)(0x13))+0x20
#define PIND_REG  (*(volatile u8*)(0x10))+0x20
*/

//(*(volatile uint8_t *)((0x16) + 0x20))
