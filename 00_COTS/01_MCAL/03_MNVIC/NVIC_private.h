/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : MSTK_Privite.h --> implementations                                             */
/* Features          : Register Definitions                                                            */
/*******************************************************************************************************/



/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/


#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


/*******************************************************************************************************/
/*                                    Macros Base Address Of NVIC Registers                            */
/*******************************************************************************************************/
 
 
#define NVIC_BASE_ADDRESS    0xE000E100

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


typedef struct 
{
    u32 ISER[8];
    u32 ICER[8];
    u32 ISPR[8];
    u32 ICPR[8];
    u32 IABR[8];
    u8  IPR[240];
    u32 RESERVED[581];
    u32 STIR;
    

} NVIC_t;

/*******************************************************************************************************/
/*                                   Struct Macros Base Address Of NVIC                                */
/*******************************************************************************************************/

#define     NVIC_REG    ((volatile NVIC_t*)(NVIC_BASE_ADDRESS))

#define     SCB_AIRCR   (*(volatile u32*) 0xE000ED0C)

#define     VECTKEY     0x05FA0000

#endif // GPIO_PRIVATE_H