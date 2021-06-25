CC=/home/keith/Tools/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gcc
CPP=/home/keith/Tools/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-g++
MACH=cortex-m4
CFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -std=gnu11 -Wall -O0
CPPFLAGS= -c -mcpu=$(MACH) -mthumb -mfloat-abi=soft -Wall -O0 -fno-exceptions -fno-rtti 
LDFLAGS= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=nano.specs -T linker.ld -Wl,-Map=final.map
LDFLAGS_SH= -mcpu=$(MACH) -mthumb -mfloat-abi=soft --specs=rdimon.specs -T linker.ld -Wl,-Map=final.map

all:main.o led.o startup.o syscalls.o final.elf

semi:main.o led.o startup.o syscalls.o final_sh.elf

main.o:main.cpp
	$(CPP) $(CPPFLAGS) -o $@ $^

led.o:led.cpp
	$(CPP) $(CPPFLAGS) -o $@ $^

startup.o:startup.c
	$(CC) $(CFLAGS) -o $@ $^

syscalls.o:syscalls.c
	$(CC) $(CFLAGS) -o $@ $^
	
final.elf: main.o led.o startup.o syscalls.o
	$(CC) $(LDFLAGS) -o $@ $^
	
final_sh.elf: main.o led.o startup.o
	$(CC) $(LDFLAGS_SH) -o $@ $^

clean:
	rm -rf *.o *.elf

load:
	 openocd -f /usr/share/openocd/scripts/board/stm32f4discovery.cfg -f /usr/share/openocd/scripts/interface/stlink-v2-1.cfg -c "stm32f4x.cpu configure -rtos ChibiOS"
	
debug:
	/home/keith/Tools/gcc-arm-none-eabi-10-2020-q4-major/bin/arm-none-eabi-gdb
