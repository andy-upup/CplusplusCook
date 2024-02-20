#include "singleton.h"

namespace design_pattern {

// LSingletonWithLock
static std::shared_ptr<LSingletonWithLock> g_lsingleton = nullptr;
static std::mutex g_lmutex;

std::shared_ptr<LSingletonWithLock> LSingletonWithLock::GetInstance() {
    if (nullptr == g_lsingleton) {
        std::unique_lock<std::mutex> lock(g_lmutex);
        if (nullptr == g_lsingleton) {
            g_lsingleton = std::shared_ptr<LSingletonWithLock>(new LSingletonWithLock());
        }
    }
    return g_lsingleton;
}

void LSingletonWithLock::Print() {
    std::cout << "Instance address of LSingletonWithLock is: " << this << std::endl;
}

// LSingletonWithStatic
LSingletonWithStatic& LSingletonWithStatic::GetInstance() {
    /*
    * Implementing single instance through local static characteristics.
    * Static local variables are only valid within current function and cannot be accessed by other functions.
    * Static local variables are only initialized when they are called for the first time and are stored in the static storage area. 
    * The life cycle starts from the first initialization to the end of the program.
    */
    static LSingletonWithStatic single;
    return single;
}

void LSingletonWithStatic::Print() {
    std::cout << "Instance address of LSingletonWithStatic is: " << this << std::endl;
}

// HSingletonWithStatic
HSingletonWithStatic* HSingletonWithStatic::singleton_ = new (std::nothrow) HSingletonWithStatic();

HSingletonWithStatic* HSingletonWithStatic::GetInstance() {
    return singleton_;
}

void HSingletonWithStatic::DeleteInstance() {
    if (singleton_) {
        delete singleton_;
        singleton_ = nullptr;
    }
}

void HSingletonWithStatic::Print() {
    std::cout << "Instance address of HSingletonWithStatic is: " << this << std::endl;
}

// HSingletonWithCallOnce
static std::shared_ptr<HSingletonWithCallOnce> g_singleton = nullptr;
static std::once_flag singleton_flag;

std::shared_ptr<HSingletonWithCallOnce> HSingletonWithCallOnce::GetInstance() {
    std::call_once(singleton_flag, [&] {
        g_singleton = std::shared_ptr<HSingletonWithCallOnce>(new HSingletonWithCallOnce());
    });
    return g_singleton;
}

void HSingletonWithCallOnce::Print() {
    std::cout << "Instance address of HSingletonWithCallOnce is: " << this << std::endl;
}

} // namespace design_pattern