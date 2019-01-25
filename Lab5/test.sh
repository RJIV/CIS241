#!/bin/bash
#test.sh

if test $# -eq 0
	then
		echo "Must provide an argument"
		exit 1
fi

if test "$1" = "-c" 
	then
		echo "The number of files:"
		ls | wc -l
		echo "The number of bytes:"
		ls | wc -c
fi

if test "$1" = "-l"
	then
		echo "List all the files"
		ls -a
fi

if test "$1" = "--help" 
	then
		echo "How to run this script:"
		echo "-c	Displays the number of files and how many bytes."
		echo "-l	Lists all the files."
		echo "--help	Diplays how to run this script."
fi

if [ ! -d "/home/hamilrob/backup" ]
	then
		mkdir /home/hamilrob/backup
fi

echo "The number of files in the current directory:"
ls | wc -l
echo "The number of bytes in the current directory:"
ls | wc -c
