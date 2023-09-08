/*
 * Linker Script for My Project
 * Created on 7/9/2023 by Hady Ayman Eldeeb
 */
ENTRY(vector)  /* Entry point of the program */

MEMORY
{   
    ROM (RX) : ORIGIN = 0x08000000, LENGTH = 128K  /* Define ROM memory region */
    RAM (RWX) : ORIGIN = 0x20000000, LENGTH = 20K   /* Define RAM memory region */
}

SECTIONS
{
    .text :
    {
        *(.vectors*)      /* Copy vector section from input files */
        *(.text*)        /* Copy code sections from input files */
        *(.rodata*)      /* Copy read-only data sections from input files */
        _E_text = .;     /* Set the address in ROM after loading these sections */
    }> ROM

    .data :
    {
        _S_DATA = .;     /* Set the start address of the data section */
        *(.data*)        /* Copy initialized data sections from input files */
        _E_DATA = .;     /* Set the end address of the data section */
    }> ROM  

    .bss :
    {
        _S_BSS = .;      /* Set the start address of the BSS section */
        *(.bss*)         /* Copy uninitialized data (BSS) sections from input files */
        _E_BSS = .;      /* Set the end address of the BSS section */
        . = ALIGN(4);    /* Align the current address to a 4-byte boundary */
        . = . + 1000;       /* Allocate 1000 bytes for the stack */
        _stack_top = .;  /* Set the stack top address */
    }> RAM
}

