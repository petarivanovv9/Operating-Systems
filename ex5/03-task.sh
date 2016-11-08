#!/bin/bash

### solution 1
echo "Enter a message:> "
read msg

echo $msg > temp

for user in $*
do
  if who | grep -q -w $user
  then
    write $user < temp
    rm temp
  fi
done
