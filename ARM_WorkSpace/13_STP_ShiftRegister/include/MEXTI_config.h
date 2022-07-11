/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : MEXTI_Config.c --> Configuration                                                */
/*******************************************************************************************************/

/*#####################################################################################################*/
/*                       File Which Devlopper Can Choise From it To Config=Init                        */
/*#####################################################################################################*/


/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/

#ifndef EXIT_CONFIG_H
#define EXIT_CONFIG_H

/* 
Option Of EXTI_Line :
		- EXTI_LINE0
		- EXTI_LINE1
		- .
		- .
		- .
		- .
		- .
		- .
		- EXTI_LINE14
		- EXTI_LINE15
*/
	#define EXTI_Line				    LINE_0     

/* 
Option Of EXIT_Sense_Mode :
		
		- Rising_Edage			
		- Falling_Edage			    
		- ON_Change			
*/
	#define EXIT_Sense_Mode				Rising		
	

#endif //EXIT_CONFIG_H	