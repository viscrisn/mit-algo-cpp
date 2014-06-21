#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

int main(void) {
  size_t i;
  printf("Input size to malloc:");
  scanf("&#37;ul", &i);
  if (malloc(i)) printf("malloc successful\n");
  else printf("malloc failed\n");
}
