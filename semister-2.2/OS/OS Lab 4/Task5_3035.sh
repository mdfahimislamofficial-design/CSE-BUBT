# ./bin/bash
read -p "Enter a number: " num
if [ $num -le 1 ]; then
    echo "$num is not a prime number"
fi
is_prime=1  
i=2
while [ $(($i*$i)) -le $num ]
do
    if [ $((num % i)) -eq 0 ]; then
        is_prime=0
    fi
    ((i++))
done
if [ $is_prime -eq 1 ]; then
    echo "$num is a prime number"
else
    echo "$num is NOT a prime number"
fi
