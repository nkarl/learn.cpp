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

void ls(const char *dirpath) {
    DIR           *dirp;
    struct dirent *entry;

    bool isCurrent = strcmp(dirpath, ".") == true;
    dirp           = opendir(dirpath);
    if (dirp == NULL) {
        fprintf(stderr, "opendir failed on '%s'", dirpath);
        return;
    }

    /* for each entry in this current directory, print child dir and file */
    for (; (entry = readdir(dirp));) {
        errno = 0;
        if (!isCurrent) printf("\t> %s/", dirpath);
        printf("%s\n", entry->d_name);
    }

    if (errno != 0) fprintf(stderr, "readdir");
    if (closedir(dirp) == -1) fprintf(stderr, "closedir");
}

int main() {
    ls(".");
}
