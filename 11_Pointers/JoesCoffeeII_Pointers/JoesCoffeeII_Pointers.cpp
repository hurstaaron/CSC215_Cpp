#include <iostream>
#include <string>
using namespace std;


// ------------------------ STEP 1 ----------------------------------
// Predecare Functions 
// These tell the compiler what functions exist before main().
// ------------------------------------------------------------------

void printTitle(string title);                                              // Prints a section title to make the program easier to read.
void printAccountData(string ownerName, int joeBalance, int hackedBalance); // Prints account information using normal values.
void normalBalanceCheck(int joeBalance, int hackedBalance);                 // This function receives COPIES, so main's original values do not change.
void applyDepositByPointer(int* balancePtr, int depositAmount);             // Adds money to a balance using a pointer,the pointer points to the real variable, the real value changes.
void swapBalancesByPointer(int* firstBalancePtr, int* secondBalancePtr);    // Swaps the two account balances using pointers. This changes the actual variables in main().
void renameOwnerByPointer(string* ownerNamePtr, string newName);            // Changes the owner's name using a string pointer.
int getNonNegativeInt(string prompt);                                       // Reads a non-negative integer from the user with basic validation.


// ------------------------ STEP 3 ----------------------------------
// Create main()
// This is where we control the program by 
// calling the functions we will use
// ------------------------------------------------------------------
int main(){
    
    printTitle("Welcome to Joe's Coffee Shoppe");  // Print a title for the UX and pass string value to parameter

    // ------------------------ STEP 4 ----------------------------------
    // Decalre variables to use in main()
    // ------------------------------------------------------------------
    string joeOwnerName = "Joe";    // Create a string variable for Joe 
    int joeCoffeeBalance = 0;       // Create integer variables for the first account balance.
    int hackedAccountBalance = 0;   // Create integer variables for the second account balance.
    int depositAmount = 0;          // Create integer variable for a deposit amount. ** Will be used for pointer later **


    // ------------------------ STEP 5 ----------------------------------
    // Get the user input here for balance info
    // ------------------------------------------------------------------
    joeCoffeeBalance = getNonNegativeInt("Enter Joe's Coffee Shop starting balance: $");      // Ask user for Joe's Coffee Shop balance. 
    hackedAccountBalance = getNonNegativeInt("Enter Hacked Account starting balance: $");     // Ask for the hacked account balance.
    depositAmount = getNonNegativeInt("Enter a deposit amount to add to Joe's account: $");   // Ask how much money user wants to deposit into Joe's account later.
    cout << endl; // Print a blank line for readability and UX.

    // ------------------------ STEP 6 ----------------------------------
    // Decalre pointers that will be used to store ADDRESS of balances
    // ------------------------------------------------------------------
    int* joeBalancePtr = &joeCoffeeBalance;         // Pointer #1: an int pointer stores the ADDRESS of joeCoffeeBalance.
    int* hackedBalancePtr = &hackedAccountBalance;  // Pointer #2: an int pointer stores the ADDRESS of the hackedAccountBalance.
    string* ownerNamePtr = &joeOwnerName;           // Pointer #3: a string pointer stores the ADDRESS of joeOwnerName.


    printTitle("Original Account Data");  // Call fuction and pass string by value
    printAccountData(joeOwnerName, joeCoffeeBalance, hackedAccountBalance); // Print the original values before things are changed in the functions.
                        
    cout << endl; // Print a blank line for readability and UX.

    // ------------------------------------------------------------------
    // Tell the user the memory location where the balance is stored
    // Statements will print a memory ADDRESS like: 000000648F15F354
    // ------------------------------------------------------------------
    printTitle("This is how the ADDRESS looks in Memory");
    cout << "joeBalancePtr stores the address of joeCoffeeBalance: " << joeBalancePtr << endl;
    cout << "hackedBalancePtr stores the address of hackedAccountBalance: " << hackedBalancePtr << endl;
    cout << "ownerNamePtr stores the address of joeOwnerName: " << ownerNamePtr << endl;

    cout << endl; // Print a blank line for readability and UX.

    printTitle("This is how the VALUE looks in Memory");
    cout << "*joeBalancePtr gives the value inside Joe's balance variable: $" << *joeBalancePtr << endl; // joeBalancePtr to print the VALUE at that address.
    cout << "*hackedBalancePtr gives the value inside Hacked Account: $" << *hackedBalancePtr << endl; // hackedBalancePtr to print the VALUE at that address.
    cout << "*ownerNamePtr gives the owner name value: " << *ownerNamePtr << endl; // Dereference ownerNamePtr to print the string value at that address.

    cout << endl; // Print a blank line for readability and UX.

    printTitle("Uses PASS BY VALUE when calling normalBalanceCheck() ");
    normalBalanceCheck(joeCoffeeBalance, hackedAccountBalance); // Call the function and pass values of the both account balances.

    printAccountData(joeOwnerName, joeCoffeeBalance, hackedAccountBalance); // Print the balances again from main(). They should still be the original starting values.

    cout << endl; // Print a blank line for readability and UX.


    // --------------------------------------------------------
    // Code block: Pointer Function #1
    // Use a pointer to change the Joe's Coffee 'real' balance.
    // The value remains changed outside the function.
    // --------------------------------------------------------
    printTitle("Pointer Function Example: Deposit Into Joe's Account");
    applyDepositByPointer(joeBalancePtr, depositAmount); // Call the deposit function and pass Joe's balance pointer.
    cout << "Joe's actual balance is now: $" << joeCoffeeBalance << endl; // Prove back in main() that Joe's real balance changed.
    cout << endl; // Print a blank line for readability and UX.


    // --------------------------------------------------------
    // Code block: Pointer Function #2
    // Swap the real balances using pointers.
    // This changes the actual variables in main().
    // --------------------------------------------------------
    printTitle("Pointer Function Swaps the balances");
    swapBalancesByPointer(joeBalancePtr, hackedBalancePtr); // Call the swap function using the two int pointers.

    // Display the actual variables enterd by the user were changed.
    cout << "Back in main() after swap" << endl;
    cout << "Joe's Coffee Shop balance is now: $" << joeCoffeeBalance << endl;
    cout << "Hacked Account balance is now: $" << hackedAccountBalance << endl;
    cout << endl; // Print a blank line for readability and UX.


    // --------------------------------------------------------
    // Code block: Pointer Function #3
    // Change the string variable with pointer for a string.
    // --------------------------------------------------------
    printTitle("Pointer Function Example: Change Owner Name");
    renameOwnerByPointer(ownerNamePtr, "Joe (Recovered Account)"); // Call the rename function and pass the string pointer.
    cout << "Back in main(), the owner name is now: " << joeOwnerName << endl; // Prove in main() that the real string changed.
    cout << endl; // Print a blank line for readability and UX.


    // --------------------------------------------------------
    // Print all final values AFTER the pointer-based changes.
    // --------------------------------------------------------
    printTitle("Final Account Data AFTER using Pointers");
    printAccountData(joeOwnerName, joeCoffeeBalance, hackedAccountBalance); // Print the final account data.

    cout << endl; // Print a blank line for readability and UX.
  
    return 0;
}

// ------------------------ STEP 2 ----------------------------------
// Declare Functions
// ------------------------------------------------------------------

// Prints a formatted title line to separate different 
// aspects of the code for UX an dreadability
// Contains logic so title will always be in the center
void printTitle(string title) {

    cout << endl; // For readability and UX
    int minimumWidth = 50; // Declare width and instantiate minimum length of border
    int titleLength = title.length(); // Get the length of the title

    // Decide width of the border line by
    // Using the larger of:
    // 1) the minimum width, or
    // 2) the length of the title
    // We want to prevent the boarder from being smaller than the title
    // But not too much larger either (50 chars tops)
    int width = minimumWidth;
    if (titleLength > width) {
        width = titleLength;
    }

    string border(width, '='); // creates the border
    int totalSpaces = width - titleLength; // Calculates spaces to the left and right of title
    
    // Split the extra spaces evenly between right and left
    int leftSpaces = totalSpaces / 2; 
    int rightSpaces = totalSpaces - leftSpaces;
   

    // Print the border and title for the user experience
    cout << border << endl; 
    cout << string(leftSpaces, ' ') << title << string(rightSpaces, ' ') << endl;
    cout << border << endl;

    return; // return to main at the line after printTitle() was called 
}


// Prints the account data in a clean format.
void printAccountData(string ownerName, int joeBalance, int hackedBalance){
    // Print the account owner's name.
    cout << "Owner Name: " << ownerName << endl;

    // Print Joe's Coffee Shop balance.
    cout << "Joe's Coffee Shop balance: $" << joeBalance << endl;

    // Print the hacked account balance.
    cout << "Hacked Account balance: $" << hackedBalance << endl;
}


// Demonstrates pass by value.
// This function only changes local copies, not the originals.
void normalBalanceCheck(int joeBalance, int hackedBalance){
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
void applyDepositByPointer(int* balancePtr, int depositAmount){
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
void swapBalancesByPointer(int* firstBalancePtr, int* secondBalancePtr){
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
void renameOwnerByPointer(string* ownerNamePtr, string newName){
    // Show the old owner name before changing it.
    cout << "Inside renameOwnerByPointer() BEFORE change: " << *ownerNamePtr << endl;

    // Use the pointer to change the actual string in main().
    *ownerNamePtr = newName;

    // Show the new owner name after the change.
    cout << "Inside renameOwnerByPointer() AFTER change: " << *ownerNamePtr << endl;
}


// Gets a non-negative integer from the user with basic validation.
int getNonNegativeInt(string prompt){
    // Create a variable to store the user's number.
    int value = 0;

    // Start an infinite loop until valid input is entered.
    while (true)    {
        // Ask the user for input.
        cout << prompt;

        // Try to read an integer from the keyboard.
        cin >> value;

        // Check whether the input succeeded and the number is non-negative.
        if (cin.fail() || value < 0)        {
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
