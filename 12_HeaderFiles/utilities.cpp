#include "utilities.h"
#include <iostream>    
#include <string>      
#include <cctype>      // needed for toupper() to normalize input

using namespace std;

// getValidChoice function handles choices in the game
// Returns: the validated uppercase character the player chose
char getValidChoice(string prompt, char optionA, char optionB) {

    char choice;  // variable to store what the player types

    // Loop forever until the player gives valid input
    // This validates the game and keeps it from crashing
    while (true) {
        cout << prompt;       // Display the choice prompt to the player
        cin >> choice;        // Capture a single character from the player

        choice = toupper(choice);

        // Check if the input matches either valid option
        if (choice == optionA || choice == optionB) {
            return choice;    // Valid input — send it back to the caller
        }

        cout << "\nYou must choose either " << optionA
             << " or " << optionB << ".\n\n";
    }
}

// playAgain functions handles the death screen and asks the player to retry or quit.
void playAgain(void (*restartFunction)()) {

    // Use our OWN getValidChoice function to handle the Y/N prompt
    char choice = getValidChoice("You have died. Play again? (Y/N): ", 'Y', 'N');

    // Route the player based on their choice
    if (choice == 'Y') {
        restartFunction();    // Call whatever function was passed in — the player retries
    }
    else {
        // Player chose N — end the game with a final farewell
        cout << "\n\nThe darkness closes in... and you are forgotten.\n"
             << "Goodbye.\n\n";
    }
}
