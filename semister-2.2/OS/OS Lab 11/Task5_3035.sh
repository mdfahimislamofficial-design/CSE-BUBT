#!/bin/bash
read s1
read s2
i=0
result=""
while [ $i -lt ${#s1} ]; do
    ch="${s1:i:1}"
    if [[ "$s2" == *"$ch"* ]]; then
        result="$result$ch"
    fi
    i=$((i+1))
done
echo "$result"

