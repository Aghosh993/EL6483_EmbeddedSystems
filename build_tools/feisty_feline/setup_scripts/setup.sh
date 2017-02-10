#!/bin/bash
/usr/bin/ruby -e "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/master/install)"

curl -L -O https://launchpad.net/gcc-arm-embedded/5.0/5-2016-q3-update/+download/gcc-arm-none-eabi-5_4-2016q3-20160926-mac.tar.bz2
mv gcc-arm-none-eabi-5_4-2016q3-20160926-mac.tar.bz2 gcc-arm-none-eabi-5_4-2016q3.tar.bz2
tar xvf gcc-arm-none-eabi-5_4-2016q3.tar.bz2 -C ../../../..
rm gcc-arm-none-eabi-5_4-2016q3.tar.bz2

brew install openocd --enable-ft2232_libftdi
