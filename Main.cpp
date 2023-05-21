#include <iostream>
#include <ctime>
#include <sstream>
#include <algorithm>
#include <vector>
#include <limits>

int rng() {
    return (std::rand() + 1325) % 16;
}

int getInput() {
    std::vector<int> validNumbers;
for (int i = 0; i <= 15; i++) {
    validNumbers.push_back(i);
} // Defines the valid numbers that can be used in the program, 1 -15.
    int guess;
    bool valid = false;
    while (!valid) {
        std::cout << "Guess a random number between 0 and 15: ";
        std::cin >> guess;

        if ((std::cin) && (std::find(validNumbers.begin(), validNumbers.end(), guess) != validNumbers.end())) {
            valid = true;
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Look, ya can't respond with anythin other than a number between 0 and 15, so please do that." << std::endl;
        }
    }
    return guess;
}

int main() {
    std::cout << "Welcome to the Wild West Random Number Guessing Game." << std::endl;

    bool playAgain = true;
    while (playAgain) {
        std::cout << "Let's go again then. Guess a number, one between 1 and 15." << std::endl;

        std::srand(static_cast<unsigned int>(std::time(nullptr)));

        int randomInt = rng();
        int numGuesses = 0;
        const int maxGuesses = 8;

        int userGuess;
        bool correctGuess = false;

        while (numGuesses < maxGuesses && !correctGuess) {
            userGuess = getInput();
            numGuesses++;

            if (userGuess == randomInt) {
                correctGuess = true;
                std::cout << "Ya got it, cowboy." << std::endl;
            }
            else {
                if (numGuesses < maxGuesses) {
                    std::cout << "Go ahead and try again." << std::endl;
                }
                else {
                    std::cout << "You're out of guesses. That number you was wonderin about, it was " << randomInt << ". Ya just can't win em all." << std::endl;
                }
            }
        }

        std::cout << "Wanna give it another go? (y/n): ";
        char playAgainInput;
        std::cin >> playAgainInput;

        playAgain = (playAgainInput == 'y' || playAgainInput == 'Y');
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}
