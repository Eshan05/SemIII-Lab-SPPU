// * Eshan Nahar
// Write a C++ program to control a ball using arrow keys. Apply the concept of
// polymorphism

#include <GL/freeglut.h>
#include <cmath>
#include <iostream>

using namespace std;

// Base class
class Shape {
 public:
  virtual void draw() = 0;                   // Pure virtual function
  virtual void move(float dx, float dy) = 0; // Pure virtual function
};

// Derived class
class Ball : public Shape {
 private:
  float x, y; // Ball position
  float radius;

 public:
  Ball(float startX, float startY, float r) : x(startX), y(startY), radius(r) {}

  void draw() override {
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color for the ball
    glVertex2f(x, y);            // Center of the circle
    for(int i = 0; i <= 100; i++) {
      float angle = 2 * 3.14159f * i / 100; // Circle angles
      glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd();
  }

  void move(float dx, float dy) override {
    x += dx;
    y += dy;
  }
};

Ball *ball;

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  ball->draw();
  glutSwapBuffers();
}

void keyPress(int key, int x, int y) {
  switch(key) {
    case GLUT_KEY_UP:
      ball->move(0.0f, 0.1f); // Move up
      break;
    case GLUT_KEY_DOWN:
      ball->move(0.0f, -0.1f); // Move down
      break;
    case GLUT_KEY_LEFT:
      ball->move(-0.1f, 0.0f); // Move left
      break;
    case GLUT_KEY_RIGHT:
      ball->move(0.1f, 0.0f); // Move right
      break;
  }
  glutPostRedisplay(); // Request a redraw
}

void init() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow("Polymorphism Example: Control a Ball");
  init();

  ball = new Ball(0.0f, 0.0f, 0.1f); // Create a ball object

  glutDisplayFunc(display);
  glutSpecialFunc(keyPress);
  glutMainLoop();

  delete ball; // Cleanup
  return 0;
}
