/**
 * * Eshan Nahar
 * Write C++ program using STL for sorting and searching user defined records such as personal records (Name, DOB, Telephone number, ...) using vector container
 * OR
 */

#include<bits/stdc++.h>
using namespace std;

class PersonalRecord {
	private: 
		string name;
		string dob;
		string phone;
	public:
		PersonalRecord(const string& name = "", const string& dob = "", const string& phone = "") : name(name), dob(dob), phone(phone) {}
		string getName() const { return name; }
		void setName(const string& name) { this->name = name; }
		// Use this->name to distinguish from member variable and parameter passed
		void display() const {
			cout << "Name: " << name << ", DOB: " << dob << ", Phone: " << phone << endl;
		}

		// Using const so it won't modify the object on which it's called
		// Comparision required for sorting
		bool operator<(const PersonalRecord& other) const {
			return name < other.name;
		}

		// Equality required for searching
		bool operator==(const PersonalRecord& other) const {
			return name == other.name;
		}
};

class PersonalRecordManager {
	private:
		vector<PersonalRecord> records;
	public:
		void addRecord() {
			string name, dob, phone;
			cout << "Enter Name: "; getline(cin, name);
			cout << "Enter DOB (YYYY-MM-DD): "; getline(cin, dob);
			cout << "Enter Phone No.: "; getline(cin, phone);
			records.emplace_back(name,dob,phone);
			cout << "Record added!\n";
		}

		void displayRecords() const {
			if(records.empty()) cout << "No records.\n";
			else 
				for(const auto& record : records)
					record.display();
		}

		void sortRecords() {
			sort(records.begin(), records.end());
			cout << "Records sorted by name.\n";
		}

		void searchRecord() const {
			string searchName;
			cout << "Enter a name to search: ";
			getline(cin, searchName);
			PersonalRecord searchRecord(searchName);
			auto it = find(records.begin(), records.end(), searchRecord);
			if(it != records.end()) {
				cout << "Record found:\n";
				it -> display();
			} else cout << "Record not found.\n";
		}

		void deleteRecord() {
			string deleteName;
			cout << "Enter name to delete: ";
			getline(cin, deleteName);
			for(auto it=records.begin(); it!=records.end(); ++it) {
				if(it -> getName() == deleteName) {
					records.erase(it);
					cout << "Record deleted!\n";
					return;
				}
			}
			cout << "Record not found.\n";
		}

		static void printMenu() {
			cout << "\nMenu:\n";
			cout << "1. Add Record\n";
			cout << "2. Display Records\n";
			cout << "3. Sort Records\n";
			cout << "4. Search Record\n";
			cout << "5. Delete Record\n";
			cout << "6. Exit\n";
			
		}
};

int main() {
	PersonalRecordManager manager;
	int choice;
	PersonalRecordManager::printMenu();
	do {
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();
		switch(choice) {
			case 1: manager.addRecord(); break;
			case 2: manager.displayRecords(); break;
			case 3: manager.sortRecords(); break;
			case 4: manager.searchRecord(); break;
			case 5: manager.deleteRecord(); break;
			case 6: cout << "Exiting\n"; break;
			default: cout << "Invalid choice\n"; break;
		} 
	} while(choice!=6);
	return 0;
}