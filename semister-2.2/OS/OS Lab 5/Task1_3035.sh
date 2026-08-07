#!/bin/bash

MIS() {
    local n=$1
    local actual_sum=0
    echo "Enter $n numbers (one per line):"
    for (( i=0; i<n; i++ ))
    do
        read num
        actual_sum=$((actual_sum + num))
    done
 
    local total_sum=$(( n * (n + 1) / 2 ))
 
    local missing=$(( total_sum - actual_sum ))
    echo "Missing number: $missing"
}
read -p "Enter total count (n): " n
MIS "$n"
