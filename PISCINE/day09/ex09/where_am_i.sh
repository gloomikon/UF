#!/bin/sh

var=$(ifconfig | grep "inet " | cut -d' ' -f2)
if test -z "$var"
then
	echo "I am lost!"
else
	echo $var | tr ' ' '\n'
fi
