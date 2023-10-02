# C Build/Stub Reduction

Investigating the effects of:

```bash
-fdata-sections
-ffunction-sections
-static
-e: custom entry
```

`base.c`: This is how you would typically write a program.

`small.c`: Implement required method from stdlib instead of importing it. Add custom entry method to avoid `libc_start` and `gmon_start`.

In theory `small.c` would create a bin larger than base if a ton of methods from `stblib.h` were used, as they all need to be inserted into the mem space.

`base_os`: compiled with `-Os` flag  
`base_static`: compiled with `-static --gc-sections -fdata-sections -ffunction-sections` flag  
`*_stripped`: stripped with gnu `strip` util.  
(check the makefile).  

Final output:  
```bash
ubuntu@performance:~/playground/size_reduction$ ls -lah bin
total 1.8M
drwxrwxr-x 2 ubuntu ubuntu 4.0K Oct  2 05:23 .
drwxrwxr-x 5 ubuntu ubuntu 4.0K Oct  2 05:09 ..
-rwxrwxr-x 1 ubuntu ubuntu  16K Oct  2 05:23 base
-rwxrwxr-x 1 ubuntu ubuntu  16K Oct  2 05:23 base_os
-rwxrwxr-x 1 ubuntu ubuntu  14K Oct  2 05:23 base_os_stripped
-rwxrwxr-x 1 ubuntu ubuntu 866K Oct  2 05:23 base_static
-rwxrwxr-x 1 ubuntu ubuntu 789K Oct  2 05:23 base_static_stripped
-rwxrwxr-x 1 ubuntu ubuntu  14K Oct  2 05:23 base_stripped
-rwxrwxr-x 1 ubuntu ubuntu 9.4K Oct  2 05:23 small
-rwxrwxr-x 1 ubuntu ubuntu 8.5K Oct  2 05:23 small_stripped
```
