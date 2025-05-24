#include "vector_module.h"

namespace cpp11 {

static void PrintVector(const std::vector<int>& vec, const std::string& tag,
                        const std::string& vec_name) {
  std::cout << tag << std::endl;
  for (auto& v : vec) {
    std::cout << v << ", ";
  }
  std::cout << std::endl;
  std::cout << vec_name << "_addr: " << vec.data() << " " << vec_name
            << "_size: " << vec.size() << " " << vec_name
            << "_capacity: " << vec.capacity() << std::endl;
  std::cout << std::endl;
}

void VectorSizeTest() {
  std::vector<int> v1{1, 2, 3, 4, 5};
  PrintVector(v1, "v1 source data is: ", "v1");

  v1.resize(2);
  PrintVector(v1, "After resizing to 2, v1 data is: ", "v1");

  v1.resize(5);
  PrintVector(v1, "After resizing to 5, v1 data is: ", "v1");

  v1.resize(12, 100);
  PrintVector(v1, "After resizing to 12, v1 data is: ", "v1");

  std::cout << "\n";
  std::cout << "============================================" << std::endl;
  std::cout << "\n";

  std::vector<int> v2{1, 2, 3, 4, 5};
  PrintVector(v2, "v2 source data is: ", "v2");

  v2.reserve(2);
  PrintVector(v2, "After reserving to 2, v2 data is: ", "v2");

  v2.reserve(5);
  PrintVector(v2, "After reserving to 5, v2 data is: ", "v2");

  v2.reserve(12);
  PrintVector(v2, "After reserving to 12, v2 data is: ", "v2");
}

}  // namespace cpp11