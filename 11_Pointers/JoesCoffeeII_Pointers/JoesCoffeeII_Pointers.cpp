// ------------------------------------------------------------
// Cpp Pointers
// This program demonstrates how pointers work in C++.
// It also compares pass-by-value behavior to pointer behavior.
// The program uses user input, multiple functions, and 3 pointers
// in main() to meet the assignment requirements.
// ------------------------------------------------------------

// Add the input/output library so we can use cout and cin.
#include <iostream>

// Add the string library so we can use string variables.
#include <string>

// This lets us write cout instead of std::cout, cin instead of std::cin, etc.
using namespace std;


// ------------------------------------------------------------
// Function Prototypes
// These tell the compiler what functions exist before main().
// ------------------------------------------------------------

// Prints a section title to make the program easier to read.
void printTitle(string title);

// Prints account information using normal values.
void printAccountData(string ownerName, int joeBalance, int hackedBalance);

// Demonstrates pass by value.
// This function receives COPIES, so main's original values do not change.
void normalBalanceCheck(int joeBalance, int hackedBalance);

// Adds money to a balance using a pointer.
// Because the pointer points to the real variable, the real value changes.
void applyDepositByPointer(int* balancePtr, int depositAmount);

// Swaps two account balances using pointers.
// This changes the actual variables in main().
void swapBalancesByPointer(int* firstBalancePtr, int* secondBalancePtr);

// Changes the owner's name using a string pointer.
// This proves pointers also work with a different data type.
void renameOwnerByPointer(string* ownerNamePtr, string newName);

// Reads a non-negative integer from the user with basic validation.
int getNonNegativeInt(string prompt);


// ------------------------------------------------------------
// main()
// This is the control center of the program.
// The assignment says main should control the other functions.
// ------------------------------------------------------------
int main()
{
    // Print a title so the user knows what the program is.
    printTitle("Welcome to Cpp Pointers");

    // Create a string variable for the owner's name.
    // This gives us one data type: string.
    string joeOwnerName = "Joe";

    // Create integer variables for the two account balances.
    // This gives us another data type: int.
    int joeCoffeeBalance = 0;
    int hackedAccountBalance = 0;

    // Create another integer variable for a deposit amount.
    // We will use this later with a pointer function.
    int depositAmount = 0;


    // --------------------------------------------------------
    // User Input Section
    // Ask the user to enter the starting balances.
    // --------------------------------------------------------

    // Ask for Joe's Coffee Shop starting balance.
    joeCoffeeBalance = getNonNegativeInt("Enter Joe's Coffee Shop starting balance: $");

    // Ask for the hacked account starting balance.
    hackedAccountBalance = getNonNegativeInt("Enter Hacked Account starting balance: $");

    // Ask how much money to deposit into Joe's account later.
    depositAmount = getNonNegativeInt("Enter a deposit amount to add to Joe's account later: $");


    // --------------------------------------------------------
    // Create 3 pointers in main()
    // Requirement: create at least two pointers in main that
    // point to variables with at least two different data types.
    // We are creating 3 pointers here.
    // --------------------------------------------------------

    // Pointer #1:
    // This is an int pointer.
    // It stores the ADDRESS of joeCoffeeBalance.
    int* joeBalancePtr = &joeCoffeeBalance;

    // Pointer #2:
    // This is another int pointer.
    // It stores the ADDRESS of hackedAccountBalance.
    int* hackedBalancePtr = &hackedAccountBalance;

    // Pointer #3:
    // This is a string pointer.
    // It stores the ADDRESS of joeOwnerName.
    string* ownerNamePtr = &joeOwnerName;


    // --------------------------------------------------------
    // Print starting data
    // --------------------------------------------------------
    printTitle("Original Account Data");

    // Print the original values before any function changes happen.
    printAccountData(joeOwnerName, joeCoffeeBalance, hackedAccountBalance);

    // Print a blank line for readability.
    cout << endl;


    // --------------------------------------------------------
    // Show pointer basics in main()
    // This helps the learner see what each pointer is doing.
    // --------------------------------------------------------
    printTitle("Pointer Basics in main()");

    // Print the memory address stored inside joeBalancePtr.
    cout << "joeBalancePtr stores the address of joeCoffeeBalance: " << joeBalancePtr << endl;

    // Print the memory address stored inside hackedBalancePtr.
    cout << "hackedBalancePtr stores the address of hackedAccountBalance: " << hackedBalancePtr << endl;

    // Print the memory address stored inside ownerNamePtr.
    cout << "ownerNamePtr stores the address of joeOwnerName: " << ownerNamePtr << endl;

    // Dereference joeBalancePtr to print the VALUE at that address.
    cout << "*joeBalancePtr gives the value inside Joe's balance variable: $" << *joeBalancePtr << endl;

    // Dereference hackedBalancePtr to print the VALUE at that address.
    cout << "*hackedBalancePtr gives the value inside Hacked Account: $" << *hackedBalancePtr << endl;

    // Dereference ownerNamePtr to print the string value at that address.
    cout << "*ownerNamePtr gives the owner name value: " << *ownerNamePtr << endl;

    // Print a blank line for readability.
    cout << endl;


    // --------------------------------------------------------
    // Pass By Value Example
    // This function gets copies only.
    // It will NOT change the real balances in main().
    // --------------------------------------------------------
    printTitle("Pass By Value Example");

    // Call the function and send copies of the two balances.
    normalBalanceCheck(joeCoffeeBalance, hackedAccountBalance);

    // After the function ends, prove the original values did not change.
    printTitle("Balances After Pass By Value Function");

    // Print the balances again from main().
    // They should still be the original starting values.
    printAccountData(joeOwnerName, joeCoffeeBalance, hackedAccountBalance);

    // Print a blank line for readability.
    cout << endl;


    // --------------------------------------------------------
    // Pointer Function #1
    // Use a pointer to change the real Joe balance.
    // This satisfies the requirement that a value changed in a
    // function remains changed outside the function.
    // --------------------------------------------------------
    printTitle("Pointer Function Example: Deposit Into Joe's Account");

    // Call the deposit function and pass Joe's balance pointer.
    applyDepositByPointer(joeBalancePtr, depositAmount);

    // Prove back in main() that Joe's real balance changed.
    cout << "Back in main(), Joe's actual balance is now: $" << joeCoffeeBalance << endl;

    // Print a blank line for readability.
    cout << endl;


    // --------------------------------------------------------
    // Pointer Function #2
    // Swap the real balances using pointers.
    // This changes the actual variables in main().
    // --------------------------------------------------------
    printTitle("Pointer Function Example: Swap the Two Balances");

    // Call the swap function using the two int pointers.
    swapBalancesByPointer(joeBalancePtr, hackedBalancePtr);

    // Prove in main() that the actual variables were changed.
    cout << "Back in main() after swap:" << endl;
    cout << "Joe's Coffee Shop balance is now: $" << joeCoffeeBalance << endl;
    cout << "Hacked Account balance is now: $" << hackedAccountBalance << endl;

    // Print a blank line for readability.
    cout << endl;


    // --------------------------------------------------------
    // Pointer Function #3
    // Change the string variable through a string pointer.
    // This shows pointers can work with a different data type.
    // --------------------------------------------------------
    printTitle("Pointer Function Example: Change Owner Name");

    // Call the rename function and pass the string pointer.
    renameOwnerByPointer(ownerNamePtr, "Joe (Recovered Account)");

    // Prove in main() that the real string changed.
    cout << "Back in main(), the owner name is now: " << joeOwnerName << endl;

    // Print a blank line for readability.
    cout << endl;


    // --------------------------------------------------------
    // Final Output Section
    // Print all final values after the pointer-based changes.
    // --------------------------------------------------------
    printTitle("Final Account Data After Pointer Functions");

    // Print the final account data.
    printAccountData(joeOwnerName, joeCoffeeBalance, hackedAccountBalance);

    // Print a closing message.
    cout << endl;
    cout << "Program ended successfully." << endl;

    // Return 0 to show the program finished correctly.
    return 0;
}


// ------------------------------------------------------------
// Function Definitions
// ------------------------------------------------------------


// Prints a formatted title line.
void printTitle(string title)
{
    // Print a top border line.
    cout << "------------------------------------------------------------" << endl;

    // Print the title text.
    cout << title << endl;

    // Print a bottom border line.
    cout << "------------------------------------------------------------" << endl;
}


// Prints the account data in a clean format.
void printAccountData(string ownerName, int joeBalance, int hackedBalance)
{
    // Print the account owner's name.
    cout << "Owner Name: " << ownerName << endl;

    // Print Joe's Coffee Shop balance.
    cout << "Joe's Coffee Shop balance: $" << joeBalance << endl;

    // Print the hacked account balance.
    cout << "Hacked Account balance: $" << hackedBalance << endl;
}


// Demonstrates pass by value.
// This function only changes local copies, not the originals.
void normalBalanceCheck(int joeBalance, int hackedBalance)
{
    // Explain what the function received.
    cout << "Inside normalBalanceCheck() BEFORE local swap:" << endl;
    cout << "Joe's Coffee Shop balance copy: $" << joeBalance << endl;
    cout << "Hacked Account balance copy: $" << hackedBalance << endl;
    cout << endl;

    // Create a temporary variable to help swap the local copies.
    int temp = joeBalance;

    // Put hackedBalance copy into joeBalance copy.
    joeBalance = hackedBalance;

    // Put old joeBalance copy into hackedBalance copy.
    hackedBalance = temp;

    // Show that the local copies changed inside this function.
    cout << "Inside normalBalanceCheck() AFTER local swap:" << endl;
    cout << "Joe's Coffee Shop balance copy: $" << joeBalance << endl;
    cout << "Hacked Account balance copy: $" << hackedBalance << endl;
    cout << endl;

    // Important note for the learner.
    cout << "These changes only happened to COPIES, not the real variables in main()." << endl;
}


// Adds money to a balance through an int pointer.
void applyDepositByPointer(int* balancePtr, int depositAmount)
{
    // Explain what this function is about to do.
    cout << "Inside applyDepositByPointer() BEFORE deposit:" << endl;

    // Dereference the pointer to print the real current value.
    cout << "Balance pointed to by balancePtr: $" << *balancePtr << endl;

    // Print the deposit amount that will be added.
    cout << "Deposit amount to add: $" << depositAmount << endl;
    cout << endl;

    // Dereference the pointer and add the deposit amount.
    // This changes the actual variable in main().
    *balancePtr = *balancePtr + depositAmount;

    // Show the updated real value after the change.
    cout << "Inside applyDepositByPointer() AFTER deposit:" << endl;
    cout << "Balance pointed to by balancePtr is now: $" << *balancePtr << endl;
}


// Swaps two balances using pointers.
void swapBalancesByPointer(int* firstBalancePtr, int* secondBalancePtr)
{
    // Explain the values before the swap.
    cout << "Inside swapBalancesByPointer() BEFORE swap:" << endl;
    cout << "First balance pointed to: $" << *firstBalancePtr << endl;
    cout << "Second balance pointed to: $" << *secondBalancePtr << endl;
    cout << endl;

    // Create a temporary variable to save the first real value.
    int temp = *firstBalancePtr;

    // Copy the second real value into the first real variable.
    *firstBalancePtr = *secondBalancePtr;

    // Copy the saved first real value into the second real variable.
    *secondBalancePtr = temp;

    // Print the values after the swap.
    cout << "Inside swapBalancesByPointer() AFTER swap:" << endl;
    cout << "First balance pointed to: $" << *firstBalancePtr << endl;
    cout << "Second balance pointed to: $" << *secondBalancePtr << endl;
}


// Changes a string variable using a string pointer.
void renameOwnerByPointer(string* ownerNamePtr, string newName)
{
    // Show the old owner name before changing it.
    cout << "Inside renameOwnerByPointer() BEFORE change: " << *ownerNamePtr << endl;

    // Use the pointer to change the actual string in main().
    *ownerNamePtr = newName;

    // Show the new owner name after the change.
    cout << "Inside renameOwnerByPointer() AFTER change: " << *ownerNamePtr << endl;
}


// Gets a non-negative integer from the user with basic validation.
int getNonNegativeInt(string prompt)
{
    // Create a variable to store the user's number.
    int value = 0;

    // Start an infinite loop until valid input is entered.
    while (true)
    {
        // Ask the user for input.
        cout << prompt;

        // Try to read an integer from the keyboard.
        cin >> value;

        // Check whether the input succeeded and the number is non-negative.
        if (cin.fail() || value < 0)
        {
            // Print an error message if the input was bad.
            cout << "Invalid input. Please enter a non-negative whole number." << endl;

            // Clear the error state from cin.
            cin.clear();

            // Ignore the bad characters left in the input buffer.
            cin.ignore(1000, '\n');
        }
        else
        {
            // If input is valid, stop the loop and return the value.
            return value;
        }
    }
}
