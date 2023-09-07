#include <iostream>

std::string GetString()
{
    return std::string("hello");
}

int GetInt()
{
    return 9;
}


void ConstReference()
{
    // IMPORTANT! if const reference is bind to temporary object, the lifetime of the 
    //            temporary object is extended to the lifetime of the const reference.

    // GetString returned temporary object.
    const auto& constRef = GetString();

    // We can use const reference to temporary object since its life time is extended
    std::cout << constRef << std::endl;
}

void MutableReference()
{
    // In contrast to const reference, ,mutable reference cannot bind to temporary objects.
    // std::string& mutableReference = GetString();

    std::string str = GetString();
    auto& mutableReference = str;

    std::cout << mutableReference << std::endl;
}

template<typename T>
void UniversalReferenceParam(T&& universalReference)
{
    // T&& is forwarding reference (only if used in template. If used for concrete type its rvalue reference).
    // Forwarding reference is like const reference, its extends the lifetime of temporary object to the lifetime
    // of the reference, but forwarding reference is mutable.

    std::cout << "universalReference:   " << universalReference << std::endl;
    universalReference++; // its mutable
    std::cout << "universalReference++: " << universalReference << std::endl;
}

void ForwardReference()
{
    // forwarding reference accepts rvalue and allows to modify them.
    UniversalReferenceParam(5);

    int num = 6;
    UniversalReferenceParam(num);

    // forwarding reference extends the lifetime of tmp objects.
    UniversalReferenceParam(GetInt());
}

int main()
{
    ConstReference();
    MutableReference();
    ForwardReference();

    return 0;
}