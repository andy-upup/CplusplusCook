#include "const_use.h"

namespace effective {

std::string TextBlock::name_ = "Hello World!";

void Print(const TextBlock& text_block) {
  std::cout << text_block[0] << std::endl;
}

}  // namespace effective