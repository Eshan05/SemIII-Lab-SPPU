/**
 * * Eshan Nahar
 * Write a C++ program that creates an output file, writes information to it, closes the file, open it again as an input file and read the information from the file
 */

#include<bits/stdc++.h>
using namespace std;

class FileHandle {
	private:
		string fileName;
	public:
		FileHandle(const string& file) : fileName(file) {}
		void write() {
			ofstream outputFile(fileName);
			if(outputFile.is_open()) {
				string input;
				cout << "Enter text to write the file (Type 'exit' to stop):\n";
				while(true) {
					getline(cin, input);
					if(input == "exit") break;
					outputFile << input << endl;
				}
				outputFile.close();
				cout << "Data written to " << fileName << " successfully.\n";
			} else cerr << "Unable to open file for writing";
		}

		void read() {
			ifstream inputFile(fileName);
			if(inputFile.is_open()) {
				string line;
				cout << "Contents of " << fileName << ":\n";
				while(getline(inputFile, line)) 
					cout << line << endl;
				inputFile.close();
			} else cerr << "Unable to open file for reading \n";
		}
};

void displayMenu() {
	cout << "\n Menu: \n";
	cout << "1. Write to file\n";
	cout << "2. Read from file\n";
	cout << "3. Exit\n";
	cout << "Choose an option: ";
}

int main() {
	FileHandle fh("output.txt");
	int choice;
	do {
		displayMenu();
		cin >> choice;
		cin.ignore();
		switch(choice) {
			case 1: fh.write(); break;
			case 2: fh.read(); break;
			case 3: cout<<"Exiting"; break;
			default: cout<<"Invalid choice";
		}
	} while(choice != 3);
	return 0;
}