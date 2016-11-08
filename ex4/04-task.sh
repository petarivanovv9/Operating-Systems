#!/bin/bash

### solution 1
current_dir=$PWD

cd $1

counter_all=`ls -l | wc -l`

dir_names=`ls`

counter_dirs=`file $dir_names | grep -w directory | wc -l`

cd $current_dir

counter_files=`expr $counter_all - $counter_dirs`

echo "The number of all files is $counter_all"
echo "The number of the dirs is $counter_dirs"
echo "The number of the files is $counter_files"

### Example
# $ ./04-task.sh /home/petar-ivanov/Projects/Operating-Systems
# The number of all files is 4
# The number of the dirs is 1
# The number of the files is 3
