/*
 * BCM_Config.h
 *
 * Created: 04/03/2020 04:38:32 م
 *  Author: mo
 */


#ifndef BCM_CONFIG_H_
#define BCM_CONFIG_H_
#include "SPI.h"
#include "uart.h"
#include "Interrupts.h"
#include "timers.h"
/*u8_channel_Protcol*/
#define UART  0
#define  SPI  1
#define I2C 2
/*u8_BCM_ID*/
#define TASK1_ID A
#define TASK2_ID  B
#define TASK3_ID  C
/************************************************************/
/*            ERROR_STATUS      */
typedef uint8_t ERROR_STATUS;
/*************************************************************/
/* u8_data_Lenght*/
typedef struct ST_BCM_ConfigType
{
uint8_t u8_channel_Protcol;
uint8_t u8_BCM_ID;
uint8_t u8_data_Lenght;
}BCM_ConfigType;


#endif /* BCM_CONFIG_H_ */
