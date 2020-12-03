#!/bin/bash

set -euxo pipefail

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

ROOT_DIR=$SCRIPT_DIR

BUILD_DIR=$ROOT_DIR/build


mkdir -p $BUILD_DIR

rm -rf $BUILD_DIR/*

cd $BUILD_DIR

conan install ..

cmake .. -GNinja -DCMAKE_MODULE_PATH=$BUILD_DIR

cmake --build .

ctest
