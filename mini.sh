#!/bin/bash
make

if [ -z $1 ] || [ -z $2 ]
then
	echo "./client <text lenght> <PID>"
	exit 1
fi

ARG=`./a.out $1`

./client $2 $ARG