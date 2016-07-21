#!/bin/bash
No=$1
#used for running c++
g++ ${No}*.cpp -o tmp
./tmp
rm ./tmp


