#./bin/bash

func() {
	local n1=$1
	local n2=1
	local n3=0
	while [ $n2 -le $n1 ] ; do
		if [ $(( $n2 % 2 )) -eq 0 ] ; then
			n3=$(( $n3 + $n2 ))
		else
			n3=$(( $n3 - $n2 ))
		fi
	n2=$(( $n2 + 1 ))
	done
	echo "Output: "$n3
}

read -p "Input: " n
func $n
