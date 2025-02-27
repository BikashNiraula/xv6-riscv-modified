// user/uproc.h
#ifndef UPROC_H
#define UPROC_H

// A minimal process info structure for user space.
struct uproc {
  int pid;          // Process ID.
  int state;        // Process state (e.g., UNUSED, EMBRYO, SLEEPING, RUNNABLE, RUNNING, ZOMBIE).
  unsigned int sz;  // Size of process memory in bytes.
  char name[16];    // Process name (null-terminated).
};

#endif // UPROC_H
