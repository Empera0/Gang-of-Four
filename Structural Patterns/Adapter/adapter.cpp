#include <iostream>

// Device interface
class Device {
public:
    virtual void on() = 0;
    virtual void off() = 0;
};

// Device class
class Fan {
public:
    void turnOn() {
        std::cout << "Fan turned on!" << std::endl;
    }

    void turnOff() {
        std::cout << "Fan turned off!" << std::endl;
    }
};

// Adapter class that adapts the Device interface to the Fan class
class DeviceAdapter : public Device {
private:
    Fan* fan;

public:
    DeviceAdapter(Fan* fan) {
        this->fan = fan;
    }

    void on() {
        fan->turnOn();
    }

    void off() {
        fan->turnOff();
    }
};

// Usage example
int main() {
    // Using the adapter to adapt the Fan class to the Device interface
    Fan* fan = new Fan();
    Device* device = new DeviceAdapter(fan);
    device->on();
    device->off();

    return 0;
}