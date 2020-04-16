#!/bin/bash

if [ -z $1 ]; then
    echo "Compiling list module"
    g++ -c list.cpp
else
if [ $1 == -t ]; then
    echo "Compiling list module and tests"
    g++ -c list.cpp
    g++ -c tests/tests.cpp
fi
fi

mv *.o compiled/

echo "Finished compiling list module"
