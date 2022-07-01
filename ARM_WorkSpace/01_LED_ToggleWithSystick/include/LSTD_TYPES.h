/*******************************************************************************************************/
/* Author            : Ahmed khaled Hammad                                                             */
/* Version           : V0.0.0                                                                          */
/* Data              : 23 May 2022                                                                     */
/* Description       : LSTD_TYPES.h                                                                    */
/*******************************************************************************************************/


/*******************************************************************************************************/
/*                               guard of file will call on time in .c		                           */       
/********************************************************************************************************/
#ifndef STD_TYPES_H_
#define STD_TYPES_H_

/*******************************************************************************************************/
/*                                           BOOLEAN VALUES	     	                                   */       
/********************************************************************************************************/
		
		
#ifndef		FALSE
#define		FALSE   (0u)
#endif
	
#ifndef		TRUE
#define		TRUE   (1u)
#endif
	
	
	
typedef unsigned char					    u8	  ;						
typedef unsigned short int			        u16	  ;					
typedef unsigned long  int			        u32	  ;					
typedef signed char					        s8	  ;							
typedef signed short int				    s16	  ;						
typedef signed long  int				    s32	  ;						
typedef unsigned long long int				u64   ;
typedef signed long long int				s64   ;
typedef float						        f32	  ;
typedef double						        f64	  ;


#define NULL  		(void*)0


#endif /* STD_TYPES_H_ */
