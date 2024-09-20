#include <iostream>
#include <random>
using namespace std;

int generateRandomNumber(mt19937& rng) {
    uniform_int_distribution<int> dist(1, 100);
    return dist(rng);
}

int findMaxRecursive(int arr[], int size, int maxSoFar) {
    if (size == 0) {
        return maxSoFar;
    }
    else{
        if (arr[size - 1] > maxSoFar) {
            maxSoFar = arr[size - 1];
        }
        return findMaxRecursive(arr, size - 1, maxSoFar);
    }
}

int main() {
    random_device rd;
    mt19937 rng(rd());

    const int arraySize = 10;
    int randomArray[arraySize];

    cout << "Generated 10 random integers between 1 and 100: ";
    for (int i = 0; i < arraySize; ++i) {
        randomArray[i] = generateRandomNumber(rng);
        cout << randomArray[i] << " ";
    }

    int maxNumber = findMaxRecursive(randomArray, arraySize, 0);
    cout << "\nThe largest element in the array: " << maxNumber << endl;

    return 0;
}
