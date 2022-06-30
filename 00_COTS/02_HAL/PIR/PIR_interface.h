/*
 * PIR
 *
 * 
 *  Author: ahmed salah elewa
 */ 


#ifndef PIR_INTERFACE_H_
#define PIR_INTERFACE_H_

#include "LIB/STD_TYPES.h"
#include "MCAL/GPIO/GPIO_interface.h"


/* put names of pir according to number of pirs (NUM_PIRS_USED) in  pir_config.h    */

enum e_pir{
	Room_Motion ,
	Living_Motion,
	Kitchen_Motion,
	Bathroom_Motion,
	Hallway_Motion
};

void PIR_INIT(enum e_pir pir, u8 _PORT ,u8 _PIN);
u8   PIR_READ(enum e_pir pir);



#endif /* pir_H_ */
