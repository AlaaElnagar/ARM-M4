/*
 * STMU_Private.h
 *
 *  Created on: Jul 10, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef STMU_PRIVATE_H_
#define STMU_PRIVATE_H_



typedef struct
{

	u16 Periodicity         ;
	void (*FuncPtr)(void)   ;
	u16	firstDelay;
	u8 State;
}Task_t;

#define			TASK_SUSPENDED			1

#define			TASK_READY				2


Task_t  Task_Array[NO_OF_TASKS] =  { NULL } ;

static void  Scheduler(void) ;


#endif /* STMU_PRIVATE_H_ */
