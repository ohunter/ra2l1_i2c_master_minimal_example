#include <cstdint>
#include <stddef.h>
#include <sys/types.h>
#include <unistd.h>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"

extern "C" {

extern char* const __HeapBase;

void _exit(int status) {
    while (1) {
    }
}

int _close(int fd) {
    return -1;
}

int _lseek(int file, off_t pos, int whence) {
    return 0;
}

int _read(int fd, void *buf, size_t cnt) {
    return 0;
}

int _write(int fd, const void *buf, size_t cnt) {
    return 0;
}

void *_sbrk(const ptrdiff_t increment) {
    static char* heap{__HeapBase};
    char *prev_heap = heap;

    heap += increment;
    return prev_heap;
}

void _kill(int pid, int sig) {
    return;
}

int _getpid(void) {
    return -1;
}

int _fstat(int file, struct stat *st) {
    return 0;
}

int _isatty(int file) {
    return 1;
}

}

#pragma GCC diagnostic pop
