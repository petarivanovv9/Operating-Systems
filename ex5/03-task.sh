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

### Example
# $ ./03-task.sh petar-ivanov asan                                                 130 ↵
# Enter a message:>
# hello my friend
#
# Message from petar-ivanov@petar-ivanov on pts/24 at 21:19 ...
# hello my friend
# EOF
