#!/bin/bash
rm -rf ./run/*
make clean
make all
objdump -d bin/ilp > run/ilp_dump
objdump -d bin/no_ilp > run/no_ilp_dump
diff run/ilp_dump run/no_ilp_dump