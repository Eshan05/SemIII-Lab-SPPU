// * Eshan Nahar
// 21. WCP for storing appointment schedule for day. Appointments are booked
// randomly using linked list. Set start and end time and min and max duration
// for visit slot. Write functions for

//   A) Display free slots
//   B) Book appointment
//   C) Sort list based on time
//   D) Cancel appointment (Check validity, time bounds, availability)
//   E) Sort list based on time using pointer manipulation

#include <iostream>
#include <string>

using namespace std;

class Appointment {
 public:
  int startHour;
  int startMinute;
  int endHour;
  int endMinute;
  string id;
  Appointment *next;

  Appointment(int sh, int sm, int eh, int em, string i)
      : startHour(sh), startMinute(sm), endHour(eh), endMinute(em), id(i),
        next(nullptr) {}
};

class AppointmentList {
 public:
  Appointment *head;
  AppointmentList() : head(nullptr) {}
  void create_Shed() { cout << "Default appointment schedule created.\n"; }

  void display_Shed() {
    int dayStartHour = 9;
    int dayStartMinute = 0;
    int dayEndHour = 17;
    int dayEndMinute = 0;
    displayAppointments(dayStartHour, dayStartMinute, dayEndHour, dayEndMinute);
  }

  void displayAppointments(int dayStartHour, int dayStartMinute, int dayEndHour,
                           int dayEndMinute) {
    Appointment *current = head;
    int prevEndHour = dayStartHour;
    int prevEndMinute = dayStartMinute;
    while(current) {
      if(current->startHour > prevEndHour ||
         (current->startHour == prevEndHour &&
          current->startMinute > prevEndMinute)) {
        cout << "Free slot: " << formatTime(prevEndHour, prevEndMinute)
             << " to " << formatTime(current->startHour, current->startMinute)
             << endl;
      }
      // Show booked slot with ID
      cout << "Slot (" << current->id
           << "): " << formatTime(current->startHour, current->startMinute)
           << " to " << formatTime(current->endHour, current->endMinute)
           << endl;

      prevEndHour = current->endHour;
      prevEndMinute = current->endMinute;
      current = current->next;
    }
    if(prevEndHour < dayEndHour ||
       (prevEndHour == dayEndHour && prevEndMinute < dayEndMinute)) {
      cout << "Free slot: " << formatTime(prevEndHour, prevEndMinute) << " to "
           << formatTime(dayEndHour, dayEndMinute) << endl;
    }
  }

  string formatTime(int hour, int minute) {
    return (hour < 10 ? "0" : "") + to_string(hour) + ":" +
           (minute < 10 ? "0" : "") + to_string(minute);
  }

  void book_App() {
    int startHour, startMinute, endHour, endMinute;
    string id;

    cout << "Enter appointment start time (hour minute): ";
    cin >> startHour >> startMinute;
    cout << "Enter appointment end time (hour minute): ";
    cin >> endHour >> endMinute;
    cout << "Enter your ID: ";
    cin >> id;

    if(endHour < startHour ||
       (endHour == startHour && endMinute <= startMinute)) {
      cout << "Invalid appointment duration.\n";
      return;
    }

    Appointment *newApp =
        new Appointment(startHour, startMinute, endHour, endMinute, id);
    if(!head || compareAppointments(newApp, head) < 0) {
      newApp->next = head;
      head = newApp;
      cout << "Appointment booked.\n";
      return;
    }

    Appointment *current = head;
    while(current->next && compareAppointments(newApp, current->next) >= 0)
      current = current->next;

    newApp->next = current->next;
    current->next = newApp;
    cout << "Appointment booked.\n";
  }

  void cancel_App() {
    int startHour, startMinute, endHour, endMinute;
    string id;

    cout << "Enter appointment start time (hour minute): ";
    cin >> startHour >> startMinute;
    cout << "Enter appointment end time (hour minute): ";
    cin >> endHour >> endMinute;
    cout << "Enter your ID: ";
    cin >> id;

    if(startHour < 9 || startHour >= 17 ||
       (startHour == 17 && startMinute > 0)) {
      cout << "Invalid appointment time.\n";
      return;
    }

    Appointment *current = head;
    Appointment *previous = nullptr;
    while(current && !(current->startHour == startHour &&
                       current->startMinute == startMinute &&
                       current->endHour == endHour &&
                       current->endMinute == endMinute && current->id == id)) {
      previous = current;
      current = current->next;
    }

    if(current) {
      if(previous) previous->next = current->next;
      else head = current->next;
      delete current;
      cout << "Appointment canceled.\n";
    } else {
      cout << "Appointment not found.\n";
    }
  }

  void sort_App() { sortAppointmentsByTime(); }
  void sortAppointmentsByTime() {
    if(!head || !head->next) return;

    Appointment *sorted = nullptr;
    Appointment *current = head;

    while(current) {
      Appointment *next = current->next;
      if(!sorted || compareAppointments(current, sorted) < 0) {
        current->next = sorted;
        sorted = current;
      } else {
        Appointment *temp = sorted;
        while(temp->next && compareAppointments(current, temp->next) >= 0) {
          temp = temp->next;
        }
        current->next = temp->next;
        temp->next = current;
      }
      current = next;
    }
    head = sorted;
  }

 private:
  int compareAppointments(Appointment *a, Appointment *b) {
    if(a->startHour != b->startHour) return a->startHour - b->startHour;
    return a->startMinute - b->startMinute;
  }
};

int main() {
  AppointmentList A1;
  int ch;
  while(true) {
    cout << "\n\n *** Menu ***";
    cout << "\n 1. Create Appointment Schedule";
    cout << "\n 2. Display Free Slots";
    cout << "\n 3. Book an Appointment";
    cout << "\n 4. Cancel an Appointment";
    cout << "\n 5. Sort Slots Based on Time";
    cout << "\n 0. Exit";
    cout << "\n\n\-> Enter your choice: ";
    cin >> ch;
    switch(ch) {
      case 1: A1.create_Shed(); break;
      case 2: A1.display_Shed(); break;
      case 3: A1.book_App(); break;
      case 4: A1.cancel_App(); break;
      case 5: A1.sort_App(); break;
      case 0: cout << "Exiting..." << endl; return 0;
      default: cout << "\n\t Wrong choice!!!\n"; break;
    }
  }
}
