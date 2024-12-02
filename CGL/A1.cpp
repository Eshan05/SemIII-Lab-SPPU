// * Eshan Nahar
// Write C++ program to draw a concave polygon and fill it with desired color
// using scan fill algorithm. Apply the concept of inheritance.

#include <cstdlib>
#include <graphics.h>
#include <iostream>
using namespace std;

#define MAX_VERTICES 20

class point {
 public:
  int x, y;
};

class poly {
 private:
  point p[MAX_VERTICES];
  int inter[MAX_VERTICES], x, y;
  int v, xmin, ymin, xmax, ymax;

 public:
  int c;
  int read();
  void calcs();
  void display();
  void ints(float);
  void sort(int);
};

int poly::read() {
  int i;
  cout << "\n === Scan Line Fill Algorithm ===";
  cout << "\n Enter the number of vertices of the polygon:";
  cin >> v;
  cout << "Enter " << v << " vertices in order";
  if(v > 2 && v <= MAX_VERTICES) {
    for(i = 0; i < v; i++) {
      cout << "\nEnter the coordinate " << (i + 1) << ": \n";
      cout << "\tx[" << (i + 1) << "] = ";
      cin >> p[i].x;
      cout << "\ty[" << (i + 1) << "] = ";
      cin >> p[i].y;
    }
    p[i].x = p[0].x;
    p[i].y = p[0].y;
    xmin = xmax = p[0].x;
    ymin = ymax = p[0].y;
  } else {
    cout << "Enter valid number of vertices (2 to " << MAX_VERTICES << ").";
    return 0;
  }
  return 1;
}

void poly::calcs() {
  for(int i = 0; i < v; i++) {
    if(xmin > p[i].x) xmin = p[i].x;
    if(xmax < p[i].x) xmax = p[i].x;
    if(ymin > p[i].y) ymin = p[i].y;
    if(ymax < p[i].y) ymax = p[i].y;
  }
}

void poly::display() {
  int ch;
  float s;
  cout << "\n*** List of vertices: ***\n";
  for(int i = 0; i < v; i++)
    cout << "Vertex " << (i + 1) << ": (" << p[i].x << ", " << p[i].y << ")\n";
  do {
    cout << "\n-=-=- MENU: -=-=-";
    cout << "\n1. Scan Line Fill";
    cout << "\n2. Exit ";
    cout << "\n\nEnter your choice: ";
    cin >> ch;
    switch(ch) {
      case 1:
        s = ymin + 0.01;
        delay(100);
        cleardevice();
        while(s <= ymax) {
          ints(s);
          sort(s);
          s++;
        }
        break;
      case 2: exit(0);
      default: cout << "Invalid choice. Please try again.";
    }

    cout << "\nDo you want to continue? (1-2): ";
    cin >> ch;
  } while(ch == 1);
}

void poly::ints(float z) {
  int x1, x2, y1, y2, temp;
  c = 0;
  for(int i = 0; i < v; i++) {
    x1 = p[i].x;
    y1 = p[i].y;
    x2 = p[i + 1].x;
    y2 = p[i + 1].y;
    if(y2 < y1) {
      temp = x1;
      x1 = x2;
      x2 = temp;
      temp = y1;
      y1 = y2;
      y2 = temp;
    }
    if(z <= y2 && z >= y1) {
      if((y1 - y2) == 0) x = x1;
      else {
        x = ((x2 - x1) * (z - y1)) / (y2 - y1);
        x = x + x1;
      }
      if(x <= xmax && x >= xmin) inter[c++] = x;
    }
  }
}

void poly::sort(int z) {
  int temp, j, i;
  for(i = 0; i < v; i++) line(p[i].x, p[i].y, p[i + 1].x, p[i + 1].y);

  delay(100);
  for(i = 0; i < c; i += 2) {
    delay(100);
    line(inter[i], z, inter[i + 1], z);
  }
}

int main() {
  int cl;
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);
  cleardevice();

  poly x;
  if(x.read())
    ;
  else return 0;
  x.calcs();
  cleardevice();
  cout << "\nEnter the fill color: (0 - 15) -> ";
  cin >> cl;
  setcolor(cl);
  x.display();
  closegraph();
  getch();

  return 0;
}