#include "JoesCoffeeGUI.h"

// Include QLabel so we can create text labels for the GUI.
#include <QLabel>

// Include QLineEdit so the user can type input values.
#include <QLineEdit>

// Include QPushButton so the user can click buttons to perform actions.
#include <QPushButton>

// Include QTextEdit so we can show multi-line output text.
#include <QTextEdit>

// Include QVBoxLayout so we can stack widgets vertically.
#include <QVBoxLayout>

// Include QHBoxLayout so we can place widgets side by side in rows.
#include <QHBoxLayout>

// Include QMessageBox so we can show popup error messages.
#include <QMessageBox>


// --------------------------------------------------------------
// Constructor
// This runs when the JoesCoffeeGUI window is created.
// --------------------------------------------------------------
JoesCoffeeGUI::JoesCoffeeGUI(QWidget* parent)
    : QWidget(parent)
{
    // Call the generated Qt function that prepares the form object.
    // Even though we are going to build our own layout in code,
    // this is still part of the normal wizard-created structure.
    ui.setupUi(this);

    // Build the custom interface we want for this project.
    setupCustomUI();

    // Connect button clicks to the code that should run.
    connectSignals();
}


// --------------------------------------------------------------
// Destructor
// Nothing special is needed here right now.
// --------------------------------------------------------------
JoesCoffeeGUI::~JoesCoffeeGUI()
{
}


// --------------------------------------------------------------
// This function builds the GUI window and widgets in code.
// --------------------------------------------------------------
void JoesCoffeeGUI::setupCustomUI()
{
    // Set the text shown on the title bar of the window.
    setWindowTitle("Joe's Coffee Shoppe GUI");

    // Set a reasonable starting size for the window.
    resize(700, 500);

    // ----------------------------------------------------------
    // Important note:
    // The wizard-generated .ui file may already contain a layout.
    // To keep this beginner project clean and predictable,
    // we create our own fresh main layout and attach it to the window.
    // ----------------------------------------------------------
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // ----------------------------------------------------------
    // Create the Owner Name row.
    // ----------------------------------------------------------
    QLabel* ownerLabel = new QLabel("Owner Name:", this);
    ui.lineEditOwnerName = new QLineEdit(this);

    QHBoxLayout* ownerLayout = new QHBoxLayout();
    ownerLayout->addWidget(ownerLabel);
    ownerLayout->addWidget(ui.lineEditOwnerName);

    // ----------------------------------------------------------
    // Create the Joe Balance row.
    // ----------------------------------------------------------
    QLabel* joeBalanceLabel = new QLabel("Joe Balance:", this);
    ui.lineEditJoeBalance = new QLineEdit(this);

    QHBoxLayout* joeLayout = new QHBoxLayout();
    joeLayout->addWidget(joeBalanceLabel);
    joeLayout->addWidget(ui.lineEditJoeBalance);

    // ----------------------------------------------------------
    // Create the Hacked Balance row.
    // ----------------------------------------------------------
    QLabel* hackedBalanceLabel = new QLabel("Hacked Balance:", this);
    ui.lineEditHackedBalance = new QLineEdit(this);

    QHBoxLayout* hackedLayout = new QHBoxLayout();
    hackedLayout->addWidget(hackedBalanceLabel);
    hackedLayout->addWidget(ui.lineEditHackedBalance);

    // ----------------------------------------------------------
    // Create the Deposit Amount row.
    // ----------------------------------------------------------
    QLabel* depositLabel = new QLabel("Deposit Amount:", this);
    ui.lineEditDepositAmount = new QLineEdit(this);

    QHBoxLayout* depositLayout = new QHBoxLayout();
    depositLayout->addWidget(depositLabel);
    depositLayout->addWidget(ui.lineEditDepositAmount);

    // ----------------------------------------------------------
    // Create the buttons for the program actions.
    // ----------------------------------------------------------
    ui.pushButtonShowOriginal = new QPushButton("Show Original Data", this);
    ui.pushButtonDeposit = new QPushButton("Deposit Into Joe Account", this);
    ui.pushButtonSwap = new QPushButton("Swap Balances", this);
    ui.pushButtonRename = new QPushButton("Rename Owner", this);
    ui.pushButtonShowFinal = new QPushButton("Show Final Data", this);

    // ----------------------------------------------------------
    // Create the output box where results will be shown.
    // ----------------------------------------------------------
    ui.textEditOutput = new QTextEdit(this);

    // Make the output box read-only so the user cannot type in it.
    ui.textEditOutput->setReadOnly(true);

    // ----------------------------------------------------------
    // Add everything to the main vertical layout.
    // ----------------------------------------------------------
    mainLayout->addLayout(ownerLayout);
    mainLayout->addLayout(joeLayout);
    mainLayout->addLayout(hackedLayout);
    mainLayout->addLayout(depositLayout);

    mainLayout->addWidget(ui.pushButtonShowOriginal);
    mainLayout->addWidget(ui.pushButtonDeposit);
    mainLayout->addWidget(ui.pushButtonSwap);
    mainLayout->addWidget(ui.pushButtonRename);
    mainLayout->addWidget(ui.pushButtonShowFinal);
    mainLayout->addWidget(ui.textEditOutput);

    // Set some starter values in the text boxes
    // so the program is easier to test the first time.
    ui.lineEditOwnerName->setText("Joe");
    ui.lineEditJoeBalance->setText("100");
    ui.lineEditHackedBalance->setText("50");
    ui.lineEditDepositAmount->setText("25");
}


// --------------------------------------------------------------
// This function connects each button to the action it should run.
// --------------------------------------------------------------
void JoesCoffeeGUI::connectSignals()
{
    // ----------------------------------------------------------
    // When the user clicks "Show Original Data"
    // ----------------------------------------------------------
    connect(ui.pushButtonShowOriginal, &QPushButton::clicked, this, [this]()
        {
            // Load and validate the input values first.
            if (!loadDataFromInputs())
            {
                return;
            }

            // Print a heading into the output box.
            ui.textEditOutput->append("=== Original Account Data ===");

            // Print the current account summary.
            ui.textEditOutput->append(buildAccountSummary());
        });

    // ----------------------------------------------------------
    // When the user clicks "Deposit Into Joe Account"
    // ----------------------------------------------------------
    connect(ui.pushButtonDeposit, &QPushButton::clicked, this, [this]()
        {
            // Load and validate the input values first.
            if (!loadDataFromInputs())
            {
                return;
            }

            // Create a pointer to Joe's real balance.
            int* joeBalancePtr = &data.joeBalance;

            // Call the pointer-based deposit function.
            applyDepositByPointer(joeBalancePtr, currentDepositAmount);

            // Show the updated data in the output box.
            ui.textEditOutput->append("=== After Deposit ===");
            ui.textEditOutput->append(buildAccountSummary());

            // Also update the text box so the GUI matches the new real value.
            ui.lineEditJoeBalance->setText(QString::number(data.joeBalance));
        });

    // ----------------------------------------------------------
    // When the user clicks "Swap Balances"
    // ----------------------------------------------------------
    connect(ui.pushButtonSwap, &QPushButton::clicked, this, [this]()
        {
            // Load and validate the input values first.
            if (!loadDataFromInputs())
            {
                return;
            }

            // Create pointers to the two real balances.
            int* joeBalancePtr = &data.joeBalance;
            int* hackedBalancePtr = &data.hackedBalance;

            // Call the pointer-based swap function.
            swapBalancesByPointer(joeBalancePtr, hackedBalancePtr);

            // Show the updated results.
            ui.textEditOutput->append("=== After Swap ===");
            ui.textEditOutput->append(buildAccountSummary());

            // Update the text boxes so the GUI reflects the new values.
            ui.lineEditJoeBalance->setText(QString::number(data.joeBalance));
            ui.lineEditHackedBalance->setText(QString::number(data.hackedBalance));
        });

    // ----------------------------------------------------------
    // When the user clicks "Rename Owner"
    // ----------------------------------------------------------
    connect(ui.pushButtonRename, &QPushButton::clicked, this, [this]()
        {
            // Load and validate the input values first.
            if (!loadDataFromInputs())
            {
                return;
            }

            // Create a pointer to the real owner name.
            string* ownerNamePtr = &data.ownerName;

            // Rename the owner using the pointer-based function.
            renameOwnerByPointer(ownerNamePtr, "Joe (Recovered Account)");

            // Show the updated results.
            ui.textEditOutput->append("=== After Rename ===");
            ui.textEditOutput->append(buildAccountSummary());

            // Update the text box so the GUI reflects the change.
            ui.lineEditOwnerName->setText(QString::fromStdString(data.ownerName));
        });

    // ----------------------------------------------------------
    // When the user clicks "Show Final Data"
    // ----------------------------------------------------------
    connect(ui.pushButtonShowFinal, &QPushButton::clicked, this, [this]()
        {
            // Load and validate the input values first.
            if (!loadDataFromInputs())
            {
                return;
            }

            // Show the final/current values.
            ui.textEditOutput->append("=== Final Account Data ===");
            ui.textEditOutput->append(buildAccountSummary());
        });
}


// --------------------------------------------------------------
// This function reads the text boxes and validates the input.
// --------------------------------------------------------------
bool JoesCoffeeGUI::loadDataFromInputs()
{
    // These true/false variables will tell us whether each text box
    // was successfully converted into an integer.
    bool joeOk = false;
    bool hackedOk = false;
    bool depositOk = false;

    // Read the owner name from the GUI text box.
    QString ownerText = ui.lineEditOwnerName->text();

    // Convert Joe's balance from text into an integer.
    int joeValue = ui.lineEditJoeBalance->text().toInt(&joeOk);

    // Convert Hacked Account balance from text into an integer.
    int hackedValue = ui.lineEditHackedBalance->text().toInt(&hackedOk);

    // Convert Deposit Amount from text into an integer.
    int depositValue = ui.lineEditDepositAmount->text().toInt(&depositOk);

    // Check whether all numeric conversions worked.
    if (!joeOk || !hackedOk || !depositOk)
    {
        // Show a popup error message if any value is invalid.
        QMessageBox::warning(this,
            "Input Error",
            "Please enter valid whole numbers for the balances and deposit amount.");

        // Tell the calling code that validation failed.
        return false;
    }

    // Reject any negative numbers.
    if (joeValue < 0 || hackedValue < 0 || depositValue < 0)
    {
        // Show a popup error message for negative values.
        QMessageBox::warning(this,
            "Input Error",
            "Please enter non-negative values only.");

        // Tell the calling code that validation failed.
        return false;
    }

    // Save the validated values into the real account data struct.
    data.ownerName = ownerText.toStdString();
    data.joeBalance = joeValue;
    data.hackedBalance = hackedValue;

    // Save the validated deposit amount separately.
    currentDepositAmount = depositValue;

    // Input is valid, so return true.
    return true;
}


// --------------------------------------------------------------
// This function builds the multi-line summary that will be shown
// in the output box.
// --------------------------------------------------------------
QString JoesCoffeeGUI::buildAccountSummary() const
{
    // Start with an empty string.
    QString summary = "";

    // Add the owner name line.
    summary += "Owner Name: " + QString::fromStdString(data.ownerName) + "\n";

    // Add Joe's Coffee Shop balance line.
    summary += "Joe's Coffee Shop balance: $" + QString::number(data.joeBalance) + "\n";

    // Add Hacked Account balance line.
    summary += "Hacked Account balance: $" + QString::number(data.hackedBalance) + "\n";

    // Return the completed summary text.
    return summary;
}


// --------------------------------------------------------------
// This function adds money to a balance using a pointer.
// --------------------------------------------------------------
void JoesCoffeeGUI::applyDepositByPointer(int* balancePtr, int depositAmount)
{
    // Dereference the pointer and update the real value in memory.
    *balancePtr = *balancePtr + depositAmount;
}


// --------------------------------------------------------------
// This function swaps two balances using pointers.
// --------------------------------------------------------------
void JoesCoffeeGUI::swapBalancesByPointer(int* firstBalancePtr, int* secondBalancePtr)
{
    // Save the first real value temporarily.
    int temp = *firstBalancePtr;

    // Copy the second real value into the first variable.
    *firstBalancePtr = *secondBalancePtr;

    // Copy the saved first value into the second variable.
    *secondBalancePtr = temp;
}


// --------------------------------------------------------------
// This function changes the owner's name using a string pointer.
// --------------------------------------------------------------
void JoesCoffeeGUI::renameOwnerByPointer(string* ownerNamePtr, string newName)
{
    // Use the pointer to change the real owner name.
    *ownerNamePtr = newName;
}

