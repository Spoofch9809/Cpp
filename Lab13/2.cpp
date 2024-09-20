#include <iostream>
#include <string>

class CarbonFootprint {
public:
    virtual double getCarbonFootprint() const = 0;
    virtual void inputData() = 0;
    virtual ~CarbonFootprint() {}
};
 
class Factory : public CarbonFootprint {
private:    
    int productionHours, energyPerHour, wastePerHour;
public:
    void inputData() override {
        std::cout << "Enter Factory's productionHours, energyPerHour, wastePerHour: ";
        std::cin >> productionHours >> energyPerHour >> wastePerHour;
    }

    double getCarbonFootprint() const override {
        return productionHours * (energyPerHour + wastePerHour);
    }
};

class Building : public CarbonFootprint {
public:
    double energyConsumption;

    void inputData() override {
        std::cout << "Enter Building's energy consumption (kWh): ";
        std::cin >> energyConsumption;
    }

    double getCarbonFootprint() const override {
        return energyConsumption;
    }
};

class EnhancedBuilding : public Building {
public:
    int numberOfOccupants;

    void inputData() override {
        std::cout << "Enter Building's energy consumption (kWh) and number of occupants: ";
        std::cin >> energyConsumption >> numberOfOccupants;
    }

    double getCarbonFootprint() const override {
        return energyConsumption * numberOfOccupants;
    }
};

class Car : public CarbonFootprint {
private:
    double fuelConsumption;
    double fuelEfficiency;

public:
    void inputData() override {
        std::cout << "Enter Car's fuel consumption (liters) and fuel efficiency (km/liter): ";
        std::cin >> fuelConsumption >> fuelEfficiency;
    }

    double getCarbonFootprint() const override {
        return (fuelConsumption / fuelEfficiency);
    }
};

class ElectricCar : public CarbonFootprint {
private:
    double energyConsumption;
    double chargeEfficiency;

public:
    void inputData() override {
        std::cout << "Enter Electric Car's energy consumption (kWh), charge efficiency (ratio): ";
        std::cin >> energyConsumption >> chargeEfficiency;
    }

    double getCarbonFootprint() const override {
        return (energyConsumption / chargeEfficiency);
    }
};

class Bicycle : public CarbonFootprint{
    public:
        double fuelConsumption;
        double fuelEfficiency;
        int manufacturingEmission;

        void inputData() override {
            std::cout << "Enter Bicycle's fuel consumption (liters), fuel efficiency (km/liter), and manufacturingEmission: ";
            std::cin >> fuelConsumption >> fuelEfficiency >> manufacturingEmission;
        }

        double getCarbonFootprint() const override {
            return (fuelConsumption / fuelEfficiency) * manufacturingEmission;
        }
};


int main() {
    EnhancedBuilding building;
    Car car;
    ElectricCar electricCar;
    Bicycle bicycle;
    Factory factory;

    
    building.inputData();
    car.inputData();
    electricCar.inputData();
    bicycle.inputData();
    factory.inputData();

    
    std::cout << "Building Carbon Footprint: " << building.getCarbonFootprint() << " tons of CO2" << std::endl;
    std::cout << "Car Carbon Footprint: " << car.getCarbonFootprint() << " tons of CO2" << std::endl;
    std::cout << "Electric Car Carbon Footprint: " << electricCar.getCarbonFootprint() << " tons of CO2" << std::endl;
    std::cout << "Bicycle Carbon Footprint: " << bicycle.getCarbonFootprint() << " tons of CO2" << std::endl;
    std::cout << "Factory Carbon Footprint: " << factory.getCarbonFootprint() << " tons of CO2" << std::endl;

    return 0;
}