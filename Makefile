
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
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES] [VERBOSE] [COURSE]
# PLATFORM=HOST or MSP432
# VFLAG=VERBOSE or NONE
# COURSE=COURSE1 or NONE or STATS
# example:"make all PLATFORM=HOST VFLAG=VERBOSE COURSE=COURSE1"
#
# Build Targets:
#      <Put a description of the supported targets here>
#	<FILE>.o - Builds <FILE>.o object file
#	build/all - Builds and links all source files
#	clean - removes all generated files
#	compile-all -compiles all files but do not link
# Platform Overrides:
#      <Put a description of the supported Overrides here>
#	CPU - ARM Cortex architecture (cortex-m4)
#	ARCH - ARM architecture (thumb)
#	SPECS - Specs file which is given to the linker (nosys.specs)
#
#------------------------------------------------------------------------------

include sources.mk



#make use code example!!!!!
#example:"make all PLATFORM=HOST VFLAG=VERBOSE COURSE=COURSE1"



#PLATFORM=HOST
ifeq ($(PLATFORM),MSP432)
	CC=arm-none-eabi-gcc
	CFLAGS=$(IDIR) -std=c99 -Wall -D$(PLATFORM) -D$(VFLAG) -D$(COURSE) -g -O0 -mcpu=cortex-m4 -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs 
	LINKER_FILE=msp432p401r.lds
	LDFLAGS=-Wl,-Map=c1final.map -T $(LINKER_FILE)
	LD=arm-none-eabi-ld
	OBJS=$(SOURCES:.c=.o)
	DEPS=$(SOURCES:.c=.dep)
	ASMS=$(SOURCES:.c=.asm)
	PPIS=$(SOURCES:.c=.i)
	SIZEFLAG=arm-none-eabi-size
	OBJDUMPFLAG=arm-none-eabi-objdump
else
	CC=gcc
	CFLAGS=$(IDIR) -std=c99 -Wall -D$(PLATFORM) -D$(VFLAG) -D$(COURSE) -g -O0
	#LDFLAGS=-Wl, -Map=c1final.map
	OBJS=$(SOURCES:.c=.o)
	DEPS=$(SOURCES:.c=.dep)
	ASMS=$(SOURCES:.c=.asm)
	PPIS=$(SOURCES:.c=.i)
	SIZEFLAG=size
	OBJDUMPFLAG=objdump
	#_DEPS = platform.h memory.h
	#DEPS= $(patsubst %,$(IDIR)/%, $(_DEPS))
endif


%.o: %.c #$(DEPS) 
	$(CC) -c -o $@ $^ $(CFLAGS)

%.i: %.c
	$(CC) -E -o $@ $^ $(CFLAGS)

c1final.asm: c1final.out
	$(OBJDUMPFLAG) -d $< > c1final.asm

%.asm: %.c
	$(CC) -S -c -o $@ $^ $(CFLAGS)

%.dep: %.c
	$(CC) -M -c -o $@ $^ $(CFLAGS)

c1final.out: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS); \
	$(SIZEFLAG) -G -t $(OBJS) c1final.out; \
	echo "build code size report saved to report.txt"; \
	$(SIZEFLAG) -G -t $(OBJS) c1final.out > report.txt 

.PHONY: compile-all
compile-all:
	$(CC) -c $(SOURCES) $(CFLAGS)

.PHONY: all
all: c1final.out
#example:"make all PLATFORM=HOST VFLAG=VERBOSE COURSE=COURSE1"
.PHONY: build
build: all

.PHONY: clean
clean: 
	rm -f $(OBJS) c1final.out $(PPIS) $(ASMS) $(DEPS) c1final.map c1final.asm src/interrupts_msp432p401r_gcc.o src/startup_msp432p401r_gcc.o src/system_msp432p401r.o  
