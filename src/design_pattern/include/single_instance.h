#ifndef SINGLE_INSTANCE_H__
#define SINGLE_INSTANCE_H__
#include <iostream>
#include <mutex>
#include <thread>

class SingleInstance {
 public:
    static SingleInstance *GetInstance();

    static void DeleteInstance();

    void Print();
 private:
    SingleInstance();
    ~SingleInstance();

    SingleInstance(const SingleInstance &signal);
    const SingleInstance &operator=(const SingleInstance &signal);

    static SingleInstance *single_instance_;
    static std::mutex mutex_;
};
#endif