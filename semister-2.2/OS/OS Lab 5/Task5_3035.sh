#!/bin/bash

gcd() {
  local x=$1
  local y=$2
  while [ $y -ne 0 ]; do
    local temp=$y
    y=$(( x % y ))
    x=$temp
  done
  echo $x
}

read -p "Enter two number:" a b
gcd $a $b
