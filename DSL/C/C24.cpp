// * Eshan Nahar
/**
 * 24. WCP to realize Set using Generalized Linked List (GLL)
 * A = {a, b, {c, d, e, {}, {f,g}, h, l, {j,k}, l, m}}
 * Store and print as set notation
*/

#include <iostream>
using namespace std;

struct GLLNode {
  char symbol;
  GLLNode *next;
  GLLNode *down;
  GLLNode(char s) : symbol(s), next(nullptr), down(nullptr) {}
  GLLNode(GLLNode *d) : symbol(' '), next(nullptr), down(d) {}
};

void printGLL(GLLNode *node) {
  if(node == nullptr) return;

  if(node->symbol != ' ') {
    cout << node->symbol;
  } else {
    cout << "{";
    printGLL(node->down); // Recursively print the down sublist
    cout << "}";
  }

  // If there's a next sibling, print a comma and recurse
  if(node->next != nullptr) {
    cout << ", ";
    printGLL(node->next);
  }
}

// Function to add an element to the linked list
GLLNode *addElement(GLLNode *head, GLLNode *element) {
  if(head == nullptr) { return element; }

  GLLNode *current = head;
  while(current->next != nullptr) {
    current = current->next; // Traverse to the last element
  }
  current->next = element; // Add the new element at the end
  return head;
}

GLLNode *createSet() {
  // Create atomic elements
  GLLNode *a = new GLLNode('a');
  GLLNode *b = new GLLNode('b');

  // Create the sublist {c, d, e, {}, {f, g}, h, l, {j, k}, l, m}
  GLLNode *c = new GLLNode('c');
  GLLNode *d = new GLLNode('d');
  GLLNode *e = new GLLNode('e');

  // Create the empty sublist {}
  GLLNode *emptySublist = new GLLNode(nullptr);

  // Create the sublist {f, g}
  GLLNode *f = new GLLNode('f');
  GLLNode *g = new GLLNode('g');
  f->next = g;
  GLLNode *fg = new GLLNode(f); // Sublist {f, g}

  // Create the sublist {j, k}
  GLLNode *j = new GLLNode('j');
  GLLNode *k = new GLLNode('k');
  j->next = k;
  GLLNode *jk = new GLLNode(j); // Sublist {j, k}

  GLLNode *h = new GLLNode('h');
  GLLNode *l1 = new GLLNode('l');
  GLLNode *l2 = new GLLNode('l');
  GLLNode *m = new GLLNode('m');

  // Construct the sublist {c, d, e, {}, {f, g}, h, l, {j, k}, l, m}
  GLLNode *sublist = nullptr;
  sublist = addElement(sublist, c);
  sublist = addElement(sublist, d);
  sublist = addElement(sublist, e);
  sublist = addElement(sublist, emptySublist); //  Empty sublist
  sublist = addElement(sublist, fg);           // Sublist {f, g}
  sublist = addElement(sublist, h);
  sublist = addElement(sublist, l1);
  sublist = addElement(sublist, jk); // Sublist {j, k}
  sublist = addElement(sublist, l2);
  sublist = addElement(sublist, m);

  // Add the sublist to the main set
  GLLNode *mainSet = nullptr;
  mainSet = addElement(mainSet, a);
  mainSet = addElement(mainSet, b);
  mainSet = addElement(mainSet, new GLLNode(sublist)); // add the sublist

  return mainSet;
}

int main() {
  GLLNode *setA = createSet();
  cout << "Set A: ";
  cout << "{";
  printGLL(setA);
  cout << "}";
  cout << endl;
  return 0;
}
