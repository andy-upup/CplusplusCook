#include <gtest/gtest.h>
#include <time.h>

#include <cstdlib>
#include <iostream>

#include "others.h"

TEST(test_algo_others, juice_unit_test) {
    std::cout << "1: " << algo::JuiceNum(1) << std::endl;
    std::cout << "2: " << algo::JuiceNum(2) << std::endl;
    std::cout << "3: " << algo::JuiceNum(3) << std::endl;
    std::cout << "4: " << algo::JuiceNum(4) << std::endl;
    std::cout << "5: " << algo::JuiceNum(5) << std::endl;
    std::cout << "6: " << algo::JuiceNum(6) << std::endl;
    std::cout << "7: " << algo::JuiceNum(7) << std::endl;
    std::cout << "8: " << algo::JuiceNum(8) << std::endl;
    std::cout << "9: " << algo::JuiceNum(9) << std::endl;
    std::cout << "10: " << algo::JuiceNum(10) << std::endl;
}

TEST(test_algo_others, pipeline_unit_test) {
    std::vector<algo::Instruction> program{
        algo::Instruction(0), algo::Instruction(1),
        algo::Instruction(2), algo::Instruction(3),
        algo::Instruction(4), algo::Instruction(5),
        algo::Instruction(6)};
    algo::ThreeStagePipeline pipeline;
    pipeline.Run(program);
}