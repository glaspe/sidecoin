#!/bin/bash
# Compile berkeley db 4.8 from source

set -e
trap "exit" INT

if [ ! -f "db-4.8.30.NC.tar.gz" ]; then
    wget http://download.oracle.com/berkeley-db/db-4.8.30.NC.tar.gz
fi
echo '12edc0df75bf9abd7f82f821795bcee50f42cb2e5f76a6a281b85732798364ef db-4.8.30.NC.tar.gz' | sha256sum -c

mkdir -p bdb
tar -xvf db-4.8.30.NC.tar.gz -C bdb --strip-components=1

cd bdb/build_unix
mkdir -p build

BDB_PREFIX=$(pwd)/build

../dist/configure --disable-shared --enable-cxx --with-pic --prefix=$BDB_PREFIX
make install

cd ../..
echo $(pwd)

g++ bdb_version_check.cpp -o bdb_version_check && ./bdb_version_check
rm bdb_version_check
