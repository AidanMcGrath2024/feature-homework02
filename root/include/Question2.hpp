#include "Question2.hpp"

void question2() {
     vector<thread> robots;  // container to store all the ongoing robot threads

    for (int i = 0; i < numberOfRobots; ++i) {
        robots.push_back(thread(robotTask, i));  // initiating the robot task in a new thread
    }

    for (auto& robot : robots) { // for loop to wait for all robot threads to complete their tasks
        robot.join();  // joining each robot thread, the main "thread" waits for all robots to be done their tasks
    }
}
