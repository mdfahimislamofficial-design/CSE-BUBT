# ./bin/bash
read -p "Input: " start end
num=$start
while [ $num -le $end ]
do
if [ $num -le 1 ]; then
    ((num++))
else
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
    echo -n "$num "
fi
fi
((num++))
done
echo

