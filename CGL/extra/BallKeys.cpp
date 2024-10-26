#include <conio.h> // For getch()
#include <graphics.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

// Base class
class Shape {
 public:
  virtual void draw(int x, int y) = 0;   // Pure virtual function
  virtual void move(int &x, int &y) = 0; // Pure virtual function
};

// Derived class
class Ball : public Shape {
 private:
  int radius;

 public:
  Ball(int r) : radius(r) {}

  void draw(int x, int y) override {
    // Draw the ball using the graphics library
    setcolor(WHITE);
    circle(x, y, radius);
    floodfill(x, y, WHITE);
  }

  void move(int &x, int &y) override {
    if(GetAsyncKeyState(VK_UP)) {
      y -= 5; // Move up
    }
    if(GetAsyncKeyState(VK_DOWN)) {
      y += 5; // Move down
    }
    if(GetAsyncKeyState(VK_LEFT)) {
      x -= 5; // Move left
    }
    if(GetAsyncKeyState(VK_RIGHT)) {
      x += 5; // Move right
    }
  }
};

int main() {
  int gdriver = DETECT, gmode;
  initgraph(&gdriver, &gmode, NULL);

  // Initial position of the ball
  int x = getmaxx() / 2;
  int y = getmaxy() / 2;

  Ball ball(20); // Create a ball with radius 20

  while(true) {
    // Clear the screen
    cleardevice();

    // Draw the ball
    ball.draw(x, y);

    // Move the ball based on key presses
    ball.move(x, y);

    // Delay for smooth movement
    delay(30);

    // Check for exit key (Esc)
    if(GetAsyncKeyState(VK_ESCAPE)) { break; }
  }

  closegraph();
  return 0;
}
