#include "examples.h"
#include <array>
#include <algorithm>
#include <iostream>

// -> x
// \/ y

// a[0, 0] a[0, 1] a[0, 2] a[0, 3]
// a[1, 0] a[1, 1] a[1, 2] a[1, 3]
// a[2, 0] a[2, 1] a[2, 2] a[2, 3]
// a[3, 0] a[3, 1] a[3, 2] a[3, 3]

static void TwoDimensionalArray()
{
    constexpr int x = 10;
    constexpr int y = 12;

    // C++ style
    std::array<std::array<int, y>, x> arr1 = {0};

    // C style
    int* arr2[x];
    for(int i=0; i < x; i++)
    {
        arr2[i] = new int[y];
    }

    for(int i=0; i < x; i++)
    {
        delete[] arr2[i];
    }
}

static void Fibonacci()
{
    std::array<int, 20> arr = {0, 1};

    int nm1 = arr[0]; // An-1
    int nm2 = arr[1]; // An-2

    // Note that lambda param is unused
    std::transform(arr.begin() , arr.end(), arr.begin(), [&nm1, &nm2](int)
    {
        int n = nm1 + nm2; //An = An-1 + An-2
        nm2 = nm1;         //An-2 = An-1
        nm1 = n;           //An-1 = An

        return n;
    });

    std::for_each(arr.begin(), arr.end(), [](int i)
    {
        std::cout << i << " ";
    });

    std::cout << std::endl;
}

void ArrayExample()
{
    Fibonacci();
    TwoDimensionalArray();
}