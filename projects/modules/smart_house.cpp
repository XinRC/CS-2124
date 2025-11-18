#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Device { 
};

class Connectable {

};

class PowerManageable {

 };

class SmartLight : public Device, public Connectable, public PowerManageable {

};

class SmartOutlet : public Device, public PowerManageable {

};

class SmartSpeaker : public Device, public Connectable {

 };

class SmartHome {
    private:
    public: // addDevice, displayAllDevices, connectDevice, turnOnDevice, displayAllDevices, disconnectAllDevices, turnoffDevice, 

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
