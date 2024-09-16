/**
 * * Eshan Nahar
 * Pizza parlor accepting maximum M orders. Orders are served in first come
 first served basis. Order once placed cannot be cancelled. Write C++ program to
simulate the system using circular queue using array.

*/

#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;
class CircularQueue {
private:
	string orders[MAX_SIZE];
	int front;
	int rear;
	int size;

public:
	CircularQueue() : front(0), rear(0), size(0) {}
	bool isEmpty() const { return size == 0; }
	bool isFull() const { return size == MAX_SIZE; }

	void addOrder(const string &order) {
		if (isFull()) {
			cout << "Error: Queue is full. Cannot add new orders." << endl;
			return;
		}
		orders[rear] = order;
		rear = (rear + 1) % MAX_SIZE;
		++size;
		cout << "Order added: " << order << endl;
	}

	void serveOrder() {
		if (isEmpty()) {
			cout << "Error: Queue is empty. No orders to serve." << endl;
			return;
		}
		cout << "Order served: " << orders[front] << endl;
		front = (front + 1) % MAX_SIZE;
		--size;
	}

	void displayOrders() const {
		if (isEmpty()) {
			cout << "No orders in the queue." << endl;
			return;
		}
		cout << "Current orders in the queue:\n";
		int i = front;
		for (int count = 0; count < size; ++count) {
			cout << orders[i] << " ";
			i = (i + 1) % MAX_SIZE;
		}
		cout << endl;
	}
};

// Function to display the menu
void printMenu() {
	cout << "Pizza Parlor Menu:\n";
	cout << "1. Add an order\n";
	cout << "2. Serve an order\n";
	cout << "3. Display all orders\n";
	cout << "4. Exit\n";
	cout << "Enter your choice: ";
}

int main() {
	CircularQueue queue;
	int choice;
	string order;

	while (true) {
		printMenu();
		cin >> choice;
		cin.ignore();
		switch (choice) {
			case 1:
				cout << "Enter order description: ";
				getline(cin, order);
				queue.addOrder(order);
				break;

			case 2: queue.serveOrder(); break;
			case 3: queue.displayOrders(); break;
			case 4: cout << "Exiting...\n"; return 0;
			default: cout << "Invalid choice, please try again.\n"; break;
		}
	}
}
