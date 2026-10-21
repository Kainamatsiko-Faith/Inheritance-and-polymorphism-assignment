=#include <iostream>
#include <memory>
#include <string>

class Vehicle {
protected:
    std::string brand;
    int year;

public:
    Vehicle(const std::string& b, int y) : brand(b), year(y) {}
    virtual ~Vehicle() = default;  // safe deletion through base pointers

    virtual void startEngine() const {
        std::cout << brand << " (" << year << ") engine started." << std::endl;
    }

    void displayBasicInfo() const {
        std::cout << "Brand: " << brand << ", Year: " << year << std::endl;
    }
};

class Car : public Vehicle {
protected:
    int numDoors;

public:
    Car(const std::string& b, int y, int doors)
        : Vehicle(b, y), numDoors(doors) {}

    void openDoors() const {
        std::cout << "Opening " << numDoors << " doors." << std::endl;
    }
};

class ElectricCar : public Car {
private:
    int batteryKWh;

public:
    ElectricCar(const std::string& b, int y, int doors, int battery)
        : Car(b, y, doors), batteryKWh(battery) {}

    void startEngine() const override {
        std::cout << brand << " (" << year << ") electric motor ready." << std::endl;
    }

    void charge() const {
        std::cout << "Charging " << batteryKWh << " kWh battery." << std::endl;
    }

    void showFullDetails() const {
        displayBasicInfo();                                         // from Vehicle
        std::cout << "Doors: " << numDoors << std::endl;            // from Car
        std::cout << "Battery: " << batteryKWh << " kWh" << std::endl;  // own member
    }
};

int main() {
    ElectricCar myTesla("Tesla Model Y", 2024, 4, 75);

    std::cout << "=== Demonstrating Multilevel Inheritance ===" << std::endl;
    myTesla.startEngine();      // overridden in ElectricCar
    myTesla.openDoors();        // inherited from Car
    myTesla.charge();           // own function
    myTesla.showFullDetails();  // uses members from all three levels

    std::cout << "\n=== Demonstrating Polymorphism ===" << std::endl;
    std::unique_ptr<Vehicle> vehicle =
        std::make_unique<ElectricCar>("Nissan Leaf", 2023, 5, 40);
    vehicle->startEngine(); 
 return 0;
}