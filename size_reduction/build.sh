#!/bin/bash
rm -rf ./run/*
make clean
make all
cp bin/base bin/base_stripped
cp bin/small bin/small_stripped
cp bin/base bin/base_stripped

objdump -d bin/base > run/base
objdump -d bin/small > run/small
la -lah bin/