#ifndef VECTOR_MODULE_H__
#define VECTOR_MODULE_H__
#include <iostream>

class Person {
 public:
    Person(int age) : _age(age) {
        std::cout << "Construct a person. " << _age << std::endl;
    }

    Person(std::string name, int age) : _name(name), _age(age) {
        std::cout << "Construct a person with name. " << _age << std::endl;
    }

    Person(const Person &p) : _age(p._age) {
        std::cout << "Copy-Construct: " << _age << std::endl;
    }

    Person(const Person &&p) noexcept : _age(p._age) {
        std::cout << "Move-Construct: " << _age << std::endl;
    }
 private:
    std::string _name;
    int _age;
};
#endif