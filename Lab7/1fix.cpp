#include <iostream>
#include <iomanip>
#include <array>

using namespace std;

class FoodPoll {
private:
    array<string, 5> dishes = {"Pad Thai", "Som Tam", "Mango Sticky Rice", "Tom Yum Goong", "Green Curry"};
    array<array<int, 5>, 10> ratings;

public:
    void collectRating() {
        for (int poll = 0; poll < 5; poll++) {
            cout << "Poll " << poll + 1 << endl;
            for (int i = 0; i < 5; i++) {
                cout << "Please input rating for " << dishes[i] << " in a scale of 1-10: ";
                int input;
                cin >> input;

                if (input < 1 || input > 10 || cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid rating. Please enter a rating between 1 and 10." << endl;
                    --i;
                    continue;
                }

                ratings[poll][i] = input;
            }
        }
    }

    void displayResults() {
        // Display a summary table with dishes on the left and ratings (1-10) across the top
        cout << setw(25) << left << "Dish";
        for (int i = 1; i <= 10; i++) {
            cout << setw(5) << right << i;
        }
        cout << setw(10) << right << "Average" << endl;

        for (int i = 0; i < 5; i++) {
            cout << setw(25) << left << dishes[i];
            int sum = 0;
            int count = 0;

            for (int j = 0; j < 5; j++) {
                sum += ratings[j][i];
                if (ratings[j][i] != 0) { // Check if a vote has been cast
                    count++;
                }
            }

            // Display the count for each rating (1-10) and average
            for (int k = 1; k <= 10; k++) {
                int ratingCount = 0;
                for (int j = 0; j < 5; j++) {
                    if (ratings[j][i] == k) {
                        ratingCount++;
                    }
                }
                cout << setw(5) << right << ratingCount;
            }

            double dishAverage = (count != 0) ? static_cast<double>(sum) / count : 0;
            cout << setw(10) << right << dishAverage << endl;
        }

        // Find and print the highest and lowest rated dishes
        int highestTotalScore = 0;
        int lowestTotalScore = numeric_limits<int>::max();
        string highestRatedDish, lowestRatedDish;

        for (int i = 0; i < 5; i++) {
            int totalScore = 0;
            for (int j = 0; j < 5; j++) {
                totalScore += ratings[j][i];
            }

            if (totalScore > highestTotalScore) {
                highestTotalScore = totalScore;
                highestRatedDish = dishes[i];
            }

            if (totalScore < lowestTotalScore) {
                lowestTotalScore = totalScore;
                lowestRatedDish = dishes[i];
            }
        }

        cout << "\nHighest Rated Dish: " << highestRatedDish << " (Total Score: " << highestTotalScore << ")" << endl;
        cout << "Lowest Rated Dish: " << lowestRatedDish << " (Total Score: " << lowestTotalScore << ")" << endl;
    }
};

int main() {
    FoodPoll foodPoll;
    foodPoll.collectRating();
    foodPoll.displayResults();

    return 0;
}
