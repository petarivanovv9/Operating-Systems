// Копирайте съдържанието на файл1 във файл2

#include <fcntl.h>
#include <stdlib.h>

main(int argc, char* argv[]){
  int fd1;
  int fd2;
  char c;

  if ( ( fd1 = open("/home/petar-ivanov/Projects/Operating-Systems/C-ex1/file_to_read.txt", O_RDONLY) ) == -1 ){
    write(2, "File failed to open in read mode\n", 33);
    exit(-1);
  }

  if ( ( fd2 = open("/home/petar-ivanov/Projects/Operating-Systems/C-ex1/file_to_write.txt", O_CREAT|O_WRONLY) ) == -1 ){
    write(2, "File failed to open in write mode\n", 33);
    exit(-1);
  }

  while ( read(fd1, &c, 1) ) {
    write(fd2, &c, 1);
  }

  close(fd1);
  close(fd2);
}

