// * Eshan Nahar
/**
 * Write C++ program to implement translation, rotation and scaling
 * transformations on equilateral triangle and rhombus. Apply the concept of
 * operator overloading
 */

#include <graphics.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

class TRT {
  int x1, y1, x2, y2, x3, y3;
  int rx1, ry1, rx2, ry2, rx3, ry3, rx4, ry4;
  void rotatePoint(int &x, int &y, float angle);

 public:
  // Constructor to initialize coordinates
  TRT() {
    // Triangle coordinates
    x1 = 150;
    y1 = 50;
    x2 = 100;
    y2 = 100;
    x3 = 200;
    y3 = 100;

    // Rhombus coordinates (center at (150, 150))
    rx1 = 150;
    ry1 = 100; // Top
    rx2 = 100;
    ry2 = 150; // Left
    rx3 = 150;
    ry3 = 200; // Bottom
    rx4 = 200;
    ry4 = 150; // Right
  }

  void translate();
  void scale();
  void rotate();
  void draw(int shapeType);
  void drawTriangle();
  void drawRhombus();
};

void TRT::translate() {
  float tx, ty;
  cout << "Enter TX TY: ";
  cin >> tx >> ty;
  x1 += tx;
  y1 += ty;
  x2 += tx;
  y2 += ty;
  x3 += tx;
  y3 += ty;
  rx1 += tx;
  ry1 += ty;
  rx2 += tx;
  ry2 += ty;
  rx3 += tx;
  ry3 += ty;
  rx4 += tx;
  ry4 += ty;
}

void TRT::scale() {
  float sx, sy;
  cout << "Enter SX SY: ";
  cin >> sx >> sy;
  x1 *= sx;
  y1 *= sy;
  x2 *= sx;
  y2 *= sy;
  x3 *= sx;
  y3 *= sy;
  rx1 *= sx;
  ry1 *= sy;
  rx2 *= sx;
  ry2 *= sy;
  rx3 *= sx;
  ry3 *= sy;
  rx4 *= sx;
  ry4 *= sy;
}

void TRT::rotatePoint(int &x, int &y, float angle) {
  int tempX = x;
  x = tempX * cos(angle) - y * sin(angle);
  y = tempX * sin(angle) + y * cos(angle);
};

void TRT::rotate() {
  float deg;
  cout << "Enter rotation angle: ";
  cin >> deg;
  float angle = deg * M_PI / 180;

  // Rotate triangle vertices
  rotatePoint(x1, y1, angle);
  rotatePoint(x2, y2, angle);
  rotatePoint(x3, y3, angle);

  // Rotate rhombus vertices
  rotatePoint(rx1, ry1, angle);
  rotatePoint(rx2, ry2, angle);
  rotatePoint(rx3, ry3, angle);
  rotatePoint(rx4, ry4, angle);
}

void TRT::draw(int shapeType) {
  int gdriver = DETECT, gmode;
  initgraph(&gdriver, &gmode, NULL);
  cleardevice();

  if(shapeType == 1) { // Triangle
    drawTriangle();
  } else { // Rhombus
    drawRhombus();
  }
}

void TRT::drawTriangle() {
  line(x1, y1, x2, y2);
  line(x2, y2, x3, y3);
  line(x3, y3, x1, y1);
}

void TRT::drawRhombus() {
  line(rx1, ry1, rx2, ry2);
  line(rx2, ry2, rx3, ry3);
  line(rx3, ry3, rx4, ry4);
  line(rx4, ry4, rx1, ry1);
}

int main() {
  int option, shapeType;
  cout << "=== Select shape to draw: ===\n1. Triangle\n2. Rhombus\nEnter your "
          "choice: ";
  cin >> shapeType;
  TRT T;
  T.draw(shapeType);
  do {
    cout << "\n1. Translation\n2. Scaling\n3. Rotation\n4. Exit: ";
    cin >> option;
    switch(option) {
      case 1:
        T.translate();
        T.draw(shapeType);
        break;
      case 2:
        T.scale();
        T.draw(shapeType);
        break;
      case 3:
        T.rotate();
        T.draw(shapeType);
        break;
      case 4: break;
      default: cout << "Invalid choice";
    }
  } while(option != 4);

  closegraph();
  return 0;
}
