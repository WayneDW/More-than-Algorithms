#!/bin/bash


if [ "$#" -ne 1 ] ; then
  echo "Please type in the words you want to commit!"
  exit 1
fi

git init *
git commit -m "$1"
git push
