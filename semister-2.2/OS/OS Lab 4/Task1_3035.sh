# ./bin/bash

read -p "input: " num
num=$(($num-1))
val=1
while [ $val -le $num ]
do
  pri=1
  while [ $pri -le $val ]
  do
    echo -n "*"
    ((pri++))
  done
  echo
  ((val++))
done

while [ $val -ge 1 ]
do
  pri=$val
  while [ $pri -ge 1 ]
  do
    echo -n "*"
    ((pri--))
  done
  echo
  ((val--))
done
