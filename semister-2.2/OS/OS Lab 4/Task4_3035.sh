# ./bin/bash
read -p "input: " num
if [ $((num % 400)) -eq 0 ] || { [ $((num % 4)) -eq 0 ] && [ $((num % 100)) -ne 0 ]; }; then
    echo "$num is a Leap Year"
else
    prev1=$((num - 1))
    prev2=$((num - 2))
    next1=$((num + 1))
    if [ $((prev1 % 400)) -eq 0 ] || { [ $((prev1 % 4)) -eq 0 ] && [ $((prev1 % 100)) -ne 0 ]; }; then
        echo "Output: $prev1"
    elif [ $((prev2 % 400)) -eq 0 ] || { [ $((prev2 % 4)) -eq 0 ] && [ $((prev2 % 100)) -ne 0 ]; }; then
        echo "Output: $prev2"
    elif [ $((next1 % 400)) -eq 0 ] || { [ $((next1 % 4)) -eq 0 ] && [ $((next1 % 100)) -ne 0 ]; }; then
        echo "Output: $next1"
    else
        echo "Output: $next2"
    fi
fi
