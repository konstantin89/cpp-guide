#include "examples.h"

#include <iostream>

int main()
{
    // Array template (compile time size)
    ArrayExample();

    // Singly linked list
    ForwardListExample();

    // Doubly linked list
    ListExample();

    // Priority queue is Heap data structure implementation.
    PriorityQueueExample();

    // Double-ended queue (efficient push to front and end)
    DequeExample();

    // Hash table based map
    UnorderedMapExample();

    return 0;
}