/******************************************************/
/******************************************************/
/*****************Author: Baraa Adel********************/
/*****************File: bit_math.h******************/
/******************Date: 26th Aug 2022*****************/
/*********************Version: V1**********************/
/************Desc: Defining BITS Operations************/
/******************************************************/
/******************************************************/



#define TOGGLE(reg,bit) reg^=1<<bit
#define CLEAR(reg,bit) reg&=(~(1 << bit))
#define GET(reg,bit) (reg>>bit)&1
#define SET(reg,bit) reg|=1<<bit
#define SHIFT_ROTATE(reg,bit) reg^=1<<bit







