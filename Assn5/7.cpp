// Question 7: Multiple Inheritance - Car Dashboard System
#include <iostream>
#include <iomanip>
using namespace std;

// First base class: Speedometer
class Speedometer {
protected:
    double speed;  // in km/h
    double maxSpeed;
    
public:
    // Constructor
    Speedometer() {
        speed = 0.0;
        maxSpeed = 200.0;
        cout << "Speedometer initialized" << endl;
    }
    
    // Set current speed
    void setSpeed(double s) {
        if (s >= 0 && s <= maxSpeed) {
            speed = s;
        } else if (s > maxSpeed) {
            speed = maxSpeed;
            cout << "Speed limited to maximum: " << maxSpeed << " km/h" << endl;
        } else {
            speed = 0;
        }
    }
    
    // Get current speed
    double getSpeed() const {
        return speed;
    }
    
    // Display speed
    void displaySpeed() {
        cout << fixed << setprecision(1);
        cout << "Speed: " << speed << " km/h";
        if (speed > 120) {
            cout << " [SPEEDING!]";
        }
        cout << endl;
    }
    
    // Destructor
    ~Speedometer() {
        cout << "Speedometer destroyed" << endl;
    }
};

// Second base class: FuelGauge
class FuelGauge {
protected:
    double fuelLevel;  // in liters
    double tankCapacity;
    
public:
    // Constructor
    FuelGauge() {
        fuelLevel = 50.0;
        tankCapacity = 60.0;
        cout << "Fuel Gauge initialized" << endl;
    }
    
    // Set fuel level
    void setFuelLevel(double fuel) {
        if (fuel >= 0 && fuel <= tankCapacity) {
            fuelLevel = fuel;
        } else if (fuel > tankCapacity) {
            fuelLevel = tankCapacity;
        } else {
            fuelLevel = 0;
        }
    }
    
    // Consume fuel (simulating driving)
    void consumeFuel(double amount) {
        if (fuelLevel >= amount) {
            fuelLevel -= amount;
        } else {
            fuelLevel = 0;
        }
    }
    
    // Refuel
    void refuel(double amount) {
        if (fuelLevel + amount <= tankCapacity) {
            fuelLevel += amount;
            cout << "Refueled " << amount << " liters" << endl;
        } else {
            cout << "Tank full! Added " << (tankCapacity - fuelLevel) << " liters" << endl;
            fuelLevel = tankCapacity;
        }
    }
    
    // Get fuel level
    double getFuelLevel() const {
        return fuelLevel;
    }
    
    // Display fuel level
    void displayFuel() {
        cout << fixed << setprecision(1);
        cout << "Fuel Level: " << fuelLevel << "/" << tankCapacity << " liters";
        
        double fuelPercentage = (fuelLevel / tankCapacity) * 100;
        if (fuelPercentage < 15) {
            cout << " [LOW FUEL WARNING!]";
        }
        cout << " (" << fuelPercentage << "%)" << endl;
    }
    
    // Destructor
    ~FuelGauge() {
        cout << "Fuel Gauge destroyed" << endl;
    }
};

// Third base class: Thermometer
class Thermometer {
protected:
    double temperature;  // in Celsius
    double normalTemp;
    double maxTemp;
    
public:
    // Constructor
    Thermometer() {
        temperature = 90.0;
        normalTemp = 90.0;
        maxTemp = 120.0;
        cout << "Thermometer initialized" << endl;
    }
    
    // Set temperature
    void setTemperature(double temp) {
        temperature = temp;
    }
    
    // Update temperature based on engine activity
    void updateTemperature(double speedFactor) {
        // Temperature increases with speed
        temperature = normalTemp + (speedFactor * 0.15);
        if (temperature > maxTemp) {
            temperature = maxTemp;
        }
    }
    
    // Get temperature
    double getTemperature() const {
        return temperature;
    }
    
    // Display temperature
    void displayTemperature() {
        cout << fixed << setprecision(1);
        cout << "Engine Temperature: " << temperature << "°C";
        
        if (temperature > 110) {
            cout << " [OVERHEATING WARNING!]";
        } else if (temperature > 100) {
            cout << " [HOT]";
        }
        cout << endl;
    }
    
    // Destructor
    ~Thermometer() {
        cout << "Thermometer destroyed" << endl;
    }
};

// Derived class using MULTIPLE INHERITANCE
class CarDashboard : public Speedometer, public FuelGauge, public Thermometer {
private:
    string carModel;
    bool engineOn;
    
public:
    // Constructor
    CarDashboard(string model) : Speedometer(), FuelGauge(), Thermometer() {
        carModel = model;
        engineOn = false;
        cout << "Car Dashboard created for: " << carModel << endl;
    }
    
    // Start engine
    void startEngine() {
        if (!engineOn) {
            engineOn = true;
            cout << "\n=== ENGINE STARTED ===" << endl;
            cout << carModel << " is ready to drive!" << endl;
        } else {
            cout << "Engine is already running!" << endl;
        }
    }
    
    // Stop engine
    void stopEngine() {
        if (engineOn) {
            engineOn = false;
            setSpeed(0);
            cout << "\n=== ENGINE STOPPED ===" << endl;
        }
    }
    
    // Simulate driving
    void drive(double newSpeed, double duration) {
        if (!engineOn) {
            cout << "Please start the engine first!" << endl;
            return;
        }
        
        setSpeed(newSpeed);
        
        // Fuel consumption (approximate: 0.1 liter per km at 60 km/h)
        double distance = (newSpeed * duration) / 60.0;  // duration in minutes
        double fuelConsumed = distance * 0.08;
        consumeFuel(fuelConsumed);
        
        // Update temperature based on speed
        updateTemperature(newSpeed);
        
        cout << "\nDriving for " << duration << " minutes at " << newSpeed << " km/h" << endl;
        cout << "Distance covered: " << distance << " km" << endl;
        cout << "Fuel consumed: " << fuelConsumed << " liters" << endl;
    }
    
    // Display complete dashboard
    void displayDashboard() {
        cout << "\n========================================" << endl;
        cout << "      " << carModel << " - DASHBOARD" << endl;
        cout << "========================================" << endl;
        cout << "Engine Status: " << (engineOn ? "ON" : "OFF") << endl;
        displaySpeed();
        displayFuel();
        displayTemperature();
        cout << "========================================" << endl;
    }
    
    // Destructor
    ~CarDashboard() {
        cout << "Car Dashboard destroyed for: " << carModel << endl;
    }
};

int main() {
    cout << "===== CAR DASHBOARD SIMULATION =====" << endl;
    cout << "\n--- Creating Car Dashboard (Multiple Inheritance) ---" << endl;
    
    CarDashboard myCar("Tesla Model S");
    
    cout << "\n--- Initial Dashboard Status ---" << endl;
    myCar.displayDashboard();
    
    // Start engine
    myCar.startEngine();
    myCar.displayDashboard();
    
    // Simulate driving scenarios
    cout << "\n--- Scenario 1: City Driving ---" << endl;
    myCar.drive(60, 15);  // 60 km/h for 15 minutes
    myCar.displayDashboard();
    
    cout << "\n--- Scenario 2: Highway Driving ---" << endl;
    myCar.drive(120, 30);  // 120 km/h for 30 minutes
    myCar.displayDashboard();
    
    cout << "\n--- Scenario 3: High Speed (Testing Limits) ---" << endl;
    myCar.drive(180, 10);  // 180 km/h for 10 minutes
    myCar.displayDashboard();
    
    // Refuel
    cout << "\n--- Refueling ---" << endl;
    myCar.refuel(30);
    myCar.displayDashboard();
    
    // Stop engine
    myCar.stopEngine();
    myCar.displayDashboard();
    
    cout << "\n===== MULTIPLE INHERITANCE BENEFITS =====" << endl;
    cout << "1. CarDashboard inherits from THREE base classes simultaneously" << endl;
    cout << "2. Each component (Speed, Fuel, Temperature) is independent and reusable" << endl;
    cout << "3. CarDashboard combines all functionalities in one unified interface" << endl;
    cout << "4. Easy to maintain - each gauge can be modified independently" << endl;
    cout << "5. Demonstrates real-world use case of multiple inheritance" << endl;
    
    cout << "\n--- Program Ending ---" << endl;
    return 0;
}