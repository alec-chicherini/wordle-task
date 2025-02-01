#!/bin/bash
cd /wordle-task
rm build -rf
mkdir build
cd build

if [ -n $QT_BUILDED_FROM_SOURCE_PATH ]
then
	cmake .. -DCMAKE_PREFIX_PATH=$QT_BUILDED_FROM_SOURCE_PATH/lib/cmake
else
	cmake ..
fi

cmake --build .
cpack .
mv *.deb /result