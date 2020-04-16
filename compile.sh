#!/bin/bash

echo "Compiling list module"

# Compile the actual module and its tests
g++ -c list.cpp
g++ -c tests/tests.cpp

mv *.o compiled/

echo "Finished compiling list module"
