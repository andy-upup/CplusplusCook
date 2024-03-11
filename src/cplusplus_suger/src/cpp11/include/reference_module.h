#ifndef REFERENCE_MODULE_H__
#define REFERENCE_MODULE_H__
#include <iostream>

namespace cpp11 {

class First {
 public:
    First(): num_(new int(0)) {
        std::cout << "First construct!" << std::endl;
    }
    First(First&& first): num_(first.num_) {
        first.num_ = NULL;
        std::cout << "First move construct!" << std::endl;
    }
 private:
    int *num_;
};

class Second {
 public:
    Second(): first_() {
        std::cout << "Second construct!" << std::endl;
    }
    Second(Second&& second): first_(std::move(second.first_)) {
        std::cout << "Second move construct!" << std::endl;
    }
    void Print() {
        std::cout << "Second hello world!" << std::endl;
    }
 private:
    First first_;
};

class LvalRvalDemo {
 public:
    LvalRvalDemo(int num): num_(num) {}
    int GetNum() {
        return this->num_;
    }
 private:
    int num_;
};

class RefQualifierDemo {
 public:
    RefQualifierDemo(int lnum, int rnum): lnum_(lnum), rnum_(rnum) {}
    int GetNumLvalRef() & {
        return this->lnum_;
    }
    int GetNumRvalRef() && {
        return this->rnum_;
    }
 private:
    int lnum_;
    int rnum_;
};

class Demo {
 public:
    Demo(): num_(new int(0)) {
        std::cout << "Construct!" << std::endl;
    }
    Demo(const Demo& demo): num_(new int(*demo.num_)) {
        std::cout << "Copy-construct!" << std::endl;
    }
    Demo(Demo&& demo): num_(demo.num_) {
        demo.num_ = NULL;
        std::cout << "Move-construct!" << std::endl;
    }
    ~Demo() {
        std::cout << "Destruct!" << std::endl;
    }
 private:
    int *num_;
};

Demo GetDemo();
void OtherDef(int& val);
void OtherDef(const int& val);

template<typename T>
void Func(T&& val) {
    OtherDef(std::forward<T>(val));
}

} // namespace cpp11
#endif