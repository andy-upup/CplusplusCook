#include <gtest/gtest.h>

#include <iostream>
#include <tuple>
#include <vector>

#include "bind_module.h"
#include "cast_module.h"
#include "class_module.h"
#include "constexpr_module.h"
#include "construct_func.h"
#include "forward_module.h"
#include "function_module.h"
#include "heap_module.h"
#include "lambda_module.h"
#include "reference_module.h"
#include "smart_pointer.h"
#include "template_module.h"
#include "tuple_module.h"
#include "variable_parameter_module.h"
#include "vector_module.h"
#include "virtual_module.h"

TEST(test11_vector, back_unit_test) {
  std::vector<cpp11::Back> box_a;
  cpp11::Back back_a(1);
  box_a.push_back(back_a);
  std::cout << "---------------" << std::endl;

  std::vector<cpp11::Back> box_b;
  box_b.push_back(cpp11::Back(2));
  std::cout << "---------------" << std::endl;

  std::vector<cpp11::Back> box_c;
  cpp11::Back back_c(3);
  box_c.emplace_back(back_c);
  std::cout << "---------------" << std::endl;

  std::vector<cpp11::Back> box_d;
  box_d.emplace_back(cpp11::Back(4));
  std::cout << "---------------" << std::endl;

  std::vector<cpp11::Back> box_e;
  box_e.emplace_back(5);
  std::cout << "---------------" << std::endl;
}

TEST(test11_vector, size_capacity_unit_test) { cpp11::VectorSizeTest(); }

TEST(test11_auto_decltype, auto_decltype_unit_test) {
  int n = 10;
  int& r1 = n;
  auto r2 = r1;
  r2 = 20;
  std::cout << n << ", " << r1 << ", " << r2 << std::endl;
  decltype(r1) r3 = n;
  r3 = 99;
  std::cout << n << ", " << r1 << ", " << r3 << std::endl;
}

TEST(test11_using, using_map_unit_test) { cpp11::str_map<int> mp; }

TEST(test11_variable_parameter, variable_parameter_unit_test) {
  cpp11::VairFun(4, 100, 110, 120, 130);
}

TEST(test11_template, variable_template_unit_test) {
  cpp11::Executor(cpp11::ComputeSum, 10, 100);
}

TEST(test11_template, specialization_unit_test) {
  cpp11::TempPartial<double, double> comp1;
  comp1.Print(3.0, 4.0);

  cpp11::TempPartial<float, int> comp2;
  comp2.Print(3.0, 3);

  cpp11::TempPartial<int, float> comp3;
  comp3.Print(3, 4.0);

  std::cout << std::endl;

  cpp11::FuncTempPrint<10>();
  cpp11::FuncTempPrint<100>();
}

TEST(test11_tuple, tuple_unit_test) { cpp11::UseApisOfTuple(); }

TEST(test11_tuple, tuple_and_others_unit_test) { cpp11::TupleTest(); }

TEST(test11_class, class_unit_test) {
  cpp11::Foo a1(123);
  cpp11::Foo a2 = 123;
  a2.Print();

  cpp11::DerivedVirtualTest derived;
  cpp11::DerivedVirtualTest* pderived = &derived;
  cpp11::BaseVirtualTest* pbase = &derived;
  derived.PrintClassName();
  derived.Print();
  pderived->PrintClassName();
  pderived->Print();
  pbase->PrintClassName();
  pbase->Print();
}

TEST(test11_virtual, virtual_unit_test) {
  std::cout << "sizeof(cpp11::CNull):  " << sizeof(cpp11::CNull) << std::endl;
  std::cout << "sizeof(cpp11::CNull2): " << sizeof(cpp11::CNull2) << std::endl;
  std::cout << "sizeof(cpp11::COneMember): " << sizeof(cpp11::COneMember)
            << std::endl;
  std::cout << "sizeof(cpp11::CTwoMember): " << sizeof(cpp11::CTwoMember)
            << std::endl;
  std::cout << "sizeof(cpp11::CThreeMember): " << sizeof(cpp11::CThreeMember)
            << std::endl;
  std::cout << "sizeof(cpp11::CComplex): " << sizeof(cpp11::CComplex)
            << std::endl;
  std::cout << "sizeof(cpp11::CVeryComplex): " << sizeof(cpp11::CVeryComplex)
            << std::endl;
  std::cout << "sizeof(cpp11::CVTwoMember): " << sizeof(cpp11::CVTwoMember)
            << std::endl;
  std::cout << "sizeof(cpp11::CVComplex): " << sizeof(cpp11::CVComplex)
            << std::endl;
  std::cout << "sizeof(cpp11::CStaticNull): " << sizeof(cpp11::CStaticNull)
            << std::endl;
  std::cout << "sizeof(cpp11::CVirtualNull): " << sizeof(cpp11::CVirtualNull)
            << std::endl;
  std::cout << "sizeof(cpp11::CVirtualA): " << sizeof(cpp11::CVirtualA)
            << std::endl;
  std::cout << "sizeof(cpp11::CVirtualB): " << sizeof(cpp11::CVirtualB)
            << std::endl;
  std::cout << "sizeof(cpp11::CPureVirtual): " << sizeof(cpp11::CPureVirtual)
            << std::endl;
  std::cout << "sizeof(cpp11::CPureVirtualA): " << sizeof(cpp11::CPureVirtualA)
            << std::endl;
}

TEST(test11_lambda, lambda_unit_test) {
  cpp11::SortWithLambda();
  cpp11::SortWithFunc();
  cpp11::LambdaRename();
  cpp11::PassValVsRef();
}

TEST(test11_constexpr, constexpr_unit_test) {
  cpp11::ReassignToReadOnlyVar();
  cpp11::InitialArray();
}

TEST(test11_reference, reference_unit_test) {
  // construct
  std::cout << "Demo1: " << std::endl;
  cpp11::Demo demo1 = cpp11::GetDemo();

  std::cout << "Demo2: " << std::endl;
  cpp11::Demo demo2 = demo1;

  std::cout << "Demo3: " << std::endl;
  cpp11::Demo demo3 = std::move(demo1);
}

TEST(test11_reference, lval_rval_unit_test) {
  cpp11::LvalRvalDemo demo(10);
  std::cout << demo.GetNum() << std::endl;
  std::cout << std::move(demo).GetNum() << std::endl;
}

TEST(test11_reference, ref_qualifier_unit_test) {
  cpp11::RefQualifierDemo demo(10, 20);
  std::cout << demo.GetNumLvalRef() << std::endl;
  // std::cout << std::move(demo).GetNumLvalRef() << std::endl;
  // std::cout << demo.GetNumRvalRef() << std::endl;
  std::cout << std::move(demo).GetNumRvalRef() << std::endl;
}

TEST(test11_reference, forward_unit_test) {
  cpp11::Func(5);
  int val = 1;
  cpp11::Func(val);
}

TEST(test11_move_construct, move_construct_unit_test) {
  cpp11::Second second;
  cpp11::Second second_move = std::move(second);
  second_move.Print();
}

TEST(test11_smart_pointer, shared_ptr_unit_test) {
  cpp11::InitSharedPtr();
  cpp11::UseSharedPtrReset();
}

TEST(test11_smart_pointer, unique_ptr_unit_test) {
  cpp11::InitUniquePtr();
  cpp11::UseUniquePtrApi();
}

TEST(test11_bind, bind_unit_test) {
  std::cout << cpp11::BindDivision(10) << std::endl;
  cpp11::BindDisplay(10);
}

TEST(test11_function, function_unit_test) {
  cpp11::FunctionSum(100, 10);
  cpp11::FunctionSumLambda(100, 10);
  cpp11::FunctionSumClass(100.f, 10.f);
  cpp11::FunctionSumClassObject(100, 10);
  cpp11::FunctionSumClassBind(100, 10);
}

TEST(test11_copy_construct, copy_construct_unit_test) {
  // const int val = 100;
  // const std::string str = "Hello World!";
  // const std::vector<int> vec(10, 9);
  // cpp11::DefaultCopyClass defalut_obj(val, str, vec);

  // cpp11::DefaultCopyClass copy_obj(defalut_obj);
  // int copy_val = copy_obj.GetVal();
  // std::string copy_str = copy_obj.GetStr();
  // std::vector<int> copy_vec = copy_obj.GetVec();

  // std::cout << "copy_val: " << copy_val << std::endl;
  // std::cout << "copy_str: " << copy_str << std::endl;
  // std::cout << "copy_vec: ";
  // for (int i = 0; i < (int)copy_vec.size(); ++i) {
  //     std::cout << copy_vec[i] << " ";
  // }
  // std::cout << std::endl;

  cpp11::TestDefaultCopyConstruct();
}

TEST(test11_copy_construct, copy_times_unit_test) {
  cpp11::Copyable obj = cpp11::ReturnRvalue();
  obj.Print();
}

TEST(test11_forward, forward_unit_test) {
  cpp11::MsgHolder holder;
  std::string lvalue_test("Lvalue test.");
  std::string rvalue_test("Rvalue_test.");

  // lvalue_test: lvalue reference
  // rvalue_test: rvalue reference
  holder.Add(2, " test of ", lvalue_test, " and ", std::move(rvalue_test));

  // copy-construct, output: "lvalue_test: Lvalue test."
  std::cout << "lvalue_test: " << lvalue_test << std::endl;
  // move-construct, output: "rvalue_test:"
  std::cout << "rvalue_test: " << rvalue_test << std::endl;
  // output: "holder: 2 test of Lvalue test. and Rvalue_test."
  std::cout << "holder: " << holder << std::endl;
}

TEST(test11_forward, forward_easy_unit_test) {
  int x = 1;
  cpp11::TestForward(x);
  std::cout << "==========" << std::endl;
  cpp11::TestForward(std::move(x));
}

TEST(test11_heap, heap_unit_test) {
  std::vector<int> vec{1, 3, 2, 4, 7};
  cpp11::TestMaxHeap(vec);
  cpp11::TestMinHeap(vec);

  std::vector<std::pair<int, int>> pair_vec{
      {1, 10}, {3, 20}, {2, 15}, {4, 7}, {7, 30}};
  cpp11::TestMaxHeap(pair_vec);
}

TEST(test11_cast, cast_unit_test) { cpp11::ConstTest(); }