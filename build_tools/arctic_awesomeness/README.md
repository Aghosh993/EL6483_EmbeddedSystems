# STM32Cube-based software development repo for the STM32 F3/F4 Discovery Boards.

This build system is for use on Linux systems. Some distributions may need minor modifications.

Tested distros: Arch Linux, Xubuntu, Ubuntu

Errata 1: (IMPORTANT FOR UBUNTU 64-bit USERS)

In order to run the toolchain on 64-bit Ubuntu, you must install the "libc6-i386" package from the repository, using "sudo apt-get install libc6-i386". See http://askubuntu.com/questions/133389/no-such-file-or-directory-but-the-file-exists for details.

Errata 2: On Arch Linux, the "lib32-ncurses5-compat-libs" and "ncurses5-compat-libs" packages may need to be installed from the AUR in order
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

# Creating a new local project:

To make a new project with name "foo" (Assuming you've already done the setup step above):

1) cd EL6483_EmbeddedSystems/build_tools/arctic_awesomeness/ if not there already

2) "./mkproject.sh foo f3" (for F3 Discovery) or "./mkproject.sh foo f4" (for F4 Discovery)

3) cd foo/

4) make && make load

5) Done :) Enjoy!

(c) Abhimanyu Ghosh, 2016
