#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

main() {
  printf("main: \n\tCurrent: %d\n\tParent: %d\n\n", getpid(), getppid());
  pid_t pid = fork();
  int status;

  if ( pid > 0 ) {
    printf("In main forkID: %d\n", pid);
    printf("main: \n\tCurrent: %d\n\tParent: %d\n\n", getpid(), getppid());

    pid_t resPid = wait(&status);
    printf("status: %d pidRes: %d\n\n", status, resPid);
  }
  else {
    printf("In child forkID: %d\n", pid);
    printf("child: \n\tCurrent: %d\n\tParent: %d\n\n", getpid(), getppid());

    execlp("ls", "ls", "-l", NULL);
  }

}
