#!/bin/bash

SHOULDBE=`cat $3`
WEHAVE=`./$1.build < $2`
if [ "$SHOULDBE" = "$WEHAVE" ]
then
  echo "Test: SUCCESS"
  /usr/bin/time -f "Time: %eSEC" ./$1.build < $2 > /dev/null
else
  echo "Test: WRONG"
fi

