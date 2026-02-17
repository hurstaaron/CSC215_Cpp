#include <iostream>
#include <string>
using namespace std;

int main() {
	//declaired Variable
	string playername;
	string pharmacyChoice;
	string SURVIVORSCAMP;
	string Playagain;


	while (true) {
		//Welcome message
		cout << " ================================== \n"
			<< " ZOMBIE APOCALYPSE : SURVIVE OR DIE\n"
			<< " ================================== \n\n"
			<< "WELCOME MESSAGE : \n"
			<< "The dead have risen, and civilization has collapsed.You're alone, low on supplies,\n"
			<< "and every decision could be your last. Will you survive the apocalypse, or become one of the infected?\n\n"
			<< "Your choices determine your fate.\n\n";

		//collect player name
		cout << "Hey zombie killer what is your name?  ";
		cin >> playername;
		cout << endl;

		cout << "hey " << playername << endl << endl;

		//Scernario1 THE ABANDONED PHARMACY
		cout << "You spot a pharmacy with shattered windows. Moans echo from inside, but you need \n"
			<< "medicine desperately. Through the darkness, you see shelves still stocked with\n"
			<< "supplies. your going to have to make a decision.\n\n"
			<< "Choice A: Sneak in quietly through the back door\n"
			<< "Choice B: Make a loud distraction and rush through the front\n\n";

		cout << "Do you want A or B?  ";
		cin >> pharmacyChoice;

		if (pharmacyChoice == "A" || pharmacyChoice == "a") {
			cout << "go job you got into the pharmacy room \n";
		}
		else {
			cout << "oof you incounter a zombie.\n";
		}

		//Scernario2 THE SURVIVOR'S CAMP
		cout << "You find a fortified camp with armed survivors on the walls. They're suspicious \n"
			<< "of strangers. One guard shouts down, demanding you prove you're not infected.\n\n"
			<< "Choice A: Show your bite free skin and ask for shelter\n"
			<< "Choice B: Turn around and leave before they shoot\n\n";

		cout << "Do you want A or B?  ";
		cin >> SURVIVORSCAMP;

		if (SURVIVORSCAMP == "A" || SURVIVORSCAMP == "a") {
			cout << "good job you got into the survivor camp \n";
		}
		else {
			cout << "you got shot on.\n";
		}
		cout << "do you want to play again (A or a)" << endl;
		cin >> Playagain;
		if (Playagain == "A" || Playagain == "a") {
			main();
		}
		else {
			break;
		}
	}
}