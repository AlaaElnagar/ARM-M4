/*
 * PIR
 *
 * 
 *  Author: ahmed salah elewa
 */ 


#ifndef PIR_CONFIG_H_
#define PIR_CONFIG_H_


/* select number of pirs */

#define NUM_PIRS_USED	  5


typedef struct  {
	u8 PIR_PORT;
	u8 PIR_PIN;
} PIR_t ;

PIR_t PIR_NUM[NUM_PIRS_USED] ;


#endif /* pir_CFG_H_ */
