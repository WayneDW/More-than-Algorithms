#!/bin/bash
git add ./c++/${1}*.cpp ./python/${1}*.py
git commit -m $2
git push
