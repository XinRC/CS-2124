/*
smart_house.cpp focuses on the use of multiple inheritance to interact with smart devices
of a home. 
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Device { 
protected:
    string name;
    string id;
public:
    Device(const string& name, const string& id) : name(name), id(id) {}
    virtual ~Device() = default;
    
    const string& get_id() const { return id; }
    const string& get_name() const { return name; }
    
    // Virtual functions for capabilities
    virtual bool canConnect() const = 0;
    virtual bool canPowerManage() const = 0;
    virtual bool isConnected() const { return false; }
    virtual bool isPoweredOn() const { return false; }
    virtual void connect() {}
    virtual void disconnect() {}
    virtual void turnOn() {}
    virtual void turnOff() {}
    
    // Virtual display function
    virtual void display() const = 0;
};

class Connectable {
protected:
    bool connected;
public:
    Connectable() : connected(false) {}
    bool isConnected() const { return connected; }
    void setConnected(bool status) { connected = status; }
};

class PowerManageable {
protected:
    bool powered_on;
public:
    PowerManageable() : powered_on(false) {}
    bool isPoweredOn() const { return powered_on; }
    void setPoweredOn(bool status) { powered_on = status; }
};

class SmartLight : public Device, public Connectable, public PowerManageable {
public:
    SmartLight(const string& name, const string& id) : Device(name, id) {}
    
    bool canConnect() const { return true; }
    bool canPowerManage() const { return true; }
    bool isConnected() const { return Connectable::isConnected(); }
    bool isPoweredOn() const { return PowerManageable::isPoweredOn(); }
    void connect() { setConnected(true); }
   void disconnect()  { setConnected(false); }
    void turnOn() { setPoweredOn(true); }
    void turnOff() { setPoweredOn(false); }
    
    void display() const  {
        cout << "SmartLight: " << name << " (ID: " << id << ") - "
             << (isConnected() ? "Connected" : "Disconnected") << ", "
             << (isPoweredOn() ? "Powered On" : "Powered Off");
    }
};

class SmartOutlet : public Device, public PowerManageable {
public:
    SmartOutlet(const string& name, const string& id) : Device(name, id) {}
    
    bool canConnect() const { return false; }
    bool canPowerManage() const { return true; }
    bool isPoweredOn() const { return PowerManageable::isPoweredOn(); }
    void turnOn() { setPoweredOn(true); }
    void turnOff() { setPoweredOn(false); }
    
    void display() const  {
        cout << "SmartOutlet: " << name << " (ID: " << id << ") - "
             << (isPoweredOn() ? "Powered On" : "Powered Off");
    }
};

class SmartSpeaker : public Device, public Connectable {
public:
    SmartSpeaker(const string& name, const string& id) : Device(name, id) {}
    
    bool canConnect() const { return true; }
    bool canPowerManage() const  { return false; }
    bool isConnected() const { return Connectable::isConnected(); }
    void connect() { setConnected(true); }
    void disconnect() { setConnected(false); }
    
    void display() const {
        cout << "SmartSpeaker: " << name << " (ID: " << id << ") - "
             << (isConnected() ? "Connected" : "Disconnected");
    }
};

class SmartHome {
private:
    vector<Device*> smart_home_network; 
public:
    void displayAllDevices() {
        cout << "DEVICES:" << endl; 
        for(size_t i = 0; i < smart_home_network.size(); ++i) {
            cout << i + 1 << ". ";
            smart_home_network[i]->display();
            cout << endl;
        }
    }

    void addDevice(Device* device) {
        smart_home_network.push_back(device);
    }

    void connectDevice(const string& device_id) {
        for (Device* device : smart_home_network) {
            if (device_id == device->get_id() && device->canConnect() && !device->isConnected()) {
                device->connect();
                cout << device->get_name() << " connected to WiFi." << endl;
                return;
            }
        }
        cout << "Device not found or cannot connect!" << endl;
    }

    void turnOnDevice(const string& device_id) {
        for (Device* device : smart_home_network) {
            if (device_id == device->get_id() && device->canPowerManage() && !device->isPoweredOn()) {
                device->turnOn();
                cout << device->get_name() << " turned ON." << endl;
                return;
            }
        }
        cout << "Device not found or cannot power manage!" << endl;
    }

    void disconnectDevice(const string& device_id) {
        for (Device* device : smart_home_network) {
            if (device_id == device->get_id() && device->canConnect() && device->isConnected()) {
                device->disconnect();
                cout << device->get_name() << " disconnected from WiFi." << endl;
                return;
            }
        }
        cout << "Device not found or not connected!" << endl;
    }

    void turnOffDevice(const string& device_id) {
        for (Device* device : smart_home_network) {
            if (device_id == device->get_id() && device->canPowerManage() && device->isPoweredOn()) {
                device->turnOff();
                cout << device->get_name() << " turned OFF." << endl;
                return;
            }
        }
        cout << "Device not found or not powered on!" << endl;
    }

    ~SmartHome() {
        for (Device* device : smart_home_network) {
            delete device;
        }
        smart_home_network.clear();
    }
};

int main() {
    SmartHome home;
    
    // Add devices
    home.addDevice(new SmartLight("Living Room Light", "LR1"));
    home.addDevice(new SmartOutlet("Kitchen Outlet", "K1")); 
    home.addDevice(new SmartSpeaker("Bedroom Speaker", "B1"));
    
    // Test operations
    cout << "=== SMART HOME STATUS ===" << endl;
    home.displayAllDevices();
    
    cout << "\n=== CONNECTING DEVICES ===" << endl;
    home.connectDevice("LR1");
    home.connectDevice("B1");
    
    cout << "\n=== POWER MANAGEMENT ===" << endl;
    home.turnOnDevice("LR1");
    home.turnOnDevice("K1");
    
    cout << "\n=== CURRENT STATUS ===" << endl;
    home.displayAllDevices();
    
    cout << "\n=== DISCONNECTING ===" << endl;
    home.disconnectDevice("B1");
    
    cout << "\n=== TURNING OFF ===" << endl;
    home.turnOffDevice("LR1");
    
    cout << "\n=== FINAL STATUS ===" << endl;
    home.displayAllDevices();
    
    return 0;
}