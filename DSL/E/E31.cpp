/**
 * * Eshan Nahar
 * A double-ended queue (deque) is a linear list in which additions and
 deletions may be made at either end. Obtain a data representation mapping a
deque into a one- dimensional array. Write C++ program to simulate deque with
functions to add and delete elements from either end of the deque.

*/

#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

class Deque {
private:
	int arr[MAX_SIZE];
	int front;
	int rear;
	int size;

public:
	Deque() : front(MAX_SIZE / 2), rear(MAX_SIZE / 2), size(0) {}

	bool isEmpty() const { return size == 0; }
	bool isFull() const { return size == MAX_SIZE; }

	void addFront(int value) {
		if (isFull()) {
			cout << "Error: Deque is full." << endl;
			return;
		}
		front = (front - 1 + MAX_SIZE) % MAX_SIZE;
		arr[front] = value;
		++size;
		cout << "Added " << value << " to the front." << endl;
	}

	void addRear(int value) {
		if (isFull()) {
			cout << "Error: Deque is full." << endl;
			return;
		}
		arr[rear] = value;
		rear = (rear + 1) % MAX_SIZE;
		++size;
		cout << "Added " << value << " to the rear." << endl;
	}

	void removeFront() {
		if (isEmpty()) {
			cout << "Error: Deque is empty." << endl;
			return;
		}
		cout << "Removed " << arr[front] << " from the front." << endl;
		front = (front + 1) % MAX_SIZE;
		--size;
	}

	void removeRear() {
		if (isEmpty()) {
			cout << "Error: Deque is empty." << endl;
			return;
		}
		rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
		cout << "Removed " << arr[rear] << " from the rear." << endl;
		--size;
	}

	void display() const {
		if (isEmpty()) {
			cout << "Deque is empty." << endl;
			return;
		}
		cout << "Deque contents:\n";
		int current = front;
		for (int i = 0; i < size; ++i) {
			cout << arr[current] << " ";
			current = (current + 1) % MAX_SIZE;
		}
		cout << endl;
	}
};

// Function to display the menu
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
	Deque deque;
	int choice;
	int value;
	while (true) {
		printMenu();
		cin >> choice;
		switch (choice) {
			case 1:
				cout << "Enter value to add to the front: ";
				cin >> value;
				deque.addFront(value);
				break;

			case 2:
				cout << "Enter value to add to the rear: ";
				cin >> value;
				deque.addRear(value);
				break;

			case 3: deque.removeFront(); break;
			case 4: deque.removeRear(); break;
			case 5: deque.display(); break;
			case 6: cout << "Exiting...\n"; return 0;
			default: cout << "Invalid choice, please try again.\n"; break;
		}
	}
}
