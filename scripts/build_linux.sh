#!/bin/bash

root_path=$(cd $(dirname $0); cd ..; pwd)
cd ${root_path}

linux_build_path=${root_path}/build_linux
if [ -d ${linux_build_path} ]; then
    rm -rf ${linux_build_path}
fi

mkdir -p ${linux_build_path}

cd ${linux_build_path}
cmake -DCMAKE_INSTALL_PREFIX=${linux_build_path} \
      -DBUILD_TEST=OFF                           \
      -DWITH_CPP_SUGER=ON                        \
      -DWITH_ALGO=ON                             \
      -DWITH_DESIGN_PATTERN=ON                   \
..

make -j4
make install