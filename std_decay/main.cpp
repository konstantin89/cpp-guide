#include <iostream>
#include <type_traits>

// Program output (-std=c++17)

// By Value - Original type: i
// By Value - Processed type: i
// By Value - Processed value: 42

// By Value - Original type: d
// By Value - Processed type: d
// By Value - Processed value: 3.14

// By Value - Original type: Pc
// By Value - Processed type: Pc
// By Value - Processed value: Hello

// By Value - Original type: PFviE
// By Value - Processed type: PFviE
// By Value - Processed value: 0

// By Reference - Original type: i
// By Reference - Processed type: i
// By Reference - Processed value: 42

// By Reference - Original type: d
// By Reference - Processed type: d
// By Reference - Processed value: 3.14

// By Reference - Original type: A6_c              // Note the difference!        
// By Reference - Processed type: Pc               // const char[6] becomes const char *
// By Reference - Processed value: Hello

// By Reference - Original type: PFviE
// By Reference - Processed type: PFviE
// By Reference - Processed value: 0

template <typename T>
void processByValue(T value) 
{
    typename std::decay<T>::type processedValue = value;

    std::cout << "By Value - Original type: " << typeid(value).name() << std::endl;
    std::cout << "By Value - Processed type: " << typeid(processedValue).name() << std::endl;
    std::cout << "By Value - Processed value: " << processedValue << std::endl;
    std::cout << std::endl;
}

template <typename T>
void processByReference(T& value) 
{
    typename std::decay<T>::type processedValue = value;

    std::cout << "By Reference - Original type: " << typeid(value).name() << std::endl;
    std::cout << "By Reference - Processed type: " << typeid(processedValue).name() << std::endl;
    std::cout << "By Reference - Processed value: " << processedValue << std::endl;
    std::cout << std::endl;
}

int main() 
{
    const int x = 42;
    const double y = 3.14;
    char z[6] = "Hello";
    void (*functionPointer)(int) = nullptr;

    // "By Value" parameters always decay! This is why using by value params in templates is better.
    processByValue(x);                 
    processByValue(y);                
    processByValue(z);                 
    processByValue(functionPointer);

    processByReference(x);                 
    processByReference(y);                 
    processByReference(z);                 // Decays array to pointer char[6], to const char*
    processByReference(functionPointer);

    return 0;
}