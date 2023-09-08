/*#Done by: Hady Ayman 
#Date: 7/9/2023 
#Titel: ///*Simple startup.s*///   
#1:Inthlization the SP in adderss 0x08000000 by the value of stack_top 
#2:Add the vector handler Function and use .word in each line to imporve from aligen address     
#3:As simple as possible Reset_handler call tha _reset to baranch at main  
#4:Use .section to divide sections as .vector and .texe  
#5:Use thumb to To allow accepte all 16 and 32 bit instruction*/ 
   
.section .vectors 
.word _stack_top
.word Reset_handler 
.word Hf_handler 

.section .text 
Hf_handler:
 b Reset_handler 
 
Reset_handler:
 b _reset
 
.thumb_func 
_reset:
 b main 
 b . 
 
