#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Device { 
    private:
        string name;
        string room;
    public:
        Device(const string& name, const string& room) 
            : name(name), room(room) {}
        const string& get_room() const { return room; }
        const string& get_name() const { return name; }
};

class Connectable {
    private:
        bool connected;
    public:
        Connectable() : connected(false) {}
        // getter / setters
        void set_connected(bool connect) { 
            if (connect == true) { connected = true; } 
            else { connected = false; }}
            
};

class PowerManageable {
    private:
        bool turned_on;
    public:
        PowerManageable() : turned_on(false) {}
        void set_turn_on(bool turn_on) {
            if (turn_on == true) { turned_on = true;}
            else { turned_on = false; }}
 };

class SmartLight : public Device, public Connectable, public PowerManageable {
    public:
        using Device::Device;
};

class SmartOutlet : public Device, public PowerManageable {
    public:
        using Device::Device;
};

class SmartSpeaker : public Device, public Connectable {
    public:
        using Device::Device;
 };

class SmartHome {
    private:
        vector<Device*> smart_home_network; 
    public: // displayAllDevices, connectDevice, turnOnDevice, displayAllDevices, disconnectAllDevices, turnoffDevice, 
        SmartHome() {}
        ~SmartHome() {
            for (size_t i = 0; i < smart_home_network.size(); ++i) {
                delete smart_home_network[i];
            }
            smart_home_network.clear();
        }
        
        void displayAllDevice() {
            cout << "DEVICES: " << endl; 
            for(Device* device : smart_home_network) {

            }
        }

        void addDevice(Device* device) {
            smart_home_network.push_back(device);
        }

        void connectDevice(const string& room) {
            for (Device* device : smart_home_network) {
                if (room == device->get_room()) {
                    cout << device->get_name() << 
                }
            }
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


/*
=== SMART HOME STATUS ===
DEVICES:
1. SmartLight: Living Room Light (ID: LR1) - Disconnected, Powered Off
2. SmartOutlet: Kitchen Outlet (ID: K1) - Powered Off  
3. SmartSpeaker: Bedroom Speaker (ID: B1) - Disconnected

=== CONNECTING DEVICES ===
Living Room Light connected to WiFi
Bedroom Speaker connected to WiFi

=== POWER MANAGEMENT ===
Living Room Light turned ON
Kitchen Outlet turned ON

=== CURRENT STATUS ===
DEVICES:
1. SmartLight: Living Room Light (ID: LR1) - Connected, Powered On
2. SmartOutlet: Kitchen Outlet (ID: K1) - Powered On
3. SmartSpeaker: Bedroom Speaker (ID: B1) - Connected

=== DISCONNECTING ===
Bedroom Speaker disconnected from WiFi

=== TURNING OFF ===
Living Room Light turned OFF

=== FINAL STATUS ===
DEVICES:
1. SmartLight: Living Room Light (ID: LR1) - Connected, Powered Off
2. SmartOutlet: Kitchen Outlet (ID: K1) - Powered On
3. SmartSpeaker: Bedroom Speaker (ID: B1) - Disconnected
*/
