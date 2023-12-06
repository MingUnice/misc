#!/bin/bash

for i in $(seq $(head -1 file.txt | tr ' ' '\n' | wc -l))
do
  line=$(cut -f $i -d ' ' file.txt | tr '\n' ' ')
  echo $line
done

# 194. Transpose File

# Given a text file file.txt, transpose its content.

# You may assume that each row has the same number of columns, and each field is separated by the ' ' character.

# Example:

# If file.txt has the following content:

# name age
# alice 21
# ryan 30
# Output the following:

# name alice ryan
# age 21 30
