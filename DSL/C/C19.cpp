// * Eshan Nahar
// 19. Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of second, third and final year of department can be granted membership on request. Similarly one may cancel the membership of club. First node is reserved for president of club and last node is reserved for secretary of club. WCP to maintain club member‘s information using singly linked list. Store student PRN and Name. Write functions to:
    
//   a) Add and delete the members as well as president or even secretary. 
//   b) Compute total number of members of club 
//   c) Display members 
//   d) Two linked lists exists for two divisions. Concatenate two lists.

#include <bits/stdc++.h>
using namespace std;

class node {
	private:
		string name;
		long prn;
		node *next;
	public:
		node() {
			prn = 0;
			next = NULL;
		}
		friend class List;
};

class List {
	private:
		node* head;
		int count;
	public:
		List() {
			head = NULL;
			count = 0;
		}
		node *create(int v, string n);
		void insertEnd();
		void insertStart();
		void deleteStart();
		void deleteEnd();
		void deleteAt(int i);
		void insertAt(int i);
		void display();
		int countAll();
		void reverse();
		node* rev(node *t);
		node* readAt(int i);
		void concatenate(List& A, List& B);
		void op();
};

node* List::create(int v, string n) {
	node* temp = new node;
	if(temp == NULL) {
		cout << "Memory not allocated" << endl;
		exit(0);
	} else {
	temp->name = n;
	temp->prn = v;
	temp->next = NULL;
	return temp; 
	}
}

void List::insertEnd() { // Secretary
	int v; string n;
	cout << "Enter PRN: "; cin >> v;
	cout << "Enter Name: "; cin.ignore(); getline(cin, n);
	node* newNode = create(v, n);
	if(head == NULL) head = newNode;
	else {
		node* temp = head;
		while(temp->next != NULL) temp = temp->next;
		temp->next = newNode;
	}
	count++;
}

void List::insertStart() {
	int v; string n;
	cout << "Enter PRN: "; cin >> v;
	cout << "Enter Name: "; cin.ignore(); getline(cin, n);
	node* newNode = create(v, n);
	newNode->next = head;
	head = newNode;
	count++;
}

void List::insertAt(int pos) {
	if(pos < 0 || pos > count) {
		cout << "Invalid Position" << endl;
		return;
	}

	int v; string n;
	cout << "Enter PRN: "; cin >> v;
	cout << "Enter Name: "; cin.ignore(); getline(cin, n);
	node* newNode = create(v, n);
	if(pos == 0) {
		newNode->next = head;
		head = newNode;
	} else {
		node* temp = head;
		for(int i = 0; i < pos - 1; i++) temp = temp->next;
		newNode->next = temp->next;
		temp->next = newNode;
	}
	count++;
}

void List::deleteStart() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    node* temp = head;
    head = head->next;
    delete temp;
    count--;
}

void List::deleteEnd() {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    if (head->next == NULL) {
        delete head; 
        head = NULL; 
    } else {
        node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        node* lastNode = temp->next;
        temp->next = NULL;
        delete lastNode; 
    }
    count--;
}

void List::deleteAt(int i) {
	if(i < 0 || i > count) {
		cout << "Invalid Position" << endl;
		return;
	}
	if(i == 0) {
		node* temp = head;
		head = head->next;
		delete temp;
	} else {
		node* temp = head;
		for(int j = 0; j < i - 1; j++) temp = temp->next;
		node* temp2 = temp->next;
		temp->next = temp2->next;
		delete temp2;
	}
	count--;
}

void List::display() {
	node* temp = head;
	while(temp != NULL) {
		cout << "PRN: " << temp->prn << ", Name: " << temp->name << endl;
		temp = temp->next;
	}
}
int List::countAll() { return count; }
void List::concatenate(List& A, List& B) {
	if (head == NULL) {
		if(A.head != NULL) {
			head = A.head;
			count = A.count;
		}
		if(B.head != NULL) {
			node* temp = head;
			while(temp->next != NULL) temp = temp->next;
			if(temp != NULL) {
				temp->next = B.head;
				count += B.count;
			} else {
				head = B.head;
				count = B.count;
			}
		}

		A.head = NULL;
		A.count = 0;
		B.head = NULL;
		B.count = 0;
	} else {
		node* temp = head;
		while(temp->next != NULL) temp = temp->next;
		if(A.head != NULL) {
			temp->next = A.head;
			count += A.count;
		}

		while(temp->next != NULL) temp = temp->next;
		if(B.head != NULL) {
			temp->next = B.head;
			count += B.count;
		}

		A.head = NULL;
		A.count = 0;
		B.head = NULL;
		B.count = 0;
	}
}

void List::op () {
	while(1) {
		int choice;
		cout << "\nEnter: \n1. Add \n2. Delete \n3. Member's Count \n4. Display \n5. Reverse the List \n0. Prev Menu" << endl;
		cin >> choice;
		switch(choice) {
			case 1:
				char c;
				cout << "\n Enter:\n A. Add President \n B. Add Secretary \n C. Add Member \n0. Prev Menu" << endl;
				cin >> c;
				switch(c) {
					case 'A': insertStart(); break;
					case 'B': insertEnd(); break;
					case 'C': insertAt(2); break;
					default: break;
				}
				break;

			case 2:
				char d;
				cout << "\n Enter:\n A. Delete President \n B. Delete Secretary \n C. Delete Member \n0. Prev Menu" << endl;
				cin >> d;
				switch(d) {
					case 'A': deleteStart(); break;
					case 'B': deleteEnd(); break;
					case 'C': deleteAt(2); break;
					default: break;
				}
				break;
			case 3: cout << "Count: " << countAll() << endl; break;
			case 4: display(); break;
			case 5: reverse(); break;
			case 0: break;
			default: cout << "Wrong Choice" << endl;
		}
		if(choice == 0) break;
	}
}



node* List::rev(node *t) {
	if(t == NULL || t->next == NULL) return t;
	node* newHead = rev(t->next);
	t->next->next = t;
	t->next = NULL;
	return newHead;
}

void List::reverse() { head = rev(head); }
node* List::readAt(int i) {
	if(i < 0 || i > count) {
		cout << "Invalid Position" << endl;
		return NULL;
	}
	node* temp = head;
	for(int j = 0; j < i; j++) temp = temp->next;
	return temp;
}


int main() {
	List L, X, Y;
	while(1) {
		int c;
		cout << "Enter your choice:\n1. Enter List A\n2. Enter List B\n3. Concatenate\n0. Exit\n-- Enter your choice --" << endl;
		cin >> c;
		switch(c) {
			case 1: cout << "\n List A: "; X.op(); break;
			case 2: cout << "\n List B: "; Y.op(); break;
			case 3: L.concatenate(X, Y); L.display(); break;
			case 0: cout << "Exiting..."; return 0;
		}
	}
}