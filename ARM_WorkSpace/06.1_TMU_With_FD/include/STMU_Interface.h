/*
 * STMU_Interface.h
 *
 *  Created on: Jul 10, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef STMU_INTERFACE_H_
#define STMU_INTERFACE_H_





/*Create Task*/
void STMU_voidCreateTask(u8 Copy_TaskID,u16 Copy_u16TaskPeriodicity , void(*Fptr)(void),u16  Copy_u16firstDelay) ;

/*Start Scheduling*/
void STMU_voidStart(void) ;

void STMU_voidSuspendTask(u8 Copy_u8TaskID);


void STMU_voidDeleteTask(u8 Copy_u8TaskID);


void STMU_voidResumeTask(u8 Copy_u8TaskID);


#endif /* STMU_INTERFACE_H_ */
