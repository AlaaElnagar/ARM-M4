/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : MUART_Config.c --> Configuration                                                */
/*******************************************************************************************************/



/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/


#ifndef  MUART_CONFIG_H_
#define  MUART_CONFIG_H_ 


#define U_ENABLE                  1
#define U_DISABLE                 0

#define U_EVEN_PARITY             0
#define U_ODD_PARITY              0

#define U_DATA_8                  0
#define U_DATA_9                  1

#define U_OVER_SAMPLING_16        0
#define U_OVER_SAMPLING_8         1

#define STOP_1                    1
#define STOP_05                   2
#define STOP_2                    3


typedef enum{
    B_1200   = 0x44505400,
    B_2400   = 0x43d05800,
    B_9600   = 0x683,
    B_19200  = 0x42504000,
    B_38400  = 0x41d08000,
    B_57600  = 0x418b0000,
    B_115200 = 0x410b0000
}u_BaudRate_t;


/*****     UART 1 configurations        ******/
//if you want to use UART 1 Make this enable otherwise its config values will be discarded
#define UART1_USED             U_ENABLE

#define UART1_SEND_BREAK       U_DISABLE
#define UART1_RECEIVER         U_ENABLE
#define UART1_TRANSMITTER      U_ENABLE

#define UART1_T_COMP_INT       U_DISABLE
#define UART1_RX_INT           U_ENABLE

#define UART1_PARITY_ENABLE    U_DISABLE
#define UART1_PARITY_MODE      U_EVEN_PARITY

#define UART1_WORD_LEN         U_DATA_8

#define UART1_BUAD_RATE        B_9600;

#define UART1_OVER_SAMPLING    U_OVER_SAMPLING_16

#define UART1_STOP_BITS        STOP_1



/*****     UART 2 configurations        ******/
//if you want to use UART 2 Make this enable otherwise its config values will be discarded
#define UART2_USED             U_DISABLE

#define UART2_SEND_BREAK       U_DISABLE
#define UART2_RECEIVER         U_ENABLE
#define UART2_TRANSMITTER      U_ENABLE
#define UART2_T_COMP_INT       U_DISABLE
#define UART2_RX_INT           U_DISABLE
#define UART2_PARITY_ENABLE    U_DISABLE
#define UART2_PARITY_MODE      U_EVEN_PARITY
#define UART2_WORD_LEN         U_DATA_8
#define UART2_BUAD_RATE        B_9600;
#define UART2_OVER_SAMPLING    U_OVER_SAMPLING_16
#define UART2_STOP_BITS        STOP_1



/*****     UART 6 configurations        ******/
//if you want to use UART 6 Make this enable otherwise its config values will be discarded
#define UART6_USED             U_DISABLE

#define UART6_SEND_BREAK       U_DISABLE
#define UART6_RECEIVER         U_ENABLE
#define UART6_TRANSMITTER      U_ENABLE

#define UART6_T_COMP_INT       U_DISABLE
#define UART6_RX_INT           U_ENABLE

#define UART6_PARITY_ENABLE    U_DISABLE
#define UART6_PARITY_MODE      U_EVEN_PARITY

#define UART6_WORD_LEN         U_DATA_8
#define UART6_BUAD_RATE        B_9600;

#define UART6_OVER_SAMPLING    U_OVER_SAMPLING_16

#define UART6_STOP_BITS        STOP_1




#endif
