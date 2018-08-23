ldapsearch -Q "(sn=*BON*)" | grep "^sn: " | cut -c 5- | wc -l | bc
