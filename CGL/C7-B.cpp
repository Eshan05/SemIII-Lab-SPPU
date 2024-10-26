// * Eshan Nahar
// Write a C++ program to implement bouncing ball using sine wave form. Apply
// the concept of polymorphism.

#include <GL/glut.h>
#include <cmath>
#include <iostream>

using namespace std;

// Base class
class Shape {
 public:
  virtual void draw(float elapsedTime) = 0; // Pure virtual function for drawing
};

// Derived class for the bouncing ball
class BouncingBall : public Shape {
 private:
  float radius;

 public:
  BouncingBall(float r) : radius(r) {}

  void draw(float elapsedTime) override {
    float x = 0.0f; // Fixed x position for the ball
    float y =
        0.5f * sin(2.0f * elapsedTime); // Calculate y position using sine wave

    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0f, 0.0f, 0.0f); // Red color for the ball
    glVertex2f(x, y);            // Center of the circle
    for(int i = 0; i <= 100; i++) {
      float angle = 2 * M_PI * i / 100; // Circle angles
      glVertex2f(x + radius * cos(angle), y + radius * sin(angle));
    }
    glEnd();
  }
};

// Function to draw the dynamic sine wave background
void drawDynamicSineWave(float elapsedTime) {
  glBegin(GL_LINE_STRIP);
  glColor3f(0.0f, 1.0f, 0.0f); // Green color for the sine wave
  for(float x = -2.0f; x <= 2.0f; x += 0.05f) {
    float y =
        0.5f * sin(2.0f * (x + elapsedTime)); // Shift the sine wave over time
    glVertex2f(x, y);
  }
  glEnd();
}

BouncingBall *ball;
float elapsedTime = 0.0f;

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  drawDynamicSineWave(elapsedTime);
  ball->draw(elapsedTime);
  glutSwapBuffers();
}

void update(int value) {
  elapsedTime += 0.05f;         // Update elapsed time
  glutPostRedisplay();          // Request a redraw
  glutTimerFunc(25, update, 0); // Call update again after 25 ms
}

void init() {
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background
  glEnable(GL_LINE_SMOOTH);             // Enable line smoothing
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutCreateWindow(
      "Polymorphism Example: Bouncing Ball with Dynamic Sine Wave");
  init();

  ball = new BouncingBall(0.1f); // Create a bouncing ball object

  glutDisplayFunc(display);
  glutTimerFunc(25, update, 0);
  glutMainLoop();

  delete ball; // Cleanup
  return 0;
}
