// =============== HEADER FILE: ADVENTURER.H ===============
// This is the HEADER file for the Adventurer class.
// Used to that tell other files WHAT functions and 
// variables this class HAS without showing HOW they work.
// =========================================================

// Header guard to prevent this file from being included twice and throwing a compiler error
#ifndef ADVENTURER_H
#define ADVENTURER_H
#include <string> // We need the string library to stores text

// ===== CREATE CLASS: Adventurer Blueprint =====
// This class will be used to create adventurers 
// in our guild of heroes
class Adventurer {

// ===== ACESS MODIFIER: PRIVATE =====
// Variables can only be changed from inside the class.
// Protects the data.
private:
    std::string name;        // Protect and store the adventurers name
    std::string heroClass;   // Protect their class (Ranger, Wizard, Warrior...)
    int level;               // Protect and store their current level
    int hitPoints;           // Protect and store their current health

// ===== ACESS MODIFIER: PUBLIC =====
// Let outside users access these fucntions.
public:
    // ===== CONSTRUCTOR =====    
    // Runs automatically everytime a new Adventurer object is created. 
    // Sets up the starting values for the object.
    Adventurer(std::string n, std::string c, int lvl, int hp); // Practicing using relevant and shorter parameter names

    // ===== GETTER FUNCTIONS ===== 
    // The public can access the the name variable but CANNOT modify it
    std::string getName();

    // ===== SETTER FUNCTIONS ===== 
    // There are no setters because the program is designed so users don't need 
    // to change anything after the object is created.
    // This program does not allow users to change class, level, or HP, so no setters needed

    // Prints adventurer's info.
    void display();
};

// End of the header guard
#endif
