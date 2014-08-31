
Debian
====================
This directory contains files used to package scarycoind/scarycoin-qt
for Debian-based Linux systems. If you compile scarycoind/scarycoin-qt yourself, there are some useful files here.

## scarycoin: URI support ##


scarycoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install scarycoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your scarycoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/scarycoin128.png` to `/usr/share/pixmaps`

scarycoin-qt.protocol (KDE)

