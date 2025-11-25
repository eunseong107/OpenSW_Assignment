#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

#define BUF_SIZE 128

int main(int argc, char* argv[]) {

    if(argc != 1) {
        printf("Usage: %s\n", argv[0]);
        exit(0);
    }

    char* readStr = (char*)malloc(sizeof(char) * BUF_SIZE);
    int read_result;
    while(1) {
        read_result = read(STDIN_FILENO, readStr, BUF_SIZE);

        if (read_result == 0) {
            printf("Detected EOF (Ctrl + D)\n");
            break; 
        }

        if (read_result < 0) {
            if (errno == EINTR) {
                continue;
            }
            perror("read 오류 발생\n");
            break;
        }

        int written_bytes = 0;
        
        while (written_bytes < read_result) {
            int write_len = write(STDOUT_FILENO, readStr + written_bytes, read_result - written_bytes);
            
            if (write_len < 0) {
                perror("write 오류 발생\n");
                written_bytes = -1;
                break;
            }
            written_bytes += write_len;
        }

        if (written_bytes == -1) {
            break;
        }
    }

    free(readStr);

    return 0;
}