#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;
class Complex {
private:
	double number;
	string type;

public:
	Complex(const double numberP, const string typeP)
			:number{ numberP }, type{ typeP }{}

	Complex(const double numberP) : Complex{ numberP, ""} {}

	Complex() : Complex{ 0, ""} {}

	friend const string operator +(const Complex& complex1, const Complex& complex2) {
		if (complex1.type == "imaginary" && complex2.type == "imaginary") {
			return to_string((complex1.number + complex2.number ) * -1) + 'i';
		}
		else if (complex1.type == "imaginary")return to_string(complex1.number * -1) + 'i' + " + " + to_string(complex2.number);
		else if (complex2.type == "imaginary")return to_string(complex1.number) + " + " + to_string(complex2.number * -1) + 'i';
		else return to_string(complex1.number + complex2.number);
	}

	friend const string operator -(const Complex& complex1, const Complex& complex2) {

		if (complex1.type == "imaginary" && complex2.type == "imaginary") {
			return to_string((complex1.number - complex2.number)* -1) + 'i';
		}
		else if (complex1.type == "imaginary")return to_string(complex1.number * -1) + 'i' + " - " + to_string(complex2.number);
		else if (complex2.type == "imaginary")return to_string(complex1.number) + " - " + to_string(complex2.number * -1) + 'i';
		else return to_string(complex1.number - complex2.number);

	}

	friend const string operator *(const Complex& complex1, const Complex& complex2) {

		int num;

		if (complex1.type == "imaginary" && complex2.type == "imaginary") {
			if (complex1.number < 0 || complex2.number < 0)num = -1;
			else num = 1;
			return to_string((complex1.number * num) * complex2.number);
		}

		else if (complex1.type == "imaginary" || complex2.type == "imaginary")return to_string(complex1.number * complex2.number * -1) + 'i';

		else return to_string(complex1.number * complex2.number);
	}

	friend const string operator /(const Complex& complex1, const Complex& complex2) {

		int num;

		if (complex1.type == "imaginary" && complex2.type == "imaginary") {
			if (complex1.number < 0 || complex2.number < 0)num = -1;
			else num = 1;
			return to_string((complex1.number / num) / complex2.number);
		}

		else if (complex1.type == "imaginary" || complex2.type == "imaginary")return to_string(complex1.number / complex2.number * -1) + 'i';

		else return to_string(complex1.number / complex2.number);
	}
};