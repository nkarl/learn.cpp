#include <stdio.h>
#include <string.h>
#include <libgen.h>

int main() {
  char *pathname = "/a/b/c";
  char buf[256] = {0};
  char *parent, *child;

  strcpy(buf, pathname);
  printf("buf \t== %s\n", buf);
  parent = dirname(buf);
  printf("parent \t== %s\n", parent);
  strcpy(buf, pathname);
  child = basename(buf);
  printf("child \t== %s\n", child);
}

