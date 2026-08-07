#./bin/bash

arm(){ 
        local n1=$1
        local n2=$n1
        local n3=0
        local n4=0
        local n6=0
        while [ $n2 -ne 0 ]; do
                n2=$(( n2 / 10 ))
                n3=$(( n3 + 1 ))
        done
        n2=$n1
        while [ $n2 -gt 0 ]; do
                n4=$(( n2 % 10 ))
                n6=1
                local i=0
                while [ $i -lt $n3 ]; do
                        n6=$(( n6 * n4 ))
                        i=$(( i + 1 ))
               done
                sum=$(( sum + n6 ))
                n2=$(( n2 / 10 ))
        done
        echo $sum
}

armv(){
        local n1=$1
        if [ $( arm $n1 ) -eq $n1 ] ; then 
                echo "Armstrong Number"
        else
                echo "Not Armstromg"
        fi
}

read -p "Input: " num
echo -n "Output: "
armv $num

