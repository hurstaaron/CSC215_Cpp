// Add preprocessing libraries
#include <iostream>
#include <string>   
using namespace std;

// ------------------- Step One -----------------------------------------
// Predeclare Function
// These tell the compiler what functions exist before it reads main().
// ------------------- Step One -----------------------------------------
void printTitle(string title); // This function prints a title to make output easier to read.
void printBalances(string account1Name, int account1Balance, string account2Name, int account2Balance); // This function prints the balances for two accounts.
void normalBalanceCheck(int joeBalance, int terrorBalance); // This function shows a normal balance check transaction.
void hackedBalanceCheck(int& joeBalance, int& terrorBalance); // This function shows the hacked transaction.


// ------------------- Step Two -----------------------------------------
// Create the main method to run the program
// ------------------- Step Two -----------------------------------------
int main(){
    // ------------------- Step Four -----------------------------------------
    // Declare and initialize variables for normal and hacked account balances
    // These are local to main() and will be used as argument values as we 
    // call several functions
    // ------------------- Step Four -----------------------------------------
    // This variable stores Joe's Coffee Shop starting balance.
    int joeCoffeeBalance = 2500; 
    // This variable stores the other account's starting balance.
    int hackedAccountBalance = 90000; 

    // ------------------- Last Step -----------------------------------------
    // Start calling fuctions
    // ------------------- Last Step -----------------------------------------
    // Call function to print an opening title so the user knows what the program is about. Pass string value to parameter.
    printTitle("Original Account Balances"); 
    // Call function to print the starting balances before any function calls happen. Pass string and int values to parameters.
    printBalances("Joe's Coffee Shop", joeCoffeeBalance, "Other Account", hackedAccountBalance);
    // Print a blank line for readability (better UX).
    cout << endl; 
    // Call function to print a new title for the normal transaction section. Pass string value to parameter
    printTitle("Normal Balance Check Transaction (Pass By Value)"); 
    // Call the function that uses pass by value, this sends COPIES of the balances, not the originals. Pass account int values to parameters.
    normalBalanceCheck(joeCoffeeBalance, hackedAccountBalance);
    // Print a blank line for readability (better UX).
    cout << endl;
    // Call function to print a title to prove the original balances did not change.
    printTitle("Balances After Normal Transaction");
    // Print the balances again, accounts should still be the same as the original balances. Pass account int values to parameters.
    printBalances("Joe's Coffee Shop", joeCoffeeBalance, "Other Account", hackedAccountBalance);
    // Print a blank line for readability (better UX).
    cout << endl;
    // Call function to print a title for the reference section of the assignment. Pass string value to parameter
    printTitle("Simulated Hacked Transaction (Pass By Reference)");
    // Call the function that uses passes values by REFERENCE to send the ACTUAL variables, so the function can change them.
    hackedBalanceCheck(joeCoffeeBalance, hackedAccountBalance);
    // Print a blank line for readability (better UX).
    cout << endl;
    // Call function to print a final title. Pass string value to parameter
    printTitle("Balances After Simulated Hacked Transaction");
    // Call function to print the balances again, accounts should be SWAPPED because the function changed the originals. Pass account int values to parameters
    printBalances("Joe's Coffee Shop", joeCoffeeBalance, "Other Account", hackedAccountBalance);
    // Print a blank line for readability (better UX).
    cout << endl;
    // Return 0, Program ended successfully.
    return 0;
}

// ------------------- Step Three -----------------------------------------
// Declare the functions that make this program work
// ------------------- Step Three -----------------------------------------

// -------------------------------------------------------------
// printTitle() - prints a formatted title line.
// -------------------------------------------------------------
void printTitle(string title){
    // Print a line of dashes before the title.(Readability and UX)
    cout << "-------------------------------------------------" << endl;
    // Print the actual title text passed into the function.
    cout << title << endl;
    // Print a line of dashes before the title.(Readability and UX)
    cout << "-------------------------------------------------" << endl;
}

// --------------------------------------------------------------
// printBalances() - prints the name and balance of two accounts.
// Accepts string and int arguements from main as values for
// use with the parameters
// --------------------------------------------------------------
void printBalances(string joeAcctName, int joeAcctBalance, string hackedAcctName, int hackedAcctBalance){
    // Print the first account name followed by its balance.
    cout << joeAcctName << " balance: $" << joeAcctBalance << endl;
    // Print the second account name followed by its balance.
    cout << hackedAcctName << " balance: $" << hackedAcctBalance << endl;
}

// -------------------------------------------------------------
// normalBalanceCheck()
// Accepts int arguements from main() as copies of the balances.
// Any change here only affects the copies, not the originals.
// -------------------------------------------------------------
void normalBalanceCheck(int joeBalance, int hackedBalance){
    // Print the balances as they arrive from main()
    cout << "Inside normalBalanceCheck BEFORE any swap:" << endl; // Help user understand what is happening
    cout << "Joe's Coffee Shop balance: $" << joeBalance << endl;
    cout << "Other Account balance: $" << hackedBalance << endl;
    // Print a blank line for readability (better UX).
    cout << endl;
    
    // This swaps the balances of the accounts
    int temp = joeBalance;      // Declare temp variable for Joe's Coffee. ONLY used in this function. Lifetime ends when function returns.
    joeBalance = hackedBalance; // Put the hacked account balance into Joe's balance variable.
    hackedBalance = temp;       // Put the saved balance into the other balance variable.

    // Print a message explaining what happened.
    cout << "Inside normalBalanceCheck AFTER swap attempt:" << endl;

    // Print Joe's copied balance after the local swap.
    cout << "Joe's Coffee Shop balance: $" << joeBalance << endl;

    // Print the other copied balance after the local swap.
    cout << "Other Account balance: $" << hackedBalance << endl;

    // Print a blank line for readability (better UX).
    cout << endl; 
}

// ------------------------------------------------------------
// hackedBalanceCheck() - Pass By REFERENCE.
// '&' means the function works with the original variables.
// ** Any change here changes the variables back in main(). **
// ------------------------------------------------------------
void hackedBalanceCheck(int& joeBalance, int& hackedBalance){
    // Print the balances before the swap happens.
    cout << "Inside hackedBalanceCheck BEFORE swap:" << endl; // Help user understand what is happening
    cout << "Joe's Coffee Shop balance: $" << joeBalance << endl;
    cout << "Other Account balance: $" << hackedBalance << endl;

    // Print a blank line for readability (better UX).
    cout << endl;

    // Create a temporary variable to help swap the balances.
    int temp = joeBalance;

    // Move the other account balance into Joe's balance.
    joeBalance = hackedBalance;

    // Move the saved original Joe balance into the other account.
    hackedBalance = temp;

    // Print the balances after the swap.
    cout << "Inside the hacked account AFTER swap:" << endl; // Help user understand what is happening
    cout << "Joe's Coffee Shop balance: $" << joeBalance << endl;
    cout << "Other Account balance: $" << hackedBalance << endl;

    // Print a blank line for readability (better UX).
    cout << endl;
}
