#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <chrono>
using namespace std;

const int numberOfRobots = 5; // amount of robots and tools, situated in a circle

mutex tools[numberOfRobots]; // creating 5 mutexes for the tools

// function simulating the robot's task
void robotTask(int id) {
    int leftTool = id; // the left tool is identified to be the "robot's" tool: robot 1's left tool is tool 1
    int rightTool = (id + 1) % numberOfRobots; // the right tool is identified to be the adjacent robot's tool, the right tool of robot 1 is tool 2. Modulus ensure that robot 5's right tool is just robot 1's left tool (tool 1)
    // robot is grabbing the left tool
    tools[leftTool].lock(); // locking the left tool
    tools[rightTool].lock(); // locking the right tool
    cout << "Robot " << id << " is reaching and grabbing the tools." << endl;
    this_thread::sleep_for(chrono::seconds(1)); // time it takes the robot to pickup both tools
    // robot has both tools, now it starts to complete its task
    cout << "Robot " << id << " acquired tools and starts performing a task." << endl;
    this_thread::sleep_for(chrono::seconds(5));  // time it takes the robot to complete its task
    // dropping the tools after the robot completed its task:
    tools[leftTool].unlock(); // unlocking the left tool
    tools[rightTool].unlock(); // unlocking the right tool
    cout << "Robot " << id << " finished the task and is returning the tools." << endl;
}

void question2();
