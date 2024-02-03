#include <gtest/gtest.h>

#include <iostream>
#include <tuple>
#include <vector>

#include "class_module.h"
#include "constexpr_module.h"
#include "function_module.h"
#include "lambda_module.h"
#include "reference_module.h"
#include "smart_pointer.h"
#include "template_module.h"
#include "tuple_module.h"
#include "vector_module.h"

TEST(TestVector, back_test_case) {
    std::vector<Person> person;
    // auto p = Person(1);
    // person.emplace_back(std::move(p));
    std::string name = "Tom";
    person.emplace_back(name, 2);

    // person.push_back(p);
}

TEST(TestAutoDecltype, auto_decltype_test_case) {
    int n = 10;
    int &r1 = n;
    auto r2 = r1;
    r2 = 20;
    std::cout << n << ", " << r1 << ", " << r2 << std::endl;
    decltype(r1) r3 = n;
    r3 = 99;
    std::cout << n << ", " << r1 << ", " << r3 << std::endl;
}

TEST(TestUsing, using_map_test_case) {
    str_map<int> mp;
}

TEST(TestFunction, func_arg_test_case) {
    VairFun(4, 100, 110, 120, 130);
}

TEST(TestTemplate, variable_template_test_case) {
    VarFun(1, "Hello World!", 2.34);
}

TEST(TestTuple, tuple_test_case) {
    UseApisOfTuple();
}

TEST(TestClass, class_test_case) {
    Foo a1(123);
    Foo a2 = 123;
    a2.Print();
}

TEST(TestLambda, lambda_test_case) {
    SortWithLambda();
    SortWithFunc();
    LambdaRename();
    PassValVsRef();
}

TEST(TestConstexpr, constexpr_test_case) {
    ReassignToReadOnlyVar();
    InitialArray();
}

TEST(TestReference, reference_test_case) {
    // construct
    std::cout << "Demo1: " << std::endl;
    Demo demo1 = GetDemo();

    std::cout << "Demo2: " << std::endl;
    Demo demo2 = demo1;

    std::cout << "Demo3: " << std::endl;
    Demo demo3 = std::move(demo1);
}

TEST(TestReference, lval_rval_test_case) {
    LvalRvalDemo demo(10);
    std::cout << demo.GetNum() << std::endl;
    std::cout << std::move(demo).GetNum() << std::endl;
}

TEST(TestReference, ref_qualifier_test_case) {
    RefQualifierDemo demo(10, 20);
    std::cout << demo.GetNumLvalRef() << std::endl;
    // std::cout << std::move(demo).GetNumLvalRef() << std::endl;
    // std::cout << demo.GetNumRvalRef() << std::endl;
    std::cout << std::move(demo).GetNumRvalRef() << std::endl;
}

TEST(TestForward, forward_test_case) {
    Func(5);
    int val = 1;
    Func(val);
}

TEST(TestMoveConstruct, move_construct_test_case) {
    Second second;
    Second second_move = std::move(second);
    second_move.Print();
}

TEST(TestSmartPointer, shared_ptr_test_case) {
    InitSharedPtr();
    UseSharedPtrReset();
}

TEST(TestSmartPointer, unique_ptr_test_case) {
    InitUniquePtr();
    UseUniquePtrApi();
}