#include <deque>

void DequeExample()
{
    // Double-ended queue (efficient push to front and end)
    // Implemented a collection of fixed length arrays (not continues memory as in std::array).

    std::deque<int> queue;
    queue.push_back(3);
    queue.push_front(1);
}