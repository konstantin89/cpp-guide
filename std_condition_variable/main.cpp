#include <iostream>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <atomic>
#include <chrono>

std::mutex gLock;
std::condition_variable gCv;
std::atomic<bool> gShouldStop;
std::atomic<bool> gIsReady;

void producer()
{
    int counter = 0;

    while((false == gShouldStop.load()) &&
          (counter < 5))
    {
        std::cout << "Data produced" << std::endl;

        gIsReady.store(true);

        counter++;

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    gCv.notify_one();
    gShouldStop.store(true);
}

void consumer()
{
    std::unique_lock<std::mutex> lock(gLock);
    
    while(false == gShouldStop.load())
    {
        gCv.wait(lock, [](){return gIsReady.load();});

        std::cout << "Data consumed" << std::endl;

        gIsReady.store(false);
    }
}

int main()
{
    gShouldStop.store(false);

    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

}