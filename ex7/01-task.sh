#!/bin/bash

outExtFilesCnt_1=`ls $1/*.out | wc -l`
outExtFilesCnt_2=`ls $2/*.out | wc -l`

if test $outExtFilesCnt_1 -gt $outExtFilesCnt_2; then
  mkdir newDirectory
  echo newDirectory

  for file in $1/
  do
    if test -f $file && test -r $file && test -w $file; then
      mv $file newDirectory
    fi
  done

fi
