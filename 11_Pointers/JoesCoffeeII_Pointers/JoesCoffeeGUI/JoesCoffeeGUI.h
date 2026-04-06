// Practice building a GUI for JoesCoffeeShoppe project

#pragma once

// Include QWidget because the class will inherit from QWidget
// QWidget is the base class for normal QT windows and controls
# include <QtWidgets/QWidget>
// Using QString to build the display text
# include <QString>
// Including header files for the UI, this was created by the .ui file from Qt
// Gives access to the widets that exists in the form designer
# include "ui_JoesCoffeeGUI.h"

// Icluding <string> to use standard C++ strings and
// connect console program to the GUI version of the program
#include <string>

// Use the standard name space to simplify the code
using namespace std;


// -------------------------------------------------
// Struct to hold the account data
// Needs 2 ints and 1 string
// -------------------------------------------------
struct AccountData {
	string ownerName;	// store the account balance 
	int joeBalance;		// store Joe's Coffee balance
	int hackedBalance;	// store the hacked account balance
};

// -------------------------------------------------
// Create the main GUI class
// This represents the applications main window
// and inherits from QWidget since we selected 
// QWidget as the base class in the wizard
// -------------------------------------------------
class JoesCoffeeGUI : public QWidget {
	Q_OBJECT

public:
	// Build the constructor to run when the window object is created
	JoesCoffeeGUI(QWidget* parent = nullptr);

	// Destructor to run when the window object is destroyed
	~JoesCoffeeGUI();

private:
	// -------------------------------------------------
	// Create an object to give access to widgets created
	// by the .ui designer file
	// -------------------------------------------------
	Ui::JoesCoffeeGUIClass ui;

	// -------------------------------------------------
	// Store the account data so GUI can work with 
	// the real values as the user clicks thru buttons
	// -------------------------------------------------
	AccountData data;

	// -------------------------------------------------
	// Store current deposit
	// -------------------------------------------------
	int currentDepositAmount = 0;

	// -------------------------------------------------
	// Declare Helper functions
	// Made private so they can only be used 
	// inside the class
	// -------------------------------------------------
	// Validates data from the input boxes, returns true
	// if all inputs are valid.
	// Important b/c we only want good data
	bool loadDataFromInputs();

	// Build the multi-line summary showing the account data
	QString buildAccountSummary() const;

	// Add money to the balance using pointer
	void applyDepositByPointer(int* balancePtr, int depositAmount);

	// Swap two balances using pointers
	void swapBalancesByPointer(int* firstBalancePtr, int* secondBalancePtr);

	// Rename the owner with a string pointer
	void renameOwnerByPointer(string* ownerNamePtr, string newName);

	// Build GUI layour and widget properties
	void setupCustomerUI();

	// Connect GUI buttons to functions 
	void connectSignals();

};



