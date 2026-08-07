#./bin/bash
read a
echo $a | awk '{for(i=NF; i>0; i--) printf "%s ", $i}'
