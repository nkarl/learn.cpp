#define NPROC 9     // number of processes allowed
#define SSIZE 1024  // stack size = 4KB

#define FREE    0
#define READY   1
#define SLEEP   2
#define ZOMBIE  3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct proc {
    struct proc *next;          // next PROC pointer
    int *        ksp;           // saved sp: at byte offset 4
    int          pid;           // PROC ID
    int          ppid;          // parent PROC pid
    int          status;        // PROC status is either FREE or READY, etc.
    int          priority;      // scheduling priority
    int          kstack[1024];  // PROC execution stack
} PROC;
