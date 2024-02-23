#include "function_module.h"

namespace cpp11 {

static int ComputeSumOrdInt(const int x, const int y) {
    return x + y;
}

// ordinary function
int FunctionSum(const int x, const int y) {
    // ordinary function
    std::function<int(int, int)> func = ComputeSumOrdInt;

    // function template
    std::function<float(float, float)> tem_func = ComputeSumOrdTem<float>;

    int sum = func(x, y);
    float tem_sum = tem_func(x, y);

    std::cout << __func__ << std::endl;
    std::cout << "Sum of " << x << " and " << y << " is: " << sum << std::endl;
    std::cout << "Sum of " << x << " and " << y << " is: " << tem_sum << std::endl;
    return sum;
}

// lambda expression
int FunctionSumLambda(const int x, const int y) {
    auto compute_sum = [] (const int x, const int y) {
        return x + y;
    };
    std::function<int(int, int)> func = compute_sum;
    int sum = func(x, y);

    std::cout << __func__ << std::endl;
    std::cout << "Sum of " << x << " and " << y << " is: " << sum << std::endl;
    return sum;
}

// class
int FunctionSumClass(const int x, const int y) {
    Functor functor;
    // ordinary member function
    std::function<int(Functor&, int, int)> func1 = &Functor::ComputeSumInt;
    std::function<int(Functor, int, int)> func2 = &Functor::ComputeSumInt;

    // ordinary member function with template
    std::function<float(Functor&, float, float)> tem_func1 = &Functor::ComputeSumTem<float>;
    std::function<float(Functor, float, float)> tem_func2 = &Functor::ComputeSumTem<float>;

    // static member function
    std::function<int(const int, const int)> st_func = Functor::ComputeSumStInt;

    // static member function with template
    std::function<float(float, float)> st_tem_func = Functor::ComputeSumStTem<float>;

    int sum1 = func1(functor, x, y);
    int sum2 = func2(functor, x, y);
    float tem_sum1 = tem_func1(functor, x, y);
    float tem_sum2 = tem_func2(functor, x, y);
    int st_sum = st_func(x, y);
    int st_tem_sum = st_tem_func(x, y);

    std::cout << __func__ << std::endl;
    std::cout << "Sum of " << x << " and " << y << " is: " << sum1 << std::endl;
    std::cout << "Sum of " << x << " and " << y << " is: " << sum2 << std::endl;
    std::cout << "Sum of " << x << " and " << y << " is: " << tem_sum1 << std::endl;
    std::cout << "Sum of " << x << " and " << y << " is: " << tem_sum2 << std::endl;
    std::cout << "Sum of " << x << " and " << y << " is: " << st_sum << std::endl;
    std::cout << "Sum of " << x << " and " << y << " is: " << st_tem_sum << std::endl;
    return sum1;
}

// function object
int FunctionSumClassObject(const int x, const int y) {
    FunctorOpInt functor;
    FunctorOpTem<float> tem_functor;
    // ordinary function object
    std::function<int(const int, const int)> func = functor;

    // function object with template
    std::function<float(float, float)> tem_func = tem_functor;

    int sum = func(x, y);
    float tem_sum = tem_func(x, y);

    std::cout << __func__ << std::endl;
    std::cout << "Sum of " << x << " and " << y << " is: " << sum << std::endl;
    std::cout << "Sum of " << x << " and " << y << " is: " << tem_sum << std::endl;
    return sum;
}

// combine bind with function
int FunctionSumClassBind(const int x, const int y) {
    FunctorBind functor;
    std::function<int(int, int)> pointer_func = std::bind(&FunctorBind::ComputeSumInt, &functor, std::placeholders::_1, std::placeholders::_2);
    std::function<int(int, int)> object_func = std::bind(&FunctorBind::ComputeSumInt, functor, std::placeholders::_1, std::placeholders::_2);
    std::function<int(int, int)> st_func = std::bind(FunctorBind::ComputeSumStInt, std::placeholders::_1, std::placeholders::_2);
    std::function<int(int, int)> tem_func = std::bind(&FunctorBind::ComputeSumTem<int>, &functor, std::placeholders::_1, std::placeholders::_2);

    int pointer_sum = pointer_func(x, y);
    int object_sum = object_func(x, y);
    int st_sum = st_func(x, y);
    int tem_sum = tem_func(x, y);

    std::cout << __func__ << std::endl;
    std::cout << "Sum of " << x << " and " << y << " is: " << pointer_sum << std::endl;
    std::cout << "Sum of " << x << " and " << y << " is: " << object_sum << std::endl;
    std::cout << "Sum of " << x << " and " << y << " is: " << st_sum << std::endl;
    std::cout << "Sum of " << x << " and " << y << " is: " << tem_sum << std::endl;
    return pointer_sum;
}

} // namespace cpp11