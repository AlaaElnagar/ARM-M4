/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : MUSART_Interface.h --> implementations                                          */
/* Features          : Register Definitions                                                            */
/*******************************************************************************************************/

/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H



void MUART_vInit(u8 copy_u8Index);

void MUART_vEnable(u8 copy_u8Index);

void MUART_vDisable(u8 copy_u8Index);

void MUART_u8SendData(u8 copy_u8Index, u8* copy_u8Data, u8 copy_u8Len);

u8 MUART_u8ReadData(u8 copy_u8Index);

UART_REG MUART_GetHandler(u8 copy_u8Index);


#endif //UART_INTERFACE_H_
