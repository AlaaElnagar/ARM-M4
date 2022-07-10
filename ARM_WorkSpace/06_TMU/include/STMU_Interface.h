/*
 * STMU_Interface.h
 *
 *  Created on: Jul 10, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef STMU_INTERFACE_H_
#define STMU_INTERFACE_H_





/*Create Task*/
void STMU_voidCreateTask(u8 Copy_TaskID, u16 Copy_u16TaskPeriodicity , void(*Fptr)(void)) ;

/*Start Scheduling*/
void STMU_voidStart(void) ;


#endif /* STMU_INTERFACE_H_ */
