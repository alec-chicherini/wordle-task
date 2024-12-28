#!/bin/bash
cd /wordle-task
git pull
bash build_script.sh
rm /result
mkdir /result
mv build/*.deb /result
