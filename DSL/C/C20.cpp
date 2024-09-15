// * Eshan Nahar
// 20. The ticket booking system of Cinemax theater has to be implemented using C++ program. There are 10 rows and 7 seats in each row. Doubly circular linked list has to be maintained to keep track of free seats at rows. Assume some random booking to start with. Use array to store pointers (Head pointer) to each row. On demand

//   a) The list of available seats is to be displayed 
//   b) The seats are to be booked 
//   c) The booking can be cancelled. 


#include <iostream>
#include <string>
using namespace std;

class node {
public: // Clearing doubly linked
	node *next;
	node *prev;
	int seat;
	string id;
	int status; // 0 = available, 1 = booked
};

class cinemax {
public:
	node *head;
	node *tail;
	cinemax() : head(nullptr), tail(nullptr) {}
	void create_list();
	void display();
	void book();
	void cancel();
	void avail();
};

void cinemax::create_list() {
	head = new node{ nullptr, nullptr, 1, "null", 0 };
	tail = head;
	for (int i = 2; i <= 70; ++i) {
		node *p = new node{ nullptr, tail, i, "null", 0 };
		tail->next = p;
		tail = p;
	}
	tail->next = head;
	head->prev = tail;
	// Circular
}

void cinemax::display() {
	node *temp = head;
	for (int i = 1; i <= 70; ++i) {
		cout << (i < 10 ? "S0" : "S") << i << " :"
		     << (temp->status ? "|_B_| " : "|___| ");
		if (i % 7 == 0) cout << endl;
		temp = temp->next;
	}
}

void cinemax::book() {
	int seatNumber;
	string userId;
	while (true) {
		cout << "\nEnter seat number to be booked (1-70): ";
		cin >> seatNumber;
		if (seatNumber < 1 || seatNumber > 70) {
			cout << "Invalid seat number. Please enter a number between 1 and "
			        "70.\n";
			continue;
		}
		cout << "Enter your ID number: ";
		cin >> userId;
		node *temp = head;
		while (temp->seat != seatNumber)
			temp = temp->next;

		if (temp->status == 1) cout << "Seat already booked!\n";
		else {
			temp->status = 1;
			temp->id = userId;
			cout << "Seat " << seatNumber << " booked!\n";
			break;
		}
	}
}

void cinemax::cancel() {
	int seatNumber;
	string userId;
	while (true) {
		cout << "Enter seat number to cancel booking (1-70): ";
		cin >> seatNumber;
		if (seatNumber < 1 || seatNumber > 70) {
			cout << "Invalid seat number. Please enter a number between 1 and 70.\n";
			continue;
		}

		cout << "Enter your ID: ";
		cin >> userId;
		node *temp = head;
		while (temp->seat != seatNumber) {
			temp = temp->next;
		}
		if (temp->status == 0) cout << "Seat not booked yet!\n";
		else {
			if (temp->id == userId) {
				temp->status = 0;
				temp->id = "null";
				cout << "Seat " << seatNumber << " cancelled!\n";
				break;
			} else {
				cout << "Wrong User ID! Seat cannot be cancelled.\n";
			}
		}
	}
}

void cinemax::avail() {
	node *temp = head;
	int count = 0;
	cout << "\n---------------\n";
	cout << " Screen this way \n";
	cout << "-----------------\n";
	do {
		cout << (temp->seat < 10 ? "S0" : "S") << temp->seat << " :";
		cout << (temp->status == 0 ? "|___| " : " ");
		++count;

		if (count % 7 == 0) cout << endl;
		temp = temp->next;
	} while (temp != head);
}

int main() {
	cinemax obj;
	obj.create_list();
	int choice;
	char cont = 'y';
	while (cont == 'y') {
		obj.display();
		cout << "\n*******************************\n";
		cout << "CINEMAX MOVIE THEATRE\n";
		cout << "*******************************\n";
		cout << "\nEnter Choice\n1.Current Seat Status\n2.Book "
		        "Seat\n3.Available Seat\n4.Cancel Seat\n";
		cin >> choice;
		switch (choice) {
			case 1: obj.display(); break;
			case 2: obj.book(); break;
			case 3: obj.avail(); break;
			case 4: obj.cancel(); break;
			default: cout << "Wrong choice input\n";
		}
		cout << "\nDo you want to perform any other operation? (y/n): ";
		cin >> cont;
	}
	return 0;
}
