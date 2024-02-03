#!/bin/bash

root_path=$(cd $(dirname $0); cd ..; pwd)

source ${root_path}/scripts/build_linux.sh

cd ${linux_build_path}/install/bin/cplusplus_suger
# ./gtest_sample --gtest_filter=gtest_sample.print
# ./function --gtest_filter=cpp_suger.function
./cpp11_test_case --gtest_filter=TestSmartPointer.unique_ptr_test_case