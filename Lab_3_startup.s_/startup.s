 
   
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
 
