/****************************************************/
/*Author      : Alaa Elnaggar						*/
/*Date        : 16Apr2022							*/
/*Verssion    : V1.0								*/
/****************************************************/

#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

		/* Set Bit */
#define SET_BIT(REG,BIT_NUM)  REG|=1<<BIT_NUM

		/* Clear Bit */
#define CLEAR_BIT(REG,BIT_NUM)  REG&=~(1<<BIT_NUM)

		/* Toggle Bit */
#define TOGGLE_BIT(REG,BIT_NUM)  REG^=(1<<BIT_NUM)

		/* GET_BIT */
#define GET_BIT(REG,BIT_NUM)   ((REG>>BIT_NUM)&1)


#endif