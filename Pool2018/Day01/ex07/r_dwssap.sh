cat /etc/passwd | grep -v "^#" | awk 'NR % 2 == 0' | sed "s/:.*//" | rev | sort -r | sed -n "$FT_LINE1,$FT_LINE2"p | rev | sed "s/:.*//" | rev | tr "\n" "," | sed "s/,/, /g" | rev | sed "s/ ,/./" | rev | tr -d '\n'
