#include <iostream>
#include <string>
using namespace std;

class Fraction {
private:
	int numerator;
	int denominator;
public:
	Fraction(const int numeratorP, const int denominatorP)
		     :numerator{ numeratorP}, denominator{ denominatorP != 0? denominatorP: 1 }{}

	Fraction(const int numeratorP): Fraction{ numeratorP, 1} {}

	Fraction() : Fraction{ 1, 1 } {}

	int GetNumerator() { return numerator; }
	int GetDenominator() { return denominator; }

	friend const string operator +(const Fraction& fraction1,const Fraction& fraction2) {

		int numerator1 = fraction2.denominator * (fraction1.numerator);
		int numerator2 = fraction1.denominator * (fraction2.numerator);

		return to_string(numerator1 + numerator2) + '/' + to_string(fraction1.denominator * fraction2.denominator);

	}

	friend const string operator -(const Fraction& fraction1, const Fraction& fraction2) {

		int numerator1 = fraction2.denominator * (fraction1.numerator);
		int numerator2 = fraction1.denominator * (fraction2.numerator);

		return to_string(numerator1 - numerator2) + '/' + to_string(fraction1.denominator * fraction2.denominator);

	}

	friend const string operator *(const Fraction& fraction1, const Fraction& fraction2) {

		return to_string(fraction1.numerator * fraction2.numerator) + '/' + to_string(fraction1.denominator * fraction2.denominator);

	}

	friend const string operator /(const Fraction& fraction1, const Fraction& fraction2) {

		return to_string(fraction1.numerator * fraction2.denominator) + '/' + to_string(fraction1.denominator * fraction2.numerator);

	}
};