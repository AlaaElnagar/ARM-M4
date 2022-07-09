/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

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


void MSPI_VidInit         ( void               ) ;
u8   MSPI1_VidSendDataU8  ( u8 Copy_u8Data     ) ;
void MSPI1_VidSetCallBack ( void (*ptr) (void) ) ;


#endif /* SPI_INTERFACE_H_ */
