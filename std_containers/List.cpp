#include <iostream>
#include <list>
#include <algorithm>

void ListExample()
{
    //Doubly linked list
    std::list<int> myList;

    myList.push_back(5);
    myList.push_back(6);

    myList.push_front(2);
    myList.push_front(1);

    for_each(myList.begin(), myList.end(), [](const int& elem)
    {
        std::cout << elem << " ";
    });

    std::cout << std::endl;
}