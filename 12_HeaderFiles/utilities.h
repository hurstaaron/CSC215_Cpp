#ifndef UTILITIES_H    // If UTILITIES_H doesn't exist
#define UTILITIES_H    // ...define it 

// Include the libraries this header's functions will need
#include <string>      // needed because we pass strings to our utility functions

// FUNCTION PROTOTYPES

// getValidChoice: A reusable input validation function.
char getValidChoice(std::string prompt, char optionA, char optionB);

void playAgain(void (*restartFunction)());

#endif // ENDS THE INCLUDE GUARDRAIL
