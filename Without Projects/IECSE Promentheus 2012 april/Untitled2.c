
#include <stdio.h>

int main()
{
  char string [256];

  printf ("Enter your address: ");

  gets (string);

  printf ("Your address is: %s\n",string);
  return 0;
}

