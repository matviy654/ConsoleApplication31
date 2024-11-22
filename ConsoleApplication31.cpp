#include <iostream>
#include <string>

class Engine {
private:
    int horsepower; 
    std::string type; 

public:
    Engine(int horsepower, const std::string& type) : horsepower(horsepower), type(type) {}

    void printInfo() const {
        std::cout << "Engine: " << type << ", Horsepower: " << horsepower << " HP\n";
    }
};

class Driver {
private:
    std::string name; 
    int age; 

public:
    Driver(const std::string& name, int age) : name(name), age(age) {}

    void printInfo() const {
        std::cout << "Driver: " << name << ", Age: " << age << " years\n";
    }
};

class Car {
private:
    std::string brand; 
    std::string model;
    int year;
    Engine engine; 
    Driver* driver; 

public:
    
    Car(const std::string& brand, const std::string& model, int year, const Engine& engine)
        : brand(brand), model(model), year(year), engine(engine), driver(nullptr) {}

    void assignDriver(Driver* driver) {
        this->driver = driver;
    }

    void printInfo() const {
        std::cout << "Car: " << brand << " " << model << " (" << year << ")\n";
        engine.printInfo();
        if (driver) {
            driver->printInfo();
        }
        else {
            std::cout << "No driver assigned.\n";
        }
    }
};

int main() {
 
    Engine engine1(1500, "Gasoline");
    Engine engine2(200, "Diesel");
    Engine engine3(30, "Electric");

    Car car1("Toyota", "Camry", 2020, engine1);
    Car car2("Ford", "Focus", 2018, engine2);
    Car car3("Tesla", "Model S", 2022, engine3);

    Driver driver1("John Doe", 35);
    Driver driver2("Jane Smith", 28);

    car1.assignDriver(&driver1);
    car2.assignDriver(&driver2);

    std::cout << "Car 1 Information:\n";
    car1.printInfo();
    std::cout << "\nCar 2 Information:\n";
    car2.printInfo();
    std::cout << "\nCar 3 Information:\n";
    car3.printInfo();

    return 0;
}
