#!/usr/bin/bash


input=$1
echo $(printf "%s" "$input" )
echo $(printf "%s" "$input" | xxd -p )
echo $(printf "%s" "$input" | xxd -p | tr -d "\n" )
echo $(printf "%s" "$input" | xxd -p | tr -d "\n" | sed 's/../%&/g')
#encoded_str=$(printf "%s" "$input" | xxd -p | tr -d "\n" | sed 's/../%&/g')
#echo $encoded_str
