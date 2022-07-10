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

  u16   Periodicity         ;
  void (*FuncPtr)(void)   ;

}Task_t;


Task_t  Task_Array[NO_OF_TASKS] = {NULL} ;

static void  Scheduler(void) ;


#endif /* STMU_PRIVATE_H_ */
