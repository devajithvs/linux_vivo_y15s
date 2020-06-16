#!/bin/bash

mkdir -p out
export CROSS_COMPILE=$HOME/arm-eabi-4.7/bin/arm-eabi-
export USE_CCACHE=1
export ARCH=arm && export SUBARCH=arm

#make clean
#make mrproper

make -C $PWD O=$PWD/out ARCH=arm s5030_defconfig
make -j$(nproc) -C $PWD O=$PWD/out ARCH=arm
