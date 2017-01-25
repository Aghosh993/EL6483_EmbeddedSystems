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

echo "Copying Udev rules to /etc/udev/rules.d/"
cp *.rules /etc/udev/rules.d/