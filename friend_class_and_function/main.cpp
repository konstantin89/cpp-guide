#include <iostream>

class FriendClass;
class MyClass;
void PrintDataFriendFunction(const MyClass& myClass);

class MyClass
{
public:

// Declaring friend class
friend class FriendClass;

// Declaring friend function
friend void PrintDataFriendFunction(const MyClass& myClass);

MyClass (int data): mPrivateData(data)
{

}

private:
int mPrivateData;
};

class FriendClass
{
public:
int ExtractData(const MyClass& myClass) const
{
    return myClass.mPrivateData;
}
};

void PrintDataFriendFunction(const MyClass& myClass)
{
    std::cout << myClass.mPrivateData << std::endl;
}

int main()
{
    MyClass myClass(3);
    FriendClass friendClass;

    // Friend class
    std::cout << friendClass.ExtractData(myClass) << std::endl;

    // Friend function
    PrintDataFriendFunction(myClass);

    return 0;
}