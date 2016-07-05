#!/bin/bash
No=$1

g++ ${No}* -o tmp
./tmp
rm ./tmp
