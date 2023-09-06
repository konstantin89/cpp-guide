#include <iostream>

// For more info: https://pvs-studio.com/en/blog/terms/6516/

// app output (cpp17)
// Constructor called
// Constructor called
// Destructor called
// Destructor called

class MyClass
{
public:
    MyClass()
    {
        std::cout << "Constructor called" << std::endl;
    }

    ~MyClass()
    {
        std::cout << "Destructor called" << std::endl;
    }

    MyClass(MyClass &&other)
    {
        std::cout << "Move constructor called" << std::endl;
    }
};

MyClass f1()
{
    // RVO (Return Value Optimization) will make the MyClass created 
    // in address of myClass1 variable in main().
    return MyClass{};
}

MyClass f2()
{
    // NRVO (Named Return Value Optimization) is like RVO but done on lvalue objects
    MyClass myClass{}; // myClass os lvalue, so the mechanism here is NRVO.
    return myClass;
}

int main()
{
    // Since C++17 copy elision is mandatory (no longer an optimisation)!
    // So in this example, for each object only one copy created.

    auto myClass1 = f1();
    auto myClass2 = f2();

    return 0;
}