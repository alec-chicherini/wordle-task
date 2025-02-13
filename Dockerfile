FROM ubuntu:24.04 AS qt_from_source

COPY . /wordle-task

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

RUN bash scripts/install_cmake.sh

RUN wget https://mirror.yandex.ru/mirrors/qt.io/archive/qt/6.7/6.7.3/single/qt-everywhere-src-6.7.3.tar.xz && \
    tar xf qt-everywhere-src-6.7.3.tar.xz

RUN mkdir qt-build && cd qt-build
RUN   ../qt-everywhere-src-6.7.3/configure -release -submodules qtbase -nomake tests -nomake examples
RUN cmake --build . --parallel 4
RUN cmake --install . --prefix /Qt-6.7.3

ENV QT_BUILDED_FROM_SOURCE_PATH=/Qt-6.7.3

RUN mkdir /result
ENTRYPOINT ["bash", "/wordle-task/client_qt/deploy/rebuild.sh"]

FROM ubuntu:20.04 AS qt_from_repo
ENV DEBIAN_FRONTEND=noninteractive
RUN apt update && \
    apt install -y \
    git \
    g++-10 \ 
    qt5-default
RUN update-alternatives --install /usr/bin/c++ c++ /usr/bin/g++-10 100
COPY . /wordle-task
RUN bash /wordle-task/scripts/install_cmake.sh
RUN mkdir /result
ENTRYPOINT ["bash", "/wordle-task/client_qt/deploy/rebuild.sh"]

FROM ubuntu:24.04 AS qt_wasm_build_from_source
ENV DEBIAN_FRONTEND=noninteractive
RUN apt update && \
    apt install -y \
    git \
    python3 \
    xz-utils \
    cmake \
    clang \
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
    libxrender-dev \
    libclang-18-dev

RUN git clone https://github.com/emscripten-core/emsdk.git && \
    cd emsdk && \
    ./emsdk install 3.1.50 && \
    ./emsdk activate 3.1.50 && \
    bash ./emsdk_env.sh

ENV EMSDK=/emsdk
ENV EMSDK_NODE=/emsdk/node/20.18.0_64bit/bin/node
ENV PATH=/emsdk:/emsdk/upstream/emscripten:/emsdk/node/20.18.0_64bit/bin:${PATH}

RUN apt update && \
    apt install -y \
    wget
RUN wget https://mirror.yandex.ru/mirrors/qt.io/archive/qt/6.7/6.7.3/single/qt-everywhere-src-6.7.3.tar.xz && \
    tar xf qt-everywhere-src-6.7.3.tar.xz  && \
    cd qt-everywhere-src-6.7.3 && \
    mkdir qt-build-base && cd qt-build-base && \
   ../configure -release -submodules qtbase,qtshadertools,qttools,qtquick3d,qtremoteobjects,qtscxml -nomake tests -nomake examples
RUN cd /qt-everywhere-src-6.7.3/qt-build-base && cmake --build . --parallel 4
RUN cd /qt-everywhere-src-6.7.3/qt-build-base && cmake --install . --prefix /Qt-6.7.3-base

RUN cd /qt-everywhere-src-6.7.3 && mkdir qt-build-wasm && cd qt-build-wasm && \
    ../configure -qt-host-path /Qt-6.7.3-base -platform wasm-emscripten -prefix /Qt-6.7.3-wasm
RUN cd /qt-everywhere-src-6.7.3/qt-build-wasm && cmake --build . --parallel 4
RUN cd /qt-everywhere-src-6.7.3/qt-build-wasm && cmake --install . --prefix /Qt-6.7.3-wasm

COPY . /wordle-task
RUN cd wordle-task/client_qt && mkdir build_wasm && cd build_wasm && \
    /Qt-6.7.3-wasm/bin/./qt-cmake .. && \
    cmake --build .
RUN chmod 755 /wordle-task/scripts/run_python_http_server_wasm.sh
ENTRYPOINT ["/wordle-task/scripts/run_python_http_server_wasm.sh", "/wordle-task/client_qt/build_wasm"]