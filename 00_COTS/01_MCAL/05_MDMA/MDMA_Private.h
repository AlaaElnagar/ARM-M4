/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : MDMA_Privite.h --> implementations                                              */
/* Features          : Register Definitions                                                            */
/*******************************************************************************************************/


/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/

#ifndef DMA_REG_H_
#define DMA_REG_H_

/*******************************************************************************************************/
/*                                    Macros Base Address Of DMA1 Registers                            */
/*******************************************************************************************************/

#define BASE_ADRESS_DMA_1            0x40026000
#define BASE_ADRESS_DMA_2            0x40026400


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
	volatile u32 CR;
	volatile u32 NDTR;
	volatile u32 PAR;
	volatile u32 M0AR;
	volatile u32 M1AR;
	volatile u32 FCR;

}DMACHANNEL;


typedef struct
{
	volatile u32 LISR;
	volatile u32 HISR;
	volatile u32 LIFCR;
	volatile u32 HIFCR;
	volatile DMACHANNEL CHANNEL[8];

}DMA;


#define MDMA_1 ( ( volatile DMA * ) 0x40026000 )

#define MDMA_2 ( ( volatile DMA * ) 0x40026400 )

#endif /* DMA_REG_H_ */
