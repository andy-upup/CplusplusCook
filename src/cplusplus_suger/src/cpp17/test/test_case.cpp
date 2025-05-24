#include <gtest/gtest.h>

#include <iostream>

#include "any_module.h"
#include "apply_module.h"
#include "as_const_module.h"
#include "if_switch_module.h"
#include "lambda_module.h"
#include "reference_module.h"
#include "string_convertion_module.h"
#include "string_view_module.h"
#include "structured_binding_module.h"
#include "variant_module.h"

TEST(test17_structured_binding, structured_binding_test_case) {
  cpp17::InitPair();
  cpp17::InitVector();
  auto [i, j] = cpp17::InitTuple();
  std::cout << i << " " << j << std::endl;

  // structured binding pair
  std::pair p(1, 2.4f);
  auto& [x, y] = p;
  x = 2;
  std::cout << x << " " << y << std::endl;

  // structured binding array
  int array[3] = {1, 2, 3};
  auto [a, b, c] = array;
  std::cout << a << " " << b << " " << c << std::endl;
}

TEST(test17_if_switch, if_switch_test_case) { cpp17::IfSwitch(10); }

TEST(test17_reference, reference_test_case) {
  int sum = cpp17::ComputeSum(1, 2, 3, 4, 5);
  std::cout << "Sum is: " << sum << std::endl;

  std::string str_x{"Hello "};
  std::string str_y{"World!"};
  std::cout << cpp17::ComputeSum(str_x, str_y) << std::endl;
}

TEST(test17_lambda, lambda_test_case) {
  std::cout << "Square is: " << cpp17::GetSquare(10) << std::endl;

  cpp17::ThisSample sample;
  sample.val = 100;
  sample.Func();
}

TEST(test17_string_convertion, string_convertion_test_case) {
  // ConvertString();
}

TEST(test17_variant, variant_test_case) { cpp17::TestVariant(); }

TEST(test17_any, any_test_case) { cpp17::TestAny(); }

TEST(test17_apply, apply_test_case) {
  cpp17::ApplyComputeSum(100, 10);

  // use std::make_from_tuple to expand a tuple as argumens for a construct
  // function
  auto tp = std::make_tuple(42, 3.14f, 0);
  std::make_from_tuple<cpp17::Foo>(std::move(tp));
}

TEST(test17_string_view, string_view_test_case) {
  std::string str = "Hello World!";
  std::cout << str << std::endl;

  std::string_view stv(str.c_str(), str.size());
  std::cout << stv << std::endl;
  cpp17::TestStringView(stv);
}

TEST(test17_as_const, as_const_test_case) { cpp17::TestAsConst(); }