#!/bin/bash
PKG_MGR_CMD=""
DEPENDENCY_PKGS="openocd"

echo "Obtaining dependencies..."

if [ $# -eq 0 ]
	then
		echo "Usage: ./setup.sh [ARCH_LINUX | UBUNTU_LINUX]"
		exit 0
fi

if [ "$1" = "ARCH_LINUX" ]; then
	PKG_MGR_CMD="pacman -Sy "$DEPENDENCY_PKGS
else
	if [ "$1" = "UBUNTU_LINUX" ]; then
		PKG_MGR_CMD="apt-get install "$DEPENDENCY_PKGS
	else
		echo "ERROR, unsupported distro! Must install packages manually!"
	fi
fi

$PKG_MGR_CMD

echo "Downloading and extracting toolchain..."
wget -P ../../../../ https://launchpad.net/gcc-arm-embedded/5.0/5-2016-q3-update/+download/gcc-arm-none-eabi-5_4-2016q3-20160926-linux.tar.bz2
tar xvf ../../../../ https://launchpad.net/gcc-arm-embedded/5.0/5-2016-q3-update/+download/gcc-arm-none-eabi-5_4-2016q3-20160926-linux.tar.bz2

echo "Copying Udev rules to /etc/udev/rules.d/"
cp *.rules /etc/udev/rules.d/
udevadm control --reload-rules