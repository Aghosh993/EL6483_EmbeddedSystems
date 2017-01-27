# Based on https://github.com/sergioprado/bare-metal-arm/blob/master/Makefile
# But heavily-edited for our purposes:
# (c) Abhimanyu Ghosh, 2016
TOOLCHAIN_ROOT=../../../../gcc-arm-none-eabi-5_4-2016q3
TOOLCHAIN=$(TOOLCHAIN_ROOT)/bin/
PREFIX=$(TOOLCHAIN)/arm-none-eabi-

ARCHFLAGS=-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I$(TOOLCHAIN_ROOT)/arm-none-eabi/include -fsingle-precision-constant 
CFLAGS=-nostdlib -I../arch/stm32/f4/inc/ -I../arch/stm32/f4/inc/CMSIS -I../arch/stm32/f4/inc/Legacy -I../user_include -I../user_include/hal_interface -g -O2 -Wall
LDFLAGS=--specs=nosys.specs -Wl,--gc-sections,-Map,$(TARGET).map,-Tlinker.ld
LDFLAGS+=$(ARCHFLAGS)

CC=$(PREFIX)gcc
LD=$(PREFIX)gcc
OBJCOPY=$(PREFIX)objcopy
SIZE=$(PREFIX)size
RM=rm -f

NAME_FILE := ./proj_name
TARGET := $(shell cat ${NAME_FILE})

SRC=$(wildcard ../arch/stm32/f4/src/*.c)
SRC+=$(wildcard ../arch/stm32/f4/src/CMSIS/*.c)
ASM_SRC=$(wildcard ../arch/stm32/f4/src/*.s)
ASM_SRC+=$(wildcard ../arch/stm32/f4/src/CMSIS/*.s)
USER_SRC=$(wildcard user_source/*.c)
USER_SRC+=$(wildcard user_source/hal_interface/*.c)
NEWLIB_ASM_SRC=$(wildcard user_source/*.s)

OBJ=$(patsubst %.c, %.o, $(SRC))
ASM_OBJS=$(patsubst %.s, %.o, $(ASM_SRC))
TARGET_OBJ=$(TARGET).o
USER_OBJ=$(patsubst %.c, %.o, $(USER_SRC))
NEWLIB_ASM_OBJ=$(patsubst %.s, %.o, $(NEWLIB_ASM_SRC))

all: build size
build: elf srec bin 
elf: $(TARGET).elf
srec: $(TARGET).srec
bin: $(TARGET).bin
md5sums: all
	md5sum $(TARGET).elf > user_app_md5sum
check: all
	md5sum $(TARGET).elf > tmp && diff tmp user_app_md5sum && rm tmp
load: all
	./load_fw.sh $(TOOLCHAIN)

clean:
	$(RM) $(TARGET).srec $(TARGET).elf $(TARGET).bin $(TARGET).map $(OBJ) $(ASM_OBJS) $(NEWLIB_ASM_OBJ) $(TARGET_OBJ) $(USER_OBJ)

%.o: %.s
	$(CC) -c $(ARCHFLAGS) $(CFLAGS) -o $@ $<

%.o: %.c
	$(CC) -c $(ARCHFLAGS) $(CFLAGS) -o $@ $<

$(TARGET).elf: $(ASM_OBJS) $(NEWLIB_ASM_OBJ) $(OBJ) $(TARGET_OBJ) $(USER_OBJ)
	$(LD) $(LDFLAGS) -o $@ $(OBJ) $(ASM_OBJS) $(NEWLIB_ASM_OBJ) $(TARGET_OBJ) $(USER_OBJ) -lm -lc

%.srec: %.elf
	$(OBJCOPY) -O srec $< $@

%.bin: %.elf
	    $(OBJCOPY) -O binary $< $@

size: $(TARGET).elf
	$(SIZE) $(TARGET).elf