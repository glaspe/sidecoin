#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/sidecoin.png
ICON_DST=../../src/qt/res/icons/sidecoin.ico
convert ${ICON_SRC} -resize 16x16 sidecoin-16.png
convert ${ICON_SRC} -resize 32x32 sidecoin-32.png
convert ${ICON_SRC} -resize 48x48 sidecoin-48.png
convert sidecoin-16.png sidecoin-32.png sidecoin-48.png ${ICON_DST}

