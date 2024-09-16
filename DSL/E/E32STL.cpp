#include <iostream>
#include <queue>
using namespace std;

class PizzaParlor {
private:
	int maxOrders;
	queue<int> orders;

public:
	PizzaParlor(int maxOrders) : maxOrders(maxOrders) {}

	void placeOrder(int orderID) {
		if (orders.size() < maxOrders) {
			orders.push(orderID);
			cout << "Order " << orderID << " placed successfully.\n";
		} else {
			cout << "Sorry, the parlor is full. Cannot place order " << orderID
					<< ".\n";
		}
	}

	void serveOrder() {
		if (orders.empty()) {
			cout << "No orders to serve.\n";
		} else {
			int servedOrder = orders.front();
			orders.pop();
			cout << "Order " << servedOrder << " is served.\n";
		}
	}

	void displayOrders() const {
		if (orders.empty()) {
			cout << "No orders in the queue.\n";
		} else {
			cout << "Current orders in the queue:\n";
			queue<int> tempQueue = orders; // Copy the queue to traverse it
			while (!tempQueue.empty()) {
				cout << "Order " << tempQueue.front() << "\n";
				tempQueue.pop();
			}
		}
	}
};

int main() {
	int maxOrders;
	cout << "Enter the maximum number of orders the parlor can handle: ";
	cin >> maxOrders;
	PizzaParlor parlor(maxOrders);
	int choice, orderID;
	do {
		cout << "\nPizza Parlor Menu:\n";
		cout << "1. Place Order\n";
		cout << "2. Serve Order\n";
		cout << "3. Display Orders\n";
		cout << "4. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1:
				cout << "Enter order ID: ";
				cin >> orderID;
				parlor.placeOrder(orderID);
				break;
			case 2: parlor.serveOrder(); break;
			case 3: parlor.displayOrders(); break;
			case 4: cout << "Exiting...\n"; break;
			default: cout << "Invalid choice. Please try again.\n"; break;
		}
	} while (choice != 4);

	return 0;
}
