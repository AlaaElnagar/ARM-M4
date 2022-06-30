/*
 *      Author: Mostafa Diab
 */

#ifndef LIGHT_SENSOR_INT_H_
#define LIGHT_SENSOR_INT_H_



/****************************************************/
/*				LIGHT SENSORS CHANNELS Num			*/
/****************************************************/
#define LIGHT_ROOM_CHANNEL			7		        //
                                                    //
#define LIGHT_KITCHEN_CHANNEL		5               //
                                                    //
#define LIGHT_LIVING_CHANNEL		6           	//
                                                    //
#define LIGHT_HALLWAY_CHANNEL		8               //
                                                    //
#define LIGHT_BATHROOM_CHANNEL		9               //
/****************************************************/
/****************************************************/



void LigtSensor_vInit(void);

void LightSensor_vGetCandela(u8 * Copy_pu8Value, u8 Copy_u8Channel);


#endif
