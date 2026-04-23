// =============== ADVENTURER.CPP ===============
// This file IMPLEMENTS the adventure class
// Associated header file tells WHAT the class does
// This file tells HOW those things are done.
// ==============================================

// Pull in my header class telling thecompiler about the adventurer class.
#include "Adventurer.h"
#include <iostream>

// ===== CONSTRUCTOR =====
// Used to Build a new Adventurer and fill in their stats.
// The "Adventurer::" tells the compiler this function belongs to the "Adventurer" class.
Adventurer::Adventurer(std::string n, std::string c, int lvl, int hp) {
    name = n;             // save the name we are given
    heroClass = c;        // save the class type we are given
    level = lvl;          // save the level we are given
    hitPoints = hp;       // save the HP we are given
}

// ===== DISPLAY =====
// Used to show all of THIS INSTANCE of the adventurer's info
void Adventurer::display() {
    // Print a header line so users can tell entries apart for UX.
    std::cout << "--- Adventurer ---" << std::endl; // 19 chars
    // Print each stat on its own line for UX.
    std::cout << "Name:  " << name << std::endl;
    std::cout << "Class: " << heroClass << std::endl;
    std::cout << "Level: " << level << std::endl;
    std::cout << "HP:    " << hitPoints << std::endl;
    // Print a divider so multiple heroes don't blur together, for UX.
    std::cout << "===================" << std::endl; // 19 chars
}

// ===== GETTER USED =====
// Used to give the adventurer's name when asked.
// This is the safest way for users to read private variables.
std::string Adventurer::getName() {
    return name;          // Give the name back to the user.
}
