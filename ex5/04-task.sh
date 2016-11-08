#!/bin/bash

### solution 1
echo "Enter a string:>"
read str
echo "Enter a number:>"
read num

for file in `ls`
do
  if [ -d $file ]
  then
    for infile in `ls $file`
    do
      filesize=`cat $file/$infile | wc -c`
      if [ $2 -lt $filesize ]
      then
        echo $infile
      fi
    done
  fi
done
