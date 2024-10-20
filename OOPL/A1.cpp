/**
 * * Eshan Nahar
 * Implement a class Complex which represents the Complex Number data type. Implement the following
 * 1. Constructor (Including a default constructor which creates complex number 0+0i)
 * 2. Overload operator + to add two complex numebrs
 * 3. Overload operator * to multiply two complex numbers
 * 4. Overload operators << and >> to print and read complex numbers
 */
#include<bits/stdc++.h>
using namespace std;

class Complex {
	private:
		double real;
		double imag;
	public:
		Complex() : real(0), imag(0) {} // Default
		Complex(double r, double i) : real(r), imag(i) {} // Parameterized
		// Other can be named anyhting
		// We don't have two parameters as it is a member function (this object applies)
		Complex operator+(const Complex& other) {	return Complex(real + other.real, imag + other.imag); }
		Complex operator*(const Complex& other) {
			return Complex(real * other.real - imag * other.imag,
										 real * other.imag + imag * other.real);
		}
		friend ostream& operator<<(ostream& os, const Complex& c) {
			os << c.real;
			if(c.imag >= 0) os << " + " << c.imag << "i";
			else os << " - " << -c.imag << "i";
			return os;
		}
		friend istream& operator>>(istream& is, Complex& c) {
			char plusMinus;
			is >> c.real >> plusMinus >> c.imag;
			if(plusMinus == '-') c.imag = -c.imag;
			return is;
		}
};

int main() {
		cout << "Eshan Nahar" << endl;
		Complex a(0, 0); 
		Complex b(0, 0); 
		int choice;
		cout << "\nMenu:\n";
		cout << "1. Input Complex Number A\n";
		cout << "2. Input Complex Number B\n";
		cout << "3. Add A and B\n";
		cout << "4. Multiply A and B\n";
		cout << "5. Display A\n";
		cout << "6. Display B\n";
		cout << "7. Exit\n";
		do {	
			cout << "Enter your choice: ";
			cin >> choice;
			switch (choice) {
				case 1: cout << "Enter complex number A (Format: a + bi): "; cin >> a; break;
				case 2: cout << "Enter complex number B (Format: a + bi): "; cin >> b; break;
				case 3: {
					Complex sum = a + b;
					cout << "Sum: " << sum << endl;
					break;
				}
				case 4: {
					Complex product = a * b;
					cout << "Product: " << product << endl;
					break;
				}
				case 5: cout << "Complex Number A: " << a << endl; break;
				case 6: cout << "Complex Number B: " << b << endl; break;
				case 7: cout << "Exiting the program." << endl; break;
				default: cout << "Invalid choice! Please try again." << endl;
			}
			if (cin.fail()) {
				cin.clear(); 
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Invalid input. Please try again." << endl;
			}
		} while (choice != 7);
		return 0;
}