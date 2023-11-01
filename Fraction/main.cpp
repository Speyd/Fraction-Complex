#include "Task1.h"
#include "Task2.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

#pragma region Special_Abilities
void ClearScrean() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	cout << "\tFraction & Comlex" << endl;
}
void Enter() {
	string enter;
	cin.ignore();
	do {
		cout << "Press enter to continue: "; getline(cin, enter);
	} while (!enter.empty());
}
#pragma endregion

int main() {
	int choice = 0;

	do {

		do {

			ClearScrean();
			cout << "Home work\n[1] - Fraction\n[2] - Complex\n[0] - Exit" << endl;

			if (choice >= 0 && choice <= 2)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";

			cin >> choice;

		} while (choice < 0 || choice > 2);

		ClearScrean();

		if (choice == 1)Task1();
		else if (choice == 2)Task2();

	} while (choice != 0);


	return 0;
}