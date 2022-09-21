#ifndef _UART_H_
#define _UART_H_

#define HW_REG8(x) *((volatile uint8_t*) x)

#define  UDR             HW_REG8(0x2c)

 /**
 * @brief USART Control and Status Register A
 */
#define  UCSRA           HW_REG8(0x2b)

#define  UCSRA_MPCM  0   
#define  UCSRA_U2X   1
#define  UCSRA_PE    2
#define  UCSRA_DOR   3
#define  UCSRA_FE    4

/** @brief USART Data Register Empty */
#define  UCSRA_UDRE  5 

/** @brief USART Transmit Complete */
#define  UCSRA_TXC   6

/** @brief USART Receive complete */
#define  UCSRA_RXC   7   


#define  UCSRB           HW_REG8(0x2a)

#define  UCSRB_TXB8   0
#define  UCSRB_RXB8   1
#define  UCSRB_UCSZ2  2
#define  UCSRB_TXEN   3
#define  UCSRB_RXEN   4
#define  UCSRB_UDRIE  5
#define  UCSRB_TXCIE  6
#define  UCSRB_RXCIE  7


#define  UCSRC           HW_REG8(0x40)

#define  UCSRC_UCPOL  0
#define  UCSRC_UCSZ0  1
#define  UCSRC_UCSZ1  2
#define  UCSRC_USBS   3
#define  UCSRC_UPM0   4
#define  UCSRC_UPM1   5
#define  UCSRC_UMSEL  6
#define  UCSRC_URSEL  7

 /**
 * @brief USART Baud Rate Register (Higher Byte)
 * @note The `UBRRH` register share the same I/O memory location as the `UCSRC` register 
 */
#define  UBRRH           HW_REG8(0x40)
 /**
 * @brief USART Baud Rate Register (Lower Byte)
 */
#define  UBRRL           HW_REG8(0x29)



typedef unsigned int uint16_t;
typedef unsigned long int uint32_t;
typedef unsigned char uint8_t; 


/*
 * baudrate: is an input argument that describes baudrate that the UART needs to make the communications.
 */
 void SWUART_init(uint32_t baudrate);

/*
 * data: is an input argument that describes a byte of data to be send over the SW UART.
 */
 void SWUART_send(uint8_t data);
 
 /*
 * data: is an output argument that describes a byte of data to be recieved by the SW UART.
 */
 void SWUART_recieve(uint8_t *data);

#endif /* _UART_H_ */
