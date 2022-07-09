/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : MUSART_Privite.h --> implementations                                            */
/* Features          : Register Definitions                                                            */
/*******************************************************************************************************/



/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/

#ifndef MSART_PRIVATE_H
#define MSART_PRIVATE_H

/*******************************************************************************************************/
/*                                    Macros Base Address Of UARTX Registers                           */
/*******************************************************************************************************/


#define USART1_BASE_ADRESS     0x40011000UL
#define USART2_BASE_ADRESS     0x40014400UL
#define USART6_BASE_ADRESS     0x40011400UL



/*******************************************************************************************************/
/*                                       Register Definitions                                          */
/*-----------------------------------------------------------------------------------------------------*/
/*     - Developer can't Edit in it                                                                    */
/*     - Register _ Defination		                                                                   */
/*     - Design :                                                                                      */
/*    				- #define	:	NO                                                                 */
/*    				- Union		:	NO                                                                 */
/*    				- Struct	:	YES                                                                */
/*                                                                                                     */
/*******************************************************************************************************/


typedef struct{
    u32 SBK       :1;
    u32 RWU       :1;
    u32 RE        :1;
    u32 TE        :1;
    u32 IDLEIE    :1;
    u32 RXNEIE    :1;
    u32 TCIE      :1;
    u32 TXEIE     :1;
    u32 PEIE      :1;
    u32 PS        :1;
    u32 PCE       :1;
    u32 WAKE      :1;
    u32 M         :1;
    u32 UE        :1;
    u32 RESERVED  :1;
    u32 OVER8     :1;
    u32 RESERVED2 :16;
}UART_CR1;


typedef struct{
    
    u32 SR;
    u32 DR;
    u32 BRR;
    UART_CR1 CR1;
    u32 CR2;
    u32 CR3;
    u32 GTPR;
}UART_t;

/*******************************************************************************************************/
/*                                   Struct Macros Base Address Of USARTx                              */
/*******************************************************************************************************/

typedef    volatile UART_t* UART_REG ;

#define     USART1_REG    ((volatile UART_t*)(USART1_BASE_ADRESS))
#define     USART2_REG    ((volatile UART_t*)(USART2_BASE_ADRESS))
#define     USART6_REG    ((volatile UART_t*)(USART6_BASE_ADRESS))

static UART_REG MUSART_GetHandler(u8 copy_u8Index);


#endif // UART_PRIVATE_H
