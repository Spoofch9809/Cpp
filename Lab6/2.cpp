#include <iostream>
#include <string>
using namespace std;

class QuizQuestion {
private:
    string question;
    string answer;

public:
    QuizQuestion(string question, string answer);
    string getQuestion();
    string getAnswer();

    void displayQuestion() {
        cout << question << endl;
    }

    bool checkAnswer() {
        string choice;
            while (true) {
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice[0]) {
                    case 'a':
                    case 'b':
                    case 'c':
                    case 'A':
                    case 'B':
                    case 'C':
                        if (choice == answer) {
                            cout << "Correct!" << endl;
                            return true;
                        } else {
                            cout << "Incorrect!" << endl;
                            return false;
                        }
                    default:
                        cout << "Invalid input. Please enter a, b, or c." << endl;
            }
        }
    }
};

QuizQuestion::QuizQuestion(string question, string answer) {
    this->question = question;
    this->answer = answer;
}

int main() {
    int score = 0;
    QuizQuestion questions[] = {
        QuizQuestion("Question 1: What is the capital of France?\na) Berlin\nb) Paris\nc) London", "b"),
        QuizQuestion("Question 2: Which planet is known as the Red Planet?\na) Mars\nb) Jupiter\nc) Saturn", "a"),
        QuizQuestion("Question 3: What is the largest mammal?\na) Elephant\nb) Blue Whale\nc) Giraffe", "b"),
        QuizQuestion("Question 4: Who wrote 'Hamlet'?\na) Mark Twain\nb) Charles Dickens\nc) William Shakespeare", "c"),
        QuizQuestion("Question 5: What is the chemical symbol for water?\na) H2O\nb) CO2\nc) O2", "a")
    };

    int numQuestions = sizeof(questions) / sizeof(questions[0]);
    int currentQuestion = 0;

    while (currentQuestion < numQuestions) {
        questions[currentQuestion].displayQuestion();
        if (questions[currentQuestion].checkAnswer()) {
            score++;
        }
        currentQuestion++;
    }

    cout << "Your total score is: " << score << "/" << numQuestions << endl;

    return 0;
}