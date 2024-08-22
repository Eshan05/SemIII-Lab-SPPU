#include<bits/stdc++.h>
using namespace std;

class Publication {
  protected:
    string title;
    float price;
  public:
    Publication() : title(""), price(0.0f) {} // Constructor with default values
    void setData(const string& t, float p) {
      title = t;
      price = p;
    }
    // Virtual because we want to override it and use inheritance
    virtual void display() const {
      cout << "Title: " << title << " Price: " << price << endl;
    }
};

class Book : public Publication {
  private:
    int pageCount;
  public:
    Book() : pageCount(0) {}
    void setData(const string& t, float p, int pc) {
      Publication::setData(t, p);
      pageCount = pc;
    }
    void display() const override {
      Publication::display();
      cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication {
  private:
    float playingTime;
  public:
    Tape() : playingTime(0.0f) {}
    void setData(const string& t, float p, float pt) {
      Publication::setData(t, p);
      playingTime = pt;
    }
    void display() const override {
      Publication::display();
      cout << "Playing Time (Minutes): " << playingTime << endl;
    }
};

void createBook() {
  Book book;
  string title; float price; int pageCount;
  cout << "Enter Book Title: ";
  cin >> title;
  cout << "Enter Book Price: ";
  cin >> price;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  // numeric_limits is used to ignore the newline character
  cout << "Enter Page Count: ";
  cin >> pageCount;
  if(cin.fail()) {
    cout << "Invalid Input for page count" << endl;
    return;
  }
  book.setData(title, price, pageCount);
  cout << "\n Book Information:" << endl;
  book.display();
}

void createTape() {
  Tape tape;
  string title; float price; float playingTime;
  cout << "Enter Tape Title: ";
  cin >> title;
  cout << "Enter Tape Price: ";
  cin >> price;
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  cout << "Enter Playing Time (Minutes): ";
  cin >> playingTime;
  if(cin.fail()) {
    cout << "Invalid Input for playing time" << endl;
    return;
  }
  tape.setData(title, price, playingTime);
  cout << "\n Tape Information:" << endl;
  tape.display();
}

int main() {
  int choice;
  do {
    cout << "===== MENU =====" << endl;
    cout << "\t 1. Create Book" << endl;
    cout << "\t 2. Create Tape" << endl;
    cout << "\t 3. Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    switch(choice) {
      case 1:
        createBook();
        break;
      case 2:
        createTape();
        break;
      case 3:
        break;
      default:
        cout << "Invalid choice" << endl;
    }
  } while(choice != 3);
  return 0;
}
