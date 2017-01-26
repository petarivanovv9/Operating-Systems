#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <fcntl.h>

main(int argc, char* argv[]) {
  int status;
  int fd1;
  char c;

  if ( fork() > 0 ) {
    wait(&status);

    if ( ( fd1 = open(argv[1], O_RDONLY, 0600) ) == -1 ) {
      write(2, "Something went wrong!\n", 22);
      exit(-1);
    }
    else {
      while ( read(fd1, &c, 1) == 1) {
        write(1, &c, 1);
        if (c == '\n') continue;
        c = ' ';
        write(1, &c, 1);
      }
    }
  }
  else {
    if ( ( fd1 = open(argv[1], O_WRONLY|O_CREAT|O_TRUNC, 0600) ) == -1 ) {
      write(2, "Something went wrong!\n", 22);
      exit(-1);
    }
    else {
      write(fd1, "Hello Tux!\n", 11);
      close(fd1);
    }
  }

}

// Example

// ./task3 testing.txt
// H e l l o   T u x !
