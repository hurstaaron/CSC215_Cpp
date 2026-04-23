// =============== HEADER FILE: SQUAD.H ==================
// HEADER file for the Squad class.
// The Squad is a group of SpaceMarine objects
// =======================================================

// Include guard - prevent the compiler from readig the file more than once
#ifndef SQUAD_H
#define SQUAD_H

// =============== INCLUDE PREPROCESSING LIBRARIES ===============
// Start with uder defined 
#include "SpaceMarine.h"
#include <vector>           // Need resizable arrays
using namespace std;

// =============== DECLARE CLASS ===============
class Squad
{
    // =============== ACCESS MODIFIER: PRIVATE ===============
    private:
        string squadName;               // Example name of a squad: "Blood Ravens"
        vector<SpaceMarine> marines;    // Dynamic list of SpaceMarine objects (how the squad contains marines)
        int maxSize;                    // The maximum number of marines allowed in a squad
        int currentSize;                // The current size of the squad

    // =============== ACCESS MODIFIER: PUBLIC ===============
    public:
                
        // =============== DECLARE CONSTRUCTOR ===============
        // Create the Squad with the name and the max size
        Squad(string n, int m);

        // =============== DECLARE GETTERS ===============
        // Get the squad's private data
        // const so compiler knows this data will never change
        string getSquadName() const;
        int getCurrentSize() const;
        int getMaxSize() const;

        // =============== DECLARE SETTERS ===============
        void setSquadName(string newName);

        // =============== DECLARE HELPER FUNCTIONS ===============
        void displaySquad() const;

        // Calculate teh squad's total power RECURSIVE function
        // Intended to add combat power of all the marines.
        // Pass an index to track where we are at in the vector
        // This function will never change
        int calculateTotalPower(int index) const;
};

#endif // Close the guard