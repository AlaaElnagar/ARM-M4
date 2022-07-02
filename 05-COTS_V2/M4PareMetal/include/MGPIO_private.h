/*
 * MGPIO_private.h
 *
 *  Created on: Jul 1, 2022
 *      Author: AlaaElnagar
 */

#ifndef MGPIO_PRIVATE_H_
#define MGPIO_PRIVATE_H_


typedef struct{

	volatile u32 MODER ;
	volatile u32 OTYPER ;
	volatile u32 OSPEEDR ;
	volatile u32 PUPDR ;
	volatile u32 IDR ;
	volatile u32 ODR ;
	volatile u32 BSRR ;
	volatile u32 LCKR ;
	volatile u32 AFRL ;
	volatile u32 AFRH ;

}GPIO_Type ;

#define MGPIOA ((volatile GPIO_Type*)0x40020000)
#define MGPIOB ((volatile GPIO_Type*)0x40020400)
#define MGPIOC ((volatile GPIO_Type*)0x40020800)
/*For Discovery Board*/
#define MGPIOD ((volatile GPIO_Type*)0x40020C00)
#define MGPIOE ((volatile GPIO_Type*)0x40021000)
#define MGPIOH ((volatile GPIO_Type*)0x40021C00)

#endif /* MGPIO_PRIVATE_H_ */
