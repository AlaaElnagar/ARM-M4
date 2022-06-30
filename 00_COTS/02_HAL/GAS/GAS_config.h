/*
 * gas
 *
 * 
 *  Author: ahmed salah elewa
 */ 


#ifndef GAS_CONFIG_H_
#define GAS_CONFIG_H_


/* select number of pirs */

#define NUM_GAS_USED	  3


typedef struct  {
	u8 GAS_PORT;
	u8 GAS_PIN;
} GAS_t ;

GAS_t GAS_NUM[NUM_GAS_USED] ;


#endif /* gas_CFG_H_ */
