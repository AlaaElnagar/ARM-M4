/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : MDMA_Interface.h --> implementations                                            */
/* Module  Features  :                                                                                 */
/*      01- MDMA_voidSetConfiguration                                                                  */
/*      02- MDMA_voidDMAEnable                                                                         */
/*      03- MDMA_voidDMADisable                                                                        */
/*      04- MDMA_voidInerruptEnable                                                                    */
/*      05- MDMA_voiddSetAddress                                                                       */
/*      06- MDMA_voiddClearFlag                                                                        */
/*      07- MDMA_u8GetFlag                                                                             */
/*      08- MDMA_VidSetCallBackChannel1                                                                */
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
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/

#ifndef DMA_INTERFACE_H_
#define DMA_INTERFACE_H_


#if(0)
//DMA Flags
#define DMA_GIF   0
#define DMA_TCIF  1
#define DMA_HTIF  2
#define DMA_TEIF  3
//DMA CHANNELS
#define CHANNEL1  0
#define CHANNEL2  1
#define CHANNEL3  2
#define CHANNEL4  3
#define CHANNEL5  4
#define CHANNEL6  5
#define CHANNEL7  6
//Interrupt Enable
#define DMA_TCIE  1
#define DMA_HTIE  2
#define DMA_TEIE  3
//Enable
#define DMA_ENABLE  0
#define DMA_DISABLE 1
//DMA Configuration
//Direction
#define MEM_TO_MEM   0
#define PREI_TO_MEM  1
#define MEM_TO_PERI  2
//Circular
#define DMA_ENABLE_CIRCULAR  0
#define DMA_DISABLE_CIRCULAR 1
//PIN & MIN
#define PERIPHERAL_INCREMENT_ENABLE  0
#define PERIPHERAL_INCREMENT_DISABLE 1
//MIN
#define MEM_INCREMENT_ENABLE  0
#define MEM_INCREMENT_DISABLE 1
//Size
#define BYTE       0
#define HALF_WORD  1
#define WORD       2
//Channel Priority
#define DMA_LOW         0
#define DMA_MEDIUM      1
#define DMA_HIGH        2
#define DMA_VERY_HIGH   3


void MDMA_VidSetConfiguration( u8 Copy_u8Channel , u8 Copy_u8Direction , u8 Copy_u8DMAMode , u8 Copy_u8PINC ,
		u8 Copy_u8MINC , u8 Copy_MEMSize , u8 Copy_u8PERSize , u8 Copy_u8ChannelPriority );

void MDMA_VidDMAEnable( u8 Copy_u8Channel );

void MDMA_VidDMADisable( u8 Copy_u8Channel );

void MDMA_VidInerruptEnable( u8 Copy_u8Channel , u8 Copy_u8INTSource );

void MDMA_VidSetAddress( u8 Copy_u8Channel , u32 * PeripheralAddress , u32 * MemoryAddress , u16 Copy_u16NDT );

void MDMA_VidClearFlag( u8 Copy_u8Channel , u8 Copy_u8Flag );

u8   MDMA_u8GetFlag( u8 Copy_u8Channel , u8 Copy_u8Flag );

void MDMA_VidSetCallBackChannel1( void ( *Ptr ) ( void ) );

#endif


/* DMA init */
void MDMA_vInit(u8 Copy_u8SreamID );
/* Function to set source and distination */
void MDMA_vSetAddress(u32 *Ptr_u32SrcAdd , u32 *Ptr_u32DistAdd , u32 Copy_u32Size ,u8 Copy_u8SreamID );
/* Func To enable DMA */
void MDMA_vStreamEnable(u8 Copy_u8SreamID );

/*Callback*/

void MDMA_VidSetCallBackChannel1( void ( *Ptr ) ( void ) );

void MDMA_VidClearFlagChannel1 (void) ;


#endif /* DMA_INTERFACE_H_ */
