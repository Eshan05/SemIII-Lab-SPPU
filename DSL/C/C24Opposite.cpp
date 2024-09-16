#include <cctype>
#include <iostream>
#include <string>
#include <vector>

struct Node {
	bool isAtomic;
	std::string value;
	std::vector<Node *> children;

	Node(bool atomic, const std::string &val = "")
		: isAtomic(atomic), value(val) {}
};


Node *createAtomicNode(const std::string &value) {
	return new Node(true, value);
}

Node *createListNode(const std::vector<Node *> &children) {
	Node *listNode = new Node(false);
	listNode->children = children;
	return listNode;
}

Node *parseGLL(const std::string &str, size_t &pos) {
	std::vector<Node *> children;

	if (str[pos] == '{') {
		++pos;
		while (pos < str.size()) {

			while (std::isspace(str[pos]))
				++pos;

			if (str[pos] == '}') {
				++pos;
				break;
			} else if (str[pos] == '{') {
				children.push_back(parseGLL(str, pos));
			} else {
				std::string value;
				while (str[pos] != ',' && str[pos] != '}' && !std::isspace(str[pos])) {
					value += str[pos++];
				}
				children.push_back(createAtomicNode(value));
			}

			while (str[pos] == ',' || std::isspace(str[pos]))
				++pos;
		}
		return createListNode(children);
	} else {
		throw std::runtime_error("Invalid input format");
	}
}

void printNodeDetails(Node *node, int depth = 0) {
	std::string indent(depth * 2, ' ');
	if (node->isAtomic) {
		std::cout << indent << "Atomic: " << node->value << std::endl;
	} else {
		std::cout << indent << "List:" << std::endl;
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
	std::string input;
	std::cout << "Enter the set in the format: {a, b, {c, d, e, {f, g}, h, l}}: ";
	std::getline(std::cin, input);

	size_t pos = 0;
	try {
		Node *gll = parseGLL(input, pos);
		std::cout << "Parsed GLL structure:" << std::endl;
		printNodeDetails(gll);
		deleteGLL(gll);
	} catch (const std::exception &e) {
		std::cerr << "Error parsing input: " << e.what() << std::endl;
	}

	return 0;
}