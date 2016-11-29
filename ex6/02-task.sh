#!/bin/bash

for file in $1/*.c:
do
  filename=$(basename $file .c)
  cc file -o "$filename".exe &
done
