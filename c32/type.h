#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10

typedef struct node {
  struct node *next;
  int id;
  char name[64];
} NODE;
