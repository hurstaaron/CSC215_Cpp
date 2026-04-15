// This is the Header file for the main branching story scenarios
// and contains function prototypes for the narrative 

// INCLUDE GUARDRAILS
// Each header uses a UNIQUE guard name based on the filename so they don't cancel each other
#ifndef SCENARIOS_H     // If SCENARIOS_H hasn't been defined yet, then
#define SCENARIOS_H     // define it now

// Include the libraries
#include <string>       // needed because grimDarkSetting takes and returns strings

// PREDECLARE FUNCTION PROTOTYPES
// grimDarkSetting() is the first choice: ruins or forest.
// Function will takes the player's name as a parameter for use in the narrative
// Returns a string
std::string grimDarkSetting(std::string name);

// theChapel() is the second senario. If ruins is selected, the player explores the ruins
// of Kareth Vane and encounters the Pale Confessor. The player then makes their second
// choice: priceForSpeaking (leasd to death) or head to the bossBattle.
// Function takes no parameters and returns nothing
void theChapel();

// listeningPaths() is the third scenario. The player enters Wyrmwood forest and finds the black pool.
// Leads to either bossBattle or seeTruth() (which leads to death).
// Function takes no parameters and returns nothing.
void listeningPaths();

#endif // ENDS THE INCLUDE GUARDRAIL
