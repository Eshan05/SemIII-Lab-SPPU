#include <iostream>
#include <string>
using namespace std;

struct GLLNode {
  char symbol;
  GLLNode *next;
  GLLNode *down;

  GLLNode(char s) : symbol(s), next(nullptr), down(nullptr) {}
  GLLNode(GLLNode *d) : symbol(' '), next(nullptr), down(d) {}
};

bool IsAlnum(char c) {
  return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') ||
         (c >= 'A' && c <= 'Z');
}

bool IsSpace(char c) {
  return c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' ||
         c == '\f';
}

void printGLLStructure(GLLNode *node, int level = 0) {
  if(node == nullptr) return;
  for(int i = 0; i < level; i++) {
    cout << "  "; // Indentation for nested levels
  }

  if(node->symbol != ' ') { // Atomic element
    cout << "(" << node->symbol << ")" << endl;
  } else { // Sublist (down)
    cout << "[Sublist]: {" << endl;
    printGLLStructure(node->down, level + 1);
    // Recursively print the down sublist
    for(int i = 0; i < level; i++) {
      cout << "  "; // Indentation for closing sublist
    }
    cout << "}" << endl;
  }

  if(node->next != nullptr) {
    for(int i = 0; i < level; i++) {
      cout << "  "; // Indentation for nested next
    }
    cout << "Next: --> ";
    printGLLStructure(node->next, level); // Print the next sibling element
  }
}

GLLNode *addElement(GLLNode *head, GLLNode *element) {
  if(head == nullptr) {
    return element; // If list is empty, return the new element
  }

  GLLNode *current = head;
  while(current->next != nullptr) { current = current->next; }
  current->next = element; //Append
  return head;
}

GLLNode *parseElement(const string &input, size_t &index) {
  char symbol = input[index++];
  return new GLLNode(symbol); // Return atoomic
}

GLLNode *parseSublist(const string &input, size_t &index) {
  index++; // Skip the '{'
  GLLNode *sublist = nullptr;

  while(index < input.size() && input[index] != '}') {
    if(input[index] == '{') {
      GLLNode *nestedSublist =
          parseSublist(input, index); // Parse nested sublist
      sublist = addElement(sublist,
                           new GLLNode(nestedSublist)); // Add to current list
    } else if(IsAlnum(input[index])) {
      GLLNode *element = parseElement(input, index); // Parse atomic element
      sublist = addElement(sublist, element);        // Add atomic to sublist
    } else if(input[index] == ',') {
      index++; // Skip comma separator
    }
    // Skip whitespace
    else if(IsSpace(input[index])) {
      index++;
    }
  }

  index++; // Skip the '}'
  return sublist;
}

GLLNode *parseSet(const string &input, size_t &index) {
  GLLNode *set = nullptr;

  while(index < input.size() && input[index] != '}') {
    if(input[index] == '{') {
      GLLNode *sublist = parseSublist(input, index); // Parse sublist
      set = addElement(set, new GLLNode(sublist)); // Add the sublist to the set
    } else if(IsAlnum(input[index])) {
      GLLNode *element = parseElement(input, index); // Parse atomic element
      set = addElement(set, element); // Add atomic element to set
    } else if(input[index] == ',') {
      index++; // Skip comma separator
    } else if(IsSpace(input[index])) {
      index++;
    }
  }

  return set; // Return the parsed set
}

int main() {
  string input;
  cout << "Enter the set in set notation (e.g., {a, b, {c, d, e, {f,g}, h, l, "
          "{j,k}, l, m}}): ";
  getline(cin, input);
  cout << "Input Set: " << input << endl;

  size_t index = 0;
  GLLNode *parsedSet = parseSet(input, index);
  cout << "\nGLL Structure:" << endl;
  printGLLStructure(parsedSet);
  cout << endl;

  return 0;
}
