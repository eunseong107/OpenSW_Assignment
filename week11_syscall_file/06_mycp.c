#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>

#define BUF_SIZE 32
#define FILE_PERM 0644

int main(int argc, char* argv[]) {

    if (argc < 2) {
        printf("Usage: %s [source file] [destination file1] [destination file2] ... \n", argv[0]);
        exit(1); 
    }
    
    // open source file (read only)
    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd == -1) {
        perror("소스 파일 열기 오류");
        exit(1);
    }

    // open dest files
    int num_files = argc - 2;
    int *dest_fd_list = (int *)malloc(sizeof(int) * num_files);
    
    if (dest_fd_list == NULL) {
        perror("메모리 할당 실패");
        close(src_fd);
        exit(1);
    }

    for (int i = 0; i < num_files; i++) {
        const char *dest_filename = argv[i + 2];
        
        dest_fd_list[i] = open(dest_filename, O_WRONLY | O_CREAT | O_TRUNC, FILE_PERM);
        
        if (dest_fd_list[i] == -1) {
            perror("대상 파일 열기/생성 오류");
            for (int j = 0; j < i; j++) {
                close(dest_fd_list[j]);
            }
            close(src_fd);
            free(dest_fd_list);
            exit(1);
        }
    }

    // read from source and write destinations & stdout
    char* readStr = (char *)malloc(sizeof(char) * BUF_SIZE);
    if (readStr == NULL) {
        perror("메모리 할당 실패");
        close(src_fd);
        for (int i = 0; i < num_files; i++) {
            close(dest_fd_list[i]);
        }
        free(dest_fd_list);
        exit(1);
    }
    
    int read_result;
    
    while(1) {
        read_result = read(src_fd, readStr, BUF_SIZE);

        if (read_result == 0) {
            break; 
        }

        if (read_result < 0) {
            if (errno == EINTR) {
                continue;
            }
            perror("Source 파일 읽기 오류");
            break;
        }
        
        int written_stdout = 0;
        while (written_stdout < read_result) {
            int write_len = write(STDOUT_FILENO, readStr + written_stdout, read_result - written_stdout);
            
            if (write_len < 0) {
                perror("Standard Output 쓰기 오류");
                break;
            }
            written_stdout += write_len;
        }

        for (int i = 0; i < num_files; i++) {
            int dest_fd = dest_fd_list[i];
            int written_dest = 0;

            while (written_dest < read_result) {
                int write_len = write(dest_fd, readStr + written_dest, read_result - written_dest);
                
                if (write_len < 0) {
                    fprintf(stderr, "Destination File FD %d 쓰기 오류: %s\n", dest_fd, strerror(errno));
                    break;
                }
                written_dest += write_len;
            }
        }
    }

    // close all files
    if (close(src_fd) == -1) {
        perror("소스 파일 닫기 오류");
    }

    for (int i = 0; i < num_files; i++) {
        if (close(dest_fd_list[i]) == -1) {
            fprintf(stderr, "Destination File FD %d 닫기 오류: %s\n", dest_fd_list[i], strerror(errno));
        }
    }

    // free
    free(readStr);
    free(dest_fd_list);

    return 0;
}