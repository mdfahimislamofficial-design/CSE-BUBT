# ./bin/bash

echo "Enter your age:"
read z

if [ $z -ge 18 ]; then
    echo "Adult"
else
    echo "Minor"
fi
