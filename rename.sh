find . -name "*scarycoin*" | awk '{a=$1; gsub(/scarycoin/,"sidecoin"); printf "mv \"%s\" \"%s\"\n", a, $1}' | sh
