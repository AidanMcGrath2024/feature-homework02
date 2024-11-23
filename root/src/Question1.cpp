#include "Question1.hpp"

int main() {
    AerospaceControlSystem ctrlSys; // instantiating the ctrlSys object as an AerospaceControlSystem class

    Sensor* Radar = SensorFactory::createSensor("Radar"); // creating a pointer for a Radar sensor with the createSensor function
    if (Radar != nullptr) { // if the pointer is not a null pointer...
        ctrlSys.addSensor(Radar); // then invoke its addSensor function, adding it to ctrlSys
    }
    Sensor* LiDAR = SensorFactory::createSensor("LiDAR"); // creating a pointer for a LiDAR sensor with the createSensor function
    if (LiDAR != nullptr) { // if the pointer is not a null pointer...
        ctrlSys.addSensor(LiDAR); // then invoke its addSensor function, adding it to ctrlSys
    }
    Sensor* IMU = SensorFactory::createSensor("IMU"); // creating a pointer for a IMU sensor with the createSensor function
    if (IMU != nullptr) { // if the pointer is not a null pointer...
        ctrlSys.addSensor(IMU); // then invoke its addSensor function, adding it to ctrlSys
    }

    // Just to prove the functionality of the selectivity of the createSensor function:
    Sensor* notAnIMU = SensorFactory::createSensor("NotAnIMU"); // creating a pointer for a IMU sensor with the createSensor function
    if (notAnIMU != nullptr) { // in this case the pointer IS a null pointer, so the line below is not executed
        ctrlSys.addSensor(notAnIMU); // not invoked
    }

    ctrlSys.monitorAndAdjust(); // invoking the monitorAndAdjust function - which will iterate through all sensors stored in the pointer vector
}
