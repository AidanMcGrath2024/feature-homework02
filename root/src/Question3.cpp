#include "Question3.hpp"
#include <chrono>
#include <thread>

ATC::ATC() : isAsleep(true), isCommunicating(false) 
{

}

void ATC::communicate(int aircraftID) 
{
    std::unique_lock<std::mutex> lock(mtx);
    if (isAsleep) 
    {
        std::cout << "ATC wakes up to communicate with Aircraft " << aircraftID << "." << std::endl;
        isAsleep = false;
    }
    isCommunicating = true;
    std::cout << "ATC is talking to Aircraft " << aircraftID << "." << std::endl;
}

void ATC::finishCommunication() 
{
    std::unique_lock<std::mutex> lock(mtx);
    std::cout << "ATC finished communication and falls asleep." << std::endl;
    isCommunicating = false;
    isAsleep = true;
    cv.notify_all(); // Notify other threads that ATC is asleep
}

Airport::Airport(ATC& atc) : atc(atc) {}

void Airport::requestLanding(int aircraftID) 
{
    {
        std::lock_guard<std::mutex> patternLock(patternMtx);
        
        if (trafficPattern.size() >= maxPatternSize)
        {
            std::cout << "Aircraft " << aircraftID << " diverts to another airport as the traffic pattern is full." << std::endl;
            return;
        }
        
        if (!atc.isCommunicating) 
        {
            atc.communicate(aircraftID);
        }
        
        trafficPattern.push(aircraftID);
        std::cout << "Aircraft " << aircraftID << " enters the traffic pattern." << std::endl;
    }

    // Simulate landing process
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // Remove the aircraft from traffic pattern after landing
    {
        std::lock_guard<std::mutex> patternLock(patternMtx);
        std::cout << "Aircraft " << aircraftID << " has landed and left the traffic pattern." << std::endl;
        trafficPattern.pop();
    }

    atc.finishCommunication();
}

int main() 
{
    ATC atc;
    Airport airport(atc);
    
    std::vector<std::thread> aircraftThreads;
    
    for (int i = 1; i <= 10; ++i) 
    {
        aircraftThreads.emplace_back(&Airport::requestLanding, &airport, i);
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Slight delay for aircraft arrivals
    }

    for (auto& t : aircraftThreads) 
    {
        t.join();
    }

    return 0;
}
