find . -name "*bitcoin*" | awk '{a=$1; gsub(/bitcoin/,"catchcoin"); printf "mv \"%s\" \"%s\"\n", a, $1}' | sh
