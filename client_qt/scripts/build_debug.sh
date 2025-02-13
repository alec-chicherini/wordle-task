#!/bin/bash
./build_script.sh
cd ../build_client
sudo apt remove wordle-task -y
sudo dpkg -i *.deb
