/*
 * Motor_Interface.h
 *
 *  Created on: Mar 24, 2022
 *      Author: Islam Adel
 */

#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

#define 	MOTOR_RIGHT				0U
#define 	MOTOR_LEFT				1U

/*****************************  MOTOR  ****************************************/

/* Function to Initiate all motor's Pinouts as an output */
void HMotor_vInit(void);

/* Function to Rotate the motor in a certain direction */
void HMotor_vRotateMotor(u8 Copy_u8MotorNumber, u8 Copy_u8MotorDirection);

/* Function to Stop Rotating the motor */
void HMotor_vStopMotor(u8 Copy_u8MotorNumber);

/******************************************************************************/

/**************************  MOTOR as a FAN  **********************************/
/* Function to Initiate all Fan's Pinouts */
void HMotor_vFanInit(void);

/* Function to Start the fan */
void HMotor_vFanStart(u8 Copy_u8FanNumber);

/* Function to Stop the fan */
void HMotor_vFanStop(u8 Copy_u8FanNumber);

/******************************************************************************/

/**************************  WINDOW  **********************************/
void HWindow_OpenWindow(u8 Copy_u8WindowNumber);
void HWindow_CloseWindow(u8 Copy_u8WindowNumber);
/**********************************************************************/

/**************************  Door  **********************************/
void HDoor_OpenDoor(u8 Copy_u8DoorNumber);
void HDoor_CloseDoor(u8 Copy_u8DoorNumber);
/**********************************************************************/

/**************************  Safety  **********************************/
void HMotor_SafetyOpen(void);
/**********************************************************************/

#endif /* MOTOR_INTERFACE_H_ */
