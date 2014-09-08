#!/bin/bash
# rebuild headless *coind (no *coin-qt)

set -e
trap "exit" INT

# make clean

if [ ! -d "src/bdb" ]; then
    cd src
    ./install_bdb.sh
    cd ..
fi

./autogen.sh
./configure --without-gui --disable-tests --enable-debug CPPFLAGS="-I${BDB_PREFIX}/include/ -O2" LDFLAGS="-L${BDB_PREFIX}/lib/" USE_UPNP=

make
strip src/scarycoind
