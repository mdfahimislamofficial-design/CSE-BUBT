#./bin/bash
read a
echo $a | grep -oi [aAeEiIoOuU] | wc -l
