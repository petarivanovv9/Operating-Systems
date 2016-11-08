#!/bin/bash

### solution 1
echo "Enter a string:> "
read str

for file in $*
do
  echo "In $file there are `grep -w $str $file | wc -l` $str words."
done

### Example
# $ ./02-task.sh test-5.txt test-5-1.txt
# Enter a string:>
# pesho
# In test-5.txt there are 2 pesho words.
# In test-5-1.txt there are 5 pesho words.
