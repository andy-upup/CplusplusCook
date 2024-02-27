#ifndef CONST_USE_H__
#define CONST_USE_H__
#include <iostream>

namespace effective {

class TextBlock {
 public:
    TextBlock(const std::string& str) {
        text_ = str;
        title_ = "";
    }

    // Two member functions can be overloaded if they only differ in constant attributes.
    const char& operator[] (const std::size_t idx) const {
        std::cout << "const interface." << std::endl;
        return text_[idx];
    }

    char& operator[] (const std::size_t idx) {
        std::cout << "non-const interface." << std::endl;
        return const_cast<char&>(static_cast<const TextBlock&>(*this)[idx]);
    }

    // const member functions can change static data members of the class.
    void ChangeName() const {
        name_ = text_;
    }

    std::string GetName() const {
        return name_;
    }

    // Const member functions can change data members with mutable.
    void ChangeTitle() const {
        title_ = text_;
    }

    std::string GetTitle() const {
        return title_;
    }

 private:
    std::string text_;
    static std::string name_;
    mutable std::string title_;
};

void Print(const TextBlock& text_block);

} // namespace effective
#endif