#include <stdio.h>
#include <stdlib.h>

char *make_arr2() {
  char *arr2 = (char *)malloc(sizeof(char) * 8);

  for (auto i = 0; i < 8; ++i) {
    arr2[i] = i + '0';
  }
  return arr2;
}

int main() {
  char arr1[8] = {'1', '2', '3', '4'};
  char *arr2 = make_arr2();
  printf("arr1: %s\n", arr1);
  printf("arr2: %s\n", arr2);
}
