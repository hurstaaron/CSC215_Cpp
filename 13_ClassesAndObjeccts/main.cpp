// =============== ADVENTURER GUILD ROSTER ===============
// This program allows users to look at the name, class,
// level, health, and weapon of the heroes of the guild.
// ================== PROGRAM WORKFLOPW ==================
// 1) Ask user to selct from list of 5 options
// 2) Depending on user selection, the user can view either
//      - The name of the and stats of the heroes 
//      - The weapon details and damage progile
//      - The Hero on top of the list
//      - The weapon on top of the list
//      - Quit browsing the guild roster
//
// NOTE: I am hard codeing for simplicity because I am working on something fun for the final

// Preprocessing libraries
#include <iostream>
#include "Adventurer.h" // Brings in the custom Adventurer class so we can create hero objects.
#include "Weapon.h"     // Brings in the custom Weapon class so we can create weapon objects.

// NOTE!!  I am trying to get into using modern best practices in the industry and
// my buddy told me to stop using namespace std because when code get longer it will get me in 
// trouble with naming conventions that will confuse the compiler. 

// Function prototypes
void displayAllHeroes(Adventurer heroes[]);
void displayAllWeapons(Weapon weapons[]);

int main() {

    // ----- Describe the program to the user -----
    std::cout << "=====================================" << std::endl;
    std::cout << "  ADVENTURER'S GUILD ROSTER v1.0    "  << std::endl;
    std::cout << "=====================================" << std::endl;
    std::cout << "This program keeps track of heroes"    << std::endl;
    std::cout << "and their weapons in our guild."       << std::endl;
    std::cout << "You can browse the full roster or"     << std::endl;
    std::cout << "view individual entries."              << std::endl;
    std::cout << std::endl;

    // ----- Hard code 5 Adventurer objects -----
    // Each line below creates ONE hero using the Adventurer constructor.
    // Arguments MUST go in order: name, class, level, HP
    Adventurer hero1("Kaelen Swiftarrow",     "Ranger",    15, 120);
    Adventurer hero2("Mira Stormweaver",      "Wizard",    18,  90);
    Adventurer hero3("Bardus Ironshield",     "Warrior",   14, 150);
    Adventurer hero4("Seraphine Lightbringer","Paladin",   16, 130);
    Adventurer hero5("Grom Shadowclaw",       "Barbarian", 12, 140);

    // Add the heroes to an array. No vector this time.
    Adventurer heroes[5] = { hero1, hero2, hero3, hero4, hero5 };

    // ----- Hard code 5 Weapon objects -----
    // Arguments MUST go in order: name, type, damage
    Weapon weapon1("Dawnbreaker",     "Sword",  45);
    Weapon weapon2("Staff of Storms", "Staff",  55);
    Weapon weapon3("Whisperwind Bow", "Bow",    38);
    Weapon weapon4("Hammer of Valor", "Hammer", 50);
    Weapon weapon5("Shadowfang",      "Dagger", 25);

    // Add weapons to an array.
    Weapon weapons[5] = { weapon1, weapon2, weapon3, weapon4, weapon5 };

    // Declare variable to remember user choice from the menu.
    // We start it at 0 so the menu loop runs at least once.
    int choice {0};

    // ===== While loop =====
    // Keep showing the menu until the user quits the program.
    while (choice != 5) {

        // Display the menu for the user to choose from.
        std::cout << "\n========= MAIN MENU =========" << std::endl;
        std::cout << "1. View all adventurers"         << std::endl;
        std::cout << "2. View all weapons"             << std::endl;
        std::cout << "3. View the lead adventurer"     << std::endl;
        std::cout << "4. View the legendary weapon"    << std::endl;
        std::cout << "5. Quit"                         << std::endl;
        std::cout << "Enter your choice (1-5): ";  // Interaction for UX. 

        // Read the number in.
        std::cin >> choice;
        std::cout << std::endl;   // blank line for readability

        // ===== Switch statement - decides what to do =====
        // I want to practivce using switch statements
        // because they are better design than a long if/else
        // statements when checking one variable against many values.
        switch (choice) {

            case 1:
                // User picked 1 -> show all heroes in the array.
                // Call helper fucntion
                displayAllHeroes(heroes);
                break;   // End the switch statement

            case 2:
                // User picked 2 -> show every weapon in the array.
                // Call the helper function
                displayAllWeapons(weapons);
                break;

            case 3:
                // User picked 3 -> show just the first hero.
                // Call the array at index 0
                heroes[0].display();
                break;

            case 4:
                // User picked 4 -> show just the first weapon.
                // Call the array at index 0
                weapons[0].display();
                break;

            case 5:
                // User picked 5 -> end the while loop and say bye for UX.
                std::cout << "Farewell, brave adventurer!" << std::endl;
                break;

            default:
                // Anything other than 1-5 lands here sends this message.
                // No break needed - default is the last case.
                std::cout << "Invalid choice. Please enter 1-5." << std::endl;
        }
    }

    return 0;
}

// ===== displayAllHeroes() =====
// This function loops through the hero array and prints each one.
void displayAllHeroes(Adventurer heroes[]) {
    // Loop through positions 0 through 4.
    for (int i = 0; i < 5; i++) {
        heroes[i].display();   // call display() on the hero at position i
    }
}

// ===== displayAllWeapons() =====
// Purpose: Loop through the weapon array and print each one.
void displayAllWeapons(Weapon weapons[]) {
    // Same pattern as above, just for weapons instead.
    for (int i = 0; i < 5; i++) {
        weapons[i].display();  // call display() on the weapon at position i
    }
}
