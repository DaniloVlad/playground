gcc -Os -Wl,-dead_strip -fdata-sections -ffunction-sections -eentry -nostartfiles -static src/small.c -o bin/sm4 -v

gcc -Os -Wl,--gc-sections -fdata-sections -ffunction-sections -eentry -nostartfiles -static src/small.c -o bin/sm4 -v
