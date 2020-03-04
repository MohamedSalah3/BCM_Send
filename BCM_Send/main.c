/*
 * BCM_Send.c
 *
 * Created: 03/03/2020 11:29:17 ص
 *  Author: mo
 */

 #include "BCM_Send.h"
extern volatile uint8_t data_sent;
int main(void)
{uint8_t data_signature='M';
	uint8_t flag=0;
	gpioPinDirection(GPIOB,BIT3,OUTPUT);
	timer2Init(T2_NORMAL_MODE,T2_OC2_DIS,T2_PRESCALER_NO,0,0,0,T2_POLLING);
	Uart_Init(Baud9600,OneStopBit,NoParity,EightBits,ASynchronous);
	Enable_communication_interrupt();
	SPI_Init();
	Led_On(LED_0);
	Uart_tryansmitfirstbyte(data_signature);
	SPI_Send(data_sent);
    while(1)
    {

        //TODO:: Please write your application code
    }
}
