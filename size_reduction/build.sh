#!/bin/bash
rm -rf ./run/*
make clean
make all
objdump -d bin/base > run/base
objdump -d bin/small > run/small
la -lah bin/