// =============== HEADER FILE: WEAPON.H ===============
// This is the HEADER file for the Weapon class.
// Used to that tell other files WHAT functions and 
// variables this class HAS without showing HOW they work.
// This will describe WHAT the weapon looks like
// Without providing the user the full logic of the code
// =========================================================

// Header guard - keeps this file from being included more than once.
#ifndef WEAPON_H
#define WEAPON_H
#include <string> // We need the strings

// ===== CREATE CLASS: Weapon Blueprint =====
class Weapon {

// ===== ACESS MODIFIER: PRIVATE =====
private:
    std::string name;     // The name of the weapon (e.g. "Dawnbreaker")
    std::string type;     // What kind it is (Sword, Staff, Bow, etc.)
    int damage;           // How much damage it deals

// ===== ACESS MODIFIER: PUBLIC =====
public:
    // ===== CONSTRUCTOR ===== 
    Weapon(std::string n, std::string t, int dmg);

    // ===== GETTER FUNCTIONS ===== 
    std::string getName();

    // ===== SETTER FUNCTIONS ===== 
    // None

    // Prints this weapon's details.
    void display();
};

// Close the header guard
#endif
