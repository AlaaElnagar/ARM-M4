/*
 * MQTT.h
 *
 *  Created on: Mar 28, 2022
 *      Author: Ahmed Khaled Hammad
 */

/*Customized Data Type */
/*======   INCLUDE LIB   ===========*/
#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
/*===========  INCLUDE MCAL  ===========*/
#include"MCAL/GPIO/GPIO_interface.h"
#include"MCAL/USART/UART_interface.h"


#include "Service/MQTT.h"
#include "string.h"

volatile u16 packetID 	= 1;  // incremented at subscribe and publish(QoS>0) packets
u8 packet[200] = {0};
u8 packetInd 	= 0;
const char protocolName[] = "MQTT";
/*************************************************************************************************************/
/*                                          1)  MQTT_Connect                                                 */
/*************************************************************************************************************/
/* Steps:
0x10         : Type->connect
0xnn         : RemLen = 6+ 1+ 1 + 2 +(2+strlen(clientID)
utf"MQTT"    : Protocal Name
0x04         : protocal Level
0x02         : flags (clean session)
0xFF         : Keep-alive time
0xFF
utf id       : client ID*/

void MQTT_Connect(u8* clientID){
	u8 remLen = ( 12 + strlen(clientID));
	// Encode packet in Buffer
	packetInd = 0;
	packet[packetInd++] = 0x10;
	packet[packetInd++] = remLen;
	packet[packetInd++] = 0x00;
	packet[packetInd++] = strlen(protocolName);
	strcpy(packet+packetInd,protocolName);
	packetInd += strlen(protocolName);

	packet[packetInd++] = 0x04;
	packet[packetInd++] = 0x02;
	packet[packetInd++] = 0xFF;
	packet[packetInd++] = 0xFF;
	packet[packetInd++] = 0x00;
	packet[packetInd++] = strlen(clientID);
	strcpy(packet+packetInd,clientID);
	packetInd += strlen(clientID);

	// send packet
	MUART_u8SendData(6,packet,packetInd);
}
/*************************************************************************************************************/
/*                                          2)  MQTT_Publish                                                 */
/*************************************************************************************************************/
/* Steps:
0x30/0x32     :type of Qos0 / Qos1
0xnn          :RemLen = (2+strlen(topic))+(2 if Qos>0) +MSG Length
utf topic name:topic name
0xnn          :Packet identifer
0xnn
Message       :Message   */
void MQTT_Publish(u8* topic, u8* msg, u32 len, u8 QoS){
	u8 msgInd = 0;
	u8 remLen = (2 + strlen(topic) + len );
	// Encode packet in Buffer
	packetInd = 0;
	if(QoS > 0){
		remLen += 2;
		packet[packetInd++] = 0x32;
	}else{
		packet[packetInd++] = 0x30;
	}
	packet[packetInd++] = remLen;
	packet[packetInd++] = 0x00;
	packet[packetInd++] = strlen(topic);
	strcpy(packet+packetInd,topic);
	packetInd += strlen(topic);

	if(QoS > 0){
		packet[packetInd++] = (u8)(packetID >> 8);
		packet[packetInd++] = (u8)(packetID);
		packetID++;
	}
	for(msgInd = 0; msgInd < len; msgInd++){
		packet[packetInd++] = msg[msgInd];
	}

	// send packet
	MUART_u8SendData(6,packet,packetInd);
}
/*************************************************************************************************************/
/*                                          3)  MQTT_Subscribe                                                 */
/*************************************************************************************************************/
/* Steps:
0x82     	  :type
0xnn          :RemLen = 2 + (2 + strlen(topic)) +1
0xnn          :Packet identifer
0xnn
utf topic name:topic name
0x01          :Req Qos <=1  */
void MQTT_Subscribe(u8* topic){
	u8 remLen = (5 + strlen(topic));
	// encode packet
	packetInd = 0;
	packet[packetInd++] = 0x82;
	packet[packetInd++] = remLen;

	packet[packetInd++] = (u8)(packetID >> 8);
	packet[packetInd++] = (u8)(packetID);
	packetID++;

	packet[packetInd++] = 0x00;
	packet[packetInd++] = strlen(topic);
	strcpy(packet+packetInd,topic);
	packetInd += strlen(topic);

	packet[packetInd++] = 0x01;
	// send packet
	MUART_u8SendData(6,packet,packetInd);
}
/*************************************************************************************************************/
/*                                          4)  MQTT_PingReq                                                 */
/*************************************************************************************************************/
/* Steps:
 0xC0 : type
 0x00 :RemLen  */
void MQTT_PingReq(void)
{
	packetInd = 0 ;
	packet[packetInd++] = 0xC0 ;
	packet[packetInd++] = 0x00 ;
	// send packet
	MUART_u8SendData(6,packet,packetInd);
}

