gcc -Os -Wl,-dead_strip -fdata-sections -ffunction-sections -eentry -nostartfiles -static src/small.c -o bin/sm4 -v

gcc -Os -Wl,--gc-sections -fdata-sections -ffunction-sections -eentry -nostartfiles -static src/small.c -o bin/sm4 -v

strip -S --strip-unneeded --remove-section=.comment --remove-section=.note --remove-section=.note.gnu.build-id --remove-section=.eh_frame --remove-section=.eh_frame_ptr --remove-section=.eh_frame_hdr ./bin/base_static_strip
