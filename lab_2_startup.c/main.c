#include<stdio.h>
#include"Typedef_plart_form.h"
#define RCC_BASE   0x4002100
#define GPIO_BASE  0x4000800

#define RCC_AB2ENR  *(volatile uint32*)(RCC_BASE + 0x18)
#define GPIO_CRH    *(volatile uint32*)(GPIO_BASE + 0x04)
#define GPIO_ODR    *(volatile uint32*)(GPIO_BASE + 0x0c)

uint32  x_0 [3] ={ 1 , 2 , 3 } ; // .Data section 
volatile const  double x_1 [3]= {1 , 2 , 3 }; // .Bss  section 
volatile uint8  a =0 , b =0 ; 
int main(void)
{

RCC_AB2ENR|=(1<<2);        // Enable clock
GPIO_CRH &= 0xff0fffff;   //Enable output from 20 to 24 = 0   clear
GPIO_CRH |= 0x00200000;   //Enable by  or with 2

while(1)
{
	GPIO_ODR |= (1<<13); //set pin
	for ( a =0 ; a<1000 ; a++);
	GPIO_ODR &= ~(1<<13);  // clear pin
	for ( b =0 ; b<1000 ; b++);
}
	return 0;
}
