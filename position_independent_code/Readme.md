# C runtime remote code injection

Aside from some usage in malware or creating a C VM I don't really see a reason this would be useful, and its a ton of headache to maintain this. In a nutshell, unless you want extremely bloated binaries, you'll need to reimplement so much standard lib stuff. But it did interest me. C is a compiled language, which means that at compile time libraries are linked, memory addresses are mapped, everything is optimized and whatever else those mystic gcc/llvm/lde contributors are conjuring up in their dreams. 

And from my last 2 projects in the playground I've been using the `objdump` command a lot and looking at ELF files. And i thought, what if there was a way to remotely load a binary, say over a socket, and then "inject" that into the running process. And I don't mean just run it as in the [`posix_load.c`](/position_independent_code/src/posix_load.c) and [`echo_load.c`](/position_independent_code/src/echo_load.c). Essentially this would be like "runtime" linking.

This project will be split into a couple sections.
1. Create a client/server, where the server asks the client to execute certain functions.
2. if the client doesn't know that function, it'll ask the server to provide it.
3. the client will execute the function
4. the client will send the results back to the server.

Extended goals:
1. register and unregister functions
2. server signatures

So lets break it down.

### Client/Server
The idea here is that the client is a fool, they've never heard of gcc. We don't want them to have to think, just do. The server is the big brains of the op, it'll handle everything for the client.  
On initial connection: Client will tell the server: required info, such as os and architecture. 
The server will persist this info somewhere. When the time comes, and the server needs some data processed it will send the client a request asking it to run a function. This function will not exist in the client build, so the client will ask for it, the server will send the client the bin for its architecture, the methods declared in the bin. The client will download it, map it to internal memory, create pointers to the functions, run the functions, return the results to the server.


## The loader

Essentially what we want is some type of loader program, or linker. I'm not sure what it would be called. 

### posix_load.c
The simplest way (and standard) to do this is `posix_load.c`.

Essentially we do all the steps above, the server responds with an executable. We store it on the execution path. We fork and run the code with `execve`. 

But what fun is that? Our code not only has to be compiled for the specific architecture, it has to be complete and well defined. Our client doesn't retain any information, it doesn't have any access to the methods of the exe, it just ran the code.

### echo_load.c
This was just for fun, and I'm too lazy to look into it, but we copy a `/bin/` system util into the cwd and then dump the bin into it and run that. It transfers the perms from the copied file to the new executable.

### static_load.c
This is why I did this.
First we start by

