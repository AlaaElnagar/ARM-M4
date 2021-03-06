/*
 * HLED_MATRIX_Config.h
 *
 *  Created on: Jul 11, 2022
 *      Author: Ahmed Khaled Hammad
 */

#ifndef HLED_MATRIX_CONFIG_H_
#define HLED_MATRIX_CONFIG_H_

/*Please write pin pair PORT,PIN */

#define HLEDMAT_ROW_0      _GPIOA_PORT,0
#define HLEDMAT_ROW_1      _GPIOA_PORT,1
#define HLEDMAT_ROW_2      _GPIOA_PORT,2
#define HLEDMAT_ROW_3      _GPIOA_PORT,3
#define HLEDMAT_ROW_4      _GPIOA_PORT,4
#define HLEDMAT_ROW_5      _GPIOA_PORT,5
#define HLEDMAT_ROW_6      _GPIOA_PORT,6
#define HLEDMAT_ROW_7      _GPIOA_PORT,7

/*Please write pin pair PORT,PIN */

#define HLEDMAT_COL_0      _GPIOB_PORT,0
#define HLEDMAT_COL_1      _GPIOB_PORT,1
#define HLEDMAT_COL_2      _GPIOB_PORT,5
#define HLEDMAT_COL_3      _GPIOB_PORT,6  // 3 for jtag
#define HLEDMAT_COL_4      _GPIOB_PORT,7  // 4 for jtag
#define HLEDMAT_COL_5      _GPIOB_PORT,8
#define HLEDMAT_COL_6      _GPIOB_PORT,9
#define HLEDMAT_COL_7      _GPIOB_PORT,10


#endif /* HLED_MATRIX_CONFIG_H_ */
