#include "tuple_module.h"

namespace cpp11 {

static bool Cmp(std::tuple<int, int, float>& a,
                std::tuple<int, int, float>& b) {
  return std::get<2>(a) > std::get<2>(b);
}

void UseApisOfTuple() {
  std::tuple<int, char> first;
  std::tuple<int, char> second(first);
  std::tuple<int, char> third(std::make_tuple(20, 'a'));
  std::tuple<long, char> fourth(third);
  std::tuple<int, char> fifth(10, 'b');

  std::tuple<int, char, double, std::string> sixth(
      std::make_tuple(30, 'c', 1., "Hello World!"));
  std::cout << "sixth size: " << std::tuple_size<decltype(sixth)>::value
            << std::endl;
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

void TupleTest() {
  std::tuple<int, float> tp1(10, 3.14);
  std::cout << "tp1: " << std::get<0>(tp1) << ' ' << std::get<1>(tp1)
            << std::endl;
  tp1 = std::make_tuple(5, 2.4);
  std::cout << "tp1: " << std::get<0>(tp1) << ' ' << std::get<1>(tp1)
            << std::endl;

  // int num = std::tuple_size<decltype(tp1)>::value;

  std::pair<int, float> pair1(1, 10.0);
  std::cout << "pair1: " << pair1.first << ' ' << pair1.second << std::endl;

  std::vector<std::pair<int, int>> pairs;
  const int pair_num = 3;
  for (int i = 0; i < pair_num; ++i) {
    pairs.emplace_back(i, i);
  }
  for (int i = 0; i < pair_num; ++i) {
    std::cout << "pair " << i << ": " << pairs[i].first << ' '
              << pairs[i].second << std::endl;
  }

  std::vector<std::tuple<int, int, float>> tuples;
  const int tuple_num = 3;
  for (int i = 0; i < tuple_num; ++i) {
    tuples.emplace_back(i, i, i);
  }

  std::sort(tuples.begin(), tuples.end(), Cmp);
  for (int i = 0; i < tuple_num; ++i) {
    std::cout << "tupe " << i << ": " << std::get<0>(tuples[i]) << ' '
              << std::get<1>(tuples[i]) << ' ' << std::get<2>(tuples[i])
              << std::endl;
  }
}

}  // namespace cpp11