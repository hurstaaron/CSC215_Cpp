// Include the preprocessing libraries needed for the code to work
#include <iostream>
#include <string>
#include <array>
#include <cstdlib>

using namespace std;

int main(){
	// Add srand() to ensure a new reandom number is generated everytime rand() is executed
	srand(time(0));

	// Declare an int array of size 20 and initialize all elements to 0
	int twenty_randomNumbers[20] { };
	
	// For 20 interations generate a new random number and assign it to a index in the array
	for (int i{ 0 }; i < 20; i++) {
		int randomNum = rand() % 101; // Declare int var to hold the random number
		twenty_randomNumbers[i] = randomNum; // Assign the random number to the ith index in the array
		cout << "For iteration " << i + 1 << ", the number is " << twenty_randomNumbers[i] << ". \n"; // Display the ith index in the array
	}
	cout << endl;

	
	//cout << "\n\n======= For validation purposes ======= \n";
	//cout << "The size of the array is " << sizeof(twenty_randomNumbers) << " bytes.\n";
	//cout << "This is because the size of an int is 4 bytes.\n" 
	//	<< "The array has 20 int variables; and 4 times 20 is " << sizeof(twenty_randomNumbers) << endl << endl;
	

	// For 20 iterations, search the array to find the smallest number
	int minValue = twenty_randomNumbers[0]; // To find minValue, start at the first element of the array
	for (int i{ 0 }; i < 20; i++) {
		if (twenty_randomNumbers[i] < minValue) {
			minValue = twenty_randomNumbers[i]; // assign minValue with the number at the index if it is smaller than the ith number
		}
	}
	cout << minValue << " is the smallest number in the array.\n"; // Display the smallest number
	

	// For 20 iterations, search the array to find the largest number
	int maxValue = twenty_randomNumbers[0]; // To find maxValue, start at the first element of the array
	for (int i{ 0 }; i < 20; i++) {
		if (twenty_randomNumbers[i] > maxValue) {
			maxValue = twenty_randomNumbers[i]; // assign maxValue with the number at the index if it is larger than the ith number
		}
	}
	cout << maxValue << " is the largest number in the array.\n";


	// For 20 iterations, search the array to find the largest number
	int sumOfValues = 0; // To find sumOfValues, start at the first element of the array
	for (int i{ 0 }; i < 20; i++) {
		sumOfValues += twenty_randomNumbers[i]; // Add each number in the array to the next
	}
	cout << sumOfValues << " is the sum of the numbers in the array.\n";


	int averageOfValues = sumOfValues / 20; // Evaluate to find the average of the numbers in the array
	cout << averageOfValues << " is the average of the numbers in the array.\n";

}

