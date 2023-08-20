ENTRY(reset)
MEMORY
{
Mem (rwx): ORIGIN = 0x00000000 , LENGTH = 64M 
}
SECTIONS
{
  . = 0x10000; 

  .startup . : 
  {
   startup.o(.text) 
  }> Mem

  .data :
  {
   *(.data)
  }> Mem

 .rodata : 
 { 
  *(.rodata)
 }> Mem

 .bss :
 {
  *(.bss) 
 }> Mem 

  .text :
   {
    *(.text)
   }> Mem 

 . = . + 0x1000; 
 stack_top = . ; 

}