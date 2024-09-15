// * Eshan Nahar
// 23. WCP for storing binary number using doubly linked lists. Write functions-
//   a) To compute 1‘s and 2‘s complement
//   b) Add two binary numbers

#include <iostream>
using namespace std;

struct Node {
	char data;
	Node *prev;
	Node *next;
	Node(char d) : data(d), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
	Node *head;
	Node *tail;

	int length() const {
		int len = 0;
		Node *current = head;
		while (current) {
			++len;
			current = current->next;
		}
		return len;
	}

	void padToEightBits() {
		int len = length();
		if (len < 8) {
			int padding = 8 - len;
			for (int i = 0; i < padding; ++i) {
				Node *newNode = new Node('0');
				newNode->next = head;
				if (head) head->prev = newNode;
				head = newNode;
				if (!tail) tail = head;
			}
		}
	}

public:
	DoublyLinkedList() : head(nullptr), tail(nullptr) {}

	~DoublyLinkedList() {
		Node *current = head;
		while (current) {
			Node *nextNode = current->next;
			delete current;
			current = nextNode;
		}
	}

	void createFromDecimal(int decimal) {
		while (head) {
			Node *temp = head;
			head = head->next;
			delete temp;
		}

		tail = nullptr;
		if (decimal == 0) {
			head = new Node('0');
			tail = head;
			return;
		}

		bool first = true;
		while (decimal > 0) {
			char bit = (decimal % 2) ? '1' : '0';
			Node *newNode = new Node(bit);
			if (first) {
				head = newNode;
				tail = newNode;
				first = false;
			} else {
				newNode->next = head;
				head->prev = newNode;
				head = newNode;
			}
			decimal /= 2;
		}

		padToEightBits();
	}

	void display() const {
		Node *current = head;
		while (current) {
			cout << current->data;
			current = current->next;
		}
		cout << endl;
	}

	void onesComplement() {
		Node *current = head;
		while (current) {
			current->data = (current->data == '0') ? '1' : '0';
			current = current->next;
		}
	}

	void twosComplement() {
		onesComplement();

		Node *current = tail;
		bool carry = true;
		while (current && carry) {
			if (current->data == '1') {
				current->data = '0';
			} else {
				current->data = '1';
				carry = false;
			}
			current = current->prev;
		}

		if (carry) {
			Node *newNode = new Node('1');
			newNode->next = head;
			if (head) head->prev = newNode;
			head = newNode;
			if (!tail) tail = head;
		}
	}

	void addBinary(const DoublyLinkedList &other) {
		Node *a = tail;
		Node *b = other.tail;
		Node *result = nullptr;
		Node *resultTail = nullptr;

		int carry = 0;
		while (a || b || carry) {
			int bitA = (a) ? a->data - '0' : 0;
			int bitB = (b) ? b->data - '0' : 0;

			int sum = bitA + bitB + carry;
			carry = sum / 2;
			char resultBit = (sum % 2) + '0';

			Node *newNode = new Node(resultBit);
			if (!result) {
				result = newNode;
				resultTail = result;
			} else {
				newNode->next = result;
				result->prev = newNode;
				result = newNode;
			}

			if (a) a = a->prev;
			if (b) b = b->prev;
		}

		while (head) {
			Node *temp = head;
			head = head->next;
			delete temp;
		}
		head = result;
		tail = resultTail;
		padToEightBits();
	}
};

void createBinaryNumberFromDecimal(DoublyLinkedList &bin) {
	int decimal;
	cout << "Enter a decimal number: ";
	cin >> decimal;
	bin.createFromDecimal(decimal);
}

int main() {
	DoublyLinkedList bin1, bin2;
	cout << "\nMenu:\n";
	cout << "1. Enter Binary Number 1 from Decimal.\n";
	cout << "2. Enter Binary Number 2 from Decimal\n";
	cout << "3. Display Binary Number 1\n";
	cout << "4. Display Binary Number 2\n";
	cout << "5. Compute 1's Complement of Binary Number 1\n";
	cout << "6. Compute 2's Complement of Binary Number 1\n";
	cout << "7. Add Binary Number 1 and Binary Number 2\n";
	cout << "8. Exit\n";
	int choice;
	do {

		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
			case 1: createBinaryNumberFromDecimal(bin1); break;
			case 2: createBinaryNumberFromDecimal(bin2); break;
			case 3:
				cout << "Binary Number 1: ";
				bin1.display();
				break;
			case 4:
				cout << "Binary Number 2: ";
				bin2.display();
				break;
			case 5:
				bin1.onesComplement();
				cout << "1's Complement of Binary Number 1: ";
				bin1.display();
				break;
			case 6:
				bin1.twosComplement();
				cout << "2's Complement of Binary Number 1: ";
				bin1.display();
				break;
			case 7:
				bin1.addBinary(bin2);
				cout << "Sum of Binary Number 1 and Binary Number 2: ";
				bin1.display();
				break;
			case 8: cout << "Exiting...\n"; break;
			default: cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 8);
	return 0;
}
