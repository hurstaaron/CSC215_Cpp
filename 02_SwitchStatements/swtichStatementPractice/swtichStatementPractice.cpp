#include <iostream>
#include <string>
using namespace std;

int main()
{
    int choice;
    cout << "==== Calculator, Yay! ====\n"
        << "1. Add\n"
        <<"2. Subtract\n"
        <<"3. Multiply\n"
        <<"4. Divide\n";
    cin >> choice;
    
    int a, b;
    cout << "Enter your first number: \n";
    cin >> a;

    cout << "Enter your second number: \n";
    cin >> b;

    switch (choice) {
    case 1: 
        cout << "Addition: " << a + b << endl;
        break;
    case 2:
        cout << "Addition: " << a + b << endl;
        break;
    case 3:
        cout << "Addition: " << a + b << endl;
        break;
    case 4:
        cout << "Addition: " << a + b << endl;
        break;
    default:
        cout << "nope, you broke the calculator: \n";
 
    }
}


