#!/bin/bash

# Да се състави командна процедура, която получава като параметри на командния си ред два символни низа -
# имена на същестуваща директория и на съществуващ обикновен файл.
# За всеки обикновен файл от директорията да извежда по подходящ начин броя символи в него на стандартния изход,
# а името на всяка директория да се добавя към файла подаден като втори параметър на командната процедура


if test ! $# -eq 2; then
  echo "Program accept exactly 2 arguments"
  exit
fi

if test ! -d $1; then
  echo "$1 is not a directory"
  exit
fi

current_dir=$PWD

cd $1

for i in *
do
  if test -d $i; then
    echo "$i" >> $current_dir/$2
  else
    echo "Chars in $i: " `wc -c $i | cut -d " " -f1`
  fi
done
