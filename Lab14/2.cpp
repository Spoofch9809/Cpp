#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    vector<double> numbers;
    double number;
    string inputLine;

    cout << "Enter numbers separated by spaces (end with a non-numeric character): ";
    getline(cin, inputLine);
    istringstream iss(inputLine);

    while (iss >> number) {
        numbers.push_back(number);
    }

    // Calculate mean
    double sum = 0;
    for (double num : numbers) {
        sum += num;
    }
    double mean = sum / numbers.size();

    // Calculate median
    sort(numbers.begin(), numbers.end());
    double median;
    if (numbers.size() % 2 == 0) {
        median = (numbers[numbers.size() / 2 - 1] + numbers[numbers.size() / 2]) / 2.0;
    } else {
        median = numbers[numbers.size() / 2];
    }

    // Calculate standard deviation
    double variance = 0;
    for (double num : numbers) {
        variance += pow(num - mean, 2);
    }
    double stddev = sqrt(variance / numbers.size());

    // Find minimum and maximum
    double minimum = *min_element(numbers.begin(), numbers.end());
    double maximum = *max_element(numbers.begin(), numbers.end());

    // Display results
    cout << fixed << setprecision(2);
    cout << "Mean: " << mean << endl;
    cout << "Median: " << median << endl;
    cout << "Standard Deviation: " << stddev << endl;
    cout << "Minimum: " << minimum << endl;
    cout << "Maximum: " << maximum << endl;

    return 0;
}
