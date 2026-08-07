#!/bin/bash
read -a a
x=""
i=0
while [ $i -lt ${#a[@]} ]; do
  num="${a[$i]}"
  if [[ ! " $b " =~ " $num " ]]; then
    b+="$num "
  fi
  ((i++))
done
echo "$b"

