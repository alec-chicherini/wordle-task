#!/bin/bash
rm build -rf
mkdir build
cd build
cmake ..
cmake --build .
