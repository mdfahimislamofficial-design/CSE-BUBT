# ./bin/bash

pal() {
    local st="$1"
    local rst=$(echo "$st" | rev)
    
    if [ "$st" = "$rst" ]; then
        echo "Palindrome"
    else
        echo "Not Palindrome"
    fi
}

read -p "Input: " st
echo -n "Output: "
pal "$st"

