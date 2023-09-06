#pragma once

#include <string>

class Person
{
public:
    Person(std::string name);
    ~Person() = default;

    void PrintStaticBinding();
    virtual void PrintVirtual();

    std::string GetName();
private:

    std::string mName;

protected:

};