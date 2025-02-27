#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "user.h"
#include "../kernel/fcntl.h"


char buf[512];

int
main(int argc, char *argv[])
{
  int fd_src, fd_dst, n;

  if(argc < 3){
    printf("Usage: cp source dest\n");
    exit(0);
  }

  // Open source file for reading.
  fd_src = open(argv[1], 0);
  if(fd_src < 0){
    printf("cp: cannot open %s\n", argv[1]);
    exit(0);
  }

  // Open destination file for writing; create if it doesn't exist.
  fd_dst = open(argv[2], O_CREATE | O_WRONLY);
  if(fd_dst < 0){
    printf("cp: cannot create %s\n", argv[2]);
    close(fd_src);
    exit(0);
  }

  // Copy the contents from the source to the destination.
  while((n = read(fd_src, buf, sizeof(buf))) > 0){
    if(write(fd_dst, buf, n) != n){
      printf("cp: write error\n");
      close(fd_src);
      close(fd_dst);
      exit(0);
    }
  }

  // Clean up.
  close(fd_src);
  close(fd_dst);
  exit(0);
}
