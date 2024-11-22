#Question 2 code


#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>

std::mutex tools[5]; // Mutexes for the 5 tools

// Function to simulate a robot performing its task
void perform_task(int robot_id)
{
    int left_tool = robot_id;            // Tool between robot and the next robot
    int right_tool = (robot_id + 1) % 5; // Tool between robot and previous robot

    // Lock both tools, ensuring the robot grabs both before starting
    if (left_tool < right_tool)
    {
        tools[left_tool].lock();
        tools[right_tool].lock();
    }
    else
    {
        tools[right_tool].lock();
        tools[left_tool].lock();
    }

    // Once both tools are locked, the robot can perform the task
    std::cout << "Robot " << robot_id << " has grabbed tools and is performing the task.\n";
    std::this_thread::sleep_for(std::chrono::seconds(5)); // Task duration

    // Release the tools after task is completed
    tools[left_tool].unlock();
    tools[right_tool].unlock();

    std::cout << "Robot " << robot_id << " has completed the task and released tools.\n";
}

int main()
{
    std::vector<std::thread> robots;

    // Creates 5 threads, one for each robot
    for (int i = 0; i < 5; ++i)
    {
        robots.push_back(std::thread(perform_task, i));
    }

    // Wait for all robots to finish their tasks
    for (auto &robot : robots)
    {
        robot.join();
    }

    return 0;
}
