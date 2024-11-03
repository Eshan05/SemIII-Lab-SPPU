// * Eshan Nahar
/**
 * Write C++ program to draw 3-D cube and perform following transformations on
 * it using OpenGL i) Scaling ii) Translation iii) Rotation about an axis
 * (X/Y/Z)
 */

#include <GL/freeglut.h>
#include <algorithm>
using namespace std;

float tx = 0.0, ty = 0.0, tz = -10.0; // Translation parameters
float angleX = 0.0;                   // X-axis rotation angle
float angleY = -45.0;                 // Rotation angle
float angleZ = 0.0;                   // Z-axis rotation angle
float sx = 1.0, sy = 1.0, sz = 1.0;   // Scaling factors

void mydisplay() {
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity(); // Reset modelview matrix

  // Apply transformations
  glTranslatef(tx, ty, tz);
  glScalef(sx, sy, sz);             // Apply scaling
  glRotatef(angleX, 1.0, 0.0, 0.0); // Rotate around X-axis
  glRotatef(angleY, 0.0, 1.0, 0.0); // Rotate around Y-axis
  glRotatef(angleZ, 0.0, 0.0, 1.0); // Rotate around Z-axis

  glBegin(GL_QUADS);
  // front (red)
  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(-1.0, 1.0, 1.0);
  glVertex3f(-1.0, -1.0, 1.0);
  glVertex3f(1.0, -1.0, 1.0);
  glVertex3f(1.0, 1.0, 1.0);

  // back (green)
  glColor3f(0.0, 1.0, 0.0);
  glVertex3f(1.0, 1.0, -1.0);
  glVertex3f(1.0, -1.0, -1.0);
  glVertex3f(-1.0, -1.0, -1.0);
  glVertex3f(-1.0, 1.0, -1.0);

  // right (blue)
  glColor3f(0.0, 0.0, 1.0);
  glVertex3f(1.0, 1.0, 1.0);
  glVertex3f(1.0, -1.0, 1.0);
  glVertex3f(1.0, -1.0, -1.0);
  glVertex3f(1.0, 1.0, -1.0);

  // left (yellow)
  glColor3f(1.0, 1.0, 0.0);
  glVertex3f(-1.0, 1.0, -1.0);
  glVertex3f(-1.0, -1.0, -1.0);
  glVertex3f(-1.0, -1.0, 1.0);
  glVertex3f(-1.0, 1.0, 1.0);

  // top (cyan)
  glColor3f(0.0, 1.0, 1.0);
  glVertex3f(-1.0, 1.0, -1.0);
  glVertex3f(-1.0, 1.0, 1.0);
  glVertex3f(1.0, 1.0, 1.0);
  glVertex3f(1.0, 1.0, -1.0);

  // bottom (magenta)
  glColor3f(1.0, 0.0, 1.0);
  glVertex3f(-1.0, -1.0, -1.0);
  glVertex3f(-1.0, -1.0, 1.0);
  glVertex3f(1.0, -1.0, 1.0);
  glVertex3f(1.0, -1.0, -1.0);

  glEnd();

  glFlush();
}

void keyboard(unsigned char key, int x, int y) {
  switch(key) {
    case 'w': ty += 0.1; break;     // Move up
    case 's': ty -= 0.1; break;     // Move down
    case 'a': tx -= 0.1; break;     // Move left
    case 'd': tx += 0.1; break;     // Move right
    case 'q': angleY += 5.0; break; // Rotate Y left
    case 'e': angleY -= 5.0; break; // Rotate Y right
    case 'r': angleX += 5.0; break; // Rotate X forward
    case 'f': angleX -= 5.0; break; // Rotate X backward
    case 't': angleZ += 5.0; break; // Rotate Z clockwise
    case 'g': angleZ -= 5.0; break; // Rotate Z counterclockwise
    case 'z':
      sx += 0.1;
      sy += 0.1;
      sz += 0.1;
      break;
    case 'x':
      sx = std::max(0.1f, sx - 0.1f);
      sy = std::max(0.1f, sy - 0.1f);
      sz = std::max(0.1f, sz - 0.1f);
      break;                 // Scale down
    case 27: exit(0); break; // ESC key to exit
  }
  glutPostRedisplay(); // Redraw the scene
}

void init() {
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glEnable(GL_DEPTH_TEST);
}

void reshape(int w, int h) {
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity(); // Resets projection matrix
  gluPerspective(60, 1, 2.0, 50.0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(500, 500);
  glutCreateWindow("3D transformations");
  glutDisplayFunc(mydisplay);
  glutReshapeFunc(reshape);
  glutKeyboardFunc(keyboard); // Register keyboard callback
  init();
  glutMainLoop();
}
