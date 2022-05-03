/****************************************************/
/*Author      : Alaa Elnaggar						*/
/*Date        : 25Apr2022							*/
/*Verssion    : V1.0								*/
/****************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_int.h"
#include "DIO_private.h"


void MGPIO_VoidSetPinDirection (u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Mode) 
{
	switch(Copy_u8Port) 
	{
		case GPIOA : 
					if (Copy_u8Pin <=7){
						GPIOA_CRL &= ~0b1111      << (Copy_u8Pin*4); 
						GPIOA_CRL |= Copy_u8Mode  << (Copy_u8Pin*4); 
						
					}
					else if (Copy_u8Pin <=15){
						Copy_u8Pin = Copy_u8Pin-8 ;
						GPIOA_CRH &= ~0b1111      << (Copy_u8Pin*4); 
						GPIOA_CRH |= Copy_u8Mode  << (Copy_u8Pin*4); 
												
					}
					break ; 
		case GPIOB :
					if (Copy_u8Pin <=7){
						GPIOB_CRL &= ~0b1111      << (Copy_u8Pin*4); 
						GPIOB_CRL |= Copy_u8Mode  << (Copy_u8Pin*4); 
						
					}
					else if (Copy_u8Pin <=15){
						Copy_u8Pin = Copy_u8Pin-8 ;
						GPIOB_CRH &= ~0b1111      << (Copy_u8Pin*4); 
						GPIOB_CRH |= Copy_u8Mode  << (Copy_u8Pin*4); 
												
					}
					break ; 		
		case GPIOC :
					if (Copy_u8Pin <=7){
						GPIOA_CRL &= ~0b1111      << (Copy_u8Pin*4); 
						GPIOA_CRL |= Copy_u8Mode  << (Copy_u8Pin*4); 
						
					}
					else if (Copy_u8Pin <=15){
						Copy_u8Pin = Copy_u8Pin-8 ;
						GPIOA_CRH &= ~0b1111      << (Copy_u8Pin*4); 
						GPIOA_CRH |= Copy_u8Mode  << (Copy_u8Pin*4); 
												
					}
					break ; 

						
		default : /*error state */
		break ; 
	}
}

void MGPIO_VoidSetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin , u8 Copy_u8Value) 
{
	switch(Copy_u8Port) 
	{
		case GPIOA : 	
				if (Copy_u8Pin == GPIO_HIGH)
				{
					SET_BIT(GPIOA_ODR, Copy_u8Pin);
				}
				else if (Copy_u8Pin == GPIO_LOW){
					
					CLR_BIT(GPIOA_ODR, Copy_u8Pin);
				}
				break ; 
		case GPIOB : 	
				if (Copy_u8Pin == GPIO_HIGH)
				{
					SET_BIT(GPIOB_ODR, Copy_u8Pin);
				}
				else if (Copy_u8Pin == GPIO_LOW){
					
					CLR_BIT(GPIOB_ODR, Copy_u8Pin);
				}
				break ; 
		case GPIOB : 	
				if (Copy_u8Pin == GPIO_HIGH)
				{
					SET_BIT(GPIOC_ODR, Copy_u8Pin);
				}
				else if (Copy_u8Pin == GPIO_LOW){
					
					CLR_BIT(GPIOC_ODR, Copy_u8Pin);
				}
				break ; 
		default :/*error */ break ;
}

u8 MGPIO_u8GetPinValue(u8 Copy_u8Port , u8 Copy_u8Pin ) 
{
	u8 Loc_PinState = 0 ; 
		switch(Copy_u8Port) 
	{
		case GPIOA : 	
					Loc_PinState = GET_BIT(GPIOA_IDR, Copy_u8Pin); break  ;

		case GPIOB : 	
					Loc_PinState = GET_BIT(GPIOB_IDR, Copy_u8Pin); break  ;

		case GPIOC : 	
					Loc_PinState = GET_BIT(GPIOC_IDR, Copy_u8Pin); break  ;

		default :/*error */ break ;
}
return Loc_PinState ;
	
}