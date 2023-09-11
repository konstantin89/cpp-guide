#include <iostream>

class MyClass
{
public:
    using IdType = int;
};

int main() 
{
    // decltype is operator that allows to determine type of expression in COMPILE TIME.

    int x = 0;
    decltype(x) y = 3;

    return 0;
}