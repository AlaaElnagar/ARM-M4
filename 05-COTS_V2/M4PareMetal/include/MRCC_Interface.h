/*
 * MRCC_Interface.h
 *
 *  Created on: Jul 1, 2022
 *      Author: AlaaElnagar
 */

#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_

enum SysBuses {

	AHB1_bus ,
	AHB2_bus ,
	APB1_bus ,
	APB2_bus

};




void MRCC_voidInitSysClock(void);


void MRCC_voidEnablePerClock( u8 Copy_u8BusId , u8 Copy_u8PerId );

void MRCC_voidDisablePerClock( u8 Copy_u8BusId , u8 Copy_u8PerId );


#endif /* MRCC_INTERFACE_H_ */
