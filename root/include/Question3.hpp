#ifndef AIRPORTSIM_H
#define AIRPORTSIM_H

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>
#include <atomic>

// Simulates the air traffic controller (ATC) and aircraft communication
class ATC
{
private:
    std::mutex mtx;                     // Mutex for synchronizing ATC access
    std::condition_variable cv;         // Condition variable to manage ATC sleep/wake state
    std::atomic<bool> isAsleep;         // Atomic flag to track ATC sleeping state
    std::atomic<bool> isCommunicating;  // Atomic flag to indicate if ATC is talking to a pilot

public:
    ATC();
    void communicate(int aircraftID);   // Method for aircraft to communicate with ATC
    void finishCommunication();         // Method to end communication and put ATC to sleep
};

// Manages the traffic pattern and aircraft landing logic
class Airport 
{
private:
    ATC& atc;                           // Reference to the ATC
    std::mutex patternMtx;              // Mutex for managing traffic pattern
    std::queue<int> trafficPattern;     // Queue representing aircraft in traffic pattern
    const int maxPatternSize = 3;       // Maximum capacity of traffic pattern

public:
    Airport(ATC& atc);
    void requestLanding(int aircraftID); // Method for aircraft to request landing
};

#endif // AIRPORTSIM_H
