#include "tuple_module.h"

namespace cpp11 {

void UseApisOfTuple() {
    std::tuple<int, char> first;
    std::tuple<int, char> second(first);
    std::tuple<int, char> third(std::make_tuple(20, 'a'));
    std::tuple<long, char> fourth(third);
    std::tuple<int, char> fifth(10, 'b');

    std::tuple<int, char, double, std::string> sixth(std::make_tuple(30, 'c', 1., "Hello World!"));
    std::cout << "sixth size: " << std::tuple_size<decltype(sixth)>::value << std::endl;
    std::cout << std::get<0>(sixth) << std::endl;
    std::cout << std::get<1>(sixth) << std::endl;
    std::cout << std::get<2>(sixth) << std::endl;
    std::cout << std::get<3>(sixth) << std::endl;

    // assign the 1st element to new value
    std::get<0>(sixth) = 100;
    std::cout << std::get<0>(sixth) << std::endl;

    // combine serval tuples to a big one
    auto cat_tuple = std::tuple_cat(fifth, sixth);
    std::cout << std::tuple_size<decltype(cat_tuple)>::value << std::endl;

    // assign tuple to certain variables
    int val;
    char str;
    std::tie(val, str) = fifth;
    std::cout << "val: " << val << std::endl;
    std::cout << "str: " << str << std::endl;
}

} // namespace cpp11