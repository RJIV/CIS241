#!/bin/bash
grep 'gvsu' input.txt
sed -n '1p' input.txt
gawk '/gvsu/ {printf "%s\n", $2}' input.txt

cp input.txt input2.txt
sed -i '/^$/d' input2.txt
sed -i '/Linux/d' input2.txt

sed -i 's/cis/CIS/g' input2.txt
echo "Please enter a string to be replaced:"
read string
result=`grep "$string" input2.txt | wc -l`
if [ "$result" = 0 ]
then
	echo "String $string does not exist!"
else
	echo "Please enter the new string:"
	read newString
	sed -i "s/$string/$newString/g" input2.txt
fi

