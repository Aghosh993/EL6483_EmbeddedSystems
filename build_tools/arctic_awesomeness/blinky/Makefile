# Based on https://github.com/sergioprado/bare-metal-arm/blob/master/Makefile
# But heavily-edited for our purposes:
# (c) Abhimanyu Ghosh, 2016
TOOLCHAIN_ROOT=../../../../gcc-arm-none-eabi-5_4-2016q3
TOOLCHAIN=$(TOOLCHAIN_ROOT)/bin/
PREFIX=$(TOOLCHAIN)/arm-none-eabi-

OPENOCD_LOC=/usr/bin

ARCHFLAGS=-mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I$(TOOLCHAIN_ROOT)/arm-none-eabi/include -fsingle-precision-constant 
CFLAGS=-nostdlib -I../hal_include/ -I../user_include -I../user_include/hal_interface -I../hal_include/CMSIS -g -O2 -Wall
LDFLAGS=--specs=nosys.specs -Wl,--gc-sections,-Map,$(TARGET).map,-Tlinker.ld
LDFLAGS+=$(ARCHFLAGS)

CC=$(PREFIX)gcc
LD=$(PREFIX)gcc
OBJCOPY=$(PREFIX)objcopy
SIZE=$(PREFIX)size
RM=rm -f

TARGET=blinky

SRC=$(wildcard ../hal_source/*.c)
SRC+=$(wildcard ../hal_source/CMSIS/*.c)
ASM_SRC=$(wildcard ../hal_source/*.s)
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
	./load_fw.sh $(OPENOCD_LOC) /usr/bin/ # The second argument here is the path to arm-none-eabi-gdb. This should really just be $(TOOLCHAIN) but Arch Linux throws a stupid libncurses.so error so we're just using the distro's shipped arm-none-eabi-gdb for the time being... :/

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