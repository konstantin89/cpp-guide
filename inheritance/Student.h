#pragma once

#include "Person.h"

class Student : public Person
{
public:
    Student(std::string name, int graduationYear);

    // There are no virtual constructors.
    // Virtual destructors on the other hand are important.
    // Rule of thumb is that is you use virtual methods, make the destructor virtual.
    virtual ~Student();

    int GetGraduationYear();
    void PrintStaticBinding();
    virtual void PrintVirtual() override;

private:

    int mGraduationYear;

};