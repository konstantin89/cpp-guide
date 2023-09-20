#include <iostream>
#include <memory>

void* operator new(size_t size)
{
    void *p = std::malloc(size);
    std::cout << "allocated " << size << " bytes" << std::endl;
    return p; 
}

void operator delete (void *p) noexcept
{
    std::cout << "delete called" << std::endl;
    free(p);
}

void SharedPtr()
{
    // The output:
    //    >>> Using new
    //    allocated 4 bytes
    //    allocated 40 bytes
    //    >>> Using make_shared
    //    allocated 40 bytes
    //    delete called
    //    delete called
    //    delete called

    // The reason for this output is that make_shared uses one new call for
    // allocating data for control block and the stored data.
    // If you use new manually then there is the  new for the data and new for the 
    // control block.

    std::cout << ">>> SharedPtr - Using new" << std::endl;
    int * p = new int;
    std::shared_ptr<int> sp(p);

    std::cout << ">>> SharedPtr - Using make_shared" << std::endl;
    std::shared_ptr<int> sp2 = std::make_shared<int>();
}

void UniquePtr()
{
    // >>> UniquePtr - Using new
    // allocated 4 bytes
    // >>> UniquePtr - Using make_unique
    // allocated 4 bytes

    std::cout << ">>> UniquePtr - Using new" << std::endl;
    int * p = new int;
    std::unique_ptr<int> up(p);
    *up = 2;

    std::cout << ">>> UniquePtr - Using make_unique" << std::endl;
    std::unique_ptr<int> up2 = std::make_unique<int>();
    *up2 = 3;
}

void WeakPointer()
{
    std::shared_ptr<int> sharedPtr = std::make_shared<int>(42);

    // Create a weak pointer from the shared pointer
    std::weak_ptr<int> weakPtr = sharedPtr;

    // Check if the weak pointer is expired
    if (!weakPtr.expired()) 
    {
        std::shared_ptr<int> sharedPtrFromWeak = weakPtr.lock();

        if (sharedPtrFromWeak) 
        {
            *sharedPtrFromWeak = 2;
        } else
         {
            std::cout << "The shared pointer is null." << std::endl;
        }
    } else 
    {
        std::cout << "The weak pointer is expired." << std::endl;
    }

    // Reset the shared pointer
    sharedPtr.reset();

    // Check again if the weak pointer is expired
    if (weakPtr.expired()) 
    {
        std::cout << "The weak pointer is expired after resetting the shared pointer." << std::endl;
    }
}

int main()
{
    SharedPtr();
    UniquePtr();
    WeakPointer();

    return 0;
}