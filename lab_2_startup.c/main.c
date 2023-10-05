#include<stdio.h>
#include"Typedef_plart_form.h"

#define RCC_BASE   0x4002100
#define GPIO_BASE  0x4001800

#define RCC_AB2ENR  (*((volatile uint32*) RCC_BASE + 0x18))
#define GPIO_CRH    (*((volatile uint32*) GPIO_BASE + 0x04))
#define GPIO_ODR    (*((volatile uint32*) GPIO_BASE + 0x0c))

volatile unsigned int   x_0 [20] ={ 1 , 2 , 3 } ; // .Data section 
volatile const  unsigned int  x_1 [30]= {1 , 2 , 3 }; // .Bss  section 
volatile unsigned int   a =0 , b =0; 
int main(void)
{

RCC_AB2ENR|=(1<<2);           // Enable clock
for(a = 0 ; a < 2000 ; a++);    // delay  
GPIO_CRH &= 0xff0fffff;     //Enable output from 20 to 24 = 0   clear
GPIO_CRH |= 0x00200000;    //Enable by  or with 2

while(1)
{
	GPIO_ODR |= (1<<13); //set pin
	for ( a =0 ; a<2000000 ; a++);
	GPIO_ODR &= ~(1<<13);  // clear pin
	for ( b =0 ; b<2000000 ; b++);
}
	return 0;
}

