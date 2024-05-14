#!/bin/bash
cd Receiver
rm -rf build
~/Qt/6.5.3/gcc_64/bin/qt-cmake -B build
cd build
make
exec ./DBusReceiver