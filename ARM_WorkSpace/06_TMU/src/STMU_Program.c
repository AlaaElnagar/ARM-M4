/*
 * STMU_Program.c
 *
 *  Created on: Jul 10, 2022
 *      Author: Ahmed Khaled Hammad
 */


#include "LSTD_TYPES.h"
#include "LBIT_MATH.h"


#include "STMU_Config.h"
#include "STMU_Interface.h"
#include "STMU_Private.h"

#include "MSYSTICK_Interface.h"



/*Create Task*/
void STMU_voidCreateTask(u8 Copy_TaskID,u16 Copy_u16TaskPeriodicity , void(*Fptr)(void))
{
    Task_Array[Copy_TaskID].Periodicity= Copy_u16TaskPeriodicity ;
    Task_Array[Copy_TaskID].FuncPtr= Fptr ;

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

/*determine the Task order*/
static void Scheduler(void)
{
    static u32 TickCounts = 0 ;
	for(u8 i = 0 ; i<NO_OF_TASKS ; i++)
	{
		if(TickCounts % Task_Array[i].Periodicity == 0 && Task_Array[i].FuncPtr != NULL)
		{
			Task_Array[i].FuncPtr() ;
		}
	}
	TickCounts++ ;
}
