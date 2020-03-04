/*
 * uart.c
 *
 * Created: 10/02/2020 08:02:23 م
 *  Author: mo
 */
#include "led.h"
#include "ledConfig.h"
#include "uartconfig.h"
#include "uart.h"
#include "registers.h"
#define Buffer_Size  10
volatile uint8_t u8_Notification_TX=0;
volatile uint8_t gU8_Data_Recieved=0;
volatile uint8_t gU8_Data_transmited=0;
uint8_t BufferRequested[Buffer_Size];
volatile uint8_t u8_index=0;
volatile uint8_t buf_is_full=0;
void Uart_Init(En_BAUD_Rate Baud_rate,En_Stop_config Stop_bits_num,
  EN_Parity parity_Bit,EN_Data_Size data_num_bits,EN_UartMode uart_mode)
{uint8_t Buffer=0;
switch (Baud_rate) {
  case Baud9600:
  UBRRL=Baud9600;
  break;
  case Baud14400:
  UBRRL=Baud14400;
  break;
  case Baud19200:
  UBRRL=Baud19200;
  break;
  case Baud38400:
  UBRRL=Baud38400;
  break;
}
switch (Stop_bits_num) {
case OneStopBit:
{ SET_BIT(Buffer,URSEL);
  CLEAR_BIT(Buffer,USBS);
  break;
}
case TwoStopBits:
{
  SET_BIT(Buffer,URSEL);
  SET_BIT(Buffer,USBS);
  break;
}
}
switch (data_num_bits)
{
case FiveBits:
{
SET_BIT(Buffer,URSEL);
CLEAR_BIT(Buffer,UCSZ0);
CLEAR_BIT(Buffer,UCSZ1);
CLEAR_BIT(UCSRB,UCSZ2);
break;
}
case SexBits:
{
  SET_BIT(Buffer,URSEL);
  SET_BIT(Buffer,UCSZ0);
  CLEAR_BIT(Buffer,UCSZ1);
  CLEAR_BIT(UCSRB,UCSZ2);
  break;
}
case SevenBits:
{
  SET_BIT(Buffer,URSEL);
  CLEAR_BIT(Buffer,UCSZ0);
  SET_BIT(Buffer,UCSZ1);
  CLEAR_BIT(UCSRB,UCSZ2);
  break;
}
case EightBits:
{   SET_BIT(Buffer,URSEL);
    SET_BIT(Buffer,UCSZ0);
    SET_BIT(Buffer,UCSZ1);
    CLEAR_BIT(UCSRB,UCSZ2);
break;
}

case NineBits:
{   SET_BIT(Buffer,URSEL);
	SET_BIT(Buffer,UCSZ0);
	SET_BIT(Buffer,UCSZ1);
	SET_BIT(UCSRB,UCSZ2);
	break;
}

}

switch (uart_mode) {
  case ASynchronous:
  {
  SET_BIT(Buffer,URSEL);
  CLEAR_BIT(Buffer,UMSEL);
  break;
  }
case Synchronous:
{
  SET_BIT(Buffer,URSEL);
  SET_BIT(Buffer,UMSEL);
  break;
}
}
switch (parity_Bit) {
  case NoParity:
{
SET_BIT(Buffer,URSEL);
CLEAR_BIT(Buffer,UPM0);
CLEAR_BIT(Buffer,UPM1);
  break;
}
case EvenParity:
{
SET_BIT(Buffer,URSEL);
CLEAR_BIT(Buffer,UPM0);
SET_BIT(Buffer,UPM1);
break;
}
case OddParity:
{
SET_BIT(Buffer,URSEL);
SET_BIT(Buffer,UPM1);
SET_BIT(Buffer,UPM0);
break;
}


}

UCSRC=Buffer;
SET_BIT(UCSRB,TXEN);/*TXEN*/
SET_BIT(UCSRB,RXEN);/*RXEN*/
}
void UartTransmitPooling(uint8_t Data)
{
while( !( UCSRA & (1<<UDRE)));
UDR=Data;
}
uint8_t UartRecievePooling(void)
{
	uint8_t data=0;
while (!( UCSRA & (1 << RXC)));/* Wait until new data receive*/
data=UDR;
return data;									/* Get and return received data */
}


void Enable_communication_interrupt(void)
{
G_interrupt_Enable();
SET_BIT(UCSRB,RXCIE);
SET_BIT(UCSRB,TXCIE);
SET_BIT(SPCR,SPIE);
}
void UartRecieveInterrupt(void)
{
/*The mechanism to access array*/
// BufferRequested[u16_index]=gU8_Data_Recieved;
//  if (u16_index < Buffer_Size){
//  u16_index++;
//  buf_is_full=0;
//  }
//  else{
//  buf_is_full=1;
//  u16_index=0;
//      }
if(u8_index<Buffer_Size)
{
  gU8_Data_Recieved=UDR;
  BufferRequested[u8_index]=gU8_Data_Recieved;
  u8_index++;
}
  else{
    u8_index=0;
      }
}
void UartTransmitInterrupt(void)
{
/*When void Uart_tryansmitfirstbyte(uint8_t data) sends first byte before while(1) we start here sendine the next bytes
gU8_Data_transmited is shared with void UartTransmitdataInt(uint8_t data_to_transmit)
that changes its data
*//*
gU8_Data_transmited=BufferRequested[u8_index];
UDR = gU8_Data_transmited;
 if (u8_index < Buffer_Size)
 {
 u8_index++;
 buf_is_full=0;
 }
 else
  {
 buf_is_full=1;
 u8_index=0;
     }
u8_Notification_TX=TRUE;
*/
UDR = gU8_Data_transmited;
}
void UartTransmitdataInt(uint8_t data_to_transmit)
{

	  gU8_Data_transmited=data_to_transmit;

}

void Uart_tryansmitfirstbyte(uint8_t data)
{
UDR=data;
}
uint8_t Uart_recievefirstbyte(void)
{
uint8_t data=0;
data = UDR;
return data;
}
