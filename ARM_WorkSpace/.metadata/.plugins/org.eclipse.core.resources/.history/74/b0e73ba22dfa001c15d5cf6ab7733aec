/***************************************************************************************/
/****************************  IMT School Training Center ******************************/
/***************************************************************************************/
/** This file is developed by IMT School training center, All copyrights are reserved **/
/***************************************************************************************/

#ifndef DMA_REG_H_
#define DMA_REG_H_

typedef struct{

	volatile u32 CCR       ;//0x000
	volatile u32 CNDTR     ;//0x004
	volatile u32 CPAR      ;//0x008
	volatile u32 CMAR      ;//0x00C
	volatile u32 RESERVED  ;//0x010

}DMACHANNEL;

typedef struct{

	volatile u32 ISR  ;//0x000
	volatile u32 IFCR ;//0x004
	DMACHANNEL CHANNEL[7];//0x008

}DMA;

#define MDMA ( ( volatile DMA * ) 0x40020000 )


#endif /* DMA_REG_H_ */
