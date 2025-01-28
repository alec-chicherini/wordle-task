FROM debian:buster

RUN apt update && \
    apt install -y \
    clang-13 \
    make \
    git \
    wget \
    qt5-default

RUN update-alternatives --install /usr/bin/c++ c++ /usr/bin/clang++-13 100 && \
    update-alternatives --install /usr/bin/cc cc /usr/bin/clang-13 100

COPY scripts/install_cmake.sh .
RUN install_cmake.sh

RUN mkdir /result

RUN git clone https://github.com/alec-chicherini/wordle-task.git && cd wordle-task && git pull

ENTRYPOINT ["bash", "/wordle-task/deploy/rebuild.sh"]
