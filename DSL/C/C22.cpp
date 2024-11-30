// * Eshan Nahar
// 22. Second year Computer Engineering class, set A of students like Vanilla
// Ice-cream and set B of students like butterscotch ice-cream. WCP to store two
// sets using linked list. compute and display-

//   a) Set of students who like both vanilla and butterscotch
//   b) Set of students who like either vanilla or butterscotch or not both
//   c) Number of students who like neither vanilla nor

#include <iostream>
#include <string>
using namespace std;

struct Node {
  string studentName;
  Node *next;
};

Node *createNode(const string &studentName) {
  Node *newNode = new Node();
  newNode->studentName = studentName;
  newNode->next = nullptr;
  return newNode;
}

void insertEnd(Node *&head, const string &studentName) {
  Node *newNode = createNode(studentName);
  if(head == nullptr) head = newNode;
  else {
    Node *temp = head;
    while(temp->next != nullptr) temp = temp->next;
    temp->next = newNode;
  }
}

void displayList(Node *head) {
  Node *temp = head;
  if(temp == nullptr) cout << "No students in the list." << endl;
  else {
    while(temp != nullptr) {
      cout << temp->studentName << " ";
      temp = temp->next;
    }
    cout << endl;
  }
}

void toLower(string &str) {
  for(int i = 0; i < str.length(); ++i) {
    if(str[i] >= 'A' && str[i] <= 'Z') { str[i] = str[i] + ('a' - 'A'); }
  }
}

// Function to check if a studentName exists in the list
bool exists(Node *head, const string &studentName) {
  Node *temp = head;
  string lowerName = studentName;
  toLower(lowerName);
  while(temp != nullptr) {
    string lowerTempName = temp->studentName;
    toLower(lowerTempName);
    if(lowerTempName == lowerName) return true;
    temp = temp->next;
  }
  return false;
}

Node *intersection(Node *headA, Node *headB) {
  Node *result = nullptr;
  Node *tempA = headA;
  while(tempA != nullptr) {
    if(exists(headB, tempA->studentName)) insertEnd(result, tempA->studentName);
    tempA = tempA->next;
  }
  return result;
}

Node *unionSets(Node *headA, Node *headB) {
  Node *result = nullptr;
  Node *tempA = headA;
  Node *tempB = headB;
  while(tempA != nullptr) {
    insertEnd(result, tempA->studentName);
    tempA = tempA->next;
  }

  // Add all elements from set B that are not in set A
  while(tempB != nullptr) {
    if(!exists(result, tempB->studentName))
      insertEnd(result, tempB->studentName);
    tempB = tempB->next;
  }

  return result;
}

Node *difference(Node *headA, Node *headB) {
  Node *result = nullptr;
  Node *tempA = headA;
  while(tempA != nullptr) {
    if(!exists(headB, tempA->studentName))
      insertEnd(result, tempA->studentName);
    tempA = tempA->next;
  }
  return result;
}

Node *symmetricDifference(Node *headA, Node *headB) {
  Node *unionAB = unionSets(headA, headB);
  Node *intersectionAB = intersection(headA, headB);
  return difference(unionAB, intersectionAB);
}

int countNodes(Node *head) {
  int count = 0;
  Node *temp = head;
  while(temp != nullptr) {
    count++;
    temp = temp->next;
  }
  return count;
}

// Function to get the number of students who like neither vanilla nor
// butterscotch
int countNeither(Node *vanillaList, Node *butterscotchList, int totalStudents) {
  Node *unionAB = unionSets(vanillaList, butterscotchList);
  int countAB = countNodes(unionAB);
  return totalStudents - countAB;
}

void deleteList(Node *&head) {
  while(head != nullptr) {
    Node *temp = head;
    head = head->next;
    delete temp;
  }
}

int main() {
  Node *vanillaList = nullptr;
  Node *butterscotchList = nullptr;

  int choice, totalStudents;
  string studentName;
  cout << "Enter the total number of students: ";
  cin >> totalStudents;
  cout << "Enter the students who like vanilla (End with empty line):\n";
  while(getline(cin, studentName) && !studentName.empty())
    insertEnd(vanillaList, studentName);
  cout << "Enter the students who like butterscotch (End with empty line):\n";
  while(getline(cin, studentName) && !studentName.empty())
    insertEnd(butterscotchList, studentName);

  do {
    cout << "\nMenu:\n";
    cout << "1. Display set of students who like both vanilla and "
            "butterscotch\n";
    cout << "2. Display set of students who like either vanilla or "
            "butterscotch but not both\n";
    cout << "3. Display number of students who like neither vanilla nor "
            "butterscotch\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(); // To ignore the newline character left by cin

    switch(choice) {
      case 1: {
        Node *both = intersection(vanillaList, butterscotchList);
        cout << "Students who like both vanilla and butterscotch: ";
        displayList(both);
        deleteList(both);
        break;
      }
      case 2: {
        Node *eitherNotBoth =
            symmetricDifference(vanillaList, butterscotchList);
        cout << "Students who like either vanilla or butterscotch but not "
                "both: ";
        displayList(eitherNotBoth);
        deleteList(eitherNotBoth);
        break;
      }
      case 3: {
        int neitherCount =
            countNeither(vanillaList, butterscotchList, totalStudents);
        if(neitherCount <= 0) {
          cout << "Out of " << totalStudents
               << " there are no students who like neither vanilla or "
                  "butterscotch";
        } else {
          cout << "Number of students who like neither vanilla nor "
                  "butterscotch: "
               << neitherCount << endl;
        }
        break;
      }
      case 4: cout << "Exiting...\n"; break;
      default: cout << "Invalid choice, please try again.\n";
    }
  } while(choice != 4);

  deleteList(vanillaList);
  deleteList(butterscotchList);
  return 0;
}
