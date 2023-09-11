#include <queue>
#include <iostream>

class MyClass
{
public:
    int id;

    MyClass(int _id) : id(_id) {}
    
    bool operator<(const MyClass& other) const
    {
        return id < other.id;
    }
};

void PriorityQueueExample()
{
    // Priority queue is Heap data structure implementation.

    std::priority_queue<MyClass> myQueue;

    myQueue.push(MyClass(5));
    myQueue.push(MyClass(2));
    myQueue.push(MyClass(8));
    myQueue.push(MyClass(1));
    myQueue.push(MyClass(22));

    std::cout << "Priority queue pops: ";
    while (!myQueue.empty())
    {
        std::cout << myQueue.top().id << " ";
        myQueue.pop();
    }

    std::cout << std::endl;
}