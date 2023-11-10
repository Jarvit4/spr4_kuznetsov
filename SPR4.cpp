#include <iostream>
#include <string>

// Базовий клас
class Vehicle {
protected:
    std::string brand;  

public:
    Vehicle(const std::string& brand) : brand(brand) {
        std::cout << "Vehicle constructor" << std::endl;
    }

    virtual ~Vehicle() {
        std::cout << "Vehicle destructor" << std::endl;
    }

    virtual void start() const = 0;  // Абстрактний метод

    void displayBrand() const {
        std::cout << "Brand: " << brand << std::endl;
    }
};

// Дочірній клас Car
class Car : public Vehicle {
private:
    int numDoors;  

public:
    Car(const std::string& brand, int numDoors) : Vehicle(brand), numDoors(numDoors) {
        std::cout << "Car constructor" << std::endl;
    }

    ~Car() override {
        std::cout << "Car destructor" << std::endl;
    }

    void start() const override {
        std::cout << "Car started" << std::endl;
    }

    void openDoors() const {
        std::cout << "Opened " << numDoors << " doors" << std::endl;
    }
};

// Дочірній клас Bicycle
class Bicycle : public Vehicle {
public:
    Bicycle(const std::string& brand) : Vehicle(brand) {
        std::cout << "Bicycle constructor" << std::endl;
    }

    ~Bicycle() override {
        std::cout << "Bicycle destructor" << std::endl;
    }

    void start() const override {
        std::cout << "Bicycle started pedaling" << std::endl;
    }

    void ringBell() const {
        std::cout << "Ring, ring!" << std::endl;
    }
};

int main() {
    const int arraySize = 3;
    Vehicle* vehicles[arraySize];

    vehicles[0] = new Car("Toyota", 4);
    vehicles[1] = new Bicycle("BMX");
    vehicles[2] = new Car("Ford", 2);

    for (int i = 0; i < arraySize; ++i) {
        vehicles[i]->start();  // Поліморфізм
        vehicles[i]->displayBrand();  // public метод базового класу
        if (Car* car = dynamic_cast<Car*>(vehicles[i])) {
            car->openDoors();  // Виклик методу дочірнього класу (якщо це автомобіль)
        }
        else if (Bicycle* bicycle = dynamic_cast<Bicycle*>(vehicles[i])) {
            bicycle->ringBell();  // Виклик методу дочірнього класу (якщо це велосипед)
        }
        std::cout << "____" << std::endl;
    }

    // Звільнення пам'яті
    for (int i = 0; i < arraySize; ++i) {
        delete vehicles[i];
    }

    return 0;
}
