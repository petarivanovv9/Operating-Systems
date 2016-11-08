#!/bin/bash

### solution 1
head -$3 $1 | tail -$2 | sort -r

### Example
# $ ./03-task.sh test-3.txt 5 10
# tretre
# serfewsfsd
# bvc
# 653
# 3vc
