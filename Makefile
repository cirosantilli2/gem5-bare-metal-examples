CROSS_COMPILE ?= arm-none-eabi-

AS           = $(CROSS_COMPILE)as
LD           = $(CROSS_COMPILE)ld
CC           = $(CROSS_COMPILE)gcc
CXX          = $(CROSS_COMPILE)g++
CPP          = $(CROSS_COMPILE)cpp
AR           = $(CROSS_COMPILE)ar
NM           = $(CROSS_COMPILE)nm
STRIP        = $(CROSS_COMPILE)strip
OBJCOPY      = $(CROSS_COMPILE)objcopy
OBJDUMP      = $(CROSS_COMPILE)objdump

CFLAGS       = -g -O3 -lunistd -I . -std=c99
CXXFLAGS     = -g -O3 -lunistd -I . -fno-exceptions -std=c++11
ASFLAGS      = -EL
LNK_OPT      = -nostartfiles
LNK_SCRIPT   = boot.ld
LNK_FILE_OPT = -nostartfiles -Xlinker -T$(LNK_SCRIPT)
