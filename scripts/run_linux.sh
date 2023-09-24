#!/bin/bash

root_path=$(cd $(dirname $0); cd ..; pwd)

source ${root_path}/scripts/build_linux.sh

cd ${linux_build_path}/test/bin
./gtest_sample --gtest_filter=gtest_sample.print
./function --gtest_filter=cpp_suger.function
./multi_thread --gtest_filter=thread.thread_pool