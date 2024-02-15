#!/bin/bash

root_path=$(cd $(dirname $0); cd ..; pwd)

source ${root_path}/scripts/build_linux.sh

if [ $# != 2]; then
    echo "Please specify execute mode! [CPP|ALGO]"
else
    echo "Execute mode is: $1"
fi

execute_mode=$1

if [ ${execute_mode} == "CPP" ]; then
    cd ${linux_build_path}/install/bin/cplusplus_suger
    ./cpp11_test_case --gtest_filter=test11_function.function_test_case
elif [ ${execute_mode} == "ALGO" ]; then
    cd ${linux_build_path}/install/bin/algorithm
    ./sort_test_case --gtest_filter=test_algo_sort.merge_sort_test_case
else
    echo "Wrong mode! [CPP|ALGO]"
fi