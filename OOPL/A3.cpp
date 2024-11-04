// clang-format off
/** 
 * * Eshan Nahar
 * Imagine a publishing company which does marketing for book and audio cassette versions. Create a class * publication that stores the title (a string) and price (type float) of publications. From this class derive two classes: book which adds a page count (type int) and tape which adds a playing time in minutes (type float). Write a program that instantiates the book and tape class, allows user to enter data and displays the data members. If an exception is caught, replace all the data member values with zero values.
 */
// clang-format on
#include <iostream>
using namespace std;

class Publication {
 protected:
  string title;
  float price;

 public:
  Publication() : title(""), price(0.0f) {} // Constructor with default values
  void setData(const string &t, float p) {
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
  void setData(const string &t, float p, int pc) {
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
  void setData(const string &t, float p, float pt) {
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
  string title;
  float price = 0;
  int pageCount = 0;
  cout << "Enter Book Title: ";
  cin >> title;

  cout << "Enter Book Price: ";
  cin >> price;
  if(price < 0) {
    price = 0;
    cout << "Invalid input for price. Re-enter: ";
    cin >> price;
  }

  cout << "Enter Page Count: ";
  cin >> pageCount;
  if(pageCount < 0) {
    pageCount = 0;
    cout << "Invalid input for page count. Re-enter: ";
    cin >> pageCount;
  }

  book.setData(title, price, pageCount);
  cout << "\n Book Information:" << endl;
  book.display();
}

void createTape() {
  Tape tape;
  string title;
  float price;
  float playingTime;
  cout << "Enter Tape Title: ";
  cin >> title;

  cout << "Enter Tape Price: ";
  cin >> price;
  if(price < 0) {
    price = 0;
    cout << "Invalid input for price. Re-enter: ";
    cin >> price;
  }

  cout << "Enter Playing Time (Minutes): ";
  cin >> playingTime;
  if(playingTime < 0) {
    playingTime = 0;
    cout << "Invalid input for playing time. Re-enter: ";
    cin >> playingTime;
  }

  tape.setData(title, price, playingTime);
  cout << "\n Tape Information:" << endl;
  tape.display();
}

int main() {
  int choice;
  do {
    cout << "===== MENU =====" << endl;
    cout << "  1. Create Book" << endl;
    cout << "  2. Create Tape" << endl;
    cout << "  3. Quit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    switch(choice) {
      case 1: createBook(); break;
      case 2: createTape(); break;
      case 3: cout << "Exiting..." << endl; break;
      default: cout << "Invalid choice" << endl;
    }
  } while(choice != 3);
  return 0;
}
