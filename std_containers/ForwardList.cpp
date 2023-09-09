#include <iostream>
#include <algorithm>
#include <forward_list>

void ForwardListExample()
{
    // Forward list is singly linked list.
    std::forward_list<int> myList;

    for(int i=0; i<10; i++)
    {
        myList.push_front(i);
    }

    for_each(myList.begin(), myList.end(), [](const int& elem)
    {
        std::cout << elem << " ";
    });

    std::cout << std::endl;
}