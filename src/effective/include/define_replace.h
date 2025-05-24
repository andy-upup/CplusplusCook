#ifndef DEFINE_REPLACE_H__
#define DEFINE_REPLACE_H__
#include <iostream>

namespace effective {

class GamePlayer {
 private:
  static const int num_turns_ = 5;
  int scores_[num_turns_];
};

}  // namespace effective
#endif