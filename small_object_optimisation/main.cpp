#include <iostream>
#include <cstring>
#include <memory>

/*
Small object optimisation is when we have some optimisation done specifically for small objects.
In this example, we implement a string class.
If the string is short, we use stack memory and do not allocate any heap memory.
If string is long, we place it in heap since managing it on stack is not efficient.
*/

class MyString
{
private:

static constexpr size_t MAX_SMALL_STR_SIZE = 16;

enum class Mode
{
    Stack, 
    Heap
};

union _Data
{
    // We use union to save some memory.
    char *heapStr;
    char stackStr[MyString::MAX_SMALL_STR_SIZE];
};

public:

MyString(const char *str)
{
    auto len = strlen(str);
    if (len < MAX_SMALL_STR_SIZE)
    {
        strcpy(mData.stackStr, str);
        mMode = Mode::Stack;
    }
    else
    {
        mData.heapStr = new char[len+1];
        strcpy(mData.heapStr, str);
        mMode = Mode::Heap;
    }
}

~MyString()
{
    if (mMode == Mode::Heap)
    {
        delete[] mData.heapStr;
    }
}

void Print()
{
    if(mMode == Mode::Heap)
    {
        std::cout << mData.heapStr << std::endl;
    }
    else
    {
        std::cout << mData.stackStr << std::endl;
    }
}

private:

_Data mData;
Mode mMode;
};

int main()
{
    // This is a short string, it will be created in stack.
    MyString strShort = MyString("String");
    strShort.Print();

    // On longer strings, memory will be allocated on heap.
    MyString strLong = MyString("Well this is one long string, it will be in heap");
    strLong.Print();

    return 0;
}