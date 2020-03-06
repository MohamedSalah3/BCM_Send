/*
 * BCM_Send.h
 *
 * Created: 04/03/2020 04:39:01 م
 *  Author: mo
 */


#ifndef BCM_SEND_H_
#define BCM_SEND_H_
#include "BCM_Config.h"

ERROR_STATUS BCM_Init (const BCM_ConfigType * ConfigPtr );

ERROR_STATUS BCM_DeInit (const BCM_ConfigType * ConfigPtr);

ERROR_STATUS BCM_TxDispatcher(void);

ERROR_STATUS BCM_Send(void);

#endif /* BCM_SEND_H_ */
