/****************************************************/
/*Author      : Alaa Elnaggar						*/
/*Date        : 25Apr2022							*/
/*Verssion    : V1.0								*/
/****************************************************/

/*GPIO PORTS*/
#define GPIOA   0 
#define GPIOB   1
#define GPIOC   2
/*GPIO PINS */
#defin  PIN0 	0 
#defin  PIN1 	1 
#defin  PIN2 	2 
#defin  PIN3 	3 
#defin  PIN4 	4 
#defin  PIN5 	5 
#defin  PIN6 	6 
#defin  PIN7 	7 
#defin  PIN8 	8 
#defin  PIN9 	9 
#defin  PIN10 	10
#defin  PIN11 	11
#defin  PIN12 	12
#defin  PIN13 	13
#defin  PIN14 	14
#defin  PIN15 	15
#defin  PIN11 	11


#define GPIO_HIGH   1 
#define GPIO_LOW    0 

		/*GPIO Moods 55:59*/
		/*INPUT*/
#define INPUT_ANALOG                0b0000
#define INPUT_FLOATING              0b0100
#define	OUTPUT_PULL_UP              0b1000
#define	OUTPUT_PULL_DOWN            0b1000
	    /*output*/
#define  OUTPUT_SPEED_10MHZ_PP      0b0001
#define  OUTPUT_SPEED_10MHZ_OD      0b0101
#define  OUTPUT_SPEED_10MHZ_AFPP    0b1001
#define  OUTPUT_SPEED_10MHZ_AFOD    0b1101

#define  OUTPUT_SPEED_2MHZ_PP       0b0010
#define  OUTPUT_SPEED_2MHZ_OD       0b0110
#define  OUTPUT_SPEED_2MHZ_AFPP     0b1010
#define  OUTPUT_SPEED_2MHZ_AFOD     0b1110

#define  OUTPUT_SPEED_50MHZ_PP      0b0011
#define  OUTPUT_SPEED_50MHZ_OD      0b0111
#define  OUTPUT_SPEED_50MHZ_AFPP    0b1011
#define  OUTPUT_SPEED_50MHZ_AFOD    0b1111


void MGPIO_VoidSetPinDirection (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode) ;

void MGPIO_VoidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value) ;

u8 MGPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin ) ;













#endif


