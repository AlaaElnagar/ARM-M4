/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : MUSART_Enum.h --> implementations                                            */
/* Features          : Register Definitions                                                            */
/*******************************************************************************************************/



/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/


#ifndef   _MUSART_ENUM_H_
#define   _MUSART_ENUM_H_

#define U_ENABLE     1
#define U_DISABLE    0

#define U_EVEN_PARITY    0
#define U_ODD_PARITY     0

#define U_DATA_8      0
#define U_DATA_9      1

#define U_OVER_SAMPLING_16    0
#define U_OVER_SAMPLING_8     1

#define STOP_1      1
#define STOP_05     2
#define STOP_2      3


typedef enum{
    B_1200   = 0x44505400,
    B_2400   = 0x43d05800,
    B_9600   = 0x683,
    B_19200  = 0x42504000,
    B_38400  = 0x41d08000,
    B_57600  = 0x418b0000,
    B_115200 = 0x410b0000
}u_BaudRate_t;

#endif
