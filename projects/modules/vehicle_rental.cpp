#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Customer;

class Vehicle {
    friend ostream& operator<<(ostream& os, const Vehicle& rhs) {
        rhs.display(os);
        return os;
    }
    private:
        string car_name;
        string car_id; 
        double daily_cost;
        int days_rented;
        Customer* rented_by;
    public:
        Vehicle(const string& name, const string& car_id, double daily_cost) 
            : car_name(name), car_id(car_id), daily_cost(daily_cost),
                rented_by(nullptr), days_rented(0) {}
        virtual ostream& display(ostream& os) const = 0; 
        virtual void displayData() const = 0;

        // getters/setters:
        const string& get_car_id() const { return car_id; }
        Customer* get_rented_by() const { return rented_by; }
        void set_rented_by(Customer* customer) { rented_by = customer; }
        const string& get_car_name() const { return car_name; }
        void set_days_rented(int days) { days_rented = days; }
        int get_days_rented() const { return days_rented; }
        double get_daily_cost() const { return daily_cost; }
};

class Car : public Vehicle {
    private:
    public:
        using Vehicle::Vehicle;
        ostream& display(ostream& os) const {
            os << "[CAR] " << get_car_name() << " (ID: " << get_car_id() << ")";
            return os;
        }
        void displayData() const {
            cout << "CAR: " << get_car_name() << " | ID: " << get_car_id() 
                << " | Seats: 5 | Trunk Size: 15 cubic ft";
        }
};

class Motorcycle : public Vehicle { 
    private:
    public:
        using Vehicle::Vehicle;
        ostream& display(ostream& os) const {
            os << "[MOTORCYCLE] " << get_car_name() << " (ID: " << get_car_id() << ")";
            return os;
        }
        void displayData() const {
            cout << "MOTORCYCLE: " << get_car_name() << " | ID: " << get_car_id() 
                << " | Engine CC: 1200 | Has Storage: No ";
        }
}; 

class Truck : public Vehicle {
    private:
    public:
        using Vehicle::Vehicle;
        ostream& display(ostream& os) const {
            os << "[TRUCK] " << get_car_name() << " (ID: " << get_car_id() << ")";
            return os;
        }
        void displayData() const {
            cout << "TRUCK: " << get_car_name() << " | ID: " << get_car_id() 
                << " | Cargo Capacity: 2000 lbs | 4WD: Yes";
        }
};

class Customer {
    friend ostream& operator<<(ostream& os, const Customer& rhs) {
        os << rhs.cust_name << " (ID: " << rhs.id << ")";
        return os; 
    }
    private:
        string cust_name;
        string id;
        int vehicles_rented; 
    public:
        Customer(const string& name, const string& id) 
        : cust_name(name), id(id), vehicles_rented(0) {}
        // getters / setters
        const string& get_id() const { return id; }
        const string& get_cust_name() const { return cust_name; }
        int get_vehicles_rented() const { return vehicles_rented; }
        void set_vehicles_rented(int value) { vehicles_rented += value; }

};

class RentalSystem {
    private:
        vector<Vehicle*> vehicle_database;
        vector<Customer*> customer_database;
    public:
        void registerCustomer(const string& name, const string& id) {
            Customer* customer = new Customer(name, id);
            customer_database.push_back(customer);
        }

        void addVehicle(Vehicle* vehicle) {
            vehicle_database.push_back(vehicle);
        }

        void rentVehicle(const string& id, const string& car_id, int days) {
            int index_of_borrower = -1; 
            for (size_t i = 0; i < customer_database.size(); ++i) {
                if (id == customer_database[i]->get_id()) {
                    index_of_borrower = i; 
                }
            }

            for (Vehicle* vehicle : vehicle_database) {
                if (car_id == vehicle->get_car_id()) {
                    if (vehicle->get_rented_by() == nullptr) {
                        vehicle->set_rented_by(customer_database[index_of_borrower]);
                        vehicle->set_days_rented(days);
                        customer_database[index_of_borrower]->set_vehicles_rented(1);
                        cout << customer_database[index_of_borrower]->get_cust_name() << " rented '" 
                            << vehicle->get_car_name() << "' for " << days << " days" << endl; 
                    } else {
                        cout << "Cannot rent '" << vehicle->get_car_name() << "' - Vehicle already rented by " 
                            << vehicle->get_rented_by()->get_cust_name() << endl; 
                    }
                }
            }
        }

        void calculateRentalCost(const string& id) {
            int index_of_person;
            for (size_t i = 0; i < customer_database.size(); ++i) {
                if (id == customer_database[i]->get_id()) {
                    index_of_person = i; 
                    break;
                }
            }
            double cost;
            for (Vehicle* vehicle : vehicle_database) {
                if (vehicle->get_rented_by() != nullptr && id == vehicle->get_rented_by()->get_id()) {
                    cost = vehicle->get_days_rented() * vehicle->get_daily_cost();
                }
            }
            cout << customer_database[index_of_person]->get_cust_name() << "'s rental cost: $" 
                << cost << endl; 
        }
        
        void displayAllVehicles() {
            cout << "VEHICLES:" << endl; 
            int start = 0; 
            for (Vehicle* vehicle : vehicle_database) {
                cout << start + 1 << ". " << *vehicle << " - ";
                if (vehicle->get_rented_by() == nullptr) {
                    cout << "Available - $" << vehicle->get_daily_cost() << "/day"; 
                } else {
                    cout << "Rented by " << vehicle->get_rented_by()->get_cust_name() << " (" 
                        << vehicle->get_days_rented() << " days)";
                }
                cout << endl;
            }
            cout << endl;
        }

        void displayAllCustomers() {
            cout << "CUSTOMERS:" << endl;

            for (Customer* customer : customer_database) {
                cout << *customer << " - " << customer->get_vehicles_rented() 
                    << " vehicles rented" << endl; 
            }

        }

        void returnVehicle(const string& id, const string& car_id) {
            int index_of_car;
            for (size_t i = 0; i < vehicle_database.size(); ++i) {
                if (vehicle_database[i]->get_car_id() == car_id) {
                    vehicle_database[i]->set_rented_by(nullptr);
                    vehicle_database[i]->set_days_rented(0);
                    index_of_car = i; 
                }
            }

            for (Customer* customer : customer_database) {
                if (customer->get_id() == id) {
                    customer->set_vehicles_rented(-1);
                    cout << customer->get_cust_name() << " returned '" 
                        << vehicle_database[index_of_car]->get_car_name() << "'" << endl;
                }
            }
        }

        void displayVehicleDetails(const string& car_id) {
            for (Vehicle* vehicle : vehicle_database) {
                if (car_id == vehicle->get_car_id()) {
                    vehicle->displayData();
                    cout << endl;
                }
            }
        }

        ~RentalSystem() {
            for (size_t i = 0; i < vehicle_database.size(); ++i) {
                delete vehicle_database[i];
            }
            for (size_t i = 0; i < customer_database.size(); ++i) {
                delete customer_database[i];
            }
            vehicle_database.clear();
            customer_database.clear();
        }
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
