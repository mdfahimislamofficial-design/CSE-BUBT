# ./bin/bash

fac(){ 
	local n1=$1
	if [ $n1 -eq 1 ] ; then
		echo 1
	else
	echo $(($n1* $( fac $(($n1-1)) ) ))
	fi
}

read -p "Input: " num
echo -n "Output: "
fac $num

