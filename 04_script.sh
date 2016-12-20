#!/bin/bash

for dir in /home/*
do
  if test -d $dir && test -r $dir && test -x $dir; then
    echo $dir >> $HOME/$1
  fi
done

chmod u=rwx $HOME/$1
chmod g=rw $HOME/$1
chmod o=r $HOME/$1
