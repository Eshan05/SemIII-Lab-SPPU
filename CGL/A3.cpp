// * Eshan Nahar
// 3A: Write C++ program to draw the following pattern. Use DDA line and
// Bresenham‘s circle drawing algorithm. Apply the concept of encapsulation.

// #include<bits/stdc++.h>
#include <graphics.h>
#include <iostream>
using namespace std;

/* 8 Way Symmetry Points
 * (x,y)
 * (-x,y)
 * (x,-y)
 * (-x,-y)
 * (y,x)
 * (-y,x)
 * (y,-x)
 * (-y,-x)
 */
class Circle {
 public:
  void draw(int cx, int cy, int r) {
    int x = 0, y = r, d;
    d = 3 - 2 * r;
    while(x <= y) {
      putpixel(cx + x, cy + y, WHITE);
      putpixel(cx - x, cy + y, WHITE);
      putpixel(cx + x, cy - y, WHITE);
      putpixel(cx - x, cy - y, WHITE);
      putpixel(cx + y, cy + x, WHITE);
      putpixel(cx - y, cy + x, WHITE);
      putpixel(cx + y, cy - x, WHITE);
      putpixel(cx - y, cy - x, WHITE);
      if(d <= 0) d += 4 * x + 6;
      else {
        d += 4 * (x - y) + 10;
        y--;
      }
      x++;
    }
  }
  void DDA(float x0, float y0, float x1, float y1) {
    int dx = x1 - x0;
    int dy = y1 - y0;
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
    float X = x0;
    float Y = y0;
    for(int i = 0; i <= steps; i++) {
      putpixel(round(X), round(Y), 111);
      X += Xinc;
      Y += Yinc;
    }
  }
};

int main() {
  int cx, cy, r2;
  Circle circle;
  cout << "Enter coordinates of center:";
  cin >> cx >> cy;
  cout << "Enter radius of outer circle: ";
  cin >> r2;
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);
  circle.draw(cx, cy, r2);
  circle.draw(cx, cy, r2 / 2);
  circle.DDA(cx, cy - r2, cx + 0.865 * r2,
             cy + (r2 / 2)); // Starts from top point goes to right
  circle.DDA(cx, cy - r2, cx - 0.865 * r2,
             cy + (r2 / 2)); // Starts from top point goes to left
  circle.DDA(cx - 0.865 * r2, cy + (r2 / 2), cx + 0.865 * r2,
             cy + (r2 / 2)); // Starts from left point goes to right
  circle.DDA(cx, cy + r2 / 2, cx, cy - r2);
  getch();
  closegraph();
  return 0;
}
