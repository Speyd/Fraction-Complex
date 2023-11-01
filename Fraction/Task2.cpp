#include "Complex.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#pragma region Special_Abilities
void ClearScreanTask2() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	cout << "\tComplex" << endl;
}
extern void Enter();
#pragma endregion

void ChoiceNum(vector<Complex>& complex) {

	int choice_num = 1;
	double num;
	string type;

	do {
		ClearScreanTask2();
		cout << "Type number\n[1] - Imaginary\n[2] - Valid" << endl;

		if (choice_num >= 1 && choice_num <= 2)cout << "Enter your choice: ";
		else cout << "There is no such choice!\nEnter your choice again: ";

		cin >> choice_num;

	} while (choice_num < 1 || choice_num > 2);

	ClearScreanTask2();
	cout << "Enter "; choice_num == 1 ? cout << "imaginary" : cout << "valid"; cout << " number: ";
	cin >> num;

	if (choice_num == 1) type = "imaginary";
	else if (choice_num == 2) type = "valid";

	complex.push_back(Complex{ num, type });
}

int Task2() {
	vector<Complex> complex;
	int choice = 0;

	do {

		ClearScreanTask2();
		ChoiceNum(complex);

		do {

			ClearScreanTask2();
			cout << "Action\n[1] - Adding(+)\n[2] - Fractions(-)\n"
				<< "[3] - Multiplication(*)\n[4] - Division(/)\n[0] - Exit" << endl;

			if (choice >= 0 && choice <= 4)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";

			cin >> choice;

		} while (choice < 0 || choice > 4);

		ClearScreanTask2();

		if (choice != 0) {

			ChoiceNum(complex);
			ClearScreanTask2();

			switch (choice) {

			case 1:cout << "Result after adding: " << complex[0] + complex[1] << endl; break;

			case 2:cout << "Result after fractions: " << complex[0] - complex[1] << endl; break;

			case 3:cout << "Result after multiplication: " << complex[0] * complex[1] << endl; break;

			case 4:cout << "Result after division: " << complex[0] / complex[1] << endl; break;
			}

			complex.clear();
			Enter();
		}

	} while (choice != 0);


	return 0;
}