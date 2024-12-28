FROM debian:buster

RUN apt update && \
    apt install -y \
    clang-13 \
    make \
    git \
    wget \
    qt5-default

RUN  rm -rf /opt/cmake && \
     mkdir /opt/cmake && \
     wget -P /opt/cmake https://github.com/Kitware/CMake/releases/download/v3.31.2/cmake-3.31.2-linux-x86_64.sh && \
     chmod +x /opt/cmake/cmake-3.31.2-linux-x86_64.sh && \
     bash -c "/opt/cmake/cmake-3.31.2-linux-x86_64.sh --skip-license --prefix=/opt/cmake" && \
     ln -s /opt/cmake/bin/cmake /bin/cmake && \
     ln -s /opt/cmake/bin/cpack /bin/cpack

RUN git clone https://github.com/alec-chicherini/wordle-task.git && cd wordle-task && git pull

ENTRYPOINT ["bash", "/wordle-task/deploy/rebuild.sh"]
