#!/bin/bash
# rebuild headless *coind (no *coin-qt)

set -e
trap "exit" INT

if [ -f "Makefile" ]; then
    echo "Making clean..."
    make clean > /dev/null 2>&1
fi

echo "Installing Berkeley DB 4.8..."
cd src
source ./install_bdb.sh
cd ..
echo "Done."

srcdir="$(dirname $0)"
cd "$srcdir"
autoreconf --install --force --prepend-include=${BDB_PREFIX}/include/

./configure CPPFLAGS="-I${BDB_PREFIX}/include/ -O2 -DNDEBUG" LDFLAGS="-L${BDB_PREFIX}/lib/" USE_UPNP= --without-gui --disable-tests

make
strip src/scarycoind
