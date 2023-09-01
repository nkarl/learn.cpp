#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    char *file = "data.txt"; 
    char buf[1024];

    if (argc > 1) 
        file = argv[1];

    /*int fd = open(file, O_RDONLY);*/
    /*lseek(fd, buf, 1024);*/
    /*read(fd, buf, 1024);*/
    /*printf("SEEK_CUR=%d\n", SEEK_CUR);*/
    /*printf("SEEK_END=%d\n", SEEK_END);*/
    /*printf("SEEK_SET=%d\n", SEEK_SET);*/

    int block_size = 1024 * (1 << 0);
    printf("blksize=0: %d\n", block_size);
    block_size = 1024 * (1 << 1);
    printf("blksize=1: %d\n", block_size);
    block_size = 1024 * (1 << 2);
    printf("blksize=2: %d\n", block_size);
}
