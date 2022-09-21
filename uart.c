#include "uart.h"
#define SET_BIT(REG, BIT_NO)     REG|=(1<<BIT_NO)
#define CLEAR_BIT(REG, BIT_NO)   REG&=~(1<<BIT_NO)
#define TOGGLE_BIT(REG, BIT_NO)  REG^=(1<<BIT_NO)
#define GET_BIT(REG, BIT_NO)     ((REG>>BIT_NO)&1)

/*
 * baudrate: is an input argument that describes baudrate that the UART needs to make the communications.
 */
 void SWUART_init(uint32_t baudrate)
 {
   uint8_t UCSRC_value=0b10000110;     /*Selects the character size to be 8-bit*/
   UCSRC=UCSRC_value;
   UBRRL=F_CPU/16/baudrate-1;        
 }

/*
 * data: is an input argument that describes a byte of data to be send over the SW UART.
 */
 void SWUART_send(uint8_t data)
 {
   if(data=='\n') SWUART_send('\r');
   while(GET_BIT(UCSRA, UCSRA_UDRE)==0);     /* Wait until the USART Data register is Empty*/
   UDR=data; 
 }
 
 /*
 * data: is an output argument that describes a byte of data to be recieved by the SW UART.
 */
 void SWUART_recieve(uint8_t *data)
 {
   while(GET_BIT(UCSRA, UCSRA_RXC)==0);      /* Busy Waiting: Wait until the receiving is complete*/
   *data= UDR; 
 }

