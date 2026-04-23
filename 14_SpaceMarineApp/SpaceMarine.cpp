// =============== IMPLEMENTATION FILE: SPACEMARINE.CPP ===============
// Implements the SpaceMarine Class.  This is the actual construction 
// where the header file is the blueprint of the class.
// Full logic and instructions for all of the functions declared in
// SpaceMarine.h are found in this file
// =====================================================================

// =============== INCLUDE PREPROCESSING LIBRARIES ===============
// Header files first to connect this .cpp file to the matching .h
#include "SpaceMarine.h"    // dev created
#include <iostream>         
using namespace std;        // so we don't need to type std:: all the time in this file

// =============== CONSTRUCTOR DEFINITION ===============
// SpaceMarine::  indicates this fucntion belongs to the SpaceMarine class
// Trying out an intersteding way to initialize the list using a : after the ()
// By using the initialization method we set all the variables as we define the constructor.
// This allows the INITIALIZER List to run before the body of the constructor.
// The curly braces are still needed even though the body is empty.
// Looks very clean and is modern C++ 26 design
SpaceMarine::SpaceMarine(string marineName, string marineRole, int power, bool veteran)
     : name(marineName), role(marineRole), combatPower(power), isVeteran(veteran){

}

// =============== GETTER DEFINITIONS ===============
// Getters will return the private variables from SpaceMarine.h
// SpaceMarine::  prefix indicates ownership by the SpaceMarine class 
// Using const as in the header file - to ensure data can never change

// Return the marine's name to the caller
string SpaceMarine::getName() const     // const tells compliler this fucntion will never change
{
    return name;
}

// Return the marine's role to the caller
string SpaceMarine::getRole() const
{
    return role;
}

// Return marine's combat power to the caller
int SpaceMarine::getCombatPower() const
{
    return combatPower;
}

// Return marine's verteran status to the caller
bool SpaceMarine::getIsVeteran() const
{
    return isVeteran;
}




