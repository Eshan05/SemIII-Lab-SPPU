#include <iostream>
#include <string>

using namespace std;

class PersonalRecord {
 private:
  string name;
  string dob; // Format: YYYY-MM-DD
  string phone;

 public:
  PersonalRecord(const string &name = "", const string &dob = "",
                 const string &phone = "")
      : name(name), dob(dob), phone(phone) {}

  string getName() const { return name; }

  void display() const {
    cout << "Name: " << name << ", DOB: " << dob << ", Phone: " << phone
         << endl;
  }

  bool operator<(const PersonalRecord &other) const {
    return name < other.name;
  }

  bool operator==(const PersonalRecord &other) const {
    return name == other.name;
  }
};

class PersonalRecordManager {
 private:
  PersonalRecord records[100];
  int recordCount;

 public:
  PersonalRecordManager() : recordCount(0) {}

  void addRecord() {
    string name, dob, phone;
    cout << "Enter Name: ";
    cin.ignore(); // Ignore any newline
    getline(cin, name);
    cout << "Enter DOB (YYYY-MM-DD): ";
    getline(cin, dob);
    cout << "Enter Phone No.: ";
    getline(cin, phone);
    records[recordCount++] = PersonalRecord(name, dob, phone);
    cout << "Record added!\n";
  }

  void displayRecords() const {
    if(recordCount == 0) {
      cout << "No records.\n";
    } else {
      for(int i = 0; i < recordCount; ++i) { records[i].display(); }
    }
  }

  void sortRecords() {
    for(int i = 0; i < recordCount - 1; ++i) {
      for(int j = 0; j < recordCount - i - 1; ++j) {
        if(records[j] < records[j + 1]) {
          // Swap records[j] and records[j + 1]
          PersonalRecord temp = records[j];
          records[j] = records[j + 1];
          records[j + 1] = temp;
        }
      }
    }
    cout << "Records sorted by name.\n";
  }

  void searchRecord() const {
    string searchName;
    cout << "Enter a name to search: ";
    cin.ignore();
    getline(cin, searchName);
    PersonalRecord searchRecord(searchName);
    for(int i = 0; i < recordCount; ++i) {
      if(records[i] == searchRecord) {
        cout << "Record found:\n";
        records[i].display();
        return;
      }
    }
    cout << "Record not found.\n";
  }

  void deleteRecord() {
    string deleteName;
    cout << "Enter name to delete: ";
    cin.ignore();
    getline(cin, deleteName);
    for(int i = 0; i < recordCount; ++i) {
      if(records[i].getName() == deleteName) {
        // Shift records to delete the specified one
        for(int j = i; j < recordCount - 1; ++j) {
          records[j] = records[j + 1];
        }
        recordCount--;
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
    switch(choice) {
      case 1: manager.addRecord(); break;
      case 2: manager.displayRecords(); break;
      case 3: manager.sortRecords(); break;
      case 4: manager.searchRecord(); break;
      case 5: manager.deleteRecord(); break;
      case 6: cout << "Exiting\n"; break;
      default: cout << "Invalid choice\n"; break;
    }
  } while(choice != 6);
  return 0;
}
