#include "smart_pointer.h"

namespace cpp11 {

static void DeleteInt(int *ptr) {
    delete []ptr;
}

struct DeleteData {
    void operator()(int *ptr) {
        delete []ptr;
    }
};

void InitSharedPtr() {
    std::shared_ptr<int> p1;
    // initialize nullptr
    std::shared_ptr<int> p2(nullptr);
    // initialize a pointer to a heap that contains 10 intger elements
    std::shared_ptr<int> p3(new int(10));
    // same as above
    std::shared_ptr<int> p4 = std::make_shared<int>(10);

    // copy-construct
    std::shared_ptr<int> p5(p4);
    // move-construct, transfer control to p6, p5 beconmes a nullptr
    std::shared_ptr<int> p6(std::move(p5));

    // control is transferred to p7, so no need to delete p7 manually
    int *ptr = new int;
    std::shared_ptr<int> p7(ptr);
    // error, not allow to initialize two shared pointers with the same ordinary pointer
    // std::shared_ptr<int> p8(ptr);

    std::shared_ptr<int> p8(new int[10], std::default_delete<int[]>());
    std::shared_ptr<int> p9(new int[10], DeleteInt);
    std::shared_ptr<int> p10(new int[10], [](int *ptr) { delete []ptr; });
}

void UseSharedPtrReset() {
    struct Demo {
        Demo() {
            std::cout << "Construct demo!" << std::endl;
        }
        ~Demo() {
            std::cout << "Destruct demo! Now num is: " << num << std::endl;
        }
        int num;
    };
    std::shared_ptr<Demo> demo_1st(new Demo);
    demo_1st->num = 5;

    Demo *demo_2nd = new Demo;
    demo_2nd->num = 10;

    // call destruct for demo_1st and transfer control from demo_2nd to demo_1st
    demo_1st.reset(demo_2nd);
    // construct a new demo, reset demo_1st and point to the new demo
    demo_1st.reset(new Demo);
    demo_1st->num = 20;

    std::cout << demo_1st.use_count() << std::endl;
    // call destruct for demo_1st
    demo_1st.reset();
    std::cout << demo_1st.use_count() << std::endl;
    std::cout << "End!" << std::endl;
}

void InitUniquePtr() {
    std::unique_ptr<int> p1(new int);
    // memory can not be shared with other unique_ptr
    // std::unique_ptr<int> p2(p1);

    // move-construct
    std::unique_ptr<int> p2(std::move(p1));
    std::unique_ptr<int> p3(new int[10]);
    std::unique_ptr<int> p4 = std::make_unique<int>(10);

    // deferent from shared_ptr, unique_ptr can only relese resources through function object
    std::unique_ptr<int, DeleteData> p5(new int[10]);
}

void UseUniquePtrApi() {
    std::unique_ptr<int> p1(new int);
    *p1 = 10;

    // p2 accepts value of p1
    int *p2 = p1.release();
    std::cout << "p2 value is: " << *p2 << std::endl;
    if (p1) {
        std::cout << "p1 is not nullptr!" << std::endl;
    } else {
        std::cout << "p1 is nullptr!" << std::endl;
    }
    std::unique_ptr<int> p3;
    p3.reset(p2);
    std::cout << "p3 value is: " << *p3 << std::endl;
}

} // namespace cpp11