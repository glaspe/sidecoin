#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/scarycoin.png
ICON_DST=../../src/qt/res/icons/scarycoin.ico
convert ${ICON_SRC} -resize 16x16 scarycoin-16.png
convert ${ICON_SRC} -resize 32x32 scarycoin-32.png
convert ${ICON_SRC} -resize 48x48 scarycoin-48.png
convert scarycoin-16.png scarycoin-32.png scarycoin-48.png ${ICON_DST}

