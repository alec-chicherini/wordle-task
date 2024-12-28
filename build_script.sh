#!/bin/bash
rm build -rf
mkdir build
cd build
cmake ..
cmake --build .
cpack .
sudo apt remove wordle-task -y
sudo dpkg -i *.deb
