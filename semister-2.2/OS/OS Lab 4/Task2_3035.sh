# ./bin/bash

read -p "input: " num
val1=1
val2=1
pri=1
while [ $pri -le $num ]
do
  echo -n "$val2 "
  tem=$val1
  val1=$(($val1+$val2))
  val2=$tem
  ((pri++))
done
