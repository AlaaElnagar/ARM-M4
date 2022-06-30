/*
 * gas
 *
 * 
 *  Author: ahmed salah elewa
 */ 


#ifndef GAS_INTERFACE_H_
#define GAS_INTERFACE_H_

#include "LIB/STD_TYPES.h"
#include "MCAL/GPIO/GPIO_interface.h"


/* put names of pir according to number of pirs (NUM_PIRS_USED) in  pir_config.h    */

enum e_gas{ Gas_Sensor };

void GAS_INIT(enum e_gas gas,u8,u8);
u8   GAS_READ(enum e_gas gas);



#endif /* gas_H_ */
