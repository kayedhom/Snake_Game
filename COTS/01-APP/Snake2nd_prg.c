/******************************************************/
/******************************************************/
/*****************Author: Baraa Adel*******************/
/******************File: Snak2nd_prg.c*****************/
/******************Date:6th Oct 2022*******************/
/*********************Version: V1**********************/
/****************Desc:SNAKE_APP_Code*******************/
/******************************************************/
/******************************************************/



#include "STD_TYPES.h"
#include "bit_math.h"
#include <util/delay.h>
#include "Snake2nd_private.h"
#include "Snake2nd_cfg.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define up 0
#define right 1
#define down 2
#define left 3




typedef struct line
{
  s16 Row,Column;
  u8 Dir:2 ;
} line;


bool LCD_Array[lcd_hight][lcd_width];
line snake_node[max_length];
line Egg_pos;
u8 Snake_Length;
bool LOSER=true,WINNER=true;
u8 Eggs_number;
u8 Snake_Bodies[8];
u8 Snake_Clear[8] = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};
bool DrawLineCheck;



void Snake2nd_Init(void)
{
		//make the array empty
	for (u8 r=0;r<lcd_hight;r++)
	  {
	     for (u8 c=0;c<lcd_width;c++)
	     {
	        LCD_Array[r][c] = false;
	     }
	  }
		//Snake body empty
	for (u8 count=0;count<(max_length);count++)
	  {
		  snake_node[count].Row=0;
		  snake_node[count].Column=0;
	  }
		//Snake Beginning body
	for (u8 count=0;count<(beginning_length);count++)
	  {
		  snake_node[count].Row=beginning_row;
		  snake_node[count].Column=beginning_col;
		  snake_node[count].Dir=beginning_dir;
	     LCD_Array[snake_node[count].Row][snake_node[count].Column] = true;
	  }
}
void Snake2nd_Beginning(void)
{
	//Let's Begin
  LCD_Position(3,0);
  LCD_StringWrite("Snake Game");
  _delay_ms(3000);
  LCD_VidClear();
  //Default Beginning
  LOSER = false;
  WINNER=false;
  Eggs_number = 0;
  Snake2nd_Init();
  Snake_Length=beginning_length;
}


void Snake2nd_AddLine(void)
{
	//Add line to Snake
  Snake_Length++;
  	//Copy to the next
  snake_node[Snake_Length-1].Row=snake_node[Snake_Length-2].Row;
  snake_node[Snake_Length-1].Column=snake_node[Snake_Length-2].Column;
  snake_node[Snake_Length-1].Dir=snake_node[Snake_Length-2].Dir;
}
void Snake2nd_AddEgg(void)
{
	  bool Egg_Check = true;
	  while (Egg_Check)
	  {
		 //Random Position for Egg
		  Egg_pos.Row = rand()%lcd_hight;
		  Egg_pos.Column = rand()%lcd_width;
		  Egg_Check = false;
	     //Egg is not in the snake body
		    for (u8 count=1;count<Snake_Length && Egg_Check==false;count++)
		    {
		    	if (snake_node[Snake_Length-count].Row == Egg_pos.Row && snake_node[Snake_Length-count].Column == Egg_pos.Column)
		    	{
		    		Egg_Check = true;
		    	}
		    }
	  }
}


void Snake2d_pop(void)
{
	//pop every line == delete snake
	for (u8 count=0;count<(max_length);count++)
	{
		snake_node[count].Row=0;
		snake_node[count].Column=0;
	}
}
void Snake2d_Loser(void)
{
  _delay_ms(1000);
  LCD_VidClear();
  LOSER = true;   //loser
  Snake2d_pop();  //delete the snake
LCD_Position(3,0);
  LCD_StringWrite("Game Over!");
LCD_Position(2,1);
  LCD_StringWrite("Your Score: ");
  LCD_WriteInteger(Eggs_number);
  _delay_ms(2500);
  LCD_VidClear();
}

void Snake2d_Winner()
{
  _delay_ms(1000);
  LCD_VidClear();
  WINNER=true; //winner
  Snake2d_pop();
LCD_Position(2,0);
  LCD_StringWrite("Winner!!");
LCD_Position(4,1);
  LCD_StringWrite("Score: ");
  LCD_WriteInteger(Eggs_number);
  _delay_ms(3000);
  LCD_VidClear();

}

void Snake2nd_MoveHead(void)
{
		//Head go ahead
	switch(snake_node[0].Dir)
  {
    case up   : snake_node[0].Row--;    break;
    case down : snake_node[0].Row++;    break;
    case right: snake_node[0].Column++; break;
    case left : snake_node[0].Column--; break;
    default : break;
  }
//Edges Conditions
	if (snake_node[0].Column >= lcd_width)
  {
	  snake_node[0].Column = 0;
  }
  else if (snake_node[0].Column < 0)
  {
	  snake_node[0].Column = lcd_width-1;
  }
  else if (snake_node[0].Row >= lcd_hight)
  {
	  snake_node[0].Row = 0;
  }
  else if (snake_node[0].Row < 0)
  {
	  snake_node[0].Row = lcd_hight-1;
  }

	//Do not eat your self
	for(u8 count=1; count<Snake_Length; count++)
  {
    if(snake_node[0].Row==snake_node[count].Row && snake_node[0].Column==snake_node[count].Column)
	{
    	Snake2d_Loser();
    }
  }
    //Check max Length to win
	if (Snake_Length==max_length)
  {
	  Snake2d_Winner();
  }
  else
  {
	  //Write in the array the head position
	  LCD_Array[snake_node[0].Row][snake_node[0].Column] = true;
	  //Check score increase or not
	  if ((snake_node[0].Row == Egg_pos.Row) && (snake_node[0].Column == Egg_pos.Column))
    {
     //increase score
      Eggs_number++;
     //new Egg
      Snake2nd_AddEgg();
     //increase length
      Snake2nd_AddLine();
    }
  }
}
void Snake2nd_push(void)
{
	//Delete the tail in the array to make sense
	LCD_Array[snake_node[Snake_Length-1].Row][snake_node[Snake_Length-1].Column] = false;
  for (u8 count=1;count<Snake_Length;count++)
  {
	  //shift the whole body
	  snake_node[Snake_Length-count].Row=snake_node[Snake_Length-count-1].Row;
	  snake_node[Snake_Length-count].Column=snake_node[Snake_Length-count-1].Column;
	  snake_node[Snake_Length-count].Dir=snake_node[Snake_Length-count-1].Dir;
  }
  //moving Head After the body join it
  Snake2nd_MoveHead();

}


void Snake2nd_Print(void)
{
//CGRAM drawing
	u8 ShapeNumber=0;
  if (!LOSER)
  {
	  //Draw the Egg in the Array
      LCD_Array[Egg_pos.Row][Egg_pos.Column] = true;
	  for (u8 count=0;count<8;count++)
      {
		   //Start by Null then ask if there is a snake body
           LCD_WriteCGRAM(count, Snake_Clear);
      }
	  	  //Check each pixel and is there a snake line draw it!
	  for(u8 row=0;row<2;row++)
      {
          for(u8 col=0;col<16;col++)
          {
        	  //default choice
        	  DrawLineCheck = false;
              for(u8 ByteCount=0;ByteCount<8;ByteCount++)
              {
            	  //the container of the snake char
                 u8 DrawLine=0;
                  //check every pixel
                 if (LCD_Array[row*8+ByteCount][col*5+0])
                 {
                    DrawLine+=0b00010000;
                    DrawLineCheck = true;
                 }
                 if (LCD_Array[row*8+ByteCount][col*5+1])
		         {
		             DrawLine+=0b00001000;
		             DrawLineCheck = true;
                 }
                 if (LCD_Array[row*8+ByteCount][col*5+2])
		         {
		             DrawLine+=0b00000100;
		             DrawLineCheck = true;
                 }
                 if (LCD_Array[row*8+ByteCount][col*5+3])
		         {
		             DrawLine+=0b00000010;
		             DrawLineCheck = true;
                 }
                 if (LCD_Array[row*8+ByteCount][col*5+4])
                 {
                     DrawLine+=0b00000001;
                     DrawLineCheck = true;
                 }
                 //Save the body char
                 Snake_Bodies[ByteCount] = DrawLine;
              }
              //Did you find a snake body?
              if (DrawLineCheck)
              {
            	  //Draw in the CGRAM
                 LCD_WriteCGRAM(ShapeNumber, Snake_Bodies);
                  //Print the Char in its position
                 LCD_Position(col,row);
    	         LCD_SendData(ShapeNumber);
    	         	 //Draw Another Body
    	         ShapeNumber++;
              }
              else
              {
            	  //Null
            	  LCD_Position(col,row);
                  LCD_SendData(' ');
              }
         }
      }
  }

}

void Snake2nd_EditHead(u8 Dir){snake_node[0].Dir=Dir;}
u8 Snake2nd_Status(void){if(WINNER||LOSER) return 1; else return 0;}
u8 Snake2nd_GetHead(void){return (snake_node[0].Dir);}

