#!/bin/bash

# Run the compiler
bash compile.sh -t

# Combine the two files and move to compiled/
g++ -o tests.out compiled/tests.o compiled/list.o
mv tests.out compiled/

# Run the tests file
echo "Running the test files now..."
./compiled/tests.out
