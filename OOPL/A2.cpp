/**
 * * Eshan Nahar
 * Develop a program in C++ to create a database of student’s information system containing the following information: Name, Roll number, Class, Division, Date of Birth, Blood group, Contact address, Telephone number, Driving license no. and other. Construct the database with suitable member function
 * Make use of constructor, default constructor, copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete as well as exception handling.
 */

#include <bits/stdc++.h>
using namespace std;

class Address {
	private:
		string street;
		string city;
		string state;
		string country;
		int zipCode;
	public:
		Address(string st, string c, string s, string co, int zip) : street(st), city(c), state(s), country(co), zipCode(zip) {}
		friend ostream& operator<<(ostream& os, const Address& addr);
};

ostream& operator<<(ostream& os, const Address& addr) {
	os << addr.street << ", " << addr.city << ", " << addr.state << ", " << addr.country << ", " << addr.zipCode;
	return os;
}

class Student {
	private:
		string name;
		int rollNumber;
		string className;
		char division;
		string dateOfBirth;
		string bloodGroup;
		Address* contactAddress;
		long telephoneNumber;
		string drivingLicenseNumber;
		static int totalStudents;

	public:
		Student(string n, int rn, string c, char d, string dob, string bg, string st, string city, string state, string country, int zip, long tel, string dl) 
			: name(n), rollNumber(rn), className(c), division(d), dateOfBirth(dob), bloodGroup(bg), telephoneNumber(tel), drivingLicenseNumber(dl) {
			contactAddress = new Address(st, city, state, country, zip);
			totalStudents++;
		}

		Student() : name("Unknown"), rollNumber(0), className("Unknown"), division('A'), dateOfBirth("01/01/1900"), bloodGroup("Unknown"), telephoneNumber(0), drivingLicenseNumber("Unknown") {
			contactAddress = new Address("Unknown", "Unknown", "Unknown", "Unknown", 0);
			totalStudents++;
		}

		Student(const Student& other) : name(other.name), rollNumber(other.rollNumber), className(other.className), division(other.division), dateOfBirth(other.dateOfBirth), bloodGroup(other.bloodGroup), telephoneNumber(other.telephoneNumber), drivingLicenseNumber(other.drivingLicenseNumber) {
			contactAddress = new Address(*other.contactAddress);
			totalStudents++;
		}

    ~Student() {
			delete contactAddress;
			totalStudents--;
    }

		static int getTotalStudents() { return totalStudents; }
		friend ostream& operator<<(ostream& os, const Student& student);
		inline int getRollNumber() const { return rollNumber; }
		// Setter functions to update student information
		void setName(const string& n) { name = n; }
		void setRollNumber(int rn) { rollNumber = rn; }
		void setClassName(const string& c) { className = c; }
		void setDivision(char d) { division = d; }
		void setDateOfBirth(const string& dob) { dateOfBirth = dob; }
		void setBloodGroup(const string& bg) { bloodGroup = bg; }
		void setTelephoneNumber(long tel) { telephoneNumber = tel; }
		void setDrivingLicenseNumber(const string& dl) { drivingLicenseNumber = dl; }
		void setContactAddress(const string& st, const string& city, const string& state, const string& country, int zip) {
				delete contactAddress; // Free existing memory
				contactAddress = new Address(st, city, state, country, zip); // Allocate new memory
		}
};

int Student::totalStudents = 0; // Resolution operator
ostream& operator<<(ostream& os, const Student& student) {
	os << "Name: " << student.name << endl;
	os << "Roll Number: " << student.rollNumber << endl;
	os << "Class: " << student.className << endl;
	os << "Division: " << student.division << endl;
	os << "Date of Birth: " << student.dateOfBirth << endl;
	os << "Blood Group: " << student.bloodGroup << endl;
	os << "Contact Address: " << *student.contactAddress << endl;
	os << "Telephone Number: " << student.telephoneNumber << endl;
	os << "Driving License Number: " << student.drivingLicenseNumber << endl;
	return os;
}

int main() {
	Student* students[100]; // Array to hold pointers to Student objects
	int studentCount = 0;
	int choice;
	cout << "\nMenu:\n";
	cout << "1. Add Student\n";
	cout << "2. Update Student\n";
	cout << "3. Delete Student\n";
	cout << "4. Display All Students\n";
	cout << "5. Display Total Students\n";
	cout << "6. Exit\n";
	do {
		
		cout << "Enter your choice: ";
		cin >> choice;
		switch (choice) {
			case 1: {
				string name, className, dateOfBirth, bloodGroup, street, city, state, country, drivingLicenseNumber;
				int rollNumber, zipCode;
				char division;
				long telephoneNumber;

				cout << "Enter Name (String): ";
				cin.ignore(); // Clear the input buffer
				getline(cin, name);
				cout << "Enter Roll Number (Integer): ";
				cin >> rollNumber;
				cout << "Enter Class (String): ";
				cin >> className;
				cout << "Enter Division (Char): ";
				cin >> division;
				cout << "Enter Date of Birth (DD/MM/YYYY) (String): ";
				cin >> dateOfBirth;
				cout << "Enter Blood Group: ";
				cin >> bloodGroup;
				cout << "Enter Street Address (String): ";
				cin.ignore();
				getline(cin, street);
				cout << "Enter City (String): ";
				getline(cin, city);
				cout << "Enter State (String): ";
				getline(cin, state);
				cout << "Enter Country (String): ";
				getline(cin, country);
				cout << "Enter Zip Code (Integer): ";
				cin >> zipCode;
				cout << "Enter Telephone Number (Integer): ";
				cin >> telephoneNumber;
				cout << "Enter Driving License Number (String): ";
				cin.ignore();
				getline(cin, drivingLicenseNumber);

				// Create a new Student object
				students[studentCount++] = new Student(name, rollNumber, className, division, dateOfBirth, bloodGroup, street, city, state, country, zipCode, telephoneNumber, drivingLicenseNumber);
				cout << "Student added successfully!" << endl;
				break;
			}
			case 2: { // Update
				int rollNumberToUpdate;
				cout << "Enter the roll number of the student to update: ";
				cin >> rollNumberToUpdate;
				for (int i = 0; i < studentCount; i++) {
					if (students[i]->getRollNumber() == rollNumberToUpdate) {
						string newClassName;
						cout << "Enter new class name: ";
						cin.ignore();
						getline(cin, newClassName);
						students[i] -> setClassName(newClassName);
						cout << "Student information updated successfully!" << endl;
						break;
					}
				}
				break;
			}
			case 3: {
				int rollNumberToDelete;
				cout << "Enter the roll number of the student to delete: ";
				cin >> rollNumberToDelete;
				for(int i=0; i<studentCount; i++) {
					if (students[i]->getRollNumber() == rollNumberToDelete) {
						delete students[i]; // Deallocation
						// Shift
						for (int j = i; j < studentCount - 1; j++) 
							students[j] = students[j+1];
						studentCount--;
						cout << "Student deleted successfully!" << endl;
						break;
					}
				}
				break;
			}
			case 4: {
				// Displaying all students
				if (studentCount == 0) cout << "No students to display." << endl;
				else {
					for (int i = 0; i < studentCount; i++) 
						cout << "Student " << (i + 1) << ":\n" << *students[i] << endl;
				}
				break;
		 	}
			case 5: cout << "Total Students: " << Student::getTotalStudents() << endl; break;
			case 6: cout << "Exiting the program." << endl; break;
			default: cout << "Invalid choice! Please try again." << endl;
		}

		// Clear input buffer to prevent infinite loop on invalid input
		if (cin.fail()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
		}
	} while (choice != 6);
	for (int i = 0; i < studentCount; i++) delete students[i];
	return 0;
}
