#include <cctype>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node {
	bool isAtomic;
	string value;
	vector<Node *> children;

	Node(bool atomic, const string &val = "")
		: isAtomic(atomic), value(val) {}
};


Node *createAtomicNode(const string &value) {
	return new Node(true, value);
}

Node *createListNode(const vector<Node *> &children) {
	Node *listNode = new Node(false);
	listNode->children = children;
	return listNode;
}

Node *parseGLL(const string &str, size_t &pos) {
	vector<Node *> children;

	if (str[pos] == '{') {
		++pos;
		while (pos < str.size()) {

			while (isspace(str[pos]))
				++pos;

			if (str[pos] == '}') {
				++pos;
				break;
			} else if (str[pos] == '{') {
				children.push_back(parseGLL(str, pos));
			} else {
				string value;
				while (str[pos] != ',' && str[pos] != '}' && !isspace(str[pos])) {
					value += str[pos++];
				}
				children.push_back(createAtomicNode(value));
			}

			while (str[pos] == ',' || isspace(str[pos]))
				++pos;
		}
		return createListNode(children);
	} else {
		throw runtime_error("Invalid input format");
	}
}

void printNodeDetails(Node *node, int depth = 0) {
	string indent(depth * 2, ' ');
	if (node->isAtomic) {
		cout << indent << "Atomic: " << node->value << endl;
	} else {
		cout << indent << "List:" << endl;
		for (const auto &child : node->children) {
			printNodeDetails(child, depth + 1);
		}
	}
}

void deleteGLL(Node *node) {
	if (!node->isAtomic) {
		for (auto child : node->children) {
			deleteGLL(child);
		}
	}
	delete node;
}

int main() {
	string input;
	cout << "Enter the set in the format: {a, b, {c, d, e, {f, g}, h, l}}: ";
	getline(cin, input);

	size_t pos = 0;
	try {
		Node *gll = parseGLL(input, pos);
		cout << "Parsed GLL structure:" << endl;
		printNodeDetails(gll);
		deleteGLL(gll);
	} catch (const exception &e) {
		cerr << "Error parsing input: " << e.what() << endl;
	}

	return 0;
}