#include <iostream>
#include <string>
#include <random>

using namespace std;

class GuessNumberGame {
private:
    int guess;
    int tries;
    int number;
    int max;
public:
    GuessNumberGame() {
        random_device rd;
        default_random_engine engine(rd());
        uniform_int_distribution<int> distribution(0, 100);
        number = distribution(engine);

        guess = 0;
        tries = 0;
        max = 10;
    }
    void play() {
        while (tries < max) {
            cout << "Guess the number (between 0 and 100): ";
            cin >> guess;

            tries++;

            if (guess == number) {
                cout << "Congratulations! You guessed the number in " << tries << " tries.\n";
            } else if (guess < number) {
                cout << "Too low. Try again.\n";
            } else {
                cout << "Too high. Try again.\n";
            }
            if (tries == max) {
                cout << "You run out of tries!!\n";
                break;
            }
        } 
    }
};

int main() {
    GuessNumberGame game;
    while (true) {
        game.play();
    }

    return 0;
}