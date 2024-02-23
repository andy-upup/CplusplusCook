#include "structured_binding_module.h"

namespace cpp17 {

// C++17 can directly infer the type of containers
void InitPair() {
    std::cout << "InitPair: " << std::endl;
    std::pair<int, double> p1(1, 2.2);
    std::pair p2(3, 4.5);
    std::cout << "p1: " << p1.first << " " << p1.second << std::endl;
    std::cout << "p2: " << p2.first << " " << p2.second << std::endl;
}

void InitVector() {
    std::cout << "InitVector: " << std::endl;
    std::vector vec{1, 2, 3};
    for (auto n: vec) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

std::tuple<int, double> InitTuple() {
    std::cout << "InitTuple: " << std::endl;
    return std::tuple(1, 2.2);
}

} // namespace cpp17