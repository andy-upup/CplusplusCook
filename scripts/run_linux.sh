#!/bin/bash

root_path=$(cd $(dirname $0); cd ..; pwd)

source ${root_path}/scripts/build_linux.sh

if [ $# != 1 ]; then
    echo "Please specify execute mode! [CPP|ALGO|DP|EF]"
else
    echo "Execute mode is: $1"
fi

execute_mode=$1

if [ ${execute_mode} == "CPP" ]; then
    cd ${linux_build_path}/install/bin/cplusplus_suger
    ./cpp11_test_case --gtest_filter=test11_function.function_test_case
elif [ ${execute_mode} == "ALGO" ]; then
    cd ${linux_build_path}/install/bin/algorithm
    ./sort_test_case --gtest_filter=test_algo_sort.heap_sort_test_case
elif [ ${execute_mode} == "DP" ]; then
    cd ${linux_build_path}/install/bin/design_pattern
    ./singleton_test_case --gtest_filter=test_design_pattern.singleton_test_case
elif [ ${execute_mode} == "EF" ]; then
    cd ${linux_build_path}/install/bin/effective
    ./const_use_test_case --gtest_filter=test_effective.const_use_test_case
else
    echo "Wrong mode! [CPP|ALGO|DP|EF]"
fi