#!/bin/bash
cd /wordle-task
git pull
rm -rf /result
mkdir /result
bash build_script.sh
mv build/*.deb /result
cd /result
