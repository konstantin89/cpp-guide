#include <iostream>

template <typename T>
class MyClass
{
public:
    using MyType = int;

    MyType myVar;

    MyType Get();
};

// Here the usage of typename is mandatory.
template <typename T>
typename MyClass<T>::MyType MyClass<T>::Get()
{
    return 20;
}

int main() 
{
    // typename is often used in template meta-programming and is related to type-dependent
    // expressions and dependent names in templates.
    // It is typically used in the context of template declarations to indicate that a dependent  
    // name refers to a type. In other words, it helps the compiler understand that a particular 
    // identifier is the name of a type, not a variable or function.

    MyClass<bool> myClass;
    auto x = myClass.Get();

    MyClass<bool>::MyType myVar;

    return 0;
}