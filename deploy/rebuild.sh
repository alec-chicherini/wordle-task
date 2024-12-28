#!/bin/bash
cd /wordle-task
git pull
bash build_script.sh
mv build/*.deb /result
