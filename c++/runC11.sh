#!/bin/bash
g++ -std=c++11 $1 -o tmp; ./tmp; rm ./tmp
