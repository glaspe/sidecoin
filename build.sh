#!/bin/bash
# rebuild headless *coind (no *coin-qt)

set -e
trap "exit" INT

# make clean

echo "Installing Berkeley DB 4.8..."
cd src
source ./install_bdb.sh > /dev/null 2>&1
cd ..
echo "Done."

echo "*********"
echo $BDB_PREFIX
echo "*********"

# ./autogen.sh
srcdir="$(dirname $0)"
cd "$srcdir"
autoreconf --install --force --prepend-include=${BDB_PREFIX}/include/ --verbose

./configure CPPFLAGS="-I${BDB_PREFIX}/include/ -O2" LDFLAGS="-L${BDB_PREFIX}/lib/" USE_UPNP=

make
strip src/scarycoind
