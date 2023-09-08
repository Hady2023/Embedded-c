/*
Done by:Hady ayman Eldeeb 
DATE: 7/9/2023 
1:define array of unsigned int to EQ to .word in assemply language and use __attribute__ to define all element in vector section
2: In element define stack top to define Limits which is 0x20001000 
   
*/
#include <stdio.h>
#include "Typedef_plart_form.h"

unsigned int i =0 , j =0; 
// Prototype

extern unsigned int _stack_top;
extern int main(void);
void Default_Handler(void);
void Reset_Handler(void);
void HF_Handler(void) __attribute__((weak, alias ("Default_Handler")));;
void BUS_Handler(void) __attribute__((weak, alias ("Default_Handler")));;

/* Create a vector section with an array of uint32 EQ to .word that is aligned to 4 bytes in each section */
uint32 vector[] __attribute__((section(".vectors"))) = {
    (uint32) &_stack_top,
    (uint32) &Reset_Handler,
    (uint32) &HF_Handler, 
	(uint32) &BUS_Handler
};
 	
void Default_Handler(void)
{
    Reset_Handler();
}

extern uint32 _E_text;
extern uint32 _S_DATA;
extern uint32 _E_DATA;
extern uint32 _S_BSS;
extern uint32 _E_BSS;
void Reset_Handler(void)
{


	uint32 Data_Size = (uint32*)&_E_DATA - (uint32*)&_S_DATA;

unsigned char *p_start = (unsigned char *)&_E_text;
unsigned char *p_END = (unsigned char *)&_S_DATA;

// Copy data from ROM (LOAD ADDRESS MEMORY) to RAM (VIRTUAL ADDRESS MEMORY)
for (i = 0; i < Data_Size; i++)
{
    *((unsigned char*)p_END++) = *((unsigned char*)p_start++);
}

// Copy .BSS section
uint32 BSS_Size = (uint32*)&_E_BSS - (uint32*)&_S_BSS;

p_start = (unsigned char *)&_S_BSS;
p_END =   (unsigned char *) &_E_BSS;

for ( j = 0; j < BSS_Size; j++)
{
    *((unsigned char*)p_start++) = (unsigned char)0;
}
//Jump in main()
    main();
}
