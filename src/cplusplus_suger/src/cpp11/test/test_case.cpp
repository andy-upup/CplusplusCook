#include <gtest/gtest.h>

#include <iostream>
#include <tuple>
#include <vector>

#include "bind_module.h"
#include "class_module.h"
#include "constexpr_module.h"
#include "construct_func.h"
#include "function_module.h"
#include "lambda_module.h"
#include "reference_module.h"
#include "smart_pointer.h"
#include "template_module.h"
#include "tuple_module.h"
#include "variable_parameter_module.h"
#include "vector_module.h"

TEST(test11_vector, back_unit_test) {
    std::vector<Person> person;
    // auto p = Person(1);
    // person.emplace_back(std::move(p));
    std::string name = "Tom";
    person.emplace_back(name, 2);

    // person.push_back(p);
}

TEST(test11_auto_decltype, auto_decltype_unit_test) {
    int n = 10;
    int &r1 = n;
    auto r2 = r1;
    r2 = 20;
    std::cout << n << ", " << r1 << ", " << r2 << std::endl;
    decltype(r1) r3 = n;
    r3 = 99;
    std::cout << n << ", " << r1 << ", " << r3 << std::endl;
}

TEST(test11_using, using_map_unit_test) {
    str_map<int> mp;
}

TEST(test11_variable_parameter, variable_parameter_unit_test) {
    VairFun(4, 100, 110, 120, 130);
}

TEST(test11_template, variable_template_unit_test) {
    VarFun(1, "Hello World!", 2.34);
}

TEST(TestTuple, tuple_unit_test) {
    UseApisOfTuple();
}

TEST(test11_class, class_unit_test) {
    Foo a1(123);
    Foo a2 = 123;
    a2.Print();
}

TEST(test11_lambda, lambda_unit_test) {
    SortWithLambda();
    SortWithFunc();
    LambdaRename();
    PassValVsRef();
}

TEST(test11_constexpr, constexpr_unit_test) {
    ReassignToReadOnlyVar();
    InitialArray();
}

TEST(test11_reference, reference_unit_test) {
    // construct
    std::cout << "Demo1: " << std::endl;
    Demo demo1 = GetDemo();

    std::cout << "Demo2: " << std::endl;
    Demo demo2 = demo1;

    std::cout << "Demo3: " << std::endl;
    Demo demo3 = std::move(demo1);
}

TEST(test11_reference, lval_rval_unit_test) {
    LvalRvalDemo demo(10);
    std::cout << demo.GetNum() << std::endl;
    std::cout << std::move(demo).GetNum() << std::endl;
}

TEST(test11_reference, ref_qualifier_unit_test) {
    RefQualifierDemo demo(10, 20);
    std::cout << demo.GetNumLvalRef() << std::endl;
    // std::cout << std::move(demo).GetNumLvalRef() << std::endl;
    // std::cout << demo.GetNumRvalRef() << std::endl;
    std::cout << std::move(demo).GetNumRvalRef() << std::endl;
}

TEST(test11_forward, forward_unit_test) {
    Func(5);
    int val = 1;
    Func(val);
}

TEST(test11_move_construct, move_construct_unit_test) {
    Second second;
    Second second_move = std::move(second);
    second_move.Print();
}

TEST(test11_smart_pointer, shared_ptr_unit_test) {
    InitSharedPtr();
    UseSharedPtrReset();
}

TEST(test11_smart_pointer, unique_ptr_unit_test) {
    InitUniquePtr();
    UseUniquePtrApi();
}

TEST(test11_bind, bind_unit_test) {
    std::cout << BindDivision(10) << std::endl;
    BindDisplay(10);
}

TEST(test11_function, function_unit_test) {
    FunctionSum(100, 10);
    FunctionSumLambda(100, 10);
    FunctionSumClass(100.f, 10.f);
    FunctionSumClassObject(100, 10);
    FunctionSumClassBind(100, 10);
}

TEST(test11_copy_construct, copy_construct_unit_test) {
    const int val = 100;
    const std::string str = "Hello World!";
    const std::vector<int> vec(10, 9);
    cpp11::DefaultCopy defalut_obj(val, str, vec);

    cpp11::DefaultCopy copy_obj(defalut_obj);
    int copy_val = copy_obj.GetVal();
    std::string copy_str = copy_obj.GetStr();
    std::vector<int> copy_vec = copy_obj.GetVec();

    std::cout << "copy_val: " << copy_val << std::endl;
    std::cout << "copy_str: " << copy_str << std::endl;
    std::cout << "copy_vec: ";
    for (int i = 0; i < (int)copy_vec.size(); ++i) {
        std::cout << copy_vec[i] << " ";
    }
    std::cout << std::endl;
}