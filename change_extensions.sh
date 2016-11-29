#!/bin/bash

while [[ $# -ge 1 ]]
do
  echo "$#"
  echo "$1"
  mv "$1" "`basename "$1" .wtf`.txt"
  shift
done
