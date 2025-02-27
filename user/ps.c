// user/ps.c
#include "../kernel/types.h"
#include "user.h"
#include "uproc.h"

#define MAX_PROCS 64

int
main(int argc, char *argv[])
{
  struct uproc proc_table[MAX_PROCS];
  int i, n;

  n = getprocs(MAX_PROCS, proc_table);
  if(n < 0){
    printf(2, "getprocs failed\n");
    exit();
  }

  printf(1, "PID\tState\tSize\tName\n");
  for(i = 0; i < n; i++){
    printf(1, "%d\t%d\t%d\t%s\n",
           proc_table[i].pid, proc_table[i].state,
           proc_table[i].sz, proc_table[i].name);
  }
  exit();
}
