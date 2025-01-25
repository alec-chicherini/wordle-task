#!/bin/bash
rm -rf /opt/cmake && \
mkdir /opt/cmake && \
wget -P /opt/cmake https://github.com/Kitware/CMake/releases/download/v3.31.2/cmake-3.31.2-linux-x86_64.sh && \
chmod +x /opt/cmake/cmake-3.31.2-linux-x86_64.sh && \
bash -c "/opt/cmake/cmake-3.31.2-linux-x86_64.sh --skip-license --prefix=/opt/cmake" && \
ln -s /opt/cmake/bin/cmake /bin/cmake && \
ln -s /opt/cmake/bin/cpack /bin/cpack