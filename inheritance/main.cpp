#include "Person.h"
#include "Student.h"

#include <memory>

int main()
{
    std::unique_ptr<Person> person = std::make_unique<Person>("James");
    std::unique_ptr<Student> student = std::make_unique<Student>("Bob", 2045);

    person->PrintStaticBinding();
    student->PrintStaticBinding();

    // Create Student in Person pointer
    std::unique_ptr<Person> person2 =  std::make_unique<Student>("Rachel", 1999);
    person2->PrintStaticBinding(); // Prints Person::PrintStaticBinding since its non virtual (static binding)
    person2->PrintVirtual();       // Prints Student::PrintVirtual since virtual

    // Virtual methods allow the implementation of polymorphism.

    return 0;
}