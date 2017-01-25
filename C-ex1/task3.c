// Реализирайте команда wc, с един аргумент подаден като входен параметър
// По-долу е предоставен вариант на решение на задачата без проверки (във възможно най-опростен вариант)

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

main(int argc, char* argv[]) {
  int fd1;
  char c;
  int lines=0, words=0, chars=0;

  fd1 = open(argv[1], O_RDONLY);

  while( read(fd1, &c, 1) ) {
    if (c == '\n') {
      lines++;
      words++;
    }

    if (c == ' ') {
      words++;
    }

    chars++;
  }

  printf("File %s has:\n%d number of lines.\n%d number of words.\n%d number of chars.\n", argv[1], lines, words, chars);
  close(fd1);
}


// Example

// ./task3 "/home/petar-ivanov/Projects/Operating-Systems/C-ex1/file_to_read.txt"              1 ↵
// File /home/petar-ivanov/Projects/Operating-Systems/C-ex1/file_to_read.txt has:
// 1 number of lines.
// 1 number of words.
// 6 number of chars.
