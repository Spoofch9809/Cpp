#include <iostream> // Standard input-output stream library
#include <string> // String manipulation library
#include <cmath> // Math functions library
#include <algorithm> // Algorithms library
#include <vector> // Vector container library

using namespace std; // Using the standard namespace for convenience

// Function for making the maze more confusing
void randByChance(int chance, string t1) { 
    int n = rand() % 10 + 1; // Generating a random number between 1 and 10
    if (n <= chance){ // Checking if the random number is less than or equal to the given chance
        cout << t1; // Outputting the given string
    } else {
        cout << " "; // Outputting an empty space
    }
}

int main(){

    srand(time(NULL)); // Seeding the random number generator with current time
    // Generate pre path
    vector<int> path; // Declaring a vector to store the path
    for (int i = 0; i < 8; ++i){ // Loop to generate 8 random numbers
        path.push_back(rand() % 13 + 1); // Adding a random number between 1 and 13 to the path vector
    }

    for  (int row = 0; row < 15; ++row){ // Loop through rows of the maze
        for  (int collumn = 0; collumn < 15; ++collumn){ // Loop through columns of the maze
            if (collumn == 0 || collumn == 14){ // Checking if it's a border column
                cout << "#"; // Outputting a border character
            } else if ( row%2 == 0){ // Checking if it's an even row
                if (collumn == path[floor(row/2)]){ // Checking if the column is part of the path
                    cout << "."; // Outputting a path character
                } else {
                    if (row == 0 || row == 14){ // Checking if it's the top or bottom row
                        cout << "#"; // Outputting a border character
                    } else {
                        randByChance(9, "#"); // Making maze more confusing by randomly replacing wall with path
                    }
                }
            } else { 
                if (collumn >= min(path[floor(row/2)], path[floor(row/2) + 1]) && collumn <= max(path[floor(row/2)], path[floor(row/2) + 1])) {
                    cout << "."; // Outputting a path character
                } else {
                    randByChance(1, "#"); // Making maze more confusing by randomly replacing space with wall
                }

            }
        }
        cout << endl; // Moving to the next line after each row
    }

    return 0; // Indicating successful program execution
}
