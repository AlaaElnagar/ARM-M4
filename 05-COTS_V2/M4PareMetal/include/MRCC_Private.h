/*
 * MRCC_Private.h
 *
 *  Created on: Jul 1, 2022
 *      Author: AlaaElnagar
 */

#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_

/*RCC Peripherial contains 22 Register*/
typedef struct {

volatile u32 CR             ;
volatile u32 PLLCFGR        ;
volatile u32 CFGR           ;
volatile u32 CIR            ;
volatile u32 AHB1RSTR       ;
volatile u32 AHB2RSTR       ;
volatile u32 Dummy0             ;
volatile u32 Dummy1             ;
volatile u32 APB1RSTR       ;
volatile u32 APB2RSTR       ;
volatile u32 Dummy2             ;
volatile u32 Dummy3             ;
volatile u32 AHB1ENR        ;
volatile u32 AHB2ENR        ;
volatile u32 Dummy4             ;
volatile u32 Dummy5             ;
volatile u32 APB1ENR        ;
volatile u32 APB2ENR        ;
volatile u32 Dummy6             ;
volatile u32 Dummy7             ;
volatile u32 AHB1LPENR      ;
volatile u32 AHB2LPENR      ;
volatile u32 Dummy8             ;
volatile u32 Dummy9             ;
volatile u32 APB1LPENR      ;
volatile u32 APB2LPENR      ;
volatile u32 Dummy10            ;
volatile u32 Dummy11            ;
volatile u32 BDCR           ;
volatile u32 CSR            ;
volatile u32 Dummy12            ;
volatile u32 Dummy13            ;
volatile u32 SSCGR          ;
volatile u32 PLLI2SCFGR     ;
volatile u32 Dummy14            ;
volatile u32 DCKCFGR        ;
}MRCC_Type ;

#define MRCC      ((volatile MRCC_Type*)(0x40023800))
/*Clk source*/
#define MRCC_HSE_CRYSTAL 0
#define MRCC_HSE_RC		 1
#define MRCC_HSI         2
#define MRCC_PLL		 3

/*PLL Input */

#define MRCC_PLL_IN_HSI         0
#define MRCC_PLL_IN_HSE_RC      1
#define MRCC_PLL_IN_HSE         2

/*PLL Configuration BITs*/
#define PLLN_BIT       6
#define PLLP_BIT       16
#define PLLM_BIT       0
/*Clock source */
#define MRCC_PLL_IN_HSI_2   0
#define MRCC_PLL_IN_HSE_2   1
#define MRCC_PLL_IN_HSE     2

/*RCC Enable and Disable */
#define MRCC_ENABLE_CS     1
#define MRCC_DISABLE_CS    0

/*PLL Configurations  */
#define MRCC_PLLP_EQUAL_2     0
#define MRCC_PLLP_EQUAL_4     1
#define MRCC_PLLP_EQUAL_6     2
#define MRCC_PLLP_EQUAL_8     3


/*AHP Prescaller */
#define MRCC_AHP_NOT_DIVIDDED       0
#define MRCC_AHP_DIV_BY_2           8
#define MRCC_AHP_DIV_BY_4           9
#define MRCC_AHP_DIV_BY_8           10
#define MRCC_AHP_DIV_BY_16          11
#define MRCC_AHP_DIV_BY_64          12
#define MRCC_AHP_DIV_BY_128         13
#define MRCC_AHP_DIV_BY_256         14
#define MRCC_AHP_DIV_BY_512         15
#define AHB_Bit                     4




/*APB2 Prescaler */

#define MRCC_APB2_NOT_DIVIDDED    0
#define MRCC_APB2_DIV_BY_2        4
#define MRCC_APB2_DIV_BY_4        5
#define MRCC_APB2_DIV_BY_8        6
#define MRCC_APB2_DIV_BY_16       7
#define APB2_Bit                  13

/*APB1 Prescaler*/
#define MRCC_APB1_NOT_DIV  			0
#define MRCC_APB1_DIV_BY_2  	    4
#define MRCC_APB1_DIV_BY_4  	    5
#define MRCC_APB1_DIV_BY_8  	    6
#define MRCC_APB1_DIV_BY_16  	    7
#define APB1_Bit                    10






#endif /* MRCC_PRIVATE_H_ */
