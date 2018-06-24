# gem5 ARM Bare Metal Examples

Written in C with Newlib.

Tested on Ubuntu 18.04, gem5 60600f09c25255b3c8f72da7fb49100e2682093a:

    apt-get install gcc-arm-none-eabi
    cd simple
    ../run ../path/to/gem5

Or if you did an out of tree build:

    ../run ../path/to/gem5/build ../path/to/gem5/src

On another shell:

    telnet localhost 3456

Outcome: shell prints:

    hello world

The instruction trace is visible at:

    less m5out/trace.txt

Another example:

    cd interrupt
    ../run

Outcome: counts every second to stdout:

    1
    2
    3
    4
    start
    5
    6
    7
    8
    9
    10
    11
    12
    13
    14
    15
    16
    17
    18
    interrupt
    19
    20
    21
    22
    23
    24
    25
    26
    27
    28
    29
    30
    31
    32
    interrupt

TODO understand the `interrupt` and `start` messages.

## Build the toolchain yourself

TODO: tried with crosstool-ng ab3c204aee88f08481f1f63825d0e94b082ef84e, on `ct-ng menuconfig` set:

- OS: bare metal. This selects Newlib as the C standard library.
- set 32-bit

And then try to compile with:

    cd simple
    PATH="/path/to/crosstool-ng/.build/arm-unknown-eabi/buildtools/bin/:${PATH}" make CROSS_COMPILE=arm-unknown-eabi-

But compilation fails with:

    main.c:1:10: fatal error: stdio.h: No such file or directory
     #include <stdio.h>
              ^~~~~~~~~
