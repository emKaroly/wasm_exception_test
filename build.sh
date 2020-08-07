#!/bin/bash

BIN="$(pwd)/bin"
if [ ! -d $BIN ]; then
    mkdir $BIN
fi

source ~/Projects_Temp/emsdk/emsdk_env.sh

emcmake cmake -G Ninja -B build -S .
cmake --build build --config Release
emrun.py --no_browser ./bin/index.html
