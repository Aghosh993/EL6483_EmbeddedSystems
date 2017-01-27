# Architecture-specific HAL

This directory shall contain a folder for each chip's HAL (Hardware 
Abstraction layer). The combination of this HAL, and a user-written HAL 
interface shall allow any user application to be ported word-for-word 
between various hardware platforms. In theory, the only change to be 
made to target an STM32 F3 board instead of a TI Hercules Launchpad for 
instance is a change in the Makefile target for firmware build and load.

Code contained within these directories is for the most part NOT 
copyrighted by me (Abhimanyu Ghosh) but rather distributed by the 
architecture's vendor with a permissive license (typically BSD or LGPL). 
I am not a lawyer, but any license for software within this directory shall 
be considered compatible with the LGPL license used for all higher-level 
implementation and HAL interface software committed by me to this repository.

Abhimanyu Ghosh, 2016
