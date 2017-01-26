#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

main(int argc, char* argv[]) {
  int status;
  pid_t res1 = fork();

  if ( argc != 3 ) {
    printf("Wrong number of arguments!\n");
    exit(-1);
  }

  if ( res1 > 0 ) {
    pid_t res2 = fork();

    if ( res2 > 0 ) {
      pid_t ho = wait(&status);
      if (res2 == ho) {
        printf("%d\n", status);
        exit(0);
      }
      wait(&status);
      printf("%d\n", status);
      exit(0);
    }
    else {
      execlp(argv[2], argv[2], NULL);
      exit(-1);
    }

  }
  else {
    execlp(argv[1], argv[1], NULL);
    exit(-1);
  }

}
