// FILE OVERVIEW:
//   main.cpp       — The program entry point, program starts here and is controlled here
//   scenarios.h    — Interactive choose your own adventure starts here (Play makes choices)
//   encounters.h   — Death and boss battle lives here
//   utilities.h    — Reusable functions live here (helper functions)

// INCLUDE OUR CUSTOM HEADERS
// Gives main() access to the functions it needs to run the program.
    // Main doesn't call encounters.h so it is not included
// The story encounters are handled by Scenarios.cpp
#include "scenarios.h"  // gives us access to grimDarkSetting()

// INCLUDE STANDARD LIBRARIES
#include <iostream>     // cout and cin for basic I/O
#include <string>       // string type for player name

using namespace std;    // Helps avoid typing std:: all the time


// BUILD MAIN
// Keep it short
int main() {
    // Trying to build a better UX because UX matters.
    // A little ASCII Art can't hurt
    cout << "\n"
         << "   ========================================\n"
         << "   ||                                    ||\n"
         << "   ||   WELCOME TO THE TOWN OF           ||\n"
         << "   ||       WHISPERINGTOLL               ||\n"
         << "   ||                                    ||\n"
         << "   ||   An Interactive Dark Fantasy      ||\n"
         << "   ||                                    ||\n"
         << "   ========================================\n\n"
         << "   Who enters these cursed lands?\n\n"
         << "   Enter your name: ";                             // <---- ask for players name

    // CAPTURE PLAYER NAME
    // Declare a string variable to hold the player's name.
    string playerName = " ";
    getline(cin, playerName); // Captures the ENTIRE line including spaces.
 
    // WARN PLAYERS TO GO BACK (UX)
    cout << "\nGo Back, " << playerName << "... NOW!\n";

    // LAUNCH THE GAME & BRANCHING
    // grimDarkSetting() is the first scenario. The function takes the player's name and returns a closing message string.
    // The game will then branches into theChapel() or listeningPaths() depending on the player choice 
    // The entire game is dependent on the opening scene of this function.
    // Declare sting var to store the return value
    string closingMessage = grimDarkSetting(playerName);
    // Display the returned value from grimDarkSetting() that is stored in closingMessage
    cout << closingMessage;

    return 0; // Exit the program
}

// NOTES ON HEADERS:
// When writing #include "scenarios.h", I am telling the compiler: "The functions declared in scenarios.h
// exist and you will find them at link time." The LINKER connects the function calls during implementation
    //   Header = promise that a function exists
    //   Source = the actual function code
    //   Linker = the matchmaker that connects them