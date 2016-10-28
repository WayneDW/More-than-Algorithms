#!/bin/bash

num=$1
echo "add question " $num
git add ./c++/${num}*.cpp ./python/${num}*.py

:<<block
if [ $# -eq 0 ]
then
    echo "Input the question number!"
elif [ $# -eq 1 ]
then
    echo "You haven't commit the task!"
else
    cmt=`expr substr "$*" 3 100` # get substring from input
    cmt=''$cmt''
    echo $cmt
    git commit -m `$cmt`
    git push
fi
block
