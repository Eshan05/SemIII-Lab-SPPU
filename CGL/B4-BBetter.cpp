#include <graphics.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

// Point class to represent 2D points
class Point {
 public:
  int x, y;

  Point(int x = 0, int y = 0) : x(x), y(y) {}

  // Overload the + operator for translation
  Point operator+(const Point &other) {
    return Point(x + other.x, y + other.y);
  }

  // Overload the * operator for scaling
  Point operator*(const float scale) {
    return Point(static_cast<int>(x * scale), static_cast<int>(y * scale));
  }
};

class TRT {
  Point triangle[3]; // Triangle vertices
  Point rhombus[4];  // Rhombus vertices
  void rotatePoint(Point &p, float angle);

 public:
  // Constructor to initialize coordinates
  TRT() {
    // Initialize triangle
    triangle[0] = Point(150, 50);
    triangle[1] = Point(100, 100);
    triangle[2] = Point(200, 100);

    // Initialize rhombus
    rhombus[0] = Point(150, 100); // Top
    rhombus[1] = Point(100, 150); // Left
    rhombus[2] = Point(150, 200); // Bottom
    rhombus[3] = Point(200, 150); // Right
  }

  void translate(const Point &translation);
  void scale(float sx, float sy);
  void rotate();
  void draw(int shapeType);
  void drawTriangle();
  void drawRhombus();
};

void TRT::translate(const Point &translation) {
  for(int i = 0; i < 3; ++i) { triangle[i] = triangle[i] + translation; }
  for(int i = 0; i < 4; ++i) { rhombus[i] = rhombus[i] + translation; }
}

void TRT::scale(float sx, float sy) {
  for(int i = 0; i < 3; ++i) { triangle[i] = triangle[i] * sx; }
  for(int i = 0; i < 4; ++i) { rhombus[i] = rhombus[i] * sx; }
}

void TRT::rotatePoint(Point &p, float angle) {
  int tempX = p.x;
  p.x = tempX * cos(angle) - p.y * sin(angle);
  p.y = tempX * sin(angle) + p.y * cos(angle);
}

void TRT::rotate() {
  float deg;
  cout << "Enter rotation angle: ";
  cin >> deg;
  float angle = deg * M_PI / 180;

  // Rotate triangle vertices
  for(int i = 0; i < 3; ++i) { rotatePoint(triangle[i], angle); }

  // Rotate rhombus vertices
  for(int i = 0; i < 4; ++i) { rotatePoint(rhombus[i], angle); }
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
  line(triangle[0].x, triangle[0].y, triangle[1].x, triangle[1].y);
  line(triangle[1].x, triangle[1].y, triangle[2].x, triangle[2].y);
  line(triangle[2].x, triangle[2].y, triangle[0].x, triangle[0].y);
}

void TRT::drawRhombus() {
  line(rhombus[0].x, rhombus[0].y, rhombus[1].x, rhombus[1].y);
  line(rhombus[1].x, rhombus[1].y, rhombus[2].x, rhombus[2].y);
  line(rhombus[2].x, rhombus[2].y, rhombus[3].x, rhombus[3].y);
  line(rhombus[3].x, rhombus[3].y, rhombus[0].x, rhombus[0].y);
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
      case 1: {
        float tx, ty;
        cout << "Enter TX TY: ";
        cin >> tx >> ty;
        T.translate(Point(tx, ty));
        T.draw(shapeType);
        break;
      }
      case 2: {
        float sx, sy;
        cout << "Enter SX SY: ";
        cin >> sx >> sy;
        T.scale(sx, sy);
        T.draw(shapeType);
        break;
      }
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
