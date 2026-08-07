#./bin/bash

echo "Input"
echo "Copy"
read a

echo "Output"
echo "Copy"
if [ $(($a%2)) -ne 1 ] ; then
	echo "YES"
else
	echo "NO"
fi
