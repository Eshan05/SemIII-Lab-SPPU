// * Eshan Nahar
/**
 * 24. WCP to realize Set using Generalized Liked List (GLL)
 * $$A = {a, b, {c, d, e, {}, {f,g}, h, l, {j,k}, l, m}}$$
 * Store and print as set notation
*/

#include <iostream>
#include <string>
#include <vector>

struct Node {
	bool isAtomic;
	std::string value;            // If isAtomic is true
	std::vector<Node *> children; //  If isAtomic is false

	Node(bool atomic, const std::string &val = "")
			: isAtomic(atomic), value(val) {}
};

Node *createAtomicNode(const std::string &value) { return new Node(true, value); }
Node *createEmptyList() { return new Node(false); }

Node *createSubList(const std::vector<std::string> &values) {
	Node *listNode = new Node(false);
	for (const auto &value : values) {
		listNode->children.push_back(createAtomicNode(value));
	}
	return listNode;
}

// Function to add a child to a parent node
void addChild(Node *parent, Node *child) {
	parent->children.push_back(child);
}

// Function to create the set A using GLL
Node *createGLL() {
	Node *root = new Node(false);

	// Atomic elements
	addChild(root, createAtomicNode("a"));
	addChild(root, createAtomicNode("b"));

	// Nested list
	Node *nestedList = new Node(false);
	addChild(nestedList, createAtomicNode("c"));
	addChild(nestedList, createAtomicNode("d"));
	addChild(nestedList, createAtomicNode("e"));
	addChild(nestedList, createEmptyList());
	addChild(nestedList, createSubList({ "f", "g" }));
	addChild(nestedList, createAtomicNode("h"));
	addChild(nestedList, createAtomicNode("l"));
	addChild(nestedList, createSubList({ "j", "k" }));
	addChild(nestedList, createAtomicNode("l"));
	addChild(nestedList, createAtomicNode("m"));

	addChild(root, nestedList);
	return root;
}

// Function to print the GLL structure
std::string printGLL(Node *node) {
	if (node->isAtomic) {
		return node->value;
	} else {
		std::string result = "{";
		for (size_t i = 0; i < node->children.size(); ++i) {
			if (i > 0) { result += ", "; }
			result += printGLL(node->children[i]);
		}
		result += "}";
		return result;
	}
}

// Clean up memory
void deleteGLL(Node *node) {
	if (!node->isAtomic) {
		for (auto child : node->children) {
			deleteGLL(child);
		}
	}
	delete node;
}

int main() {
	Node *gll = createGLL();
	std::cout << printGLL(gll) << std::endl;
	deleteGLL(gll);
	return 0;
}

/**
 * In generalized linked list, each element is either an atom or a list itself. Elements of linear are atomic, elements of linear list can be addressed by it's index/
 * In A = {a, {d,e}, c}
 * H -> a -> h -> c
 * 					 
 * 					 d
 * 					 
 * 					 e
 */