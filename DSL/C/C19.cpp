// * Eshan Nahar
// 19. Department of Computer Engineering has student's club named 'Pinnacle
// Club'. Students of second, third and final year of department can be granted
// membership on request. Similarly one may cancel the membership of club. First
// node is reserved for president of club and last node is reserved for
// secretary of club. WCP to maintain club member‘s information using singly
// linked list. Store student PRN and Name. Write functions to:

//   a) Add and delete the members as well as president or even secretary.
//   b) Compute total number of members of club
//   c) Display members
//   d) Two linked lists exists for two divisions. Concatenate two lists.

#include <iostream>
#include <string>
using namespace std;

enum Role { PRESIDENT, SECRETARY, MEMBER };
// Node structure definition
struct node {
  string name;
  int PRN;
  Role role;
  node *next;
  node(string nm, int prn, Role r)
      : name(nm), PRN(prn), role(r), next(nullptr) {}
};

// Linked list class definition
class ll {
  node *head;
  node *tail;

 public:
  ll() : head(nullptr), tail(nullptr) {}
  ~ll() {
    while(head) { removePresident(); }
  }

  void create();
  void display();
  void addPresident();
  void addSecretary();
  void addMember();
  void removePresident();
  void deleteSecretary();
  void deleteMember(int prn);
  int computeTotal();
  void concatLists(ll &other);

 private:
  bool isValidPRN(int prn);
  node *createNode(Role role);
};

bool ll::isValidPRN(int prn) {
  // First, check if PRN is greater than 0
  if(prn <= 0) {
    cout << "Invalid PRN number: " << prn << endl;
    return false;
  }

  node *temp = head;
  while(temp) {
    if(temp->PRN == prn) {
      cout << "PRN " << prn << " already exists. Cannot add." << endl;
      return false; // PRN is not unique
    }
    temp = temp->next;
  }

  return true; // PRN is valid and unique
}

node *ll::createNode(Role role) {
  string name;
  int prn;

  cout << "Enter PRN number for "
       << ((role == PRESIDENT)   ? "President"
           : (role == SECRETARY) ? "Secretary"
                                 : "Member")
       << ": ";
  try {
    cin >> prn;
    if(!isValidPRN(prn)) throw prn;
  } catch(int prn) {
    cout << "Invalid PRN number: " << prn << endl;
    return nullptr;
  }
  cout << "Enter name: ";
  cin >> name;
  cout << "Successfully added:"
       << (role == PRESIDENT ? " President"
                             : (role == SECRETARY ? " Secretary" : " Member"))
       << ": (" << name << ") [" << prn << "]" << endl;
  return new node(name, prn, role);
}

void ll::create() {
  head = createNode(PRESIDENT);
  tail = head;
  cout << "List created with President: " << head->name << endl;
}

void ll::display() {
  node *temp = head;
  if(!temp) {
    cout << "List is empty." << endl;
    return;
  }
  cout << "Club Members:\n";
  while(temp) {
    switch(temp->role) {
      case PRESIDENT:
        cout << "President: " << temp->name << ", PRN: " << temp->PRN << endl;
        break;
      case MEMBER:
        cout << "Member: " << temp->name << ", PRN: " << temp->PRN << endl;
        break;
      case SECRETARY:
        cout << "Secretary: " << temp->name << ", PRN: " << temp->PRN << endl;
        break;
    }
    temp = temp->next;
  }
}

void ll::addPresident() {
  if(head && head->role == PRESIDENT) {
    cout << "There is already a President" << endl;
    return;
  }
  node *newPresident = createNode(PRESIDENT);
  newPresident->next = head;
  head = newPresident;
  if(!tail) tail = newPresident;
}

void ll::addSecretary() {
  if(tail && tail->role == SECRETARY) {
    cout << "There is already a Secretary" << endl;
    return;
  }
  node *newSecretary = createNode(SECRETARY);
  if(!head) {
    head = newSecretary;
    tail = newSecretary;
  } else {
    tail->next = newSecretary;
    tail = newSecretary;
  }
}

void ll::addMember() {
  node *newMember = createNode(MEMBER);
  if(!head) {
    head = newMember;
    tail = newMember;
  } else {
    tail->next = newMember;
    tail = newMember;
  }
}

void ll::removePresident() {
  if(!head) {
    cout << "No president to remove." << endl;
    return;
  }
  node *temp = head;
  head = head->next;
  delete temp;
  cout << "President removed." << endl;
}

void ll::deleteSecretary() {
  if(!head || tail->role != SECRETARY) {
    cout << "No secretary to remove." << endl;
    return;
  }
  if(head == tail) { // Only one member
    delete head;
    head = tail = nullptr;
    cout << "Secretary removed." << endl;
    return;
  }

  node *temp = head;
  while(temp->next && temp->next->role != SECRETARY) { temp = temp->next; }
  if(!temp->next) {
    cout << "No secretary to remove." << endl;
    return;
  }
  node *secretaryToRemove = temp->next;
  temp->next = secretaryToRemove->next;
  if(secretaryToRemove == tail) { tail = temp; }
  delete secretaryToRemove;
  cout << "Secretary removed." << endl;
}

void ll::deleteMember(int prn) {
  node *temp = head;
  node *prev = nullptr;
  while(temp && temp->PRN != prn) {
    prev = temp;
    temp = temp->next;
  }
  if(!temp) {
    cout << "Member with PRN " << prn << " not found." << endl;
    return;
  }

  if(prev) prev->next = temp->next;
  else head = temp->next;

  if(temp == tail) { tail = prev; }
  delete temp;
  cout << "Member with PRN " << prn << " removed." << endl;
}

int ll::computeTotal() {
  node *temp = head;
  int count = 0;
  while(temp) {
    count++;
    temp = temp->next;
  }
  return count;
}

void ll::concatLists(ll &other) {
  // cout << "List 1 head: " << head->name << ", tail: " << tail->name << endl;
  // cout << "List 2 head: " << other.head->name << ", tail: " << other.tail->name << endl;
  if(!head) {
    head = other.head;
    tail = other.tail;
  } else {
    tail->next = other.head;
    if(other.tail) {
      tail = other.tail; // Update tail if necessary
    }
  }

  other.head = nullptr;
  other.tail = nullptr;
  // cout << "List 1 head: " << head->name << ", tail: " << tail->name << endl;
  cout << "Lists concatenated." << endl;
  display();
  cout << "Total members (including President & Secretary): " << computeTotal();
}

int main() {
  ll list1, list2;
  int choice, listChoice;

  do {
    cout << "\n=== Select Option ===\n1. List 1\n2. List 2\n3. Concatenate "
            "Lists\n0. Exit\nEnter choice: ";
    cin >> listChoice;
    ll *currentList = (listChoice == 1)   ? &list1
                      : (listChoice == 2) ? &list2
                                          : nullptr;

    if(listChoice == 3) {
      cout << "Concatenating List 1 and List 2..." << endl;
      list1.concatLists(list2);
    } else if(!currentList) {
      cout << "Invalid list choice. Please try again." << endl;
      continue;
    }

    if(listChoice == 0) {
      cout << "Exiting...";
      break;
    }

    cout << "\n1. Create\n2. Add President\n3. Add Secretary\n4. Add "
            "Member\n5. Display\n"
         << "6. Remove President\n7. Remove Secretary\n8. Remove Member\n9. "
            "Total Members\n"
         << "0. Exit";
    do {
      cout << "\n-> Enter your choice: ";
      cin >> choice;
      switch(choice) {
        case 1: currentList->create(); break;
        case 2: currentList->addPresident(); break;
        case 3: currentList->addSecretary(); break;
        case 4: currentList->addMember(); break;
        case 5: currentList->display(); break;
        case 6: currentList->removePresident(); break;
        case 7: currentList->deleteSecretary(); break;
        case 8: {
          int prn;
          cout << "Enter PRN of member to be deleted: ";
          cin >> prn;
          currentList->deleteMember(prn);
          break;
        }
        case 9:
          cout << "Total members (including President & Secretary): "
               << currentList->computeTotal() << endl;
          break;
        case 0: break;
        default: cout << "Invalid choice." << endl;
      }
    } while(choice != 0);
  } while(listChoice != 0);

  return 0;
}
