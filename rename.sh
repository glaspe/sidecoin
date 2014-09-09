find . -name "*bitcoin*" | awk '{a=$1; gsub(/bitcoin/,"sidecoin"); printf "mv \"%s\" \"%s\"\n", a, $1}' | sh
