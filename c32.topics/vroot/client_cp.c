#include <dirent.h>
#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <fcntl.h>
#include <sys/stat.h>

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif

void cp(char *dest, char *src) {
    DIR           *dirp;
    struct dirent *entry;

    // char *local = "local";

    int fd = open(".", O_RDONLY);
    chdir("./local");

    // open src input
    int in_fd = open(src, O_RDONLY);
    if (in_fd == -1) fprintf(stderr, "ERROR: open(in_fd)\n");

    // open dest output
    int    openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    mode_t filePerms = S_IRUSR | S_IWUSR;

    int out_fd = open(dest, openFlags, filePerms);
    if (out_fd == -1) fprintf(stderr, "ERROR: open(out_fd)\n");

    /* TRANSER DATA */
    ssize_t numRead;
    char    buf[BUF_SIZE];
    while ((numRead = read(in_fd, buf, BUF_SIZE) > 0)) {
        if (write(out_fd, buf, numRead) != numRead) {
            fprintf(stderr, "couldn't write whole buffer.\n");
        }
    }

    if (numRead == -1) fprintf(stderr, "ERROR: read\n");
    if (close(in_fd) == -1) fprintf(stderr, "LOG: close input\n");
    if (close(out_fd) == -1) fprintf(stderr, "LOG: close output\n");
    close(in_fd);
    close(out_fd);
    fchdir(fd);
    close(fd);
}

int main() {
    // ls(".");

    char *src  = "mk";
    char *dest = "new_mk";
    cp(dest, src);
}
