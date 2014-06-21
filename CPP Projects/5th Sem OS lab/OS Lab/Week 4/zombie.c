#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
  pid_t pid1;

  pid1 = fork ();
  if (pid1 > 0) {
    sleep (60);
  }
  else {
    exit (0);
  }
  return 0;
}

