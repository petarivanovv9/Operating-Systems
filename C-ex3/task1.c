// Да се напише програма на С, която получава като параметър - команда (без опции).
// При успешното изпълнение на командата подадена като първи аргуемнт, нека програмата извежда на стандартния изход името на изпълнената команда.

#include <stdio.h> //printf
#include <unistd.h> //execl, execlp
#include <sys/types.h> // fork, getpid, getppid
#include <sys/wait.h> // wait
#include <stdlib.h> // exi

main(int argc, char* argv[]){
  int status;
  // printf("%s\n", argv[1]);
  if ( fork() > 0 ) {
    wait(&status);
    printf("Name of executed command is: %s\n", argv[1]);
    exit(0);
  }
  else {
    if ( execlp(argv[1], argv[1], 0) == -1 ) {
      printf("Wrong command!\n");
      exit(-1);
    }
    else {
      printf("Will this line ever be printed? Why?\n");
    }
  }
}
