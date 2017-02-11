# STM32Cube-based software development repo for the STM32 F3/F4 Discovery Boards.

This build system is for use on Linux systems. Some distributions may need minor modifications.

Tested distros: Arch Linux, Xubuntu, Ubuntu

## Known issues:

**Issue 1:** (IMPORTANT FOR UBUNTU 64-bit USERS)

In order to run the toolchain on 64-bit Ubuntu, you must install the "libc6-i386" and "libncurses5:i386" packages from the apt repository, using "sudo apt-get install libc6-i386 libncurses5:i386". See http://askubuntu.com/questions/133389/no-such-file-or-directory-but-the-file-exists for details.

**Issue 2:** On Arch Linux, the "lib32-ncurses5-compat-libs" and "ncurses5-compat-libs" packages may need to be installed from the AUR in order to resolve the fact that Arch has moved to ncurses 6 while the ARM-none toolchain is still by default compiled against ncurses-5.

The other more painful alternative is re-compiling the arm-none-eabi toolchain from source against the new ncurses, but this is decidedly more painful...

**Issue 3:** On some newer STM32 F3 boards, there is a new version of the ST-Link (V2-1). The symptom of the issue will be that when you attempt to "make load" you will get the following output or something similar:

```bash
Info : The selected transport took over low-level target control. The results might differ compared to plain JTAG/SWD
none separate
srst_only separate srst_nogate srst_open_drain connect_deassert_srst
Info : Unable to match requested speed 1000 kHz, using 950 kHz
Info : Unable to match requested speed 1000 kHz, using 950 kHz
Info : clock speed 950 kHz
Error: open failed
in procedure 'init' 
in procedure 'ocd_bouncer'
```

If you get something like this output, open the file called "stm32f3discovery.cfg" in a text editor. Find the line that says "source [find interface/stlink-v2.cfg]" and change it to "source [find interface/stlink-v2-1.cfg]"

## Quickstart guide to flash firmware onto the STM32 Discovery in 7 commands:

Pre-requisites: git, GNU Make, Udev

1) 

```bash
git clone https://github.com/Aghosh993/EL6483_EmbeddedSystems.git
```

2) 

```bash
cd EL6483_EmbeddedSystems/build_tools/arctic_awesomeness/setup_scripts/
```

3) 

```bash
sudo ./setup.sh UBUNTU_LINUX 
```

(or ARCH_LINUX depending on O/S) [This may take a while. Go get a coffee...]

4) 

```bash
cd ..
```

5) 

```bash
./mkproject.sh test f3
```

(Use "f3" make an F3 Discovery project, or "f4" for the F4 Discovery)

6) 

```bash
cd test
```

7) 

```bash
make && make load
```

8) ???

9) PROFIT!!

## Creating a new local project:

PLEASE ALWAYS CREATE A NEW PROJECT USING THIS PROCEDURE!! This helps make sure the core repository contents (example apps and other code) are untouched, and you do all development work separate from the tracked files on this Git repository.

To make a new project with name "test" (Assuming you've already done the setup step above):

1) 

(If not there already:)

```bash
cd EL6483_EmbeddedSystems/build_tools/arctic_awesomeness/
```

2)

```bash
./mkproject.sh test f3
```

(Use "f3" make an F3 Discovery project, or "f4" for the F4 Discovery)

3) 

```bash
cd test/
```

4) 

```bash
make && make load
```

5) Done :) Enjoy!

(c) Abhimanyu Ghosh, 2017
