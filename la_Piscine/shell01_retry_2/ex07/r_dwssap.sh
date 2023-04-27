#!/bin/bash
cat /etc/passwd | sed -n '11,$p'| awk 'NR%2==0' | cut -d ':' -f1 | rev | sort -r | awk -v X=$FT_LINE1 -v Y=$FT_LINE2 'NR >= X && NR <= Y'| tr '\n' ' '| sed 's/ /, /g' | sed 's/, $//'  | sed 's/$/./g' | tr -d '\n'
