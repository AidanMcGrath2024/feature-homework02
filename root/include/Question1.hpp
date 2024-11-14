#Question1headerfilesforcpp
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
using namespace std;

class Sensor {
public:
    Sensor() {};
    virtual gatherData() {};
    virtual processData() {};
};

class Radar : public Sensor
{
public:
    Radar() {};
    virtual gatherData() {
        cout << "Gathering data from Radar Sensor." << endl;
    }
    virtual processData() {
        cout << "Processing data from Radar Sensor." << endl;
    }

};

class LiDAR : public Sensor
{
public:
    LiDAR() {};
    virtual gatherData() {
        cout << "Gathering data from LiDAR Sensor." << endl;
    }
    virtual processData() {
        cout << "Processing data from LiDAR Sensor." << endl;
    }

};

class IMU : public Sensor
{
public:
    IMU() {};
    virtual gatherData() {
        cout << "Gathering data from IMU Sensor." << endl;
    }
    virtual processData() {
        cout << "Processing data from IMU Sensor." << endl;
    }

};

class SensorFactory {
    public:
    static ptr createSensor(string ) {

    }
}
