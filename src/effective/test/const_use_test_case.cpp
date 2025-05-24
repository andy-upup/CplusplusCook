#include <gtest/gtest.h>

#include <iostream>

#include "const_use.h"

TEST(test_effective, const_use_unit_test) {
  /*
      char greeting[] = "Hello World!";
      // non-const pointer, non-const data
      char *ptr = greeting;
      // non-const pointer, const data
      const char *ptr = greeting;
      // const pointer, non-const data
      char *const ptr = greeting;
      // const pointer, const data
      const char *const ptr = greeting;
  */

  std::vector<int> vec(1);
  // const iterator, like const pointer
  const std::vector<int>::iterator iter = vec.begin();
  *iter = 10;  // Correct, non-const data
  // ++iter;  // Wrong

  // like const data
  std::vector<int>::const_iterator citer = vec.begin();
  ++citer;  // Correct, non-const pointer

  effective::TextBlock text_block("Hello");
  // Call non-const operator[], then call const operator[]
  std::cout << text_block[0] << std::endl;

  const effective::TextBlock ctext_block("World");
  // Call const operator[]
  std::cout << ctext_block[0] << std::endl;

  std::cout << text_block.GetName() << std::endl;
  text_block.ChangeName();
  std::cout << text_block.GetName() << std::endl;

  std::cout << text_block.GetTitle() << std::endl;
  text_block.ChangeTitle();
  std::cout << text_block.GetTitle() << std::endl;
}