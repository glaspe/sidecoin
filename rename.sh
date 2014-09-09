find . -name "*sidecoin*" | awk '{a=$1; gsub(/sidecoin/,"sidecoin"); printf "mv \"%s\" \"%s\"\n", a, $1}' | sh
