#!/usr/bin/bash


input=$1
encoded_str=$(printf "%s" "$input" | xxd -p | tr -d "\n" | sed 's/../%&/g')
echo $encoded_str
