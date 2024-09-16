#include <deque>
#include <iostream>
#include <string>
using namespace std;

void printMenu() {
  cout << "Deque Menu:\n";
  cout << "1. Add to front\n";
  cout << "2. Add to rear\n";
  cout << "3. Remove from front\n";
  cout << "4. Remove from rear\n";
  cout << "5. Display all elements\n";
  cout << "6. Exit\n";
  cout << "Enter your choice: ";
}

int main() {
  deque<int> dq; 
  int choice;
  int value;

  while (true) {
    printMenu();
    cin >> choice;
    switch (choice) {
      case 1:
        cout << "Enter value to add to the front: ";
        cin >> value;
        dq.push_front(value);
        cout << "Added " << value << " to the front." << endl;
        break;

      case 2:
        cout << "Enter value to add to the rear: ";
        cin >> value;
        dq.push_back(value);
        cout << "Added " << value << " to the rear." << endl;
        break;

      case 3:
        if (!dq.empty()) {
          cout << "Removed " << dq.front() << " from the front." << endl;
          dq.pop_front();
        } else { cout << "Error: Deque is empty." << endl; }
        break;

      case 4:
        if (!dq.empty()) {
          cout << "Removed " << dq.back() << " from the rear." << endl;
          dq.pop_back();
        } else { cout << "Error: Deque is empty." << endl; }
        break;

      case 5:
        if (dq.empty()) { cout << "Deque is empty." << endl; } 
        else {
          cout << "Deque contents:\n";
          for (int item : dq) { cout << item << " "; }
          cout << endl;
        }
        break;

      case 6: cout << "Exiting...\n"; return 0;
      default: cout << "Invalid choice, please try again.\n"; break;
    }
  }
}
