#!/bin/bash
./build_script.sh
cd build
sudo apt remove wordle-task -y
sudo dpkg -i *.deb
