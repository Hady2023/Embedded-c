#Done By : Hady Ayman Eldeeb 
#Date:8/7/2023
#1:Genrate all the (obj) file  
#2:collected all the files in the static library so its suitable to run .c or .s file  
#3:Genrate (.elf) by linking static library with debugge 
#4:Finaly genrate (.bin)
CC =arm-none-eabi-
CFLAGS =-gdwarf-2 -mcpu=cortex-m3 -mthumb
INCS = -I.
SRC =$(wildcard *.c)
OBJ =$(SRC:.c=.o)
AS =$(wildcard *.s)
ASOBJ =$(AS:.s =.o)
Project-NAME=LED_P13
NUM_LINKER=_3
all: $(Project-NAME).bin
	@echo "============= Build is Done =============="	
%.o: %.c
	$(CC)gcc.exe -c	$(CFLAGS) $(INCS)	$<	-o	$@ 
LIP_STATIC.a:	$(OBJ)	$(ASOBJ)  
	$(CC)ar.exe rcs LIP_STATIC.a	$(OBJ)	$(ASOBJ)
$(Project-NAME).elf:	LIP_STATIC.a 
	$(CC)ld.exe -T linkerscript$(NUM_LINKER).ld		LIP_STATIC.a	-o	$@	-Map=out.map
$(Project-NAME).bin:	$(Project-NAME).elf
	$(CC)objcopy -O binary $< $@
clean:
	rm	*.bin *.elf 
clean_all:
	rm	*.o *.bin *.elf *.a *.map
	
