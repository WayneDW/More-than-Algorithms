#!/bin/bash

num=$1
echo "add question " $num
if [ -f ./c++/${num}_*[^.cpp] ]
then
   rm ./c++/${num}_*[^.cpp] # delete executable file 
fi
git add ./c++/${num}_*.cpp 
#git add ./python/${num}*.py

if [ $# -eq 0 ]
then
    echo "Input the question number!"
elif [ $# -eq 1 ]
then
    echo "You haven't commit the task!"
else
    len=${#num}
    echo $n
    if [ $len -eq 3 ]
    then
        cmt=`expr substr "$*" 4 100` # get the 2nd-100th parameters as commit
    elif [ $len -eq 2 ]
    then
        cmt=`expr substr "$*" 3 100` # get the 2nd-100th parameters as commit
    elif [ $len -eq 1 ]
    then
        cmt=`expr substr "$*" 2 100` # get the 2nd-100th parameters as commit
    fi
    
    cmt=''$cmt''
    echo $cmt
    git commit -m "${cmt}"
    git push
fi
