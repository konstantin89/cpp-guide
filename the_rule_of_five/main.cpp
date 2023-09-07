#include <iostream>
#include <cstring>

// The Rule of Five consists of five special member functions that should be defined when a class manages a resource 
// (like memory allocation) to ensure proper resource management and avoid issues like memory leaks. 
// These special member functions are:
//
//     Destructor (to release resources).
//     Copy Constructor (to create a copy of the object).
//     Copy Assignment Operator (to assign the value of one object to another).
//     Move Constructor (to efficiently transfer ownership of resources).
//     Move Assignment Operator (to efficiently assign the value of one object to another).

class Buffer {
private:
    char* mData;
    size_t mSize;

public:
    // Constructor
    Buffer(size_t bufferSize) : mSize(bufferSize) 
    {
        mData = new char[mSize];
    }

    // 1 - Destructor
    ~Buffer() 
    {
        delete[] mData;
    }

    // 2 - Copy Constructor
    Buffer(const Buffer& other) : mSize(other.mSize) 
    {
        mData = new char[mSize];
        std::memcpy(mData, other.mData, mSize);
    }

    // 3 - Copy Assignment Operator
    Buffer& operator=(const Buffer& other) 
    {
        if (this == &other) {
            return *this;
        }

        delete[] mData;

        mSize = other.mSize;
        mData = new char[mSize];
        std::memcpy(mData, other.mData, mSize);

        return *this;
    }

    // 4 - Move Constructor
    Buffer(Buffer&& other) noexcept : mData(other.mData), mSize(other.mSize) 
    {
        other.mData = nullptr;
        other.mSize = 0;
    }

    // 5 - Move Assignment Operator
    Buffer& operator=(Buffer&& other) noexcept 
    {
        if (this == &other) {
            return *this;
        }

        delete[] mData;
        mData = other.mData;
        mSize = other.mSize;
        other.mData = nullptr;
        other.mSize = 0;

        return *this;
    }

    char *GetData() const
    {
        return mData;
    }

    size_t GetSize() const
    {
        return mSize;
    }

    // Example member function to print the buffer content
    void print() const 
    {
        for (size_t i = 0; i < mSize; ++i) 
        {
            std::cout << mData[i];
        }
        std::cout << std::endl;
    }
};

int main() 
{
    // Create a Buffer object
    Buffer buffer1(10);
    strcpy(buffer1.GetData(), "Hello");

    // Copy constructor
    Buffer buffer2(buffer1);
    buffer2.print();

    // Move constructor
    Buffer buffer3(std::move(buffer1));
    buffer3.print();

    // Copy assignment operator
    Buffer buffer4(5);
    buffer4 = buffer2;
    buffer4.print();

    // Move assignment operator
    Buffer buffer5(3);
    buffer5 = std::move(buffer3);
    buffer5.print();

    return 0;
}