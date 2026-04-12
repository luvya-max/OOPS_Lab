// Question 9: Multilevel Inheritance - Vehicle Fleet Management
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Level 1: Base class - Vehicle
class Vehicle {
protected:
    string make;
    string model;
    int year;
    double mileage;
    
public:
    // Constructor
    Vehicle() {
        make = "Unknown";
        model = "Unknown";
        year = 2020;
        mileage = 0.0;
        cout << "Vehicle default constructor called" << endl;
    }
    
    Vehicle(string mk, string mdl, int yr) {
        make = mk;
        model = mdl;
        year = yr;
        mileage = 0.0;
        cout << "Vehicle created: " << year << " " << make << " " << model << endl;
    }
    
    // Display vehicle information
    void displayVehicleInfo() {
        cout << "Make: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
        cout << fixed << setprecision(1);
        cout << "Mileage: " << mileage << " km" << endl;
    }
    
    // Add mileage
    void addMileage(double km) {
        mileage += km;
        cout << "Added " << km << " km to mileage. Total: " << mileage << " km" << endl;
    }
    
    // Getters
    string getMake() const { return make; }
    string getModel() const { return model; }
    int getYear() const { return year; }
    double getMileage() const { return mileage; }
    
    // Calculate vehicle age
    int calculateAge() {
        return 2024 - year;
    }
    
    // Virtual destructor
    virtual ~Vehicle() {
        cout << "Vehicle destroyed: " << make << " " << model << endl;
    }
};

// Level 2: Derived class from Vehicle - Truck
class Truck : public Vehicle {
protected:
    double loadCapacity;  // in tons
    double currentLoad;
    
public:
    // Constructor
    Truck() : Vehicle() {
        loadCapacity = 0.0;
        currentLoad = 0.0;
        cout << "Truck default constructor called" << endl;
    }
    
    Truck(string mk, string mdl, int yr, double capacity) : Vehicle(mk, mdl, yr) {
        loadCapacity = capacity;
        currentLoad = 0.0;
        cout << "Truck created with load capacity: " << capacity << " tons" << endl;
    }
    
    // Display truck information
    void displayTruckInfo() {
        cout << "\n=== TRUCK INFORMATION ===" << endl;
        displayVehicleInfo();  // Call base class method
        cout << fixed << setprecision(2);
        cout << "Load Capacity: " << loadCapacity << " tons" << endl;
        cout << "Current Load: " << currentLoad << " tons" << endl;
        cout << "Available Capacity: " << (loadCapacity - currentLoad) << " tons" << endl;
    }
    
    // Load cargo
    void loadCargo(double weight) {
        if (currentLoad + weight <= loadCapacity) {
            currentLoad += weight;
            cout << "Loaded " << weight << " tons. Current load: " << currentLoad << " tons" << endl;
        } else {
            cout << "Cannot load " << weight << " tons. Exceeds capacity!" << endl;
            cout << "Available space: " << (loadCapacity - currentLoad) << " tons" << endl;
        }
    }
    
    // Unload cargo
    void unloadCargo(double weight) {
        if (currentLoad >= weight) {
            currentLoad -= weight;
            cout << "Unloaded " << weight << " tons. Remaining load: " << currentLoad << " tons" << endl;
        } else {
            cout << "Cannot unload " << weight << " tons. Current load is only " << currentLoad << " tons" << endl;
        }
    }
    
    // Check if truck is at full capacity
    bool isFullyLoaded() {
        return currentLoad >= loadCapacity;
    }
    
    // Getters
    double getLoadCapacity() const { return loadCapacity; }
    double getCurrentLoad() const { return currentLoad; }
    
    // Destructor
    ~Truck() {
        cout << "Truck destroyed with capacity: " << loadCapacity << " tons" << endl;
    }
};

// Level 3: Derived class from Truck - RefrigeratedTruck
class RefrigeratedTruck : public Truck {
private:
    double temperatureControl;  // in Celsius
    double minTemperature;
    double maxTemperature;
    bool coolingSystemOn;
    
public:
    // Constructor
    RefrigeratedTruck() : Truck() {
        temperatureControl = 5.0;
        minTemperature = -20.0;
        maxTemperature = 20.0;
        coolingSystemOn = false;
        cout << "RefrigeratedTruck default constructor called" << endl;
    }
    
    RefrigeratedTruck(string mk, string mdl, int yr, double capacity, double temp) 
        : Truck(mk, mdl, yr, capacity) {
        temperatureControl = temp;
        minTemperature = -20.0;
        maxTemperature = 20.0;
        coolingSystemOn = false;
        cout << "Refrigerated Truck created with temperature control: " << temp << "°C" << endl;
    }
    
    // Display refrigerated truck information
    void displayRefrigeratedTruckInfo() {
        cout << "\n=== REFRIGERATED TRUCK INFORMATION ===" << endl;
        displayVehicleInfo();  // From Vehicle (Level 1)
        cout << fixed << setprecision(2);
        cout << "Load Capacity: " << loadCapacity << " tons" << endl;  // From Truck (Level 2)
        cout << "Current Load: " << currentLoad << " tons" << endl;
        cout << "Temperature Setting: " << temperatureControl << "°C" << endl;
        cout << "Temperature Range: " << minTemperature << "°C to " << maxTemperature << "°C" << endl;
        cout << "Cooling System: " << (coolingSystemOn ? "ON" : "OFF") << endl;
    }
    
    // Turn cooling system on
    void startCooling() {
        if (!coolingSystemOn) {
            coolingSystemOn = true;
            cout << "Cooling system started. Maintaining temperature at " << temperatureControl << "°C" << endl;
        } else {
            cout << "Cooling system is already running." << endl;
        }
    }
    
    // Turn cooling system off
    void stopCooling() {
        if (coolingSystemOn) {
            coolingSystemOn = false;
            cout << "Cooling system stopped." << endl;
        } else {
            cout << "Cooling system is already off." << endl;
        }
    }
    
    // Set temperature
    void setTemperature(double temp) {
        if (temp >= minTemperature && temp <= maxTemperature) {
            temperatureControl = temp;
            cout << "Temperature set to " << temperatureControl << "°C" << endl;
        } else {
            cout << "Temperature out of range! Must be between " << minTemperature 
                 << "°C and " << maxTemperature << "°C" << endl;
        }
    }
    
    // Load perishable cargo
    void loadPerishableCargo(double weight, string cargoType) {
        if (!coolingSystemOn) {
            cout << "WARNING: Cooling system is OFF! Start cooling before loading perishables." << endl;
        }
        
        loadCargo(weight);  // Call Truck's method (Level 2)
        cout << "Loaded perishable cargo: " << cargoType << endl;
        
        if (coolingSystemOn) {
            cout << "Cargo is being kept at " << temperatureControl << "°C" << endl;
        }
    }
    
    // Check if suitable for cargo type
    bool isSuitableForCargo(string cargoType) {
        if (cargoType == "Frozen Food" && temperatureControl <= 0) {
            return true;
        } else if (cargoType == "Fresh Produce" && temperatureControl > 0 && temperatureControl <= 10) {
            return true;
        } else if (cargoType == "Dairy" && temperatureControl >= 2 && temperatureControl <= 8) {
            return true;
        }
        return false;
    }
    
    // Getters
    double getTemperature() const { return temperatureControl; }
    bool isCoolingOn() const { return coolingSystemOn; }
    
    // Destructor
    ~RefrigeratedTruck() {
        cout << "Refrigerated Truck destroyed (Temp: " << temperatureControl << "°C)" << endl;
    }
};

int main() {
    cout << "===== VEHICLE FLEET MANAGEMENT SYSTEM =====" << endl;
    cout << "\n--- MULTILEVEL INHERITANCE DEMONSTRATION ---" << endl;
    
    // Level 1: Create a basic Vehicle
    cout << "\n--- Creating Base Vehicle (Level 1) ---" << endl;
    Vehicle vehicle1("Honda", "Civic", 2022);
    vehicle1.displayVehicleInfo();
    vehicle1.addMileage(5000);
    cout << "Vehicle age: " << vehicle1.calculateAge() << " years" << endl;
    
    // Level 2: Create a Truck (inherits from Vehicle)
    cout << "\n--- Creating Truck (Level 2) ---" << endl;
    Truck truck1("Ford", "F-150", 2023, 3.5);
    truck1.displayTruckInfo();
    
    cout << "\n--- Loading Cargo into Truck ---" << endl;
    truck1.loadCargo(1.5);
    truck1.loadCargo(1.0);
    truck1.loadCargo(1.5);  // This will exceed capacity
    truck1.addMileage(150);
    truck1.displayTruckInfo();
    
    // Level 3: Create a Refrigerated Truck (inherits from Truck -> Vehicle)
    cout << "\n--- Creating Refrigerated Truck (Level 3) ---" << endl;
    RefrigeratedTruck refTruck1("Volvo", "FH16", 2024, 15.0, 5.0);
    refTruck1.displayRefrigeratedTruckInfo();
    
    cout << "\n--- Operating Refrigerated Truck ---" << endl;
    refTruck1.startCooling();
    refTruck1.setTemperature(3.0);
    
    cout << "\n--- Loading Perishable Cargo ---" << endl;
    refTruck1.loadPerishableCargo(5.0, "Fresh Vegetables");
    refTruck1.loadPerishableCargo(4.0, "Dairy Products");
    refTruck1.loadPerishableCargo(3.5, "Fruits");
    
    cout << "\n--- Checking Cargo Suitability ---" << endl;
    cout << "Suitable for Dairy? " << (refTruck1.isSuitableForCargo("Dairy") ? "Yes" : "No") << endl;
    cout << "Suitable for Frozen Food? " << (refTruck1.isSuitableForCargo("Frozen Food") ? "Yes" : "No") << endl;
    
    refTruck1.addMileage(350);
    refTruck1.displayRefrigeratedTruckInfo();
    
    cout << "\n--- Delivering Cargo ---" << endl;
    refTruck1.unloadCargo(5.0);
    refTruck1.unloadCargo(4.0);
    refTruck1.stopCooling();
    refTruck1.displayRefrigeratedTruckInfo();
    
    // Another refrigerated truck for frozen goods
    cout << "\n--- Creating Frozen Food Transport Truck ---" << endl;
    RefrigeratedTruck refTruck2("Mercedes", "Actros", 2024, 20.0, -18.0);
    refTruck2.startCooling();
    refTruck2.loadPerishableCargo(10.0, "Frozen Meat");
    refTruck2.loadPerishableCargo(8.0, "Ice Cream");
    refTruck2.displayRefrigeratedTruckInfo();
    
    cout << "\n===== MULTILEVEL INHERITANCE STRUCTURE =====" << endl;
    cout << "Level 1: Vehicle (make, model, year, mileage)" << endl;
    cout << "   |" << endl;
    cout << "   v" << endl;
    cout << "Level 2: Truck (inherits Vehicle + adds loadCapacity, currentLoad)" << endl;
    cout << "   |" << endl;
    cout << "   v" << endl;
    cout << "Level 3: RefrigeratedTruck (inherits Truck + adds temperatureControl, cooling)" << endl;
    
    cout << "\n===== KEY BENEFITS =====" << endl;
    cout << "1. RefrigeratedTruck has access to ALL features from Vehicle and Truck" << endl;
    cout << "2. Gradual specialization: Vehicle -> Truck -> RefrigeratedTruck" << endl;
    cout << "3. Code reusability at each level" << endl;
    cout << "4. Each level adds more specific functionality" << endl;
    cout << "5. Easy to maintain and extend the hierarchy" << endl;
    
    cout << "\n--- Program Ending (Destructors will be called in reverse order) ---" << endl;
    return 0;
}