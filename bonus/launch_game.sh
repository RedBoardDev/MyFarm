#!/bin/sh

input="bonus/list_all_files.txt"
return_value=0

for i in $(cat $input)
do
    if [[ ! -f $i ]]; then
        echo "$i doesnt exist"
        return_value=1
    fi
done

if [[ $return_value -eq 1 ]]; then
    exit 1
fi

make && ./my_rpg
