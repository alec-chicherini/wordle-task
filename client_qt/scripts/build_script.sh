#!/bin/bash
rm ../build_client -rf
mkdir ../build_client
cd ../build_client
cmake ..
cmake --build .
cpack .
