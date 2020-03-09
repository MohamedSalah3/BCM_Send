/*
 * BCM_Send.c
 *
 * Created: 03/03/2020 11:29:17 ص
 *  Author: mo
 */
 #include "BCM_Send.h"
#define BUFFER_SIZE 255
uint8_t size=BUFFER_SIZE;
 volatile uint8_t u8_DATA='T';
uint8_t Buffer_Array[BUFFER_SIZE];
int main(void)
{
  /*
	gpioPinDirection(GPIOB,BIT3,OUTPUT);
	Uart_Init(Baud9600,OneStopBit,NoParity,EightBits,ASynchronous);
	Enable_communication_interrupt();
	SPI_Init();
*/
BCM_Init (&BCM_Configuration);
/*	SPDR=u8_DATA;*/
BCM_Send(UARTANDSPI,'M',250,4);



    while(1)
    {

        //TODO:: Please write your application code
    }
}
