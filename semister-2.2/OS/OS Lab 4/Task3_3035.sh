# ./bin/bash
read -p "input: " num
val1=$(($num%400))
val2=$(($num%100))
val3=$(($num%4))
if [ $val3 -eq 0 ] || ([ $val2 -ne 0] && [ $val1 -eq 0]); then
  echo "Is a Leap Year"
else 
 echo "Not a Leap Year"
fi
