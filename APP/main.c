/*
 * main.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Hedra
 */
#include"../HAL/KeyPad_Handler_V1/KeyPad_int.h"
#include"../HAL/LCD_handler_v1/LCD_int.h"
#include"../HAL/LCD_handler_v1/LCD_Functions.h"
#include"util/delay.h"
#define NO_KEY_PRESSED 255

void main()
{
	/*Initializations*/
	LCD_vidinit();
	LCD_u8goTo(0,4);
	LCD_vidwriteString("Hedra Sami");


	_delay_ms(30);
	LCD_u8goTo(1,2);
	LCD_vidwriteString("D2B_Converter");

	_delay_ms(30);
	LCD_u8goTo(1,2);
	LCD_vidwriteString("D2B_Converter");
	_delay_ms(30);
	LCD_vidclearDisplay();
	LCD_viddisplayOnCursorOn();
	LCD_vidblinkCursor();
	KEYPAD_vidInit();
	u8 Local_u8Keypressed;
	u32 Local_u32Num=0;
	u8 num_organize[10];
	u8 Local_u8NumLength = 0 ;
	u32 iteration=1;
	Local_u8Keypressed = NO_KEY_PRESSED;
	while(1)
	{
		LCD_vidwriteString("Enter Num:");
		/*Enter the decimal number*/
		while(Local_u8Keypressed!='=')
		{
			Local_u8Keypressed = KEYPAD_u8GetPressed();
			if(Local_u8Keypressed != NO_KEY_PRESSED)
			{
				if(Local_u8Keypressed<=9)
				{
					LCD_vidwriteNumber(Local_u8Keypressed);
					num_organize[Local_u8NumLength]=Local_u8Keypressed;
					Local_u8NumLength++;
				}
				else
				{
					switch(Local_u8Keypressed)
					{
					case'=':
						break;
					case 'c':
						Local_u8NumLength=0;
						LCD_vidclearDisplay();
						LCD_vidwriteString("Enter Num:");
						break;
					case '-':
						LCD_vidshiftLeftCursor();
						LCD_vidwriteCharacter(' ');
						LCD_vidshiftLeftCursor();
						num_organize[Local_u8NumLength]='0';
						Local_u8NumLength--;
						break;
					case '+':
						break;
					case'*':
						break;
					default:
						break;
					}
				}
			}
		}
		for(u8 Local_u8DigitCounter = 0 ; Local_u8DigitCounter<Local_u8NumLength ; Local_u8DigitCounter++)
		{
			Local_u32Num += num_organize[Local_u8NumLength-Local_u8DigitCounter-1]*iteration;
			iteration*=10;
		}
		iteration=1;
		Local_u8NumLength=0;
		if(Local_u8Keypressed =='=')
		{
			LCD_vidbeginAtSecondLine();
			LCD_viddecimalToBinary(Local_u32Num);
			Local_u32Num=0;
		}
		Local_u8Keypressed=NO_KEY_PRESSED;
	}
}



