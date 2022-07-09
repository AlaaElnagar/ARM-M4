/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : MSPI_Interface.c --> implementations                                            */
/* Module  Features  :                                                                                 */
/*      01- MSPI1_voidInit                                                                             */
/*      02- MSPI1_voidSendDataU8                                                                       */
/*      03- MSPI1_voidSetCallBack                                                                      */
/*******************************************************************************************************/

/*******************************************************************************************************/
/*	* What i sell To Customer                                                                          */
/*		*  The Archictect Give The API	                                                               */
/*						- The Name Of Function                                                         */
/*						- What is The Input                                                            */
/*						- What Is The Output                                                           */
/*						- Macro                                                                        */
/*******************************************************************************************************/

/*******************************************************************************************************/
/*                                   guard of file will call one time in .c                            */
/*******************************************************************************************************/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"


/*#####################################################################################################*/
/*#####################################################################################################*/




#define MSPI_DISABLE                 0
#define MSPI_ENABLE                  1

#define MSPI_MODE0                   0
#define MSPI_MODE1                   1
#define MSPI_MODE2                   2
#define MSPI_MODE3                   3

#define MSPI_MASTER                  0
#define MSPI_SLAVE                   1

#define MSPI_FPCLK_DIVIDED_BY_2      0b000
#define MSPI_FPCLK_DIVIDED_BY_4      0b001
#define MSPI_FPCLK_DIVIDED_BY_8      0b010
#define MSPI_FPCLK_DIVIDED_BY_16     0b011
#define MSPI_FPCLK_DIVIDED_BY_32     0b100
#define MSPI_FPCLK_DIVIDED_BY_64     0b101
#define MSPI_FPCLK_DIVIDED_BY_128    0b110
#define MSPI_FPCLK_DIVIDED_BY_256    0b111

#define MSPI_MSB_FIRST               0
#define MSPI_LSB_FIRST 				 1

#define HW_SLAVE_MANAGEMENT          0
#define SW_SLAVE_MANAGEMENT          1

#define MSPI_8BIT_DATA               0
#define MSPI_16BIT_DATA              1

#define MSPI_INT_DISABLE             0
#define MSPI_TXE_INT_ENABLE          1
#define MSPI_RXNE_INT_ENABLE         2


void MSPI1_voidInit         ( void               ) ;
u8   MSPI1_voidSendDataU8  ( u8 Copy_u8Data     ) ;
void MSPI1_voidSetCallBack ( void (*ptr) (void) ) ;


#endif /* SPI_INTERFACE_H_ */
