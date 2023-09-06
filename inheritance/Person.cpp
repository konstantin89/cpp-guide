#include "Person.h"
#include <iostream>

Person::Person(std::string name)
{
    mName = name;
}

void Person::PrintStaticBinding()
{
    std::cout << "Person: " << mName << std::endl;
}

void Person::PrintVirtual()
{
    std::cout << "Person: " << mName << std::endl;
}

std::string Person::GetName()
{
    return mName;
}