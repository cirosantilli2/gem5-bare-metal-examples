#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define UNUSED __attribute__((unused))

volatile unsigned int *const UART0DR = (unsigned int *)0x10009000;
register char *stack_ptr __asm ("sp");
/* TODO defined in some header? */
struct _reent;

int _read_r(UNUSED struct _reent *r, UNUSED int file, UNUSED char *ptr, UNUSED int len) {
    errno = EINVAL;
    return -1;
}

int _lseek_r(UNUSED struct _reent *r, UNUSED int file, UNUSED int ptr, UNUSED int dir) {
    return 0;
}

void gem5_print(const char *s) {
    while (*s != '\0') {
        *UART0DR = (unsigned int)(*s);
        s++;
    }
}

int _write_r(UNUSED struct _reent *r, UNUSED int file, char *ptr, int len) {
    gem5_print(ptr);
    return len;
}

int _close_r (struct _reent *r, int file) {
    return 0;
}

caddr_t _sbrk_r(struct _reent *r, int incr) {
    extern char end __asm__ ("end");
    static char *heap_end;
    char *prev_heap_end;

    if (heap_end == NULL)
        heap_end = & end;
    prev_heap_end = heap_end;
    if (heap_end + incr > stack_ptr) {
        errno = ENOMEM;
        return (caddr_t) -1;
    }
    heap_end += incr;
    return (caddr_t) prev_heap_end;
}

int _fstat_r(UNUSED struct _reent *r, UNUSED int file, struct stat *st) {
    memset(st, 0, sizeof (*st));
    st->st_mode = S_IFCHR;
    return 0;
}

int _isatty_r(UNUSED struct _reent *r, UNUSED int fd) {
    return 1;
}
