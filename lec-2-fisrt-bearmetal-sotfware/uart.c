#include<stdio.h>
#include"uart.h"

int learn_in; 
void SET_STRING (unsigned char*p_tx_string)
{

while(*p_tx_string !='\0')
   {
   UART0D=(unsigned int )*p_tx_string; 
   p_tx_string++; 
   }

}