#include "../kernel/types.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  uint t = uptime();
  printf("System uptime: %d ticks\n", t);
  exit(0);
}
