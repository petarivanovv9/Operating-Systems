#include <stdio.h> //printf
#include <unistd.h> //execl, execlp
#include <sys/types.h> // fork, getpid, getppid
#include <sys/wait.h> // wait
#include <stdlib.h> // exi

main(int argc, char* argv[]){
  // променлива ползваща се от wait().
  // съдържа кода на завършване на процеса дете.
  int status;

  // fork връща 0 при детето и > 0 при бащата.
  // така различаваме кой процес, кой е.
  if ( fork() > 0 ) {
    // инструктираме процесът баща да изчака завършването на процеса син.
    wait(&status);
    // долните два реда ще се изпълнят чак след като сина завърши.
    printf("Name of executed command is: %s\n", argv[1]);
    exit(0);
  }
  else {
    // чрез execlp изпълняваме процес, с цената на смяна на образа на този, който го изпълнява.
    if ( execlp(argv[1], argv[1], 0) == -1 ) {
      printf("Wrong command!\n");
      exit(-1);
    }
    else {
      // кодът след смяната на образа на процеса никога няма да бъде изпълнен.
      printf("Will this line ever be printed? Why?\n");
    }
  }
}
