/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : MRCC_Privite.h --> implementations                                              */
/* Features          : Register Definitions                                                            */
/*******************************************************************************************************/


/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/
#ifndef MRCC_PRIVATE_H
#define MRCC_PRIVATE_H

/*******************************************************************************************************/
/*                                       Register Definitions                                          */
/*-----------------------------------------------------------------------------------------------------*/
/*     - Developer can't Edit in it                                                                    */
/*     - Register _ Defination		                                                                   */
/*     - Design :                                                                                      */
/*    				- #define	:	YES                                                                */
/*    				- Union		:	NO                                                                 */
/*    				- Struct	:	NO                                                                 */
/*                                                                                                     */
/*******************************************************************************************************/


/*******************************************************************************************************/
/*                                    Macros Base Address Of RCC Registers                             */
/*******************************************************************************************************/


#define MRCC_BASE_ADDRESS     0x40023800

/*******************************************************************************************************/
/*                                    Macros Of RCC Register Map                                       */
/*******************************************************************************************************/

#define RCC_CR                      (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x00)))    
#define RCC_PLLCFGR                 (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x04)))      
#define RCC_CFGR                    (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x08)))  
#define RCC_CIR                     (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x0C)))  
#define RCC_AHB1RSTR                (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x10)))  
#define RCC_AHB2RSTR                (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x14)))  
#define RCC_APB1RSTR                (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x20)))  
#define RCC_APB2RSTR                (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x24)))  
#define RCC_AHB1ENR                 (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x30)))  
#define RCC_AHB2ENR                 (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x34)))  
#define RCC_APB1ENR                 (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x40)))  
#define RCC_APB2ENR                 (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x44)))  
#define RCC_AHB1LPENR               (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x50)))  
#define RCC_AHB2LPENR               (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x54)))  
#define RCC_APB1LPENR               (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x60)))  
#define RCC_APB2LPENR               (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x64)))  
#define RCC_BDCR                    (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x70)))  
#define RCC_CSR                     (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x74)))  
#define RCC_SSCGR                   (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x80)))  
#define RCC_PLLI2SCFGR              (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x84)))  
#define RCC_DCKCFGR                 (*(( volatile u32* )(MRCC_BASE_ADDRESS + 0x8c)))  

/**********************************************/
#define CSSON   19U
/**********************************************/

/*******************************************************************************************************/
/*                                       Register Definitions                                          */
/*-----------------------------------------------------------------------------------------------------*/
/*     - Developer can't Edit in it                                                                    */
/*     - Register _ Defination		                                                                   */
/*     - Design :                                                                                      */
/*    				- #define	:	NO                                                                */
/*    				- Union		:	NO                                                                 */
/*    				- Struct	:	YES                                                                */
/*                                                                                                     */
/*******************************************************************************************************/

typedef struct
{
  volatile u32 CR;            /*!< RCC clock control register,                                  Address offset: 0x00 */ 
  volatile u32 PLLCFGR;       /*!< RCC PLL configuration register,                              Address offset: 0x04 */
  volatile u32 CFGR;          /*!< RCC clock configuration register,                            Address offset: 0x08 */
  volatile u32 CIR;           /*!< RCC clock interrupt register,                                Address offset: 0x0C */
  volatile u32 AHB1RSTR;      /*!< RCC AHB1 peripheral reset register,                          Address offset: 0x10 */
  volatile u32 AHB2RSTR;      /*!< RCC AHB2 peripheral reset register,                          Address offset: 0x14 */
  volatile u32 RESERVED0;     /*!< RCC AHB3 peripheral reset register,                          Address offset: 0x18 */ 
  volatile u32 RESERVED1;     /*!< Reserved, 0x1C                                                                    */
  volatile u32 APB1RSTR;      /*!< RCC APB1 peripheral reset register,                          Address offset: 0x20 */
  volatile u32 APB2RSTR;      /*!< RCC APB2 peripheral reset register,                          Address offset: 0x24 */
  volatile u32 RESERVED2[2];  /*!< Reserved, 0x28-0x2C                                                               */
  volatile u32 AHB1ENR;       /*!< RCC AHB1 peripheral clock register,                          Address offset: 0x30 */
  volatile u32 AHB2ENR;       /*!< RCC AHB2 peripheral clock register,                          Address offset: 0x34 */
  volatile u32 RESERVED3;     /*!< RCC AHB3 peripheral clock register,                          Address offset: 0x38 */   
  volatile u32 RESERVED4;     /*!< Reserved, 0x3C                                                                    */
  volatile u32 APB1ENR;       /*!< RCC APB1 peripheral clock enable register,                   Address offset: 0x40 */
  volatile u32 APB2ENR;       /*!< RCC APB2 peripheral clock enable register,                   Address offset: 0x44 */
  volatile u32 RESERVED5[2];  /*!< Reserved, 0x48-0x4C                                                               */
  volatile u32 AHB1LPENR;     /*!< RCC AHB1 peripheral clock enable in low power mode register, Address offset: 0x50 */
  volatile u32 AHB2LPENR;     /*!< RCC AHB2 peripheral clock enable in low power mode register, Address offset: 0x54 */
  volatile u32 RESERVED6;     /*!< RCC AHB3 peripheral clock enable in low power mode register, Address offset: 0x58 */ 
  volatile u32 RESERVED7;     /*!< Reserved, 0x5C                                                                    */
  volatile u32 APB1LPENR;     /*!< RCC APB1 peripheral clock enable in low power mode register, Address offset: 0x60 */
  volatile u32 APB2LPENR;     /*!< RCC APB2 peripheral clock enable in low power mode register, Address offset: 0x64 */
  volatile u32 RESERVED8[2];  /*!< Reserved, 0x68-0x6C                                                               */
  volatile u32 BDCR;          /*!< RCC Backup domain control register,                          Address offset: 0x70 */
  volatile u32 CSR;           /*!< RCC clock control & status register,                         Address offset: 0x74 */
  volatile u32 RESERVED9[2];  /*!< Reserved, 0x78-0x7C                                                               */
  volatile u32 SSCGR;         /*!< RCC spread spectrum clock generation register,               Address offset: 0x80 */
  volatile u32 PLLI2SCFGR;    /*!< RCC PLLI2S configuration register,                           Address offset: 0x84 */
  volatile u32 RESERVED10[1]; /*!< Reserved, 0x88                                                                    */ 
  volatile u32 DCKCFGR;       /*!< RCC Dedicated Clocks configuration register,                 Address offset: 0x8C */
}RCC_TypeDeff;

/*================================================================
	-)Struct Macros :
			*  Base_Address RRC 				
=================================================================*/
#define    MRCC     ((volatile RCC_TypeDeff *) (MRCC_BASE_ADDRESS))

#endif //MRCC_PRIVATE_H
