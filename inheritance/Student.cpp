#include "Student.h"
#include <iostream>

Student::Student(std::string name, int graduationYear) : Person(name)
{
    mGraduationYear = graduationYear;
}

Student::~Student()
{

}

int Student::GetGraduationYear()
{
    return mGraduationYear;
}
    
void Student::PrintStaticBinding()
{
    std::cout << "Student: " << GetName() << ", " << GetGraduationYear() << std::endl;
}

void Student::PrintVirtual()
{
    std::cout << "Student: " << GetName() << ", " << GetGraduationYear() << std::endl;
}