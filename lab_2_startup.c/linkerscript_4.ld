/*
 * Linker Script for My Project
 * Created on 7/9/2023 by Hady Ayman Eldeeb
 */
ENTRY(vectors)

MEMORY
{   
    ROM (RX) : ORIGIN = 0x08000000, LENGTH = 128K     /* Define ROM memory region */
    RAM (RWX) : ORIGIN = 0x20000000, LENGTH = 20K   /* Define RAM memory region */
}

SECTIONS
{
    .text :
    {
        *(.vectors*)      /* Copy vector section from input files */
        *(.text*)        /* Copy code sections from input files */
        *(.rodata*)     /* Copy read-only data sections from input files */
        _E_text = .;   /* Set the address in ROM after loading these sections */
    }> ROM

    .data :
    {
        _S_DATA = .;     /* Set the start address of the data section */
        *(.data*) 		
        _E_DATA = .;     /* Set the end address of the data section */
    }> RAM	AT>	ROM  

    .bss :
    {
        _S_BSS = .;      /* Set the start address of the BSS section */
        *(.bss*)                      		
        _E_BSS = .;      /* Set the end address of the BSS section */
        . = . + 0x1000; 
        _stack_top = .;
    }> RAM 
}
