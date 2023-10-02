#!/bin/bash
rm -rf ./run/*
make clean
make all
cp bin/base bin/base_stripped
cp bin/small bin/small_stripped
cp bin/base_os bin/base_os_stripped
cp bin/base_static bin/base_static_stripped


#strip some stuffs:
strip -S --strip-unneeded --remove-section=.comment --remove-section=.note --remove-section=.note.gnu.build-id --remove-section=.eh_frame --remove-section=.eh_frame_ptr --remove-section=.eh_frame_hdr ./bin/*_stripped
objdump -D bin/base > run/base
objdump -D bin/base_os > run/base_os
objdump -D bin/base_static > run/base_static
objdump -D bin/small > run/small

objdump -D bin/base_stripped > run/base_stripped
objdump -D bin/base_os_stripped > run/base_os_stripped
objdump -D bin/base_static_stripped > run/base_static_stripped
objdump -D bin/small_stripped > run/small_stripped

ls -lah bin/