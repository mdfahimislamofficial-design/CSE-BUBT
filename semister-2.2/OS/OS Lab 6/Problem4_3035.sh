#./bin/bash

func(){
	local n1=$1
	local n2=1
	local n3=1
	while [ $n1 -ge 1 ] ; do
		read n2 n3
		n2=$(( $n2 % $n3 ))
		if [ $n2 -eq 0 ] ; then
			echo "0"
		else
			n3=$(( $n3 - $n2 ))
			echo $n3
		fi
		n1=$(( $n1 - 1 ))
	done
}

read -p "Input: " n
func $n
