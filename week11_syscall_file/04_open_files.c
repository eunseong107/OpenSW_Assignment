#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>

int open(const char *pathname, int flags, ...
                  /* mode_t mode */ );

int close(int fd);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [file name] ... \n", argv[0]);
        return 0;
        }

    int fd;
    
    for (int i = 1; i < argc; i++) {
        const char *filename = argv[i];
        
        fd = open(filename, O_RDONLY);
        
        if (fd == -1) {
            perror(filename);
        } else {
            printf("'%s': File open successful! (fd: %d)\n", filename, fd);
            
            close(fd);
        }
    }

    return 0;
}