#!/bin/bash
No=$1
#used for running c++
g++ ${No}* -o tmp
./tmp
rm ./tmp


