/*
 * LCD_int.h
 *
 *  Created on: Feb 10, 2022
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef LCD_INT_H_
#define LCD_INT_H_

ES_t LCD_enuInit(void);

ES_t LCD_enuWriteData(u8 Copy_u8Data);

ES_t LCD_enuWriteIntegerNum(u16 Copy_u16IntegerData);

ES_t LCD_enuWriteCommand(u8 Copy_u8Command);

ES_t LCD_enuSendString(const char * Copy_pcString);

ES_t LCD_enuGoToPosition(u8 Copy_u8Row, u8 Copy_u8Col);

#endif /* LCD_INT_H_ */
