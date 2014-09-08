#!/bin/bash
# Compile berkeley db 4.8 from source

set -e
trap "exit" INT

if [ ! -d "bdb" ]; then
    if [ ! -f "db-4.8.30.NC.tar.gz" ]; then
        wget http://download.oracle.com/berkeley-db/db-4.8.30.NC.tar.gz
        # echo '12edc0df75bf9abd7f82f821795bcee50f42cb2e5f76a6a281b85732798364ef  db-4.8.30.NC.tar.gz' | sha256sum -c
    fi
    mkdir -p bdb

    tar -xvf db-4.8.30.NC.tar.gz -C bdb --strip-components=1 > /dev/null 2>&1

    cd bdb/build_unix
    mkdir -p build

    ../dist/configure --disable-shared --enable-cxx --with-pic --prefix=$BDB_PREFIX > /dev/null 2>&1
    make install

    export BDB_PREFIX=$(pwd)/build

    cd ../..
    echo "Done."
else
    export BDB_PREFIX=$(pwd)/bdb/build_unix/build

    echo "Local Berkeley DB installation found."
fi

echo "Checking Berkeley DB version..."

g++ bdb_version_check.cpp -I${BDB_PREFIX}/include/ -L${BDB_PREFIX}/lib/ -O2 -o bdb_version_check
./bdb_version_check
rm bdb_version_check
