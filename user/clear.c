#include "../kernel/types.h"  // Defines types like uint.
#include "user/user.h"

int main(int argc, char *argv[]) {
  // ANSI escape sequence to clear the screen and move the cursor to the home position
  printf("\033[H\033[J");
  exit(0);
}