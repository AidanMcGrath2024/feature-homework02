#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <memory>
#include <vector>
using namespace std;

class Sensor {
public:
    Sensor() {};
    virtual void gatherData() {}; // simulating data gathering
    virtual void processData() {}; // simulating data processing
    virtual string getType() const = 0; // making a getType function so that we can print out the type of the sensors when added or deleted
    virtual ~Sensor() {} // destructor for the sensor
};

class Radar : public Sensor // Radar class is derived from sensor 
{
public:
    Radar() {}; 
    virtual void gatherData() { // Radar's gather data function
        cout << "Gathering data from Radar Sensor." << endl;
    }
    virtual void processData() { // Radar's process data function
        cout << "Processing data from Radar Sensor." << endl;
    }
    string getType() const {
        return "Radar"; // the getType function for Radar will return "Radar"
    }

};

class LiDAR : public Sensor
{
public:
    LiDAR() {};
    virtual void gatherData() { // LiDAR's gather data function
        cout << "Gathering data from LiDAR Sensor." << endl;
    }
    virtual void processData() { // LiDAR's process data function
        cout << "Processing data from LiDAR Sensor." << endl;
    }
    string getType() const {
        return "LiDAR"; // the getType function for LiDAR will return "LiDAR"
    }

};

class IMU : public Sensor
{
public:
    IMU() {};
    virtual void gatherData() { // IMU's gather data function
        cout << "Gathering data from IMU Sensor." << endl;
    }
    virtual void processData() { // IMU's process data function
        cout << "Processing data from IMU Sensor." << endl;
    }
    string getType() const {
        return "IMU"; // the getType function for IMU will return "IMU"
    }

};

class SensorFactory {
    public:
    static Sensor* createSensor(const string& sensorType) {
        if (sensorType == "Radar"){ // if the sensor type is Radar...
            return new Radar(); // then a Radar sensor is added to the heap
        }
        else if (sensorType == "LiDAR") { // if the sensor type is LiDAR...
            return new LiDAR(); // then a LiDAR sensor is added to the heap
        }
        else if (sensorType == "IMU") { // if the sensor type is IMU...
            return new IMU(); // then an IMU sensor is added to the heap
        }
        else { // otherwise, 
            return nullptr; // a nullpointer is returned
        }
    }
};

class AerospaceControlSystem {
    private:
    vector<Sensor*> sensorPointers; // making a vector to store the sensor pointers

    public:
    void addSensor(Sensor* sensor) { // lowercase sensor in this case represents the pointer associated with the sensor in question
        sensorPointers.push_back(sensor); // adding the sensor pointer to the sensorPointers vector
        cout << "sensor created " << sensor << " of type """ << sensor->getType() << """" << endl; // sensor creation message
    }
    void monitorAndAdjust() {
        for(int i = 0; i < sensorPointers.size(); i++){
            sensorPointers[i]->gatherData(); // invoking the sensor's gatherData() function
            sensorPointers[i]->processData(); // invoking the sensor's processData() function
            cout << "Adjusting controls based on sensor data." << endl;
        }
    }
    ~AerospaceControlSystem() { // a destructor that will clean up the memeory of the sensorPointers vector
        for (Sensor* sensor : sensorPointers) { // loop that iterates through all pointers in sensorPointers
            cout << "sensor deleted " << sensor << " of type """ << sensor->getType() << """" << endl; // sensor deletion message (before its actually deleted, I know it hasn't been "deleted" yet)
            delete sensor;
        }
    }

};
