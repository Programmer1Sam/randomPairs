#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

/*
* AUTHOR:JACK TAYLOR
* PROGRAM:RANDOM PAIR GENERATION
* PURPOSE:CREATE RANDOM GROUPS OF PEOPLE FOR JOBS, SCHOOLS, OR ACTIVITIES IN PAIRS OF TWO
*/
int main() {
	string tempPerson;
	int amountPeople;
	int groupSize;
	int randPlacement = -1;
	bool goAgain = true;
	char redo;

		// gets initial amount of people
		cout << "How many people would you like to split into groups?: ";
		cin >> amountPeople;

		while (amountPeople == 0) {
			cout << "You cannot put zero people as an input, try again: ";
			cin >> amountPeople;
		}

		string* initialGroup = new string[amountPeople];

		for (int person = 0; person < amountPeople; person++) {
			cout << "Enter name for person " << person + 1 << ": ";

			tempPerson = "";

			cin >> tempPerson;

			initialGroup[person] = tempPerson;
		}
		while (goAgain) {
			srand(time(0));
			for (int i = 0; i < amountPeople; i++) {
				tempPerson = "";
				tempPerson = initialGroup[i];
				randPlacement = rand() % amountPeople;
				initialGroup[i] = initialGroup[randPlacement];
				initialGroup[randPlacement] = tempPerson;
			}


			if (amountPeople % 2 != 0) {
				cout << "Group 1: " << initialGroup[0] << ", " << initialGroup[1] << ", " << initialGroup[2] << endl;

				for (int i = 3, groupName = 2; i < amountPeople; i += 2, groupName++) {
					cout << "Group " << groupName << ": ";
					randPlacement = rand() % 2;
					if (randPlacement == 0) {
						cout << initialGroup[1 + i] << ", " << initialGroup[0 + i] << endl;
					}
					else {
						cout << initialGroup[0 + i] << ", " << initialGroup[1 + i] << endl;
					}
				}
			}

			else {
				for (int i = 0, groupName = 1; i < amountPeople; i += 2, groupName++) {
					cout << "Group " << groupName << ": ";
					randPlacement = rand() % 2;
					if (randPlacement == 0) {
						cout << initialGroup[1 + i] << ", " << initialGroup[0 + i] << endl;
					}
					else {
						cout << initialGroup[0 + i] << ", " << initialGroup[1 + i] << endl;
					}
				}
			}

			cout << "Would you like to shuffle the groups again(y/n): ";

			cin >> redo;

			if (redo == 'n' || redo == 'N') {
				goAgain = false;
			}
			else {
				system("CLS");
			}
		}
	return 0;
}