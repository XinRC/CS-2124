#include <iostream>
#include <vector>
#include <string>
using namespace std;


/*
Different vehicle types: Car, Motorcycle, Truck (inheritance)

Customers can rent and return vehicles

Track which vehicles are rented by which customers

Calculate rental costs based on vehicle type and rental days

Prevent renting if vehicle is already rented
*/

class Vehicle {
    private:
        string car_name;
        string model; 
        double daily_cost;
    public:
        Vehicle(const string& name, const string& model, double daily_cost) 
            : car_name(name), model(model), daily_cost(daily_cost) {}
};


class Car : public Vehicle {
    private:
    public:
        using Vehicle::Vehicle;
};

class Motorcycle : public Vehicle { 
    private:
    public:
        using Vehicle::Vehicle;

}; 

class Truck : public Vehicle {
    private:
    public:
        using Vehicle::Vehicle;
};

class Customer {
    private:
        string cust_name;
        string id;
    public:
        Customer(const string& name, const string& id) 
        : cust_name(name), id(id) {}
};

class RentalSystem {
    private:
        vector<Vehicle*> vehicle_database;
        vector<Customer*> customer_database;
    public:
    // methods: addVehicle, registerCustomer, displayAllVehicles, rentVehicle, calculateRentalCost, returnVehicle, displayVehicleDetails
};

int main() {
    RentalSystem rental;
    
    // Add vehicles to rental system
    rental.addVehicle(new Car("Toyota Camry", "C001", 50.0));      // $50 per day
    rental.addVehicle(new Car("Honda Civic", "C002", 45.0));
    rental.addVehicle(new Motorcycle("Harley Davidson", "M001", 75.0));  // $75 per day
    rental.addVehicle(new Truck("Ford F-150", "T001", 100.0));     // $100 per day
    
    // Register customers
    rental.registerCustomer("Alice Johnson", "CU001");
    rental.registerCustomer("Bob Smith", "CU002");
    
    // Test operations
    cout << "=== RENTAL SYSTEM STATUS ===" << endl;
    rental.displayAllVehicles();
    rental.displayAllCustomers();
    
    cout << "\n=== RENTING VEHICLES ===" << endl;
    rental.rentVehicle("CU001", "C001", 3);  // Alice rents Camry for 3 days
    rental.rentVehicle("CU002", "M001", 2);  // Bob rents Harley for 2 days
    
    cout << "\n=== ATTEMPT DUPLICATE RENT ===" << endl;
    rental.rentVehicle("CU001", "M001", 1);  // Try to rent already rented vehicle
    
    cout << "\n=== CALCULATE RENTAL COSTS ===" << endl;
    rental.calculateRentalCost("CU001");  // Alice's rental cost
    rental.calculateRentalCost("CU002");  // Bob's rental cost
    
    cout << "\n=== CURRENT STATUS ===" << endl;
    rental.displayAllVehicles();
    
    cout << "\n=== RETURNING VEHICLE ===" << endl;
    rental.returnVehicle("CU001", "C001");  // Alice returns Camry
    
    cout << "\n=== FINAL STATUS ===" << endl;
    rental.displayAllVehicles();
    rental.displayAllCustomers();
    
    // Test polymorphism - different vehicle types
    cout << "\n=== VEHICLE INFORMATION (POLYMORPHISM) ===" << endl;
    rental.displayVehicleDetails("C002");  // Available car
    rental.displayVehicleDetails("M001");  // Rented motorcycle  
    rental.displayVehicleDetails("T001");  // Available truck
    
    return 0;
}


/*
=== RENTAL SYSTEM STATUS ===
VEHICLES:
1. [CAR] Toyota Camry (ID: C001) - Available - $50/day
2. [CAR] Honda Civic (ID: C002) - Available - $45/day  
3. [MOTORCYCLE] Harley Davidson (ID: M001) - Available - $75/day
4. [TRUCK] Ford F-150 (ID: T001) - Available - $100/day

CUSTOMERS:
Alice Johnson (ID: CU001) - 0 vehicles rented
Bob Smith (ID: CU002) - 0 vehicles rented

=== RENTING VEHICLES ===
Alice Johnson rented 'Toyota Camry' for 3 days
Bob Smith rented 'Harley Davidson' for 2 days

=== ATTEMPT DUPLICATE RENT ===
Cannot rent 'Harley Davidson' - Vehicle already rented by Bob Smith

=== CALCULATE RENTAL COSTS ===
Alice Johnson's rental cost: $150.00
Bob Smith's rental cost: $150.00

=== CURRENT STATUS ===
VEHICLES:
1. [CAR] Toyota Camry (ID: C001) - Rented by Alice Johnson (3 days)
2. [CAR] Honda Civic (ID: C002) - Available - $45/day
3. [MOTORCYCLE] Harley Davidson (ID: M001) - Rented by Bob Smith (2 days)
4. [TRUCK] Ford F-150 (ID: T001) - Available - $100/day

=== RETURNING VEHICLE ===
Alice Johnson returned 'Toyota Camry'

=== FINAL STATUS ===
VEHICLES:
1. [CAR] Toyota Camry (ID: C001) - Available - $50/day
2. [CAR] Honda Civic (ID: C002) - Available - $45/day
3. [MOTORCYCLE] Harley Davidson (ID: M001) - Rented by Bob Smith (2 days)
4. [TRUCK] Ford F-150 (ID: T001) - Available - $100/day

CUSTOMERS:
Alice Johnson (ID: CU001) - 0 vehicles rented
Bob Smith (ID: CU002) - 1 vehicles rented

=== VEHICLE INFORMATION (POLYMORPHISM) ===
CAR: Honda Civic | ID: C002 | Seats: 5 | Trunk Size: 15 cubic ft
MOTORCYCLE: Harley Davidson | ID: M001 | Engine CC: 1200 | Has Storage: No  
TRUCK: Ford F-150 | ID: T001 | Cargo Capacity: 2000 lbs | 4WD: Yes
*/