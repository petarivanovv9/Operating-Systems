#!/bin/bash

ls $1/*.txt >fileB

ls $1 | wc -l >>fileB

num_files=`grep $2 $1/*.txt | wc -l`

echo "The number of lines that contains $2 is $num_files"

echo $@ # all given arguments
echo $# # the number of all given arguments

### Example
# $ ./03_script.sh ex5 ho
# The number of lines that contains ho is 11
