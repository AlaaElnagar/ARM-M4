/*
 * RELAY
 *
 * 
 *  Author: ahmed salah elewa
 */ 


#ifndef RELAY_INTERFACE_H_
#define RELAY_INTERFACE_H_

#include "LIB/STD_TYPES.h"
#include "MCAL/GPIO/GPIO_interface.h"


/* put names of relays according to number of relays (NUM_RELAYS_USED) in  relay_config.h    */

enum e_relay{
	LoginSystem_Buzzer ,
	Alarm,
};

void Relay_vInit(enum e_relay relay, u8 _PORT , u8 _PIN);
void Relay_vOn(enum e_relay relay);
void Relay_vOff(enum e_relay relay);
void Relay_vTog(enum e_relay relay);

#endif /* relay_H_ */
