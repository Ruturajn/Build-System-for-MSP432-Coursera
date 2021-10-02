#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material.
#
#*****************************************************************************

#------------------------------------------------------------------------------
# A makefile for the Build System to be implemented for the Module-2
# Assesment for "Introduction to Embedded Software and Development
# Environments.
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.d - Dependency Files for each source file
#      <FILE>.o - Object files for individual files
#      <FILE>.i - Preprocessor files for each source file
#      <FILE>.asm - Assembly files for each source file
#      build - Produces final execuatble by compiling and linking
#              (Generates c1m2.out and c1m2.map and the size occupied)
#      clean - removes all the generated files after using make
#      build-asm - Shows the assembly programs from the c1m2.out
#	           (objdump is used for this purpose)
#      compile-all - Ony compiles all source files and does not link
#
#
# Platform Overrides:
#      PLATFORM - The intended platform for the code to get executed
#      		  (HOST, MSP432)
#
# Author : Ruturaj A. Nanoti
# Date : 24 September, 2021
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
PLATFORM = MSP432

#------------------------------------------------------------------------------

# Architectures Specific Flags
LINKER_FILE = ../msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
THUMB = thumb
FLOAT = float-abi=hard
FPU = fpu=fpv4-sp-d16
SPECS = nosys.specs

#------------------------------------------------------------------------------

# Compiler Flags and Defines
LD = arm-none-eabi-ld
SIZECC = arm-none-eabi-size
TARGET = c1m2
LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
CFLAGS = -march=$(ARCH) --specs=$(SPECS) -Wall -Werror -g\
	  -O0 -std=c99 -m$(THUMB) -m$(FLOAT) -m$(FPU) \
	  -mcpu=$(CPU)
CPPFLAGS = -M
OBJDUMP = arm-none-eabi-objdump
SIZEFLAGS = -Atd

#------------------------------------------------------------------------------

# Changing the Parameters based on the PLATFORM
ifeq ($(PLATFORM),HOST)
		CC = gcc
		CFLAGS = -Wall -Werror -g -O0 -std=c99
		SOURCES = main.c \
			  memory.c
		INCLUDES = -I ../include/common
		LDFLAGS = -Wl,-Map=$(TARGET).map
		SIZECC = size
		SIZEFLAGS = -A
		OBJDUMP = objdump
else
		CC = arm-none-eabi-gcc
endif

#------------------------------------------------------------------------------

#Creating all the Dependency Files *.d
DEPS = $(SOURCES:.c=.d)
%.d : %.c
	$(CC) $(CPPFLAGS) -D$(PLATFORM) $(CFLAGS) $(INCLUDES) -o $@ $^

#------------------------------------------------------------------------------

#Creating all the object files
OBJS = $(SOURCES:.c=.o)
%.o : %.c
	$(CC) -c $< -D$(PLATFORM) $(CFLAGS) $(INCLUDES) -o $@

#------------------------------------------------------------------------------

#Creating all the .i files (Pre-processor files)
PPFS = $(SOURCES:.c=.i)
%.i : %.c
	$(CC) -E $< -D$(PLATFORM) $(CFLAGS) $(INCLUDES) -o $@

#------------------------------------------------------------------------------

#Creating all the Assembly Files
ASMFS = $(SOURCES:.c=.asm)
%.asm : %.c
		$(CC) -S $< -D$(PLATFORM) $(CFLAGS) $(INCLUDES) -o $@

#------------------------------------------------------------------------------

#Building all the files
.PHONY: build
build: $(TARGET)

.PHONY: build-asm
build-asm: $(TARGET).out
	$(OBJDUMP) -d $(TARGET).out

$(TARGET): $(TARGET).out
	$(SIZECC) $(SIZEFLAGS) $(TARGET).out

$(TARGET).out: $(OBJS) $(DEPS)
	$(CC) $(OBJS) $(CFLAGS) $(INCLUDES) $(LDFLAGS) -o $@

#------------------------------------------------------------------------------

#Only compile all files don't link
.PHONY: compile-all
compile-all: $(SOURCES) $(OBJS)

#------------------------------------------------------------------------------

#Clearing all the generated files after make
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET).out $(TARGET).map $(PPFS) $(ASMFS) $(DEPS) *.map
