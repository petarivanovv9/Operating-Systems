#!/bin/bash

who | grep -w $1 | wc -l

# Example
# $> ./01-task.sh petar-ivanov
# 2
