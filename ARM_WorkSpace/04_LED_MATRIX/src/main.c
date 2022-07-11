
#include "LSTD_TYPES.h"

#include "MRCC_interface.h"
#include "MGPIO_interface.h"

#include "HLED_MATRIX_Interface.h"

u8 DataArray[8] ={0,124,18,18,18,124,0,0};
int main(void)
{
	/*System Clock is 16MHz from HSI*/
	MRCC_voidInitSystemClk();

	/*Enable GPIO Peripheral clock*/
	MRCC_voidEnablePeripheralClock(AHB1,_PERIPHERAL_EN_GPIOA ) ;
	MRCC_voidEnablePeripheralClock(AHB1,_PERIPHERAL_EN_GPIOB ) ;

	/*Initialize LED Matrix*/
	HLEDMAT_voidInit();


	/*Send Data To lED Matrix*/

	HLEDMAT_voidDisplayFrame(DataArray);


	/* Loop forever */
	while(1)
	{
	}
}
















