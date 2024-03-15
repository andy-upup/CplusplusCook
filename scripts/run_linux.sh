#!/bin/bash

root_path=$(cd $(dirname $0); cd ..; pwd)

source ${root_path}/scripts/build_linux.sh

if [ $# != 1 ]; then
    echo "Please specify execute mode! [CPP|ALGO|DP|EF|OTHERS]"
else
    echo "Execute mode is: $1"
fi

execute_mode=$1

if [ ${execute_mode} == "CPP" ]; then
    cd ${linux_build_path}/install/bin/cplusplus_suger
    ./cpp11_test_case --gtest_filter=test11_copy_construct.copy_times_unit_test
elif [ ${execute_mode} == "ALGO" ]; then
    cd ${linux_build_path}/install/bin/algorithm
    ./graph_test_case --gtest_filter=test_algo_graph.path_find_unit_test
elif [ ${execute_mode} == "DP" ]; then
    cd ${linux_build_path}/install/bin/design_pattern
    ./singleton_test_case --gtest_filter=test_design_pattern.singleton_test_case
elif [ ${execute_mode} == "EF" ]; then
    cd ${linux_build_path}/install/bin/effective
    ./non_member_func_define_test_case --gtest_filter=test_effective.non_member_func_define_unit_test
elif [ ${execute_mode} == "OTHERS" ]; then
    cd ${linux_build_path}/install/bin/others
    ./swap_without_mem_test_case --gtest_filter=test_others.swap_without_mem_test_case
else
    echo "Wrong mode! [CPP|ALGO|DP|EF|OTHERS]"
fi