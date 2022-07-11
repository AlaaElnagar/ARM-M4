/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : MGPIO_Interface.c --> implementations                                           */
/* Module  Features  :                                                                                 */
/*      01- MGPIO_voidSetPinMode                                                                       */
/*      02- MGPIO_voidSetPinOutPutType                                                                 */
/*      03- MGPIO_voidSetPinOutSpeed                                                                   */
/*      04- MGPIO_voidSetPullType                                                                      */
/*      05- MGPIO_u8ReadData                                                                           */
/*      06- MGPIO_voidWriteData                                                                        */
/*      07- MGPIO_voidPinLock                                                                          */
/*      08- MGPIO_voidDirectSetReset                                                                   */
/*      09- MGPIO_voidSetPinAltFn                                                                      */
/*******************************************************************************************************/

/*******************************************************************************************************/	
/*	* What i sell To Customer                                                                          */
/*		*  The Archictect Give The API	                                                               */
/*						- The Name Of Function                                                         */
/*						- What is The Input                                                            */
/*						- What Is The Output                                                           */
/*						- Macro                                                                        */
/*******************************************************************************************************/

/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/

#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H


/*******************************************************************************************************/
/*                                      Standard Types LIB                                             */
/*******************************************************************************************************/

#include "LSTD_TYPES.h"
#include "LERROR_STATES.h"
#include "LBIT_MATH.h"


/*#####################################################################################################*/
/*#####################################################################################################*/

/*******************************************************************************************************/
/*                                      MCAL Components                                                */
/*******************************************************************************************************/

#include "MGPIO_private.h"
#include "MGPIO_config.h"

/*******************************************************************************************************/
/*                                      Macros Of Port                                                 */
/*******************************************************************************************************/

#define _GPIOA_PORT   		   0U
#define _GPIOB_PORT   		   1U
#define _GPIOC_PORT   		   2U
#define _GPIOD_PORT   		   3U
#define _GPIOE_PORT   		   4U
#define _GPIOH_PORT   		   5U

/*******************************************************************************************************/
/*                                      Macros Of Pins                                                 */
/*******************************************************************************************************/

#define _PIN_0        		   0U 
#define _PIN_1        		   1U 
#define _PIN_2        		   2U 
#define _PIN_3        		   3U 
#define _PIN_4        		   4U 
#define _PIN_5        		   5U
#define _PIN_6        		   6U
#define _PIN_7        		   7U
#define _PIN_8        		   8U
#define _PIN_9        		   9U
#define _PIN_10       		   10U
#define _PIN_11       		   11U
#define _PIN_12       		   12U
#define _PIN_13       		   13U
#define _PIN_14       		   14U
#define _PIN_15       		   15U

/*******************************************************************************************************/
/*                                      Macros Of Mode                                                 */
/*******************************************************************************************************/

#define _MODE_INPUT      	 (0b00)
#define _MODE_OUTPUT     	 (0b01)
#define _MODE_ALTF       	 (0b10)
#define _MODE_ANALOG     	 (0b11)

/*******************************************************************************************************/
/*                                      Macros Of Type                                                 */
/*******************************************************************************************************/

#define _OUTPUT_TYPE_PUSH_PULL    0U
#define _OUTPUT_TYPE_OPEN_DRAIN   1U

/*******************************************************************************************************/
/*                                      Macros Of Speed                                                 */
/*******************************************************************************************************/

#define _OUTPUT_SPEED_LOW       (0b00)
#define _OUTPUT_SPEED_MEDUIM    (0b01)
#define _OUTPUT_SPEED_HIGH      (0b10)
#define _OUTPUT_SPEED_VERY_HIGH (0b11)

/*******************************************************************************************************/
/*                                      Macros Of PULL                                                 */
/*******************************************************************************************************/

#define _PULL_OFF              (0b00)
#define _PULL_UP               (0b01)
#define _PULL_DOWN             (0b10)
/*******************************************************************************************************/
/*                                      Macros Write Data                                              */
/*******************************************************************************************************/


#define _HIGH                     	1U
#define _LOW	                 	0U

/*******************************************************************************************************/
/*                                      Macros ALTF                                                    */
/*******************************************************************************************************/

#define _ALTFN_0           0b0000
#define _ALTFN_1           0b0001
#define _ALTFN_2           0b0010
#define _ALTFN_3           0b0011
#define _ALTFN_4           0b0100
#define _ALTFN_5           0b0101
#define _ALTFN_6           0b0110
#define _ALTFN_7           0b0111
#define _ALTFN_8           0b1000
#define _ALTFN_9           0b1001
#define _ALTFN_10          0b1010
#define _ALTFN_11          0b1011
#define _ALTFN_12          0b1100
#define _ALTFN_13          0b1101
#define _ALTFN_14          0b1110
#define _ALTFN_15          0b1111

/*******************************************************************************************************/
/*                                      Macros Of PIN_State                                            */
/*******************************************************************************************************/

#define LOW						0U
#define HIGH					1U

/*#####################################################################################################*/
/*                                      Function Prototypes                                            */
/*#####################################################################################################*/



/*******************************************************************************************************/
/*                                      01- MGPIO_voidSetPinMode                                       */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Function Set The Mode Of Pin Mode Take 2Bits                             */
/*                                                                                                     */
/*      1- MODE_INPUT                                                                                  */
/*      2- MODE_OUTPUT                                                                                 */
/*      3- MODE_ALTF                                                                                   */
/*      4- MODE_ANALOG                                                                                 */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum ,   Copy_u8Mod                         */                   
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MGPIO_voidSetPinMode(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8Mode  );

/*******************************************************************************************************/
/*                                      02- MGPIO_voidSetPinOutPutType                                 */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Set The Type Of OutPut (OpenDrain = 0 , PushPull = 1)                    */
/*                                                                                                     */
/*       - OUTPUT_TYPE_PUSH_PULL                                                                       */
/*       - OUTPUT_TYPE_OPEN_DRAIN	                                                                   */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum ,   Copy_u8OutPutType                  */                   
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MGPIO_voidSetPinOutPutType(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8OutPutType  );

/*******************************************************************************************************/
/*                                      03- MGPIO_voidSetPinOutSpeed                                   */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Set The Speed (LOW , Meduim , High ,VeryHaigh):                          */
/*                             - OUTPUT_SPEED_LOW                                                      */
/*                             - OUTPUT_SPEED_MEDUIM                                                   */
/*                             - OUTPUT_SPEED_HIGH                                                     */    
/*                             - OUTPUT_SPEED_VERY_HIGH	                                               */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum ,   Copy_u8OutSpeed                    */                   
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MGPIO_voidSetPinOutSpeed(u8 Copy_u8PortName ,u32 Copy_u8PinNum ,u32 Copy_u8OutSpeed );

/*******************************************************************************************************/
/*                                      04- MGPIO_voidSetPullType                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Set The PULL Resistor Connection State                                   */
/*                              - PULL_OFF                                                             */
/*                              - PULL_UP                                                              */
/*                              - PULL_DOWN                                                            */    
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum ,   Copy_u8PullType                    */                   
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MGPIO_voidSetPullType(u8 Copy_u8PortName ,u32 Copy_u8PinNum ,u32 Copy_u8PullType );

/*******************************************************************************************************/
/*                                      05- MGPIO_u8ReadData                                           */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Read Data From IDR                                                       */  
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum                                        */                   
/* 3- Function Return      -> LOC_u8ReturnValue                                                        */
/*******************************************************************************************************/

u8 MGPIO_u8ReadData(u8 Copy_u8PORT ,u8 Copy_u8PIN);


/*******************************************************************************************************/
/*                                      06- MGPIO_voidWriteData                                        */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> Write Data At ODR	Value :                                                */
/*                               - HIGH                                                                */
/*                               - LOW	                                                               */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum ,   Copy_u8State                       */                   
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MGPIO_voidWriteData(u8 Copy_u8PortName ,u8 Copy_u8PinNum ,u8 Copy_u8State);

/*******************************************************************************************************/
/*                                      07- MGPIO_voidPinLock                                          */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> to Lock pin :                                                            */
/*                               1)Set Pin                                                             */
/*                               2)Set Pin 16                                                          */
/*                               3)Wait bit 16 =high                                                   */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum                                        */                   
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MGPIO_voidPinLock(u8 Copy_u8PortNum ,u8 Copy_u8PinNum );

/*******************************************************************************************************/
/*                                      08- MGPIO_voidDirectSetReset                                   */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> to Set pin Direction :                                                   */
/*                               1)Set Pin                                                             */
/*                               2)ReSet Pin                                                           */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum  ,Copy_u8State                         */                   
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/
void MGPIO_vDirectSetReset(u8 Copy_u8PortName , u8 Copy_u8PinNum, u8 Copy_u8State);

/*******************************************************************************************************/
/*                                      09- MGPIO_voidSetPinAltFn                                      */
/*-----------------------------------------------------------------------------------------------------*/
/* 1- Function Description -> to Set pin Altarnate :                                                   */
/* 2- Function Input       -> Copy_u8PortName ,   Copy_u8PinNum  ,Copy_u8ALF                           */                   
/* 3- Function Return      -> No Thing                                                                 */
/*******************************************************************************************************/

void MGPIO_voidSetPinAltFn( u8 Copy_u8PortNum ,u8 Copy_u8PinNum, u8 Copy_u8ALF );

#endif //_GPIO_INTERFACE_H

