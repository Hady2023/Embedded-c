#include <stdio.h>
#include "uart.h"

const char string_input_user [100] = "Learn-in-depth:Hadyayman"; // Iwill viwe in (.rodata) in ROM  
char Buffer_2 [100];  // I will viwe in (.bss) section  at run time in RAM  
int main(void)     // will viwe in  (.text)  in ROM
{

SET_STRING(string_input_user); 

return 0; 
}
