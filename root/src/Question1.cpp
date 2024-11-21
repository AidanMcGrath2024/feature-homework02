#include "Question1.hpp"

int main() {
    AerospaceControlSystem ctrlSys; // instantiating the ctrlSys object as an AerospaceControlSystem class

    Sensor* Radar = SensorFactory::createSensor("Radar");
    if (Radar != nullptr) {
        ctrlSys.addSensor(Radar);
    }
    Sensor* LiDAR = SensorFactory::createSensor("LiDAR");
    if (LiDAR != nullptr) {
        ctrlSys.addSensor(LiDAR);
    }
    Sensor* IMU = SensorFactory::createSensor("IMU");
    if (IMU != nullptr) {
        ctrlSys.addSensor(IMU);
    }

    ctrlSys.monitorAndAdjust();

    return 0;
}
