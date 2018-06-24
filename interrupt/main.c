#include <stdio.h>

int main(void) {
    unsigned int delay = 0;
    unsigned int counter = 0;

    int *timer1 = (int*)0x10011000;
    *timer1 = 0x1000;
    while (1) {
        if (counter > 300000) {
            counter = 0;
            delay++;
            if (delay == 5) {
                printf("start\n");
                timer1[2] = 0xE0;
            }
            printf("%u\n", delay);
        } else {
            counter++;
        }
    }
}
