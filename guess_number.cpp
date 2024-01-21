#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to generate a random number between 1 and 100
int generateRandomNumber() {
    return rand() % 100 + 1;
}

// Function to get user's guess and provide feedback
bool playGame(int secretNumber) {
    int userGuess;
    int attempts = 0;

    do {
        // Get user's guess
        cout << "Enter your guess: ";
        cin >> userGuess;

        // Increment attempts
        attempts++;

        // Provide feedback
        if (userGuess < secretNumber) {
            cout << "Too low! Try again.\n";
        } else if (userGuess > secretNumber) {
            cout << "Too high! Try again.\n";
        } else {
            cout << "Congratulations! You guessed the correct number in " << attempts << " attempts.\n";
            return true; // The user guessed correctly
        }

    } while (userGuess != secretNumber);

    return false; // This line should never be reached, but included to avoid compiler warnings
}

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = generateRandomNumber();

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "Try to guess the secret number between 1 and 100.\n\n";

    // Call the playGame function
    playGame(secretNumber);

    return 0;
}
