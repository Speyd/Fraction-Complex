#include "Fraction.h"
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

#pragma region Special_Abilities
extern void ClearScreanTask1() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	cout << "\tFranction" << endl;
}
extern void Enter();
#pragma endregion

void InputInfo(vector<Fraction>& fractions) {

	int numerator, denominator;

	for (int i = 0; i != 2; i++) {

		cout << "Enter numerator " << i + 1 << "-th fraction: "; cin >> numerator;

		cout << "Enter denominator " << i + 1 << "-th fraction: "; cin >> denominator;

		ClearScreanTask1();

		fractions.push_back(Fraction{ numerator , denominator });
	}
}

int Task1() {

	vector<Fraction> fractions;
	int choice = 0;

	do {

		do {

			ClearScreanTask1();
			cout << "Action\n[1] - Adding fractions(+)\n[2] - Subtracting fractions(-)\n"
				<< "[3] - Multiplication of fractions(*)\n[4] - Division fractions(/)\n[0] - Exit" << endl;

			if (choice >= 0 && choice <= 4)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";

			cin >> choice;

		} while (choice < 0 || choice > 4);

		ClearScreanTask1();

		if (choice != 0)InputInfo(fractions);

		switch (choice) {

		case 1:cout << "The result of adding fraction(" << fractions[0].GetNumerator() << '/'
			<< fractions[0].GetDenominator() << ") and fraction (" << fractions[1].GetNumerator() << '/'
			<< fractions[1].GetDenominator() << ") is equal " << setprecision(2) << fractions[0] + fractions[1] << endl; break;

		case 2:cout << "The result of subtracting fraction(" << fractions[0].GetNumerator() << '/'
			<< fractions[0].GetDenominator() << ") and fraction (" << fractions[1].GetNumerator() << '/'
			<< fractions[1].GetDenominator() << ") is equal " << setprecision(2) << fractions[0] - fractions[1] << endl; break;

		case 3:cout << "The result of multiplication fraction(" << fractions[0].GetNumerator() << '/'
			<< fractions[0].GetDenominator() << ") and fraction (" << fractions[1].GetNumerator() << '/'
			<< fractions[1].GetDenominator() << ") is equal " << setprecision(2) << fractions[0] * fractions[1] << endl; break;

		case 4:cout << "The result of division fraction(" << fractions[0].GetNumerator() << '/'
			<< fractions[0].GetDenominator() << ") and fraction (" << fractions[1].GetNumerator() << '/'
			<< fractions[1].GetDenominator() << ") is equal " << setprecision(2) << fractions[0] / fractions[1] << endl; break;

		}



		if (choice != 0)Enter();

		fractions.clear();

	} while (choice != 0);

	return 0;
}