#ifndef REFERENCE_MODULE_H__
#define REFERENCE_MODULE_H__
#include <iostream>

namespace cpp11 {

class First {
 public:
    First(): _num(new int(0)) {
        std::cout << "First construct!" << std::endl;
    }
    First(First &&first): _num(first._num) {
        first._num = NULL;
        std::cout << "First move construct!" << std::endl;
    }
 private:
    int *_num;
};

class Second {
 public:
    Second(): _first() {
        std::cout << "Second construct!" << std::endl;
    }
    Second(Second &&second): _first(std::move(second._first)) {
        std::cout << "Second move construct!" << std::endl;
    }
    void Print() {
        std::cout << "Second hello world!" << std::endl;
    }
 private:
    First _first;
};

class LvalRvalDemo {
 public:
    LvalRvalDemo(int num): _num(num) {}
    int GetNum() {
        return this->_num;
    }
 private:
    int _num;
};

class RefQualifierDemo {
 public:
    RefQualifierDemo(int lnum, int rnum): _lnum(lnum), _rnum(rnum) {}
    int GetNumLvalRef() & {
        return this->_lnum;
    }
    int GetNumRvalRef() && {
        return this->_rnum;
    }
 private:
    int _lnum;
    int _rnum;
};

class Demo {
 public:
    Demo(): _num(new int(0)) {
        std::cout << "Construct!" << std::endl;
    }
    Demo(const Demo &demo): _num(new int(*demo._num)) {
        std::cout << "Copy-construct!" << std::endl;
    }
    Demo(Demo &&demo): _num(demo._num) {
        demo._num = NULL;
        std::cout << "Move-construct!" << std::endl;
    }
    ~Demo() {
        std::cout << "Destruct!" << std::endl;
    }
 private:
    int *_num;
};

Demo GetDemo();
void OtherDef(int &val);
void OtherDef(const int &val);

template<typename T>
void Func(T &&val) {
    OtherDef(std::forward<T>(val));
}

} // namespace cpp11
#endif