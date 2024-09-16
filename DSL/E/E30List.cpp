#include <iostream>
#include <list>
#include <string>
using namespace std;

template <typename T> class PriorityQueue {
private:
	class QueueItem {
	public:
		T data;
		int priority;
		QueueItem(const T &data, int priority) : data(data), priority(priority) {}
		bool operator<=(const QueueItem &other) const { return priority >= other.priority; }
		friend ostream &operator<<(ostream &os, const QueueItem &item) {
			os << "Data: " << item.data << ", Priority: " << item.priority;
			return os;
		}
	};

	list<QueueItem> items;

public:
	void push(const T &data, int priority) {
		auto it = items.begin();
		while (it != items.end() && !(QueueItem(data, priority) <= *it)) { ++it; }
		items.insert(it, QueueItem(data, priority));
	}

	bool pop(T &item) {
		if (items.empty()) {
			cout << "Error: PriorityQueue is empty." << endl;
			return false;
		}
		item = items.front().data;
		items.pop_front();
		return true;
	}

	bool peek(T &item) const {
		if (items.empty()) {
			cout << "Error: PriorityQueue is empty." << endl;
			return false;
		}
		item = items.front().data;
		return true;
	}

	bool isEmpty() const { return items.empty(); }
	void display() const {
		if (items.empty()) {
			cout << "PriorityQueue is empty." << endl;
			return;
		}
		cout << "PriorityQueue contents:\n";
		for (const auto &item : items) {
			cout << item << endl;
		}
	}
};

void printMenu() {
	cout << "Priority Queue Menu:\n";
	cout << "1. Add item\n";
	cout << "2. Remove item\n";
	cout << "3. Peek item\n";
	cout << "4. Check if empty\n";
	cout << "5. Display all items\n";
	cout << "6. Exit\n";
	cout << "Enter your choice: ";
}

int main() {
	PriorityQueue<string> pq;
	int choice;
	string data;
	int priority;

	while (true) {
		printMenu();
		cin >> choice;
		cin.ignore(); 
		switch (choice) {
			case 1:
				cout << "Enter item: ";
				getline(cin, data);
				cout << "Enter priority: ";
				cin >> priority;
				pq.push(data, priority);
				cout << "Item added.\n";
				break;

			case 2: if (pq.pop(data)) { cout << "Removed item: " << data << endl; } break;
			case 3: if (pq.peek(data)) { cout << "Highest priority item: " << data << endl; } break;
			case 4: cout << (pq.isEmpty() ? "Priority queue is empty." : "Priority queue is not empty.") << endl; break;
			case 5: pq.display(); break;
			case 6: cout << "Exiting...\n"; return 0;
			default: cout << "Invalid choice, please try again.\n"; break;
		}
	}
}