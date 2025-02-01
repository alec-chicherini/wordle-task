FROM ubuntu:24.04 AS qt_from_source

RUN apt update && \
    apt install -y \
    git \
    g++-13 \
    build-essential \
    libgl1-mesa-dev \
    libfontconfig1-dev \
    libfreetype-dev \
    libx11-dev \
    libx11-xcb-dev \
    libxcb-cursor-dev \
    libxcb-glx0-dev \
    libxcb-icccm4-dev \
    libxcb-image0-dev \
    libxcb-keysyms1-dev \
    libxcb-randr0-dev \
    libxcb-render-util0-dev \
    libxcb-shape0-dev \
    libxcb-shm0-dev \
    libxcb-sync-dev \
    libxcb-util-dev \
    libxcb-xfixes0-dev \
    libxcb-xinerama0-dev \
    libxcb-xkb-dev \
    libxcb1-dev \
    libxext-dev \
    libxfixes-dev \
    libxi-dev \
    libxkbcommon-dev \
    libxkbcommon-x11-dev \
    libxrender-dev

RUN update-alternatives --install /usr/bin/c++ c++ /usr/bin/g++-13 100
COPY --chmod=777 scripts/install_cmake.sh ./
RUN ./install_cmake.sh

RUN wget https://mirror.yandex.ru/mirrors/qt.io/archive/qt/6.7/6.7.3/single/qt-everywhere-src-6.7.3.tar.xz && \
    tar xf qt-everywhere-src-6.7.3.tar.xz

RUN mkdir qt-build && cd qt-build
RUN   ../qt-everywhere-src-6.7.3/configure -release -submodules qtbase -nomake tests -nomake examples
RUN cmake --build . --parallel
RUN cmake --install . --prefix /Qt-6.7.3

ENV QT_BUILDED_FROM_SOURCE_PATH=/Qt-6.7.3

RUN mkdir /result
COPY . /wordle-task
ENTRYPOINT ["bash", "/wordle-task/deploy/rebuild.sh"]

FROM ubuntu:20.04 AS qt_from_repo

ENV DEBIAN_FRONTEND=noninteractive

RUN apt update && \
    apt install -y \
    git \
    g++-10 \ 
    qt5-default
RUN update-alternatives --install /usr/bin/c++ c++ /usr/bin/g++-10 100
COPY --chmod=777 scripts/install_cmake.sh ./
RUN ./install_cmake.sh
RUN mkdir /result
COPY . /wordle-task/
ENTRYPOINT ["bash", "/wordle-task/deploy/rebuild.sh"]
