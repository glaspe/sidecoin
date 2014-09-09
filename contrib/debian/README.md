
Debian
====================
This directory contains files used to package sidecoind/sidecoin-qt
for Debian-based Linux systems. If you compile sidecoind/sidecoin-qt yourself, there are some useful files here.

## sidecoin: URI support ##


sidecoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install sidecoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your sidecoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/sidecoin128.png` to `/usr/share/pixmaps`

sidecoin-qt.protocol (KDE)

