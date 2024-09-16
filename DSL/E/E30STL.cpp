#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

struct Task {
	string name;
	int priority;
	Task(const string &n, int p) : name(n), priority(p) {}

	// Comparator for priority queue (Max Heap)
	bool operator<(const Task &other) const {
		return priority < other.priority; 
	}
};

ostream &operator<<(ostream &os, const Task &task) {
	os << "Task: " << task.name << ", Priority: " << task.priority;
	return os;
}

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
	// Priority queue of Task
	priority_queue<Task> pq;
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
				pq.push(Task(name, priority));
				cout << "Task added.\n";
				break;

			case 2:
				if (!pq.empty()) { cout << "Removed task: " << pq.top() << endl; pq.pop(); } 
				else { cout << "Error: Priority queue is empty." << endl; }
				break;

			case 3:
				if (!pq.empty()) { cout << "Highest priority task: " << pq.top() << endl; } 
				else { cout << "Error: Priority queue is empty." << endl; }
				break;

			case 4: cout << (pq.empty() ? "Priority queue is empty." : "Priority queue is not empty.")<< endl; break;
			case 5:
				if (pq.empty()) { cout << "Priority queue is empty." << endl; } 
				else {
					cout << "Priority queue contents:\n";
					// Create a copy of the priority queue to display its contents
					priority_queue<Task> temp = pq;
					while (!temp.empty()) {
						cout << temp.top() << endl;
						temp.pop();
					}
				}
				break;
			case 6: cout << "Exiting...\n"; return 0;
			default: cout << "Invalid choice, please try again.\n"; break;
		}
	}
}
