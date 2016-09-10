#!/usr/bin/expect


if [ "$#" -ne 2 ] ; then
  echo "Please type in the question number and the words that you want to commit!"
  exit 1
fi

git add ./python/${1}*.py ./c++/${1}*.cpp
git commit -m $2
git push
expect "Username for 'https://github.com':" { send "waynedw\r"; exp_continue }
expect "Password for 'https://waynedw@github.com':" { send "dw070703\r"; exp_continue }
