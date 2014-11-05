## SideCoin

[![Build Status](https://travis-ci.org/tensorjack/sidecoin.svg?branch=master)](https://travis-ci.org/tensorjack/sidecoin)

The sidecar to Bitcoin's motorcycle.  SideCoin is a fork of Bitcoin v. 0.9.1.

Sidecoin allows you to take a snapshot of bitcoin's blockchain distribution and put it
into a new blockchain

    - P2P port: 6543 (16543 for testnet)
    - RPC port: 6544 (16544 for testnet)

### Installation

If you're on a somewhat recent version of Ubuntu, you can install using:

    $ ./install.sh

### OS X Build Instructions

use brew to get boost

./autogen.sh
sudo ./configure --with-boost=/usr/local/Cellar/boost/1.55.0_2/ --with-incompatible-bdb --with-qt
make
