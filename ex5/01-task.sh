#!/bin/bash

### solution 1
while true
do
  if who | grep -q $1
    echo "OMG"
  then
    echo "BOOOM"
    break
  fi
done

### Example
