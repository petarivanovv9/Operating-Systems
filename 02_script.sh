#!/bin/bash

# Напишете командна процедура на bash, която приема на командния си ред произволен брой аргументи.
# Аргументите съответстват на съществуващи обикновени файлове и директории в текущата директория.
# Нека командната процедура извежда на стандартния изход подходящо съобщение, ако подаден аргумент е директория,
# започваща с буква 'M'.
# Ако подаденият аргумент е директория, да изведе на стандартния изход само файловете, които имат по-малък размер от
# броя на файловете в директорията.


while [[ $# -ge 1 ]]
do
  if test -d $1; then
    if [[ $1 == M* ]]; then
      echo $1 " is dir begining with M"
    else
      echo $1 " is a directory."
    fi

    echo "Files in $1 that have size smaller than the number of elements in it"
    cd $1
    # On Ubuntu every ls -l begins with "total X" so ignore it
    count_files=`ls -l | grep -v ^t | wc -l`

    if test $count_files -gt 0; then
      for i in *
      do
        file_size=`du -k $i | cut -f1`
        if test $file_size -lt $count_files; then
          echo " $i"
        fi
      done
    fi

    cd ..
  fi

shift
done
