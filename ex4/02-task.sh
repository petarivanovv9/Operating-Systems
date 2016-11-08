#!/bin/bash

### solution 1
sort $1 > temp
mv temp $1

### solution 2
# sort $1 > temp
# more temp > $1
# rm temp

### Example
# ./02-task.sh test-2.txt
