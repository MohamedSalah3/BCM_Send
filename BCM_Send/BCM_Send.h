/*
 * BCM_Send.h
 *
 * Created: 04/03/2020 04:39:01 م
 *  Author: mo
 */


#ifndef BCM_SEND_H_
#define BCM_SEND_H_
#include "BCM_Config.h"


EnmBCMError_t BCM_Init (const BCM_ConfigType * ConfigPtr );
/*Intialize SPI....intialize UART*/
EnmBCMError_t BCM_DeInit ( void );
/*
BCM_TxDispatch();

BCM_Send();

*/

#endif /* BCM_SEND_H_ */
