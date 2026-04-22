// ============================================================
// Weapon.cpp
// IMPLEMENTATION file for the Weapon class.
// This file contains the actual code for each function
// declared in Weapon.h.
// ============================================================

// Include our own header so the compiler knows our class exists.
#include "Weapon.h"
// Include iostream for screen output.
#include <iostream>

// ===== Constructor =====
// Purpose: Create a new Weapon object and set its starting values.
Weapon::Weapon(std::string n, std::string t, int dmg) {
    name = n;             // store the weapon's name
    type = t;             // store what type of weapon it is
    damage = dmg;         // store how much damage it does
}

// ===== display() =====
// Purpose: Print out everything about this weapon to the screen.
void Weapon::display() {
    // Print a header so users know this is a weapon entry.
    std::cout << "--- Weapon ---" << std::endl;
    // Print each stat on its own line.
    std::cout << "Name:   " << name << std::endl;
    std::cout << "Type:   " << type << std::endl;
    std::cout << "Damage: " << damage << std::endl;
    // Divider line to keep things tidy when many weapons print.
    std::cout << "--------------" << std::endl;
}

// ===== getName() =====
// Purpose: Safely return the weapon's name to outside code.
std::string Weapon::getName() {
    return name;          // send the name back to the caller
}
