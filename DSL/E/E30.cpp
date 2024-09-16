/**
 * * Eshan Nahar
 * Write program to implement a priority queue in C++ using an inorder list to
 store the items in the queue. Create a class that includes the data items
(which should be template) and the priority (which should be int). The inorder
list should contain these objects, with operator <= overloaded so that the
items with highest priority appear at the start of the list (which will make it
relatively easy to retrieve the highest item.)

*/

#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100; 
struct Task {
	string name;
	int priority;
};

class PriorityQueue {
private:
	Task tasks[MAX_SIZE];
	int size;

	void swap(int i, int j) {
		Task temp = tasks[i];
		tasks[i] = tasks[j];
		tasks[j] = temp;
	}

	void heapifyDown(int index) {
		int largest = index;
		int left = 2 * index + 1;
		int right = 2 * index + 2;

		if (left < size && tasks[left].priority > tasks[largest].priority) { largest = left; }

		if (right < size && tasks[right].priority > tasks[largest].priority) { largest = right; }

		if (largest != index) {
			swap(index, largest);
			heapifyDown(largest);
		}
	}

	void heapifyUp(int index) {
		if (index && tasks[(index - 1) / 2].priority < tasks[index].priority) {
			swap(index, (index - 1) / 2);
			heapifyUp((index - 1) / 2);
		}
	}

public:
	PriorityQueue() : size(0) {}
	bool isEmpty() const { return size == 0; }
	void addTask(const string &name, int priority) {
		if (size >= MAX_SIZE) {
			cout << "Error: PriorityQueue is full." << endl;
			return;
		}
		tasks[size] = { name, priority };
		heapifyUp(size);
		++size;
		cout << "Task added." << endl;
	}

	bool removeHighestPriorityTask(string &name) {
		if (isEmpty()) {
			cout << "Error: PriorityQueue is empty." << endl;
			return false;
		}
		name = tasks[0].name;
		tasks[0] = tasks[size - 1];
		--size;
		heapifyDown(0);
		return true;
	}

	bool peekHighestPriorityTask(string &name) const {
		if (isEmpty()) {
			cout << "Error: PriorityQueue is empty." << endl;
			return false;
		}
		name = tasks[0].name;
		return true;
	}

	void display() const {
		if (isEmpty()) {
			cout << "PriorityQueue is empty." << endl;
			return;
		}
		cout << "PriorityQueue contents:\n";
		for (int i = 0; i < size; ++i) {
			cout << "Task: " << tasks[i].name << ", Priority: " << tasks[i].priority << endl;
		}
	}
};

// Function to display the menu
void printMenu() {
	cout << "Priority Queue Menu:\n";
	cout << "1. Add task\n";
	cout << "2. Remove highest-priority task\n";
	cout << "3. Peek at highest-priority task\n";
	cout << "4. Check if queue is empty\n";
	cout << "5. Display all tasks\n";
	cout << "6. Exit\n";
	cout << "Enter your choice: ";
}

int main() {
	PriorityQueue pq;
	int choice;
	string name;
	int priority;

	while (true) {
		printMenu();
		cin >> choice;
		cin.ignore();

		switch (choice) {
			case 1:
				cout << "Enter task name: ";
				getline(cin, name);
				cout << "Enter priority: ";
				cin >> priority;
				pq.addTask(name, priority);
				break;

			case 2: if (pq.removeHighestPriorityTask(name)) { cout << "Removed task: " << name << endl; } break;
			case 3: if (pq.peekHighestPriorityTask(name)) { cout << "Highest priority task: " << name << endl; } break;

			case 4:
				cout << (pq.isEmpty() ? "Priority queue is empty." : "Priority queue is not empty.")<< endl;
				break;

			case 5: pq.display(); break;
			case 6: cout << "Exiting...\n"; return 0;
			default: cout << "Invalid choice, please try again.\n"; break;
		}
	}
}
