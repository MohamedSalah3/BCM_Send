/*
 * BCM_Send.c
 *
 * Created: 03/03/2020 11:29:17 ص
 *  Author: mo
 */
 #include "BCM_Send.h"
 volatile uint8_t u8_DATA='T';
int main(void)
{
	gpioPinDirection(GPIOB,BIT3,OUTPUT);
	Uart_Init(Baud9600,OneStopBit,NoParity,EightBits,ASynchronous);
	Enable_communication_interrupt();
	SPI_Init();
	Led_On(LED_0);
	//Uart_tryansmitfirstbyte(data_signature);
  //u8_DATA=UDR;
	SPDR=u8_DATA;
  //Uart_tryansmitfirstbyte(u8_DATA);

    while(1)
    {

        //TODO:: Please write your application code
    }
}
