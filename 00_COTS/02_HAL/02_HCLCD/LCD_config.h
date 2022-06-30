/*
 * LCD_config.h
 *
 *  Created on: Feb 10, 2022
 *      Author: Ahmed El-Gaafrawy
 */

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/*			Mode : EIGHT_BIT -  FOUR_BIT     */
#define LCD_MODE		FOUR_BIT

/*			Control Pins					*/
#define RS_GRP			_GPIOD_PORT
#define RS_PIN			_PIN_12

#define RW_GRP			_GPIOD_PORT
#define RW_PIN			_PIN_13

#define EN_GRP			_GPIOD_PORT
#define EN_PIN			_PIN_14


/*				Data Pins		*/

#define D7_GRP			_GPIOD_PORT
#define D7_PIN			_PIN_11

#define D6_GRP			_GPIOD_PORT
#define D6_PIN			_PIN_10

#define D5_GRP			_GPIOD_PORT
#define D5_PIN			_PIN_9

#define D4_GRP			_GPIOD_PORT
#define D4_PIN			_PIN_8



#define D3_GRP			_GPIOD_PORT
#define D3_PIN			_PIN_7

#define D2_GRP			_GPIOD_PORT
#define D2_PIN			_PIN_6

#define D1_GRP			_GPIOD_PORT
#define D1_PIN			_PIN_5

#define D0_GRP			_GPIOD_PORT
#define D0_PIN			_PIN_4


#endif /* LCD_CONFIG_H_ */
