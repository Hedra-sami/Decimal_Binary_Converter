/*
 * Keypad_int.h
 *
 *  Created on: Aug 14, 2023
 *      Author: Hedra
 */

#ifndef HAL_KEYPAD_HANDLER_V1_KEYPAD_INT_H_
#define HAL_KEYPAD_HANDLER_V1_KEYPAD_INT_H_
#include"../../lib/stdtypes.h"

void KEYPAD_vidInit();
u8 KEYPAD_u8GetPressed();
u8 KEPAD_u8IsPressed(u8 copy_u8ID);
const u8*KEYPAD_u8cpGetAll();

#endif /* HAL_KEYPAD_HANDLER_V1_KEYPAD_INT_H_ */
