#ifndef VIRTUAL_MODULE_H__
#define VIRTUAL_MODULE_H__
#include <iostream>

namespace cpp11 {

// 1 byte
class CNull {};

// 1 byte, member function do not occupy memory
class CNull2 {
 public:
  void Print() { std::cout << "CNull2::Print()" << std::endl; }
};

//////////////////////////////////////////////////////////////
// 4 bytes, member variable occupies memory
class COneMember {
 private:
  int ione_;
};

// 8 bytes
class CTwoMember : public COneMember {
 private:
  int itwo_;
};

// 12 bytes
class CThreeMember : public CTwoMember {
 private:
  int ithree_;
};

//////////////////////////////////////////////////////////////
class ClassA {
 private:
  int ia_;
};

class ClassB {
 private:
  int ib_;
};

class ClassC {
 private:
  int ic_;
};

// 16bytes
class CComplex : public ClassA, public ClassB, public ClassC {
 private:
  int icomplex_;
};

//////////////////////////////////////////////////////////////
// 32 bytes
class CVeryComplex : public CThreeMember, public CComplex {
 private:
  int ivery_complex_;
};

// 16 bytes
class CVTwoMember : virtual public COneMember {
 private:
  int itwo_;
};

//////////////////////////////////////////////////////////////
class ClassVA {
 private:
  int ia_;
};

class CVlassVB : virtual public ClassVA {
 private:
  int ib_;
};

class ClassVC : virtual public ClassVA {
 private:
  int ic_;
};

// 40 bytes
class CVComplex : public CVlassVB, public ClassVC {
 private:
  int icomplex_;
};

//////////////////////////////////////////////////////////////
// 1 byte, static member variable do not occupy class memory,
// it locates at static region
class CStaticNull {
 private:
  static int ival_;
};

//////////////////////////////////////////////////////////////
// 8 bytes, virtual table pointer(64-bit system)
class CVirtualNull {
 public:
  virtual void Print() {}
};

// 16 bytes, vptr + member variable(aligned?)
class CVirtualA : public CVirtualNull {
 private:
  int ivi_;
};

// 16 bytes, same as above,
// new virtual function does not increase memory
class CVirtualB : public CVirtualNull {
 public:
  virtual void PrintX() {}

 private:
  int ivi_;
};

//////////////////////////////////////////////////////////////
// 8 bytes
class CPureVirtual {
 public:
  virtual void Foo() = 0;
};

// 8 bytes
class CPureVirtualA : public CPureVirtual {
 public:
  void Foo() {}
};

}  // namespace cpp11

#endif