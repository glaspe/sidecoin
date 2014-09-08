#!/bin/bash
# rebuild headless *coind (no *coin-qt)
trap "exit" INT
make clean
./autogen.sh
./configure --with-incompatible-bdb --without-gui --disable-tests --enable-debug --without-miniupnpc CPPFLAGS="-I${BDB_PREFIX}/include/ -O2" LDFLAGS="-L${BDB_PREFIX}/lib/" USE_UPNP=
make
strip src/scarycoind
