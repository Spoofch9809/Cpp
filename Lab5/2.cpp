#include <iostream>
#include <iomanip>

using namespace std;

class PopulationGrowth {
private:
    double initialPopulation;
    double annualGrowthRate;

public:
    PopulationGrowth(double initialPop, double growthRate)
        : initialPopulation(initialPop), annualGrowthRate(growthRate) {}

    void calculateGrowth(int years) {
        cout.imbue(locale(""));
        cout << setw(5) << "Year" << setw(25) << "Projected Population" << setw(20) << "Annual Increase" << endl;
        cout << setw(5) << "----" << setw(25) << "---------------------" << setw(20) << "----------------" << endl;
    
        double population = initialPopulation;
        bool doublingPrinted = false;

        for (int year = 1; year <= years; ++year) {
            double increase = population * (annualGrowthRate / 100);
            population += increase;

            cout << setw(5) << year << setw(25) << fixed << setprecision(2) << population << setw(20) << increase << endl;

            if (!doublingPrinted && population >= 2 * initialPopulation) {
                cout << "Population doubles in year " << year << endl;
                doublingPrinted = true;
            }
        }
    }
};

int main() {
    double initialPopulation;
    double annualGrowthRate;

    cout << "Enter the current world population: ";
    cin >> initialPopulation;

    cout << "Enter the annual growth rate (percentage): ";
    cin >> annualGrowthRate;

    int simulationYears = 75;

    PopulationGrowth populationGrowth(initialPopulation, annualGrowthRate);
    populationGrowth.calculateGrowth(simulationYears);

    return 0;
}
