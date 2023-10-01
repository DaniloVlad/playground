# Instruction Level Parallelism (ILP)

## Purpose

The purpose of this repo was to understand GCC and how it reorganizes code under the hood to optimize for ILP.
Essentially the question i had was will gcc reorganize the code to optimize for cpu cycles.
So we have:
`no_ilp.c`:
```c
int d = a + b;
int e = a + d;
int f = b + c;
```
and

`ilp.c`:
```c
int d = a + b;
int f = b + c;
int e = a + d;
```

The the result of `int e = a + d` relies on the execution of `int d = a + b`, and in a non-optimized compilier, this would result in `noop`'s happening for stages ID/EX/MEM/WB (see below). Thats 4 additional cycles for each execution of main.

Run it: `./build.sh`

## Background
Two main approaches to ILP:
1. Hardware
2. Software

## Hardware ILP

Hardware ILP works on dynamic parallelism, which means the processor decides at runtime which instructions to execute in parallel.

## Software ILP

Software ILP works on static parallelism, which means the compiler decides what instructions to execute in parallel.

## Methods of ILP

### Instruction Pipelining

Classic 5 stage reduced instruction set computer central processing units (RISC):
1. Instruction Fetch (IF)
2. Instruction Decode (ID)
3. Execute (EX)
4. Memory Access (MEM)
5. Register Write Back (WB)


Links:
https://en.wikipedia.org/wiki/Instruction_pipelining
https://en.wikipedia.org/wiki/Classic_RISC_pipeline