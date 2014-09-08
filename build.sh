#!/bin/bash
# rebuild headless bitcoind (no bitcoin-qt)
trap "exit" INT
make clean
./autogen.sh
./configure --with-incompatible-bdb --without-gui --disable-tests --enable-debug --enable-logging --without-miniupnpc
make
