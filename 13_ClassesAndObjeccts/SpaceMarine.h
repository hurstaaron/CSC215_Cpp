// HEADER FILE for SpaceMarine.cpp
// Contains the function prototypes

// OPEN INCLUDE GUARD to prevent the compiler from readign the file twice
#ifndef SPACEMARINE_H
#define SPACEMARINE_H

// Inlcude preproccesor libraries
#include <string>       // We want to use the string data type
using namespace std;    // Standard namespace makes it so we don't have to write std:: all the time

// ############### DECLARE CLASS: SpaceMarine ###############
// A Space Marine object exists and here are the attributes 
// (what it knows) and the methods (what it can do)
class SpaceMarine{
// ############### ENCAPSULATION!!! - DECLARE PRIVATE ###############
// The "private" access modifier means only THIS calss can use these variables
// This is an example of ENCAPSULATION in OOP, one of the most important and 
// powerful aspects of OOP. Encapsulation allows us to hide our data inside
// this class and only allow "controlled access" through getters and setters.
// The dev decides who can read the data, change it, and when. 
private:
    string name, role;  // The Space Marine's name and battlefield role
    int combatPower;    // This number rates strength in battle
    bool isVeteran;     // true = veteran, false = standard Marine

// Declare PUBLIC functions
// The "public" access modifier means these functions can be used anywhere, even outside the class
public:
    // ############### DECLARE CONSTRUCTOR ###############
    // Constructors are special function that runs automatically as soon as the Space Marine
    // object is created.  Sets up the starting values of the Space Marine object.
    // Constructors NEVER have return types.
    SpaceMarine(string marineName, string marineRole, int power, bool veteran);

    // ############### DECLARE GETTERS ###############  
    // Getter methods return the private variables and allow the outside world (public) 
    // to read the values through these 'getter methods".
    // Use "const" at the end so they will NOT change the objects data.
    // Notice we just add "get" infront of our variable name
    string getName() const;     
    string getRole() const;  
    int getCombatPower() const;
    bool getIsVeteran() const;
    
    // ############### DECLARE SETTERS ###############  
    // Setter methods are functions that will allow CHANGES to the private variables.
    // The outside world (public) will have the abilitiy to WRITE new data through them.
    // Notice we just add "set" infront of our variable name. 
    void setName(string newName);
    void setRole(string newRole);
    void setCombatPower(int newPower);
    void setIsVeteran(bool veteran);

    // ############### DECLARE DISPLAY ############### 
    // This function prints out the Marine's info.
    // It is delcared at the end so every Space Marine object created 
    // will know how to display itself to the user
    // Use "const" at the end so the fucntion will NOT change 
    void displayInfo() const;

};

// CLOSE INCLUDE GUARD to end the protected status of the code between the guard
#endif