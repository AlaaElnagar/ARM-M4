/*
 * STMU_Program.c
 *
 *  Created on: Jul 10, 2022
 *      Author: Ahmed Khaled Hammad
 */


#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"

#include "MSYSTICK_Interface.h"

#include "STMU_Config.h"
#include "STMU_Private.h"
#include "STMU_Interface.h"


/*Create Task*/
void STMU_voidCreateTask(u8 Copy_TaskID,u16 Copy_u16TaskPeriodicity , void(*Fptr)(void),u16 Copy_u16firstDelay)
{
    Task_Array[Copy_TaskID].Periodicity= Copy_u16TaskPeriodicity ;
    Task_Array[Copy_TaskID].FuncPtr= Fptr ;
    Task_Array[Copy_TaskID].State = TASK_READY ;
    Task_Array[Copy_TaskID].firstDelay =  Copy_u16firstDelay;
}

/*Start Scheduling*/
void STMU_voidStart(void)
{
  /*initialize Systick to determine tick time */
  MSTK_voidInit() ;
  /*set Call Back Function */
  MSTK_voidSetCallBack(Scheduler);
  /*Enable interrupt*/
  MSTK_voidINTStatus(MSTK_INT_EN);
  /*when HSI=16Mhz , system tick is 1ms*/
   MSTK_voidStart(2000) ;
}


void STMU_voidSuspendTask(u8 Copy_u8TaskID)
{
	Task_Array[Copy_u8TaskID].State = TASK_SUSPENDED ;
}

void STMU_voidDeleteTask(u8 Copy_u8TaskID)
{
	Task_Array[Copy_u8TaskID].FuncPtr = NULL ;
}

void STMU_voidResumeTask(u8 Copy_u8TaskID)
{
	Task_Array[Copy_u8TaskID].State = TASK_READY ;
}
/*determine the Task order*/
static void Scheduler(void)
{

	for(u8 i = 0 ; i<NO_OF_TASKS ; i++)
	{
		/*chack that task isn't deleted or suspended */
		if(Task_Array[i].State == TASK_READY && Task_Array[i].FuncPtr != NULL)
		{
			/*Check until the first delay equal to zero*/
			if(Task_Array[i].firstDelay == 0)
			{
				Task_Array[i].firstDelay = Task_Array[i].Periodicity - 1 ;
				/*Invoke the task function*/
				Task_Array[i].FuncPtr() ;
			}
			else
			{
				/*Decrement the first delay*/
				Task_Array[i].firstDelay--;
			}

		}
		else
		{/*Do Nothing*/}
	}
}

