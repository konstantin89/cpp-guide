#include <iostream>
#include <thread>
#include <atomic>
#include <memory>

struct MyStruct
{
    int i;
    double d;
    long l;
};

void LockFreeProperty()
{
    auto i = std::atomic<int>{3};

    // atomic variable that is not using mutex or other sync mechanism is called
    // lock free.

    // std::atomic uses mutex for some types.
    // We can check during run time if our atomic variable uses lock.
    std::cout << "std::atomic<int> is_lock_free: " << i.is_lock_free() << std::endl;

    // We can check it during compile time as well.
    static_assert(std::atomic<int>::is_always_lock_free);

    // On modern platforms, any std::atomic<T> where T fits into the native 
    // word size will typically be always lock-free.

    i.store(34);
    auto i_value = i.load();
}

void AtomicFlags()
{
    // Atomic flag is guaranteed to be lock free.

    // In C++20 atomic flag has API close to conditional variable.
    std::atomic_flag flag;

    while (flag.test_and_set(std::memory_order_acquire))
    {
        // We have the flag
    }

    // Release the flag
    flag.clear();
}

void AtomicSharedPtr()
{
    // Since C++20 we can store shared_ptr in atomic variables
    // https://en.cppreference.com/w/cpp/memory/shared_ptr/atomic2

    //auto p = std::make_shared<int>();

    // X This is not working for some reason
    //auto a = std::atomic<std::shared_ptr<int>>{};

    //a.store(p);
    //auto local_ptr = a.load();
}


int main()
{
    LockFreeProperty();
    AtomicFlags();
    AtomicSharedPtr();

    // std::atomic_ref are introduced in C++20.

    return 0;
}