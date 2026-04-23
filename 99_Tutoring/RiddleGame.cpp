// this is where all the code for the riddle game is interpreted. 
// my custom source code file for the game
#include "RiddleGame.h" // header file 
#include <iostream> // for user input and output
#include <cstdlib> // for random riddle generation
#include <ctime> // for time function to seed random generator
#include <array> // for array of riddles
#include <string> // for string variable
using namespace std;

// Implement the RiddleGame constructor here to initialize the game and load the riddles and answers.
RiddleGame::RiddleGame()
{
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));
    // Load the riddles and answers into the game
    loadRiddles();
}


// This function will Greet the user and display the instructions of the game 
void RiddleGame :: greetings()
{
    cout << "------------------------------------------" << endl;
    cout << "Welcome to the C++ Ultimate Riddle Game!" << endl;
    cout << "------------------------------------------" << endl;

    // make user enter their name in 
  // declare variables for user input of thier name 
    string firstName;
    string lastName;
    cout << "\nPlease enter your first name:";
    cin >> firstName;
    cout << "\nPlease enter your last name: ";
    cin >> lastName;

}

// This function  will load riddles and answers in the game. 
void RiddleGame::loadRiddles() {

    //array of riddles and answers to be used in the game.
    getRiddles[0] = "I speak without a mouth and hear without ears. I have no body.";
    // ----------------------------------------------------------
    getAnswers[0] = "Echo";
    // ----------------------------------------------------------
    getRiddles[1] = "What is brown and has a tail, a head, and no legs?";
    // ----------------------------------------------------------
    getAnswers[1] = "Penny";
    // ----------------------------------------------------------
    getRiddles[2] = "You don't know me yet, but you always miss me when I'm gone.";
    // ----------------------------------------------------------
    getAnswers[2] = "Time";
    // ----------------------------------------------------------
    getRiddles[3] = "I can fly but have no wings. I cry but have no eyes.";
    // ----------------------------------------------------------
    getAnswers[3] = "Clouds";
    // ----------------------------------------------------------
    getRiddles[4] = "What color is the wind?";
    // ----------------------------------------------------------
    getAnswers[4] = "Blew";
    // ----------------------------------------------------------
    getAiddles[5] = "What is between heaven and earth?";
    // ----------------------------------------------------------
    getAnswers[5] = "And";
    // ----------------------------------------------------------
    getRiddles[6] = "When is L greater than XL?";
    // ----------------------------------------------------------
    getAnswers[6] = "Roman Numerals";
    // ----------------------------------------------------------
    getRiddles[7] = "My thunder comes before the lightning...";
    // ----------------------------------------------------------
    getAnswers[7] = "Volcano";
    // ----------------------------------------------------------
    getRiddles[8] = "What 5-letter word reads the same upside down?";
    // ----------------------------------------------------------
    getAnswers[8] = "SWIMS";
    // ----------------------------------------------------------
    getRiddles[9] = "What has hands but cannot clap?";
    // ----------------------------------------------------------
    getAnswers[9] = "Clock";

}

// This function will display the riddle to the user based on the index of the riddle in the array above .
void displayRiddle(int index);

// call getriddle array over here to get the riddle from the array and display it to the user.
    // variables and code block to display the riddle based on the index of the riddle in the array above. 
    {
	int index = 10; // index variable to keep track of which riddle to display (for example, it slects a random riddle from the array above)
    
    
    cout << "Riddle: " << getRiddles[10] << endl; // Display the riddle here with index variables
}


// This function will ask the user a riddle and return the number of attempts it took for the user to answer correctly.
int askRiddle(int attempts);

string userAnswer; // variable to store the user's answer
int attempts = 3;




// This function will run the main game loop, where the user will be asked riddles and their answers will be checked.
void playGame();
// this function will be called infinitely as long the players says yes to play again. 



for (int i = 0; i < 10; i++) {
	 displayRiddle(i); // Display the riddle based on the index of the riddle in the array above.


cout << "You have " << attempts << " attempts to guess the riddle." << endl;

cout << displayRiddle(i) << endl; // Display the riddle here with index variables

cout << " Your answer: " << endl;
cin >> userAnswer;



// This function will check the user's answer against the correct answer and return 1 if correct, 0 if incorrect.
int checkanswer();

if (userAnswer == getAnswers[i]) {
    cout << "Correct!" << endl;
    return 1; // Return 1 if the answer is correct
}
else {
    cout << "Incorrect. Try again." << endl;
    attempts--; // Decrease the number of attempts
    return 0; // Return 0 if the answer is incorrect
}
}

// This function will ask the user if they want to play again after the game is over.
void playAgain();
string response; // variable to store the user's response to play again or not
//ask the user if they want to play again after the game is over.
cout << "Do you want to play again? (Y/N)" << endl;
cin >> response;

// if user says yes, call the playGame function again to start a new game.
if 
 (response == "Y" || response == "y") {
    playGame(); // calls the playgame function again Start a new game
}
// if user says no, display score and end the program. 
else if 
     
(response == "N" || response == "n") {
    score(); // Display the user's score
    cout << "Thanks for playing!" << endl;
    exit(0); // End the program
}

// This function will calculate and display the user's score if they don't want to play again.
void score();

if (response == "Y" || response == "y") {
    playGame(); // calls the playgame function again Start a new game
}
else if (response == "N" || response == "n") {
    score(); // Display the user's score
    cout << "Thanks for playing!" << endl;
    exit(0); // End the program
}