#include <stdio.h>

void isr(void) {
    int *timer1 = (int*)0x10011000;
    timer1[3] = 0xff;
    printf("interrupt\n");
}
