#include "construct_func.h"

namespace cpp11 {

Copyable ReturnRvalue() { return Copyable(); }

void TestDefaultCopyConstruct() {
  std::cout << __func__ << std::endl;
  std::vector<int> vec{1, 4, 5};
  DefaultCopyClass obj_a(10, "Hello World!", vec);

  std::vector<int> arr{6, 3, 9, 8, 2};
  obj_a.InitArr(arr);
  obj_a.PrintArr();
  obj_a.PrintPtr();

  std::cout << std::endl;
  DefaultCopyClass obj_b = obj_a;
  obj_b.PrintArr();
  obj_b.PrintPtr();
}

}  // namespace cpp11