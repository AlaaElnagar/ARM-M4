/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : MADC_Privite.h --> implementations                                              */
/* Features          : Register Definitions                                                            */
/*******************************************************************************************************/


/*******************************************************************************************************/
/*                                   guard of file will call on time in .c                             */
/*******************************************************************************************************/
#ifndef MADC_PRIVITE_H_
#define MADC_PRIVITE_H_


/**
  * @brief Analog to Digital Converter
  */

typedef struct
{
  volatile u32 SR;     /*!< ADC status register,                         Address offset: 0x00 */
  volatile u32 CR1;    /*!< ADC control register 1,                      Address offset: 0x04 */
  volatile u32 CR2;    /*!< ADC control register 2,                      Address offset: 0x08 */
  volatile u32 SMPR1;  /*!< ADC sample time register 1,                  Address offset: 0x0C */
  volatile u32 SMPR2;  /*!< ADC sample time register 2,                  Address offset: 0x10 */
  volatile u32 JOFR1;  /*!< ADC injected channel data offset register 1, Address offset: 0x14 */
  volatile u32 JOFR2;  /*!< ADC injected channel data offset register 2, Address offset: 0x18 */
  volatile u32 JOFR3;  /*!< ADC injected channel data offset register 3, Address offset: 0x1C */
  volatile u32 JOFR4;  /*!< ADC injected channel data offset register 4, Address offset: 0x20 */
  volatile u32 HTR;    /*!< ADC watchdog higher threshold register,      Address offset: 0x24 */
  volatile u32 LTR;    /*!< ADC watchdog lower threshold register,       Address offset: 0x28 */
  volatile u32 SQR1;   /*!< ADC regular sequence register 1,             Address offset: 0x2C */
  volatile u32 SQR2;   /*!< ADC regular sequence register 2,             Address offset: 0x30 */
  volatile u32 SQR3;   /*!< ADC regular sequence register 3,             Address offset: 0x34 */
  volatile u32 JSQR;   /*!< ADC injected sequence register,              Address offset: 0x38*/
  volatile u32 JDR1;   /*!< ADC injected data register 1,                Address offset: 0x3C */
  volatile u32 JDR2;   /*!< ADC injected data register 2,                Address offset: 0x40 */
  volatile u32 JDR3;   /*!< ADC injected data register 3,                Address offset: 0x44 */
  volatile u32 JDR4;   /*!< ADC injected data register 4,                Address offset: 0x48 */
  volatile u32 DR;     /*!< ADC regular data register,                   Address offset: 0x4C */
} ADC_TypeDef;

typedef struct
{
  volatile u32 CSR;    /*!< ADC Common status register,                  Address offset: ADC1 base address + 0x300 */
  volatile u32 CCR;    /*!< ADC common control register,                 Address offset: ADC1 base address + 0x304 */
  volatile u32 CDR;    /*!< ADC common regular data register for dual
                             AND triple modes,                            Address offset: ADC1 base address + 0x308 */
} ADC_Common_TypeDef;




/*!< Peripheral memory map */

#define PERIPH_BASE           ((u32)0x40000000) /*!< Peripheral base address in the alias region*/

#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x00010000)
#define AHB1PERIPH_BASE       (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE       (PERIPH_BASE + 0x10000000)

#define ADC1_BASE             (APB2PERIPH_BASE + 0x2000)
#define ADC_BASE              (APB2PERIPH_BASE + 0x2300)

#define ADC1                ((ADC_TypeDef *) ADC1_BASE)
#define ADC                 ((ADC_Common_TypeDef *) ADC_BASE)



/******************************************************************************/
/*                                                                            */
/*                        Analog to Digital Converter                         */
/*                                                                            */
/******************************************************************************/
/********************  Bit definition for ADC_SR register  ********************/
#define  ADC_SR_AWD                          ((uint32_t)0x00000001)       /*!<Analog watchdog flag */
#define  ADC_SR_EOC                          ((uint32_t)0x00000002)       /*!<End of conversion */
#define  ADC_SR_JEOC                         ((uint32_t)0x00000004)       /*!<Injected channel end of conversion */
#define  ADC_SR_JSTRT                        ((uint32_t)0x00000008)       /*!<Injected channel Start flag */
#define  ADC_SR_STRT                         ((uint32_t)0x00000010)       /*!<Regular channel Start flag */
#define  ADC_SR_OVR                          ((uint32_t)0x00000020)       /*!<Overrun flag */

/*******************  Bit definition for ADC_CR1 register  ********************/
#define  ADC_CR1_AWDCH                       ((uint32_t)0x0000001F)        /*!<AWDCH[4:0] bits (Analog watchdog channel select bits) */
#define  ADC_CR1_AWDCH_0                     ((uint32_t)0x00000001)        /*!<Bit 0 */
#define  ADC_CR1_AWDCH_1                     ((uint32_t)0x00000002)        /*!<Bit 1 */
#define  ADC_CR1_AWDCH_2                     ((uint32_t)0x00000004)        /*!<Bit 2 */
#define  ADC_CR1_AWDCH_3                     ((uint32_t)0x00000008)        /*!<Bit 3 */
#define  ADC_CR1_AWDCH_4                     ((uint32_t)0x00000010)        /*!<Bit 4 */
#define  ADC_CR1_EOCIE                       ((uint32_t)0x00000020)        /*!<Interrupt enable for EOC */
#define  ADC_CR1_AWDIE                       ((uint32_t)0x00000040)        /*!<AAnalog Watchdog interrupt enable */
#define  ADC_CR1_JEOCIE                      ((uint32_t)0x00000080)        /*!<Interrupt enable for injected channels */
#define  ADC_CR1_SCAN                        ((uint32_t)0x00000100)        /*!<Scan mode */
#define  ADC_CR1_AWDSGL                      ((uint32_t)0x00000200)        /*!<Enable the watchdog on a single channel in scan mode */
#define  ADC_CR1_JAUTO                       ((uint32_t)0x00000400)        /*!<Automatic injected group conversion */
#define  ADC_CR1_DISCEN                      ((uint32_t)0x00000800)        /*!<Discontinuous mode on regular channels */
#define  ADC_CR1_JDISCEN                     ((uint32_t)0x00001000)        /*!<Discontinuous mode on injected channels */
#define  ADC_CR1_DISCNUM                     ((uint32_t)0x0000E000)        /*!<DISCNUM[2:0] bits (Discontinuous mode channel count) */
#define  ADC_CR1_DISCNUM_0                   ((uint32_t)0x00002000)        /*!<Bit 0 */
#define  ADC_CR1_DISCNUM_1                   ((uint32_t)0x00004000)        /*!<Bit 1 */
#define  ADC_CR1_DISCNUM_2                   ((uint32_t)0x00008000)        /*!<Bit 2 */
#define  ADC_CR1_JAWDEN                      ((uint32_t)0x00400000)        /*!<Analog watchdog enable on injected channels */
#define  ADC_CR1_AWDEN                       ((uint32_t)0x00800000)        /*!<Analog watchdog enable on regular channels */
#define  ADC_CR1_RES                         ((uint32_t)0x03000000)        /*!<RES[2:0] bits (Resolution) */
#define  ADC_CR1_RES_0                       ((uint32_t)0x01000000)        /*!<Bit 0 */
#define  ADC_CR1_RES_1                       ((uint32_t)0x02000000)        /*!<Bit 1 */
#define  ADC_CR1_OVRIE                       ((uint32_t)0x04000000)         /*!<overrun interrupt enable */

/*******************  Bit definition for ADC_CR2 register  ********************/
#define  ADC_CR2_ADON                        ((uint32_t)0x00000001)        /*!<A/D Converter ON / OFF */
#define  ADC_CR2_CONT                        ((uint32_t)0x00000002)        /*!<Continuous Conversion */
#define  ADC_CR2_DMA                         ((uint32_t)0x00000100)        /*!<Direct Memory access mode */
#define  ADC_CR2_DDS                         ((uint32_t)0x00000200)        /*!<DMA disable selection (Single ADC) */
#define  ADC_CR2_EOCS                        ((uint32_t)0x00000400)        /*!<End of conversion selection */
#define  ADC_CR2_ALIGN                       ((uint32_t)0x00000800)        /*!<Data Alignment */
#define  ADC_CR2_JEXTSEL                     ((uint32_t)0x000F0000)        /*!<JEXTSEL[3:0] bits (External event select for injected group) */
#define  ADC_CR2_JEXTSEL_0                   ((uint32_t)0x00010000)        /*!<Bit 0 */
#define  ADC_CR2_JEXTSEL_1                   ((uint32_t)0x00020000)        /*!<Bit 1 */
#define  ADC_CR2_JEXTSEL_2                   ((uint32_t)0x00040000)        /*!<Bit 2 */
#define  ADC_CR2_JEXTSEL_3                   ((uint32_t)0x00080000)        /*!<Bit 3 */
#define  ADC_CR2_JEXTEN                      ((uint32_t)0x00300000)        /*!<JEXTEN[1:0] bits (External Trigger Conversion mode for injected channelsp) */
#define  ADC_CR2_JEXTEN_0                    ((uint32_t)0x00100000)        /*!<Bit 0 */
#define  ADC_CR2_JEXTEN_1                    ((uint32_t)0x00200000)        /*!<Bit 1 */
#define  ADC_CR2_JSWSTART                    ((uint32_t)0x00400000)        /*!<Start Conversion of injected channels */
#define  ADC_CR2_EXTSEL                      ((uint32_t)0x0F000000)        /*!<EXTSEL[3:0] bits (External Event Select for regular group) */
#define  ADC_CR2_EXTSEL_0                    ((uint32_t)0x01000000)        /*!<Bit 0 */
#define  ADC_CR2_EXTSEL_1                    ((uint32_t)0x02000000)        /*!<Bit 1 */
#define  ADC_CR2_EXTSEL_2                    ((uint32_t)0x04000000)        /*!<Bit 2 */
#define  ADC_CR2_EXTSEL_3                    ((uint32_t)0x08000000)        /*!<Bit 3 */
#define  ADC_CR2_EXTEN                       ((uint32_t)0x30000000)        /*!<EXTEN[1:0] bits (External Trigger Conversion mode for regular channelsp) */
#define  ADC_CR2_EXTEN_0                     ((uint32_t)0x10000000)        /*!<Bit 0 */
#define  ADC_CR2_EXTEN_1                     ((uint32_t)0x20000000)        /*!<Bit 1 */
#define  ADC_CR2_SWSTART                     ((uint32_t)0x40000000)        /*!<Start Conversion of regular channels */

/******************  Bit definition for ADC_SMPR1 register  *******************/
#define  ADC_SMPR1_SMP10                     ((uint32_t)0x00000007)        /*!<SMP10[2:0] bits (Channel 10 Sample time selection) */
#define  ADC_SMPR1_SMP10_0                   ((uint32_t)0x00000001)        /*!<Bit 0 */
#define  ADC_SMPR1_SMP10_1                   ((uint32_t)0x00000002)        /*!<Bit 1 */
#define  ADC_SMPR1_SMP10_2                   ((uint32_t)0x00000004)        /*!<Bit 2 */
#define  ADC_SMPR1_SMP11                     ((uint32_t)0x00000038)        /*!<SMP11[2:0] bits (Channel 11 Sample time selection) */
#define  ADC_SMPR1_SMP11_0                   ((uint32_t)0x00000008)        /*!<Bit 0 */
#define  ADC_SMPR1_SMP11_1                   ((uint32_t)0x00000010)        /*!<Bit 1 */
#define  ADC_SMPR1_SMP11_2                   ((uint32_t)0x00000020)        /*!<Bit 2 */
#define  ADC_SMPR1_SMP12                     ((uint32_t)0x000001C0)        /*!<SMP12[2:0] bits (Channel 12 Sample time selection) */
#define  ADC_SMPR1_SMP12_0                   ((uint32_t)0x00000040)        /*!<Bit 0 */
#define  ADC_SMPR1_SMP12_1                   ((uint32_t)0x00000080)        /*!<Bit 1 */
#define  ADC_SMPR1_SMP12_2                   ((uint32_t)0x00000100)        /*!<Bit 2 */
#define  ADC_SMPR1_SMP13                     ((uint32_t)0x00000E00)        /*!<SMP13[2:0] bits (Channel 13 Sample time selection) */
#define  ADC_SMPR1_SMP13_0                   ((uint32_t)0x00000200)        /*!<Bit 0 */
#define  ADC_SMPR1_SMP13_1                   ((uint32_t)0x00000400)        /*!<Bit 1 */
#define  ADC_SMPR1_SMP13_2                   ((uint32_t)0x00000800)        /*!<Bit 2 */
#define  ADC_SMPR1_SMP14                     ((uint32_t)0x00007000)        /*!<SMP14[2:0] bits (Channel 14 Sample time selection) */
#define  ADC_SMPR1_SMP14_0                   ((uint32_t)0x00001000)        /*!<Bit 0 */
#define  ADC_SMPR1_SMP14_1                   ((uint32_t)0x00002000)        /*!<Bit 1 */
#define  ADC_SMPR1_SMP14_2                   ((uint32_t)0x00004000)        /*!<Bit 2 */
#define  ADC_SMPR1_SMP15                     ((uint32_t)0x00038000)        /*!<SMP15[2:0] bits (Channel 15 Sample time selection) */
#define  ADC_SMPR1_SMP15_0                   ((uint32_t)0x00008000)        /*!<Bit 0 */
#define  ADC_SMPR1_SMP15_1                   ((uint32_t)0x00010000)        /*!<Bit 1 */
#define  ADC_SMPR1_SMP15_2                   ((uint32_t)0x00020000)        /*!<Bit 2 */
#define  ADC_SMPR1_SMP16                     ((uint32_t)0x001C0000)        /*!<SMP16[2:0] bits (Channel 16 Sample time selection) */
#define  ADC_SMPR1_SMP16_0                   ((uint32_t)0x00040000)        /*!<Bit 0 */
#define  ADC_SMPR1_SMP16_1                   ((uint32_t)0x00080000)        /*!<Bit 1 */
#define  ADC_SMPR1_SMP16_2                   ((uint32_t)0x00100000)        /*!<Bit 2 */
#define  ADC_SMPR1_SMP17                     ((uint32_t)0x00E00000)        /*!<SMP17[2:0] bits (Channel 17 Sample time selection) */
#define  ADC_SMPR1_SMP17_0                   ((uint32_t)0x00200000)        /*!<Bit 0 */
#define  ADC_SMPR1_SMP17_1                   ((uint32_t)0x00400000)        /*!<Bit 1 */
#define  ADC_SMPR1_SMP17_2                   ((uint32_t)0x00800000)        /*!<Bit 2 */
#define  ADC_SMPR1_SMP18                     ((uint32_t)0x07000000)        /*!<SMP18[2:0] bits (Channel 18 Sample time selection) */
#define  ADC_SMPR1_SMP18_0                   ((uint32_t)0x01000000)        /*!<Bit 0 */
#define  ADC_SMPR1_SMP18_1                   ((uint32_t)0x02000000)        /*!<Bit 1 */
#define  ADC_SMPR1_SMP18_2                   ((uint32_t)0x04000000)        /*!<Bit 2 */

/******************  Bit definition for ADC_SMPR2 register  *******************/
#define  ADC_SMPR2_SMP0                      ((uint32_t)0x00000007)        /*!<SMP0[2:0] bits (Channel 0 Sample time selection) */
#define  ADC_SMPR2_SMP0_0                    ((uint32_t)0x00000001)        /*!<Bit 0 */
#define  ADC_SMPR2_SMP0_1                    ((uint32_t)0x00000002)        /*!<Bit 1 */
#define  ADC_SMPR2_SMP0_2                    ((uint32_t)0x00000004)        /*!<Bit 2 */
#define  ADC_SMPR2_SMP1                      ((uint32_t)0x00000038)        /*!<SMP1[2:0] bits (Channel 1 Sample time selection) */
#define  ADC_SMPR2_SMP1_0                    ((uint32_t)0x00000008)        /*!<Bit 0 */
#define  ADC_SMPR2_SMP1_1                    ((uint32_t)0x00000010)        /*!<Bit 1 */
#define  ADC_SMPR2_SMP1_2                    ((uint32_t)0x00000020)        /*!<Bit 2 */
#define  ADC_SMPR2_SMP2                      ((uint32_t)0x000001C0)        /*!<SMP2[2:0] bits (Channel 2 Sample time selection) */
#define  ADC_SMPR2_SMP2_0                    ((uint32_t)0x00000040)        /*!<Bit 0 */
#define  ADC_SMPR2_SMP2_1                    ((uint32_t)0x00000080)        /*!<Bit 1 */
#define  ADC_SMPR2_SMP2_2                    ((uint32_t)0x00000100)        /*!<Bit 2 */
#define  ADC_SMPR2_SMP3                      ((uint32_t)0x00000E00)        /*!<SMP3[2:0] bits (Channel 3 Sample time selection) */
#define  ADC_SMPR2_SMP3_0                    ((uint32_t)0x00000200)        /*!<Bit 0 */
#define  ADC_SMPR2_SMP3_1                    ((uint32_t)0x00000400)        /*!<Bit 1 */
#define  ADC_SMPR2_SMP3_2                    ((uint32_t)0x00000800)        /*!<Bit 2 */
#define  ADC_SMPR2_SMP4                      ((uint32_t)0x00007000)        /*!<SMP4[2:0] bits (Channel 4 Sample time selection) */
#define  ADC_SMPR2_SMP4_0                    ((uint32_t)0x00001000)        /*!<Bit 0 */
#define  ADC_SMPR2_SMP4_1                    ((uint32_t)0x00002000)        /*!<Bit 1 */
#define  ADC_SMPR2_SMP4_2                    ((uint32_t)0x00004000)        /*!<Bit 2 */
#define  ADC_SMPR2_SMP5                      ((uint32_t)0x00038000)        /*!<SMP5[2:0] bits (Channel 5 Sample time selection) */
#define  ADC_SMPR2_SMP5_0                    ((uint32_t)0x00008000)        /*!<Bit 0 */
#define  ADC_SMPR2_SMP5_1                    ((uint32_t)0x00010000)        /*!<Bit 1 */
#define  ADC_SMPR2_SMP5_2                    ((uint32_t)0x00020000)        /*!<Bit 2 */
#define  ADC_SMPR2_SMP6                      ((uint32_t)0x001C0000)        /*!<SMP6[2:0] bits (Channel 6 Sample time selection) */
#define  ADC_SMPR2_SMP6_0                    ((uint32_t)0x00040000)        /*!<Bit 0 */
#define  ADC_SMPR2_SMP6_1                    ((uint32_t)0x00080000)        /*!<Bit 1 */
#define  ADC_SMPR2_SMP6_2                    ((uint32_t)0x00100000)        /*!<Bit 2 */
#define  ADC_SMPR2_SMP7                      ((uint32_t)0x00E00000)        /*!<SMP7[2:0] bits (Channel 7 Sample time selection) */
#define  ADC_SMPR2_SMP7_0                    ((uint32_t)0x00200000)        /*!<Bit 0 */
#define  ADC_SMPR2_SMP7_1                    ((uint32_t)0x00400000)        /*!<Bit 1 */
#define  ADC_SMPR2_SMP7_2                    ((uint32_t)0x00800000)        /*!<Bit 2 */
#define  ADC_SMPR2_SMP8                      ((uint32_t)0x07000000)        /*!<SMP8[2:0] bits (Channel 8 Sample time selection) */
#define  ADC_SMPR2_SMP8_0                    ((uint32_t)0x01000000)        /*!<Bit 0 */
#define  ADC_SMPR2_SMP8_1                    ((uint32_t)0x02000000)        /*!<Bit 1 */
#define  ADC_SMPR2_SMP8_2                    ((uint32_t)0x04000000)        /*!<Bit 2 */
#define  ADC_SMPR2_SMP9                      ((uint32_t)0x38000000)        /*!<SMP9[2:0] bits (Channel 9 Sample time selection) */
#define  ADC_SMPR2_SMP9_0                    ((uint32_t)0x08000000)        /*!<Bit 0 */
#define  ADC_SMPR2_SMP9_1                    ((uint32_t)0x10000000)        /*!<Bit 1 */
#define  ADC_SMPR2_SMP9_2                    ((uint32_t)0x20000000)        /*!<Bit 2 */

/******************  Bit definition for ADC_JOFR1 register  *******************/
#define  ADC_JOFR1_JOFFSET1                  ((uint32_t)0x0FFF)            /*!<Data offset for injected channel 1 */

/******************  Bit definition for ADC_JOFR2 register  *******************/
#define  ADC_JOFR2_JOFFSET2                  ((uint32_t)0x0FFF)            /*!<Data offset for injected channel 2 */

/******************  Bit definition for ADC_JOFR3 register  *******************/
#define  ADC_JOFR3_JOFFSET3                  ((uint32_t)0x0FFF)            /*!<Data offset for injected channel 3 */

/******************  Bit definition for ADC_JOFR4 register  *******************/
#define  ADC_JOFR4_JOFFSET4                  ((uint32_t)0x0FFF)            /*!<Data offset for injected channel 4 */

/*******************  Bit definition for ADC_HTR register  ********************/
#define  ADC_HTR_HT                          ((uint32_t)0x0FFF)            /*!<Analog watchdog high threshold */

/*******************  Bit definition for ADC_LTR register  ********************/
#define  ADC_LTR_LT                          ((uint32_t)0x0FFF)            /*!<Analog watchdog low threshold */

/*******************  Bit definition for ADC_SQR1 register  *******************/
#define  ADC_SQR1_SQ13                       ((uint32_t)0x0000001F)        /*!<SQ13[4:0] bits (13th conversion in regular sequence) */
#define  ADC_SQR1_SQ13_0                     ((uint32_t)0x00000001)        /*!<Bit 0 */
#define  ADC_SQR1_SQ13_1                     ((uint32_t)0x00000002)        /*!<Bit 1 */
#define  ADC_SQR1_SQ13_2                     ((uint32_t)0x00000004)        /*!<Bit 2 */
#define  ADC_SQR1_SQ13_3                     ((uint32_t)0x00000008)        /*!<Bit 3 */
#define  ADC_SQR1_SQ13_4                     ((uint32_t)0x00000010)        /*!<Bit 4 */
#define  ADC_SQR1_SQ14                       ((uint32_t)0x000003E0)        /*!<SQ14[4:0] bits (14th conversion in regular sequence) */
#define  ADC_SQR1_SQ14_0                     ((uint32_t)0x00000020)        /*!<Bit 0 */
#define  ADC_SQR1_SQ14_1                     ((uint32_t)0x00000040)        /*!<Bit 1 */
#define  ADC_SQR1_SQ14_2                     ((uint32_t)0x00000080)        /*!<Bit 2 */
#define  ADC_SQR1_SQ14_3                     ((uint32_t)0x00000100)        /*!<Bit 3 */
#define  ADC_SQR1_SQ14_4                     ((uint32_t)0x00000200)        /*!<Bit 4 */
#define  ADC_SQR1_SQ15                       ((uint32_t)0x00007C00)        /*!<SQ15[4:0] bits (15th conversion in regular sequence) */
#define  ADC_SQR1_SQ15_0                     ((uint32_t)0x00000400)        /*!<Bit 0 */
#define  ADC_SQR1_SQ15_1                     ((uint32_t)0x00000800)        /*!<Bit 1 */
#define  ADC_SQR1_SQ15_2                     ((uint32_t)0x00001000)        /*!<Bit 2 */
#define  ADC_SQR1_SQ15_3                     ((uint32_t)0x00002000)        /*!<Bit 3 */
#define  ADC_SQR1_SQ15_4                     ((uint32_t)0x00004000)        /*!<Bit 4 */
#define  ADC_SQR1_SQ16                       ((uint32_t)0x000F8000)        /*!<SQ16[4:0] bits (16th conversion in regular sequence) */
#define  ADC_SQR1_SQ16_0                     ((uint32_t)0x00008000)        /*!<Bit 0 */
#define  ADC_SQR1_SQ16_1                     ((uint32_t)0x00010000)        /*!<Bit 1 */
#define  ADC_SQR1_SQ16_2                     ((uint32_t)0x00020000)        /*!<Bit 2 */
#define  ADC_SQR1_SQ16_3                     ((uint32_t)0x00040000)        /*!<Bit 3 */
#define  ADC_SQR1_SQ16_4                     ((uint32_t)0x00080000)        /*!<Bit 4 */
#define  ADC_SQR1_L                          ((uint32_t)0x00F00000)        /*!<L[3:0] bits (Regular channel sequence length) */
#define  ADC_SQR1_L_0                        ((uint32_t)0x00100000)        /*!<Bit 0 */
#define  ADC_SQR1_L_1                        ((uint32_t)0x00200000)        /*!<Bit 1 */
#define  ADC_SQR1_L_2                        ((uint32_t)0x00400000)        /*!<Bit 2 */
#define  ADC_SQR1_L_3                        ((uint32_t)0x00800000)        /*!<Bit 3 */

/*******************  Bit definition for ADC_SQR2 register  *******************/
#define  ADC_SQR2_SQ7                        ((uint32_t)0x0000001F)        /*!<SQ7[4:0] bits (7th conversion in regular sequence) */
#define  ADC_SQR2_SQ7_0                      ((uint32_t)0x00000001)        /*!<Bit 0 */
#define  ADC_SQR2_SQ7_1                      ((uint32_t)0x00000002)        /*!<Bit 1 */
#define  ADC_SQR2_SQ7_2                      ((uint32_t)0x00000004)        /*!<Bit 2 */
#define  ADC_SQR2_SQ7_3                      ((uint32_t)0x00000008)        /*!<Bit 3 */
#define  ADC_SQR2_SQ7_4                      ((uint32_t)0x00000010)        /*!<Bit 4 */
#define  ADC_SQR2_SQ8                        ((uint32_t)0x000003E0)        /*!<SQ8[4:0] bits (8th conversion in regular sequence) */
#define  ADC_SQR2_SQ8_0                      ((uint32_t)0x00000020)        /*!<Bit 0 */
#define  ADC_SQR2_SQ8_1                      ((uint32_t)0x00000040)        /*!<Bit 1 */
#define  ADC_SQR2_SQ8_2                      ((uint32_t)0x00000080)        /*!<Bit 2 */
#define  ADC_SQR2_SQ8_3                      ((uint32_t)0x00000100)        /*!<Bit 3 */
#define  ADC_SQR2_SQ8_4                      ((uint32_t)0x00000200)        /*!<Bit 4 */
#define  ADC_SQR2_SQ9                        ((uint32_t)0x00007C00)        /*!<SQ9[4:0] bits (9th conversion in regular sequence) */
#define  ADC_SQR2_SQ9_0                      ((uint32_t)0x00000400)        /*!<Bit 0 */
#define  ADC_SQR2_SQ9_1                      ((uint32_t)0x00000800)        /*!<Bit 1 */
#define  ADC_SQR2_SQ9_2                      ((uint32_t)0x00001000)        /*!<Bit 2 */
#define  ADC_SQR2_SQ9_3                      ((uint32_t)0x00002000)        /*!<Bit 3 */
#define  ADC_SQR2_SQ9_4                      ((uint32_t)0x00004000)        /*!<Bit 4 */
#define  ADC_SQR2_SQ10                       ((uint32_t)0x000F8000)        /*!<SQ10[4:0] bits (10th conversion in regular sequence) */
#define  ADC_SQR2_SQ10_0                     ((uint32_t)0x00008000)        /*!<Bit 0 */
#define  ADC_SQR2_SQ10_1                     ((uint32_t)0x00010000)        /*!<Bit 1 */
#define  ADC_SQR2_SQ10_2                     ((uint32_t)0x00020000)        /*!<Bit 2 */
#define  ADC_SQR2_SQ10_3                     ((uint32_t)0x00040000)        /*!<Bit 3 */
#define  ADC_SQR2_SQ10_4                     ((uint32_t)0x00080000)        /*!<Bit 4 */
#define  ADC_SQR2_SQ11                       ((uint32_t)0x01F00000)        /*!<SQ11[4:0] bits (11th conversion in regular sequence) */
#define  ADC_SQR2_SQ11_0                     ((uint32_t)0x00100000)        /*!<Bit 0 */
#define  ADC_SQR2_SQ11_1                     ((uint32_t)0x00200000)        /*!<Bit 1 */
#define  ADC_SQR2_SQ11_2                     ((uint32_t)0x00400000)        /*!<Bit 2 */
#define  ADC_SQR2_SQ11_3                     ((uint32_t)0x00800000)        /*!<Bit 3 */
#define  ADC_SQR2_SQ11_4                     ((uint32_t)0x01000000)        /*!<Bit 4 */
#define  ADC_SQR2_SQ12                       ((uint32_t)0x3E000000)        /*!<SQ12[4:0] bits (12th conversion in regular sequence) */
#define  ADC_SQR2_SQ12_0                     ((uint32_t)0x02000000)        /*!<Bit 0 */
#define  ADC_SQR2_SQ12_1                     ((uint32_t)0x04000000)        /*!<Bit 1 */
#define  ADC_SQR2_SQ12_2                     ((uint32_t)0x08000000)        /*!<Bit 2 */
#define  ADC_SQR2_SQ12_3                     ((uint32_t)0x10000000)        /*!<Bit 3 */
#define  ADC_SQR2_SQ12_4                     ((uint32_t)0x20000000)        /*!<Bit 4 */

/*******************  Bit definition for ADC_SQR3 register  *******************/
#define  ADC_SQR3_SQ1                        ((uint32_t)0x0000001F)        /*!<SQ1[4:0] bits (1st conversion in regular sequence) */
#define  ADC_SQR3_SQ1_0                      ((uint32_t)0x00000001)        /*!<Bit 0 */
#define  ADC_SQR3_SQ1_1                      ((uint32_t)0x00000002)        /*!<Bit 1 */
#define  ADC_SQR3_SQ1_2                      ((uint32_t)0x00000004)        /*!<Bit 2 */
#define  ADC_SQR3_SQ1_3                      ((uint32_t)0x00000008)        /*!<Bit 3 */
#define  ADC_SQR3_SQ1_4                      ((uint32_t)0x00000010)        /*!<Bit 4 */
#define  ADC_SQR3_SQ2                        ((uint32_t)0x000003E0)        /*!<SQ2[4:0] bits (2nd conversion in regular sequence) */
#define  ADC_SQR3_SQ2_0                      ((uint32_t)0x00000020)        /*!<Bit 0 */
#define  ADC_SQR3_SQ2_1                      ((uint32_t)0x00000040)        /*!<Bit 1 */
#define  ADC_SQR3_SQ2_2                      ((uint32_t)0x00000080)        /*!<Bit 2 */
#define  ADC_SQR3_SQ2_3                      ((uint32_t)0x00000100)        /*!<Bit 3 */
#define  ADC_SQR3_SQ2_4                      ((uint32_t)0x00000200)        /*!<Bit 4 */
#define  ADC_SQR3_SQ3                        ((uint32_t)0x00007C00)        /*!<SQ3[4:0] bits (3rd conversion in regular sequence) */
#define  ADC_SQR3_SQ3_0                      ((uint32_t)0x00000400)        /*!<Bit 0 */
#define  ADC_SQR3_SQ3_1                      ((uint32_t)0x00000800)        /*!<Bit 1 */
#define  ADC_SQR3_SQ3_2                      ((uint32_t)0x00001000)        /*!<Bit 2 */
#define  ADC_SQR3_SQ3_3                      ((uint32_t)0x00002000)        /*!<Bit 3 */
#define  ADC_SQR3_SQ3_4                      ((uint32_t)0x00004000)        /*!<Bit 4 */
#define  ADC_SQR3_SQ4                        ((uint32_t)0x000F8000)        /*!<SQ4[4:0] bits (4th conversion in regular sequence) */
#define  ADC_SQR3_SQ4_0                      ((uint32_t)0x00008000)        /*!<Bit 0 */
#define  ADC_SQR3_SQ4_1                      ((uint32_t)0x00010000)        /*!<Bit 1 */
#define  ADC_SQR3_SQ4_2                      ((uint32_t)0x00020000)        /*!<Bit 2 */
#define  ADC_SQR3_SQ4_3                      ((uint32_t)0x00040000)        /*!<Bit 3 */
#define  ADC_SQR3_SQ4_4                      ((uint32_t)0x00080000)        /*!<Bit 4 */
#define  ADC_SQR3_SQ5                        ((uint32_t)0x01F00000)        /*!<SQ5[4:0] bits (5th conversion in regular sequence) */
#define  ADC_SQR3_SQ5_0                      ((uint32_t)0x00100000)        /*!<Bit 0 */
#define  ADC_SQR3_SQ5_1                      ((uint32_t)0x00200000)        /*!<Bit 1 */
#define  ADC_SQR3_SQ5_2                      ((uint32_t)0x00400000)        /*!<Bit 2 */
#define  ADC_SQR3_SQ5_3                      ((uint32_t)0x00800000)        /*!<Bit 3 */
#define  ADC_SQR3_SQ5_4                      ((uint32_t)0x01000000)        /*!<Bit 4 */
#define  ADC_SQR3_SQ6                        ((uint32_t)0x3E000000)        /*!<SQ6[4:0] bits (6th conversion in regular sequence) */
#define  ADC_SQR3_SQ6_0                      ((uint32_t)0x02000000)        /*!<Bit 0 */
#define  ADC_SQR3_SQ6_1                      ((uint32_t)0x04000000)        /*!<Bit 1 */
#define  ADC_SQR3_SQ6_2                      ((uint32_t)0x08000000)        /*!<Bit 2 */
#define  ADC_SQR3_SQ6_3                      ((uint32_t)0x10000000)        /*!<Bit 3 */
#define  ADC_SQR3_SQ6_4                      ((uint32_t)0x20000000)        /*!<Bit 4 */

/*******************  Bit definition for ADC_JSQR register  *******************/
#define  ADC_JSQR_JSQ1                       ((uint32_t)0x0000001F)        /*!<JSQ1[4:0] bits (1st conversion in injected sequence) */
#define  ADC_JSQR_JSQ1_0                     ((uint32_t)0x00000001)        /*!<Bit 0 */
#define  ADC_JSQR_JSQ1_1                     ((uint32_t)0x00000002)        /*!<Bit 1 */
#define  ADC_JSQR_JSQ1_2                     ((uint32_t)0x00000004)        /*!<Bit 2 */
#define  ADC_JSQR_JSQ1_3                     ((uint32_t)0x00000008)        /*!<Bit 3 */
#define  ADC_JSQR_JSQ1_4                     ((uint32_t)0x00000010)        /*!<Bit 4 */
#define  ADC_JSQR_JSQ2                       ((uint32_t)0x000003E0)        /*!<JSQ2[4:0] bits (2nd conversion in injected sequence) */
#define  ADC_JSQR_JSQ2_0                     ((uint32_t)0x00000020)        /*!<Bit 0 */
#define  ADC_JSQR_JSQ2_1                     ((uint32_t)0x00000040)        /*!<Bit 1 */
#define  ADC_JSQR_JSQ2_2                     ((uint32_t)0x00000080)        /*!<Bit 2 */
#define  ADC_JSQR_JSQ2_3                     ((uint32_t)0x00000100)        /*!<Bit 3 */
#define  ADC_JSQR_JSQ2_4                     ((uint32_t)0x00000200)        /*!<Bit 4 */
#define  ADC_JSQR_JSQ3                       ((uint32_t)0x00007C00)        /*!<JSQ3[4:0] bits (3rd conversion in injected sequence) */
#define  ADC_JSQR_JSQ3_0                     ((uint32_t)0x00000400)        /*!<Bit 0 */
#define  ADC_JSQR_JSQ3_1                     ((uint32_t)0x00000800)        /*!<Bit 1 */
#define  ADC_JSQR_JSQ3_2                     ((uint32_t)0x00001000)        /*!<Bit 2 */
#define  ADC_JSQR_JSQ3_3                     ((uint32_t)0x00002000)        /*!<Bit 3 */
#define  ADC_JSQR_JSQ3_4                     ((uint32_t)0x00004000)        /*!<Bit 4 */
#define  ADC_JSQR_JSQ4                       ((uint32_t)0x000F8000)        /*!<JSQ4[4:0] bits (4th conversion in injected sequence) */
#define  ADC_JSQR_JSQ4_0                     ((uint32_t)0x00008000)        /*!<Bit 0 */
#define  ADC_JSQR_JSQ4_1                     ((uint32_t)0x00010000)        /*!<Bit 1 */
#define  ADC_JSQR_JSQ4_2                     ((uint32_t)0x00020000)        /*!<Bit 2 */
#define  ADC_JSQR_JSQ4_3                     ((uint32_t)0x00040000)        /*!<Bit 3 */
#define  ADC_JSQR_JSQ4_4                     ((uint32_t)0x00080000)        /*!<Bit 4 */
#define  ADC_JSQR_JL                         ((uint32_t)0x00300000)        /*!<JL[1:0] bits (Injected Sequence length) */
#define  ADC_JSQR_JL_0                       ((uint32_t)0x00100000)        /*!<Bit 0 */
#define  ADC_JSQR_JL_1                       ((uint32_t)0x00200000)        /*!<Bit 1 */

/*******************  Bit definition for ADC_JDR1 register  *******************/
#define  ADC_JDR1_JDATA                      ((uint32_t)0xFFFF)            /*!<Injected data */

/*******************  Bit definition for ADC_JDR2 register  *******************/
#define  ADC_JDR2_JDATA                      ((uint32_t)0xFFFF)            /*!<Injected data */

/*******************  Bit definition for ADC_JDR3 register  *******************/
#define  ADC_JDR3_JDATA                      ((uint32_t)0xFFFF)            /*!<Injected data */

/*******************  Bit definition for ADC_JDR4 register  *******************/
#define  ADC_JDR4_JDATA                      ((uint32_t)0xFFFF)            /*!<Injected data */

/********************  Bit definition for ADC_DR register  ********************/
#define  ADC_DR_DATA                         ((uint32_t)0x0000FFFF)        /*!<Regular data */
#define  ADC_DR_ADC2DATA                     ((uint32_t)0xFFFF0000)        /*!<ADC2 data */

/*******************  Bit definition for ADC_CSR register  ********************/
#define  ADC_CSR_AWD1                        ((uint32_t)0x00000001)        /*!<ADC1 Analog watchdog flag */
#define  ADC_CSR_EOC1                        ((uint32_t)0x00000002)        /*!<ADC1 End of conversion */
#define  ADC_CSR_JEOC1                       ((uint32_t)0x00000004)        /*!<ADC1 Injected channel end of conversion */
#define  ADC_CSR_JSTRT1                      ((uint32_t)0x00000008)        /*!<ADC1 Injected channel Start flag */
#define  ADC_CSR_STRT1                       ((uint32_t)0x00000010)        /*!<ADC1 Regular channel Start flag */
#define  ADC_CSR_DOVR1                       ((uint32_t)0x00000020)        /*!<ADC1 DMA overrun  flag */
#define  ADC_CSR_AWD2                        ((uint32_t)0x00000100)        /*!<ADC2 Analog watchdog flag */
#define  ADC_CSR_EOC2                        ((uint32_t)0x00000200)        /*!<ADC2 End of conversion */
#define  ADC_CSR_JEOC2                       ((uint32_t)0x00000400)        /*!<ADC2 Injected channel end of conversion */
#define  ADC_CSR_JSTRT2                      ((uint32_t)0x00000800)        /*!<ADC2 Injected channel Start flag */
#define  ADC_CSR_STRT2                       ((uint32_t)0x00001000)        /*!<ADC2 Regular channel Start flag */
#define  ADC_CSR_DOVR2                       ((uint32_t)0x00002000)        /*!<ADC2 DMA overrun  flag */
#define  ADC_CSR_AWD3                        ((uint32_t)0x00010000)        /*!<ADC3 Analog watchdog flag */
#define  ADC_CSR_EOC3                        ((uint32_t)0x00020000)        /*!<ADC3 End of conversion */
#define  ADC_CSR_JEOC3                       ((uint32_t)0x00040000)        /*!<ADC3 Injected channel end of conversion */
#define  ADC_CSR_JSTRT3                      ((uint32_t)0x00080000)        /*!<ADC3 Injected channel Start flag */
#define  ADC_CSR_STRT3                       ((uint32_t)0x00100000)        /*!<ADC3 Regular channel Start flag */
#define  ADC_CSR_DOVR3                       ((uint32_t)0x00200000)        /*!<ADC3 DMA overrun  flag */

/*******************  Bit definition for ADC_CCR register  ********************/
#define  ADC_CCR_MULTI                       ((uint32_t)0x0000001F)        /*!<MULTI[4:0] bits (Multi-ADC mode selection) */
#define  ADC_CCR_MULTI_0                     ((uint32_t)0x00000001)        /*!<Bit 0 */
#define  ADC_CCR_MULTI_1                     ((uint32_t)0x00000002)        /*!<Bit 1 */
#define  ADC_CCR_MULTI_2                     ((uint32_t)0x00000004)        /*!<Bit 2 */
#define  ADC_CCR_MULTI_3                     ((uint32_t)0x00000008)        /*!<Bit 3 */
#define  ADC_CCR_MULTI_4                     ((uint32_t)0x00000010)        /*!<Bit 4 */
#define  ADC_CCR_DELAY                       ((uint32_t)0x00000F00)        /*!<DELAY[3:0] bits (Delay between 2 sampling phases) */
#define  ADC_CCR_DELAY_0                     ((uint32_t)0x00000100)        /*!<Bit 0 */
#define  ADC_CCR_DELAY_1                     ((uint32_t)0x00000200)        /*!<Bit 1 */
#define  ADC_CCR_DELAY_2                     ((uint32_t)0x00000400)        /*!<Bit 2 */
#define  ADC_CCR_DELAY_3                     ((uint32_t)0x00000800)        /*!<Bit 3 */
#define  ADC_CCR_DDS                         ((uint32_t)0x00002000)        /*!<DMA disable selection (Multi-ADC mode) */
#define  ADC_CCR_DMA                         ((uint32_t)0x0000C000)        /*!<DMA[1:0] bits (Direct Memory Access mode for multimode) */
#define  ADC_CCR_DMA_0                       ((uint32_t)0x00004000)        /*!<Bit 0 */
#define  ADC_CCR_DMA_1                       ((uint32_t)0x00008000)        /*!<Bit 1 */
#define  ADC_CCR_ADCPRE                      ((uint32_t)0x00030000)        /*!<ADCPRE[1:0] bits (ADC prescaler) */
#define  ADC_CCR_ADCPRE_0                    ((uint32_t)0x00010000)        /*!<Bit 0 */
#define  ADC_CCR_ADCPRE_1                    ((uint32_t)0x00020000)        /*!<Bit 1 */
#define  ADC_CCR_VBATE                       ((uint32_t)0x00400000)        /*!<VBAT Enable */
#define  ADC_CCR_TSVREFE                     ((uint32_t)0x00800000)        /*!<Temperature Sensor and VREFINT Enable */

/*******************  Bit definition for ADC_CDR register  ********************/
#define  ADC_CDR_DATA1                      ((uint32_t)0x0000FFFF)         /*!<1st data of a pair of regular conversions */
#define  ADC_CDR_DATA2                      ((uint32_t)0xFFFF0000)         /*!<2nd data of a pair of regular conversions */

#endif /* ADC_ZEBALA_H_ */
