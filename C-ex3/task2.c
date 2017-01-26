#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

main(int argc, char* argv[]) {
  int status;
  int pid_of_child;
  int i;

  for (i = 1; i < 4; i++) {
    if ( ( pid_of_child = fork() ) > 0 ) {
      wait(&status);

      printf("Pid of first child is: %d, %d\n", pid_of_child, getpid());
      printf("Exit code of child with pid %d is: %d\n", pid_of_child, status);
    }
    else {
      if ( execlp(argv[i], argv[i], 0) == -1 ) {
        printf("Wrong command!\n");
        exit(-1);
      }
      else {
        printf("Will this line ever be printed? Why?\n");
      }
    }
  }

}
