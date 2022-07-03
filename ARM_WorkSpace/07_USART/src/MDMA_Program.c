/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : MDMA_Program.c --> implementations                                              */
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
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/


#include "MDMA_Interface.h"
#include "MDMA_Private.h"


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      Functions Implementations                                      */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      01- MEXTI_voidInit(void)                                       */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Enable Peripheral Clock                                                  */
/* 2- Function Input       -> Copy_uBusName ,   Copy_u8PerNum                                          */
/*   - BusName_t      : The Bus Of The Prepheral ( AHB1 , AHB2 , APB1 , APB2 ) Every One               */
/*                      Detect Which REG To Choice Pripheral From It                                   */
/*   - Copy_u8PerName :  The Order Of Prepheral On The Selected Reg                                    */
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

#if(0)

void MDMA_voidSetConfiguration( u8 Copy_u8Channel , u8 Copy_u8Direction , u8 Copy_u8DMAMode , u8 Copy_u8PINC ,
		u8 Copy_u8MINC , u8 Copy_MEMSize , u8 Copy_u8PERSize , u8 Copy_u8ChannelPriority ){

	//Disable DMA

	CLR_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 0 );
	// Wait Until DMA Disable
	while( GET_BIT(  MDMA->CHANNEL[ Copy_u8Channel ].CR , 0 ) == 1 );

	///////////////////////Direction/////////////////////////////////////
	if( Copy_u8Direction == MEM_TO_MEM ){

		SET_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 14 );

	}else if ( Copy_u8Direction == PREI_TO_MEM ){

		CLR_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 4  );

	}else if( Copy_u8Direction == MEM_TO_PERI ){

		SET_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 4  );

	}
	/////////////////////////////DMA MODE//////////////////////////////////
	if( Copy_u8DMAMode == DMA_ENABLE_CIRCULAR ){

		SET_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 5  );

	}else if( Copy_u8DMAMode == DMA_DISABLE_CIRCULAR ){

		CLR_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 5  );

	}
	//////////////////////////// PINC ////////////////////////////////////
	if( Copy_u8PINC == PERIPHERAL_INCREMENT_ENABLE ){

		SET_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 6  );

	}else if ( Copy_u8PINC == PERIPHERAL_INCREMENT_DISABLE ){

		CLR_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 6  );

	}
	/////////////////////////// MINC //////////////////////////////
	if( Copy_u8MINC == MEM_INCREMENT_ENABLE ){

		SET_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 7  );

	}else if ( Copy_u8MINC == MEM_INCREMENT_DISABLE ){

		CLR_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 7  );

	}
	////////////////////////// MEMORY SIZE //////////////////////////////
	if( Copy_MEMSize == BYTE ){

		CLR_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 10 );
		CLR_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 11 );

	}else if( Copy_MEMSize == HALF_WORD  ){

		SET_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 10 );
		CLR_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 11 );

	}else if ( Copy_MEMSize == WORD ){

		CLR_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 10 );
		SET_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 11 );

	}
	//////////////////////// PERIPHERAL SIZE //////////////////////
	if( Copy_u8PERSize == BYTE ){

		CLR_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 8 );
		CLR_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 9 );

	}else if( Copy_u8PERSize == HALF_WORD  ){

		SET_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 8 );
		CLR_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 9 );

	}else if ( Copy_u8PERSize == WORD ){

		CLR_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 8 );
		SET_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 9 );

	}
	//////////////////////// CHANNEL PRIORITY ///////////////////////////
	if( Copy_u8ChannelPriority == DMA_LOW ){

		CLR_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 12 );
		CLR_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 13 );

	}else if( Copy_u8ChannelPriority == DMA_MEDIUM ){

		SET_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 12 );
		CLR_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 13 );

	}else if( Copy_u8ChannelPriority == DMA_HIGH ){

		CLR_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 12 );
		SET_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 13 );

	}else if( Copy_u8ChannelPriority == DMA_VERY_HIGH ){

		SET_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 12 );
		SET_BIT( MDMA_2->CHANNEL[ Copy_u8Channel ].CR , 13 );

	}

}


void MDMA_VidDMAEnable( u8 Copy_u8Channel ){

	MDMA_VidClearFlag( Copy_u8Channel , DMA_GIF  );
	MDMA_VidClearFlag( Copy_u8Channel , DMA_TCIF );
	MDMA_VidClearFlag( Copy_u8Channel , DMA_HTIF );
	MDMA_VidClearFlag( Copy_u8Channel , DMA_TEIF );

	SET_BIT( MDMA->CHANNEL[ Copy_u8Channel ].CCR , DMA_ENABLE );

}

void MDMA_VidDMADisable( u8 Copy_u8Channel ){

	CLR_BIT( MDMA->CHANNEL[ Copy_u8Channel ].CCR , 0 );

}

void MDMA_VidInerruptEnable( u8 Copy_u8Channel , u8 Copy_u8INTSource ){

	SET_BIT( MDMA->CHANNEL[ Copy_u8Channel ].CCR , Copy_u8INTSource );

}

void MDMA_VidSetAddress( u8 Copy_u8Channel , u32 * PeripheralAddress , u32 * MemoryAddress , u16 Copy_u16NDT ){

	MDMA->CHANNEL[ Copy_u8Channel ].CPAR  = (u32)PeripheralAddress ;
	MDMA->CHANNEL[ Copy_u8Channel ].CMAR  = (u32)MemoryAddress ;
	MDMA->CHANNEL[ Copy_u8Channel ].CNDTR =  Copy_u16NDT ;

}


void MDMA_VidClearFlag( u8 Copy_u8Channel , u8 Copy_u8Flag ){

	Copy_u8Channel *= 4 ;

	SET_BIT( MDMA->IFCR , (Copy_u8Channel + Copy_u8Flag) );

}


u8 MDMA_u8GetFlag( u8 Copy_u8Channel , u8 Copy_u8Flag ){

	u8 LOC_u8Result = 0;

	Copy_u8Channel *= 4 ;

	LOC_u8Result = GET_BIT( MDMA->ISR , ( Copy_u8Channel + Copy_u8Flag ) );

	return LOC_u8Result ;

}

/*----------------------------------------------------------------------------------------------------------*/
void MDMA_VidSetCallBackChannel1( void ( *Ptr ) ( void ) ){

	DMA_CallBackChannel1 = Ptr ;

}

void DMA1_Channel1_IRQHandler(void){

	DMA_CallBackChannel1();

}


#endif

void ( *DMA_CallBackChannel1 )( void ) = NULL;

void MDMA_vInit(u8 Copy_u8SreamID )
{
	/* 1- Before Any Config The Bit Of EN Must = 0 ,It must Be Disable*/
	/* Use Stream NUM = 0 */
	/* If Enable Bit == 1 */
	if((MDMA_2->CHANNEL[Copy_u8SreamID].CR) == 1 )
	{
		/* Disable It*/
		(MDMA_2->CHANNEL[Copy_u8SreamID].CR) &=~(1U<<0);
		/*It Take Time To Be Disable So Wait Time */
		while((MDMA_2->CHANNEL[Copy_u8SreamID].CR) == 1){}

	}
	else {/* Not used Misra*/}

	/* 2- Select The Channel(Used For Conect Peripheral To Memory) In stream  But From Mermoery To Memory Not Use*/

	/* 3-SoftWare Priority Stream :{ LOW , Medium , High , VeryHigh} BIT(16 , 17)---> VeryHigh  */
	(MDMA_2->CHANNEL[Copy_u8SreamID]).CR|= ((1U<<16)| (1U<<17)) ;

	/* 4- Set DIR Mode :{ (MTM) ,PTM ,MTP} BIT (6,7)  -->MTM */
	(MDMA_2->CHANNEL[Copy_u8SreamID].CR)|= (1U<<7);
	(MDMA_2->CHANNEL[Copy_u8SreamID].CR)&=~(1U<<6);
	// Select Circular mode
	(MDMA_2->CHANNEL[Copy_u8SreamID].CR)|=(1U<<8);

	/* 5- Set M & M SIZE BIT(13,14) ,(11,12) :{Byte , HaveWord , (Word)}*/
	/* 	As Word 32 For Source	*/
	(MDMA_2->CHANNEL[Copy_u8SreamID].CR)|= (1U<<12);
	(MDMA_2->CHANNEL[Copy_u8SreamID].CR)&=~(1U<<11);
	/* 	As Word 32 For Distination	*/
	(MDMA_2->CHANNEL[Copy_u8SreamID].CR)|= (1U<<14);
	(MDMA_2->CHANNEL[Copy_u8SreamID].CR)&=~(1U<<13);

	/*INCR4 (incremental burst of 4 beats) for Source*/
//	(MDMA_2->CHANNEL[Copy_u8SreamID].CR)|= (1U<<20);
//	(MDMA_2->CHANNEL[Copy_u8SreamID].CR)&=~(1U<<21);
//
//	/*INCR4 (incremental burst of 4 beats) For Dist*/
//	(MDMA_2->CHANNEL[Copy_u8SreamID].CR)|= (1U<<23);
//	(MDMA_2->CHANNEL[Copy_u8SreamID].CR)&=~(1U<<24);

	/* 6- Disable Direct Mode to used fifo  */
	(MDMA_2->CHANNEL[Copy_u8SreamID].FCR)|=(1U<<2);

	/* 7-Set FIFO Threshold {(1/4),(1/2),(3/4),full} */
	/* Use (Full)*/
	MDMA_2->CHANNEL[Copy_u8SreamID].FCR|=(1U<<0);
	MDMA_2->CHANNEL[Copy_u8SreamID].FCR&=~(1U<<1);
	/* 8-SRC & DIS Increament For Both */
	MDMA_2->CHANNEL[Copy_u8SreamID].CR|=(1U<<9);
	MDMA_2->CHANNEL[Copy_u8SreamID].CR|=(1U<<10);
	/* 9- EN Interrput Of Transfer Complete */
	MDMA_2->CHANNEL[Copy_u8SreamID].CR|=(1U<<4);

}

void MDMA_vSetAddress(u32 *Ptr_u32SrcAdd , u32 *Ptr_u32DistAdd , u32 Copy_u32Size ,u8 Copy_u8SreamID )
{

	MDMA_2->CHANNEL[Copy_u8SreamID].PAR= (u32)Ptr_u32SrcAdd;
	MDMA_2->CHANNEL[Copy_u8SreamID].M0AR=(u32)Ptr_u32DistAdd;
	MDMA_2->CHANNEL[Copy_u8SreamID].NDTR=Copy_u32Size;

}

void MDMA_vStreamEnable(u8 Copy_u8SreamID )
{
	/* All Flag == 0 or make them =0 */
	(MDMA_2->LIFCR)|=((1U<<0)|(1U<<2)|(1U<<3)|(1U<<4)|(1U<<5));

	//(MDMA_2->CHANNEL[Copy_u8SreamID].CR)|= (1U<<0);
	SET_BIT( MDMA_2->CHANNEL[ Copy_u8SreamID ].CR , 0 );
}

void MDMA_VidSetCallBackChannel1( void ( *Ptr ) ( void ) ){

	DMA_CallBackChannel1 = Ptr ;

}


/*This ISR Is Called By Any Flag The 5 Flag From  DMA*/
void MDMA_VidClearFlagChannel1 (void)
{
	/* Must Clear The Flag Trasfer = 5  */
	(MDMA_2->LIFCR)|=((1U<<0)|(1U<<2)|(1U<<3)|(1U<<4)|(1U<<5));
}

void DMA2_Stream0_IRQHandler(void){

	DMA_CallBackChannel1();

}


