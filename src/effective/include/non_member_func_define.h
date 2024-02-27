#ifndef NON_MEMBER_FUNC_DEFINE_H__
#define NON_MEMBER_FUNC_DEFINE_H__
#include <iostream>

// 46
namespace effective {

template<typename T> class Rational;

template<typename T>
const Rational<T> DoMutiply(const Rational<T>& lhs, const Rational<T>& rhs);

template<typename T>
class Rational {
 public:
    Rational(const T& numerator = 0, const T& denominator = 1) {}

    const T GetNumerator() const { return (T)(0); }
    const T GetDenominator() const { return (T)(0); }

    friend const Rational operator*(const Rational& lhs, const Rational& rhs) {
        return DoMutiply(lhs, rhs);
    }

    void Print() {
        std::cout << "Hello World!" << std::endl;
    }
};

template<typename T>
const Rational<T> DoMutiply(const Rational<T>& lhs, const Rational<T>& rhs) {
    return Rational<T>(lhs.GetNumerator() * rhs.GetNumerator(), lhs.GetDenominator() * rhs.GetDenominator());
}

} // namespace effective
#endif