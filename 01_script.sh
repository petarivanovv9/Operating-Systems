#!/bin/bash

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
