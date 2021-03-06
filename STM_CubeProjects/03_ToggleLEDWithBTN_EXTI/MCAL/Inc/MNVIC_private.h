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

#if(0)
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

#endif

typedef struct{

	volatile u32 ISER    [ 32 ];
	volatile u32 ICER    [ 32 ];
	volatile u32 ISPR    [ 32 ];
	volatile u32 ICPR    [ 32 ];
	volatile u32 IAPR    [ 32 ];
	volatile u32 RESERVED[ 32 ];
	volatile u8 IPR      [ 128];

}NVIC;

#define MNVIC      ( ( volatile NVIC *)0xE000E100 )

#define MNVIC_STIR ( ( volatile u32  *)0xE000EF00 )

//SCB
typedef struct{

	volatile u32 CPUID;
	volatile u32 ICSR;
	volatile u32 VTOR;
	volatile u32 AIRCR;
	volatile u32 SCR;
	volatile u32 CCR;
	volatile u32 SHPR1;
	volatile u32 SHPR2;
	volatile u32 SHPR3;
	volatile u32 SHCSR;
	volatile u32 CFSR;
	volatile u32 HFSR;
	volatile u32 RESERVED;
	volatile u32 MMFAR;
	volatile u32 BFAR;

}SCB_Type;

#define SCB ((volatile SCB_Type *) 0xE000ED00 )

#endif // GPIO_PRIVATE_H
