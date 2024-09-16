/**
 * * Eshan Nahar
 * Queues are frequently used in computer programming, and a typical example is
 the creation of a job queue by an operating system. If the operating system
does not use priorities, then the jobs are processed in the order they enter
the system. Write C++ program for simulating job queue. Write functions to add
job and delete job from queue.

*/

#include <iostream>
#define MAX 10
using namespace std;

struct QueueData {
	int data[MAX];
	int front, rear;
};

class Queue {
private:
	QueueData q;

public:
	Queue() { q.front = q.rear = -1; }
	bool isEmpty() const { return q.front == q.rear; }
	bool isFull() const { return q.rear == MAX - 1; }
	void enqueue(int x);
	int dequeue();
	void display() const;
};

void Queue::enqueue(int x) {
	if (isFull()) {
		cout << "Queue overflow\n\n";
		return;
	}
	q.data[++q.rear] = x;
}

int Queue::dequeue() {
	if (isEmpty()) {
		cout << "Queue underflow\n\n";
		return -1; // Indicate error condition
	}
	return q.data[++q.front];
}

void Queue::display() const {
	if (isEmpty()) {
		cout << "Queue is empty!!!\n\n";
		return;
	}

	cout << "\nQueue contains: \n";
	for (int i = q.front + 1; i <= q.rear; ++i) {
		cout << q.data[i] << " ";
	}
	cout << endl;
}

int main() {
	Queue obj;
	int choice, x;
	do {
		cout << "\n1. Insert Job\n2. Delete Job\n3. Display\n4. Exit\nEnter your choice: ";
		cin >> choice;
		switch (choice) {
			case 1:
				cout << "Enter data: ";
				cin >> x;
				obj.enqueue(x);
				break;
			case 2:
				x = obj.dequeue();
				if (x != -1) { cout << "Deleted Element = " << x << endl; }
				obj.display();
				break;
			case 3: obj.display(); break;
			case 4: cout << "Exiting Program....." << endl; break;
			default: cout << "Invalid choice, please try again." << endl; break;
		}
	} while (choice != 4);

	return 0;
}
