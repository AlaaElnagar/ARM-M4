/*
 * Motor_Config.h
 *
 *  Created on: Mar 24, 2022
 *      Author: Islam Adel
 */

#ifndef MOTOR_DRIVER_MOTOR_CONFIG_H_
#define MOTOR_DRIVER_MOTOR_CONFIG_H_

#define MOTOR_NUM		3
#define FAN_NUM			5
#define LIMITSWITCH_NUM MOTOR_NUM


typedef struct
{
	u8 Terminal1_GROUP;
	u8 Terminal1_PIN;

	u8 Terminal2_GROUP;
	u8 Terminal2_PIN;
}Motor_t;

typedef struct
{
	u8 Relay_Group;
	u8 Relay_PIN;
}Fan_t;

typedef struct
{
	u8 MotorEnd1_GROUP;
	u8 MotorEnd1_PIN;

	u8 MotorEnd2_GROUP;
	u8 MotorEnd2_PIN;

}LimitSwitch_t;

#endif /* MOTOR_DRIVER_MOTOR_CONFIG_H_ */
