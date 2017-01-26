# STM32CubeF3-based software development repo for the STM32 F3 Discovery Board.

This build system is for use on Linux systems. Some distributions may need minor modifications.

Tested distros: Arch Linux, Xubuntu, Ubuntu

Errata: On Arch Linux, the "lib32-ncurses5-compat-libs" and "ncurses5-compat-libs" packages may need to be installed from the AUR in order
to resolve the fact that Arch has moved to ncurses 6 while the ARM-none toolchain is still by default compiled against ncurses-5.
The other more painful alternative is re-compiling the arm-none-eabi toolchain from source against the new ncurses, but this is decidedly 
more painful...

## Quickstart guide to flash firmware onto the STM32 Discovery in 5 commands:

Pre-requisites: git, GNU Make, Udev

1) git clone https://github.com/Aghosh993/EL6483_EmbeddedSystems.git

2) cd EL6483_EmbeddedSystems/build_tools/arctic_awesomeness/setup_scripts/

3) sudo ./setup.sh UBUNTU_LINUX (or ARCH_LINUX depending on O/S) [This may take a while. Go get a coffee...]

4) cd ../f3_basic_app/

5) make && make load

6) ???

7) PROFIT!!

(c) Abhimanyu Ghosh, 2016
