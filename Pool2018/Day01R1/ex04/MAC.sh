ifconfig | grep "ether" | rev | cut -c 2- | sed "s/ .*//" | rev
