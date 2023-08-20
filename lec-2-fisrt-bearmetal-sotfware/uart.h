#include<stdio.h>
#ifndef  _UART_H
#define  _UART_H

#define UART0D  *( (volatile unsigned int *)( (unsigned int *)0x101f1000) ) 
void SET_STRING (unsigned char *p_tx_string);
 
#endif 