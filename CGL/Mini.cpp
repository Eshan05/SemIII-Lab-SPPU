// * Eshan Nahar
// Design and implement game / animation clip / Graphics Editor using open
// source graphics library. Make use of maximum features of Object Oriented
// Programming

// Rubik Cube in OpenGL

#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>
using namespace std;

struct cube_rotate {
  GLfloat angle, x, y, z;
};

GLfloat angle, fAspect, cube_size;
GLint rot_x, rot_y, crement, x_0, x_k, y_0, y_k, z_0, z_k, gap, gap_crement;
// cube_rotate cube_rotations[3][3][3];
vector<cube_rotate> cube_rotations[3][3][3];

void load_visualization_parameters(void);

void apply_rotation(GLfloat angle) {
  vector<cube_rotate> face[3][3];
  int index;
  cube_rotate rotation;

  // Copy face to be rotated
  // Apply rotation to face
  for(int i = 0; i < 3; ++i)
    for(int j = 0; j < 3; ++j) {
      index = 2 - j % 3;
      if(x_0 == x_k) {
        rotation = { angle, 1.0, 0.0, 0.0 };
        face[index][i] = cube_rotations[x_k][i][j];
      }

      if(y_0 == y_k) {
        rotation = { angle, 0.0, 1.0, 0.0 };
        face[index][i] = cube_rotations[j][y_k][i];
      }

      if(z_0 == z_k) {
        rotation = { -1 * angle, 0.0, 0.0, 1.0 };
        face[index][i] = cube_rotations[j][i][z_k];
      }

      face[index][i].push_back(rotation);
    }

  // Copy back rotated face
  for(int i = 0; i < 3; ++i)
    for(int j = 0; j < 3; ++j) {
      if(x_0 == x_k) cube_rotations[x_k][i][j] = face[i][j];
      if(y_0 == y_k) cube_rotations[j][y_k][i] = face[i][j];
      if(z_0 == z_k) cube_rotations[j][i][z_k] = face[i][j];
    }
}

// reset face selection parameters
void reset_selected_face() {
  x_0 = 0;
  x_k = 2;
  y_0 = 0;
  y_k = 2;
  z_0 = 0;
  z_k = 2;
}

void set_camera() { gluLookAt(0, 80, 200, 0, 0, 0, 0, 1, 0); }

// Draw a cube
void draw_cube(int x, int y, int z) {
  vector<cube_rotate> lrot = cube_rotations[x][y][z];
  glPushMatrix();

  // Translate to final position
  glTranslatef((x - 1) * cube_size + x * gap, (y - 1) * cube_size + y * gap,
               (z - 1) * cube_size + z * gap);

  // Rotate cube to correct position
  for(int i = lrot.size() - 1; i >= 0; --i)
    glRotatef(lrot[i].angle, lrot[i].x, lrot[i].y, lrot[i].z);

  glColor3f(1.0f, 0.0f, 0.0f);
  glBegin(GL_QUADS);         // Front
  glNormal3f(0.0, 0.0, 1.0); // Face normal
  glVertex3f(cube_size / 2, cube_size / 2, cube_size / 2);
  glVertex3f(-cube_size / 2, cube_size / 2, cube_size / 2);
  glVertex3f(-cube_size / 2, -cube_size / 2, cube_size / 2);
  glVertex3f(cube_size / 2, -cube_size / 2, cube_size / 2);
  glEnd();

  glColor3f(1.0f, 0.5f, 0.0f);
  glBegin(GL_QUADS);          // Back
  glNormal3f(0.0, 0.0, -1.0); // Face normal
  glVertex3f(cube_size / 2, cube_size / 2, -cube_size / 2);
  glVertex3f(cube_size / 2, -cube_size / 2, -cube_size / 2);
  glVertex3f(-cube_size / 2, -cube_size / 2, -cube_size / 2);
  glVertex3f(-cube_size / 2, cube_size / 2, -cube_size / 2);
  glEnd();

  glColor3f(0.0f, 0.0f, 1.0f);
  glBegin(GL_QUADS);          // Left
  glNormal3f(-1.0, 0.0, 0.0); // Face normal
  glVertex3f(-cube_size / 2, cube_size / 2, cube_size / 2);
  glVertex3f(-cube_size / 2, cube_size / 2, -cube_size / 2);
  glVertex3f(-cube_size / 2, -cube_size / 2, -cube_size / 2);
  glVertex3f(-cube_size / 2, -cube_size / 2, cube_size / 2);
  glEnd();

  glColor3f(0.0f, 1.0f, 0.0f);
  glBegin(GL_QUADS);         // Right
  glNormal3f(1.0, 0.0, 0.0); // Face normal
  glVertex3f(cube_size / 2, cube_size / 2, cube_size / 2);
  glVertex3f(cube_size / 2, -cube_size / 2, cube_size / 2);
  glVertex3f(cube_size / 2, -cube_size / 2, -cube_size / 2);
  glVertex3f(cube_size / 2, cube_size / 2, -cube_size / 2);
  glEnd();

  glColor3f(1.0f, 1.0f, 1.0f);
  glBegin(GL_QUADS);         // Top
  glNormal3f(0.0, 1.0, 0.0); // Face normal
  glVertex3f(-cube_size / 2, cube_size / 2, -cube_size / 2);
  glVertex3f(-cube_size / 2, cube_size / 2, cube_size / 2);
  glVertex3f(cube_size / 2, cube_size / 2, cube_size / 2);
  glVertex3f(cube_size / 2, cube_size / 2, -cube_size / 2);
  glEnd();

  glColor3f(1.0f, 1.0f, 0.0f);
  glBegin(GL_QUADS);          // Bottom
  glNormal3f(0.0, -1.0, 0.0); // Face normal
  glVertex3f(-cube_size / 2, -cube_size / 2, -cube_size / 2);
  glVertex3f(cube_size / 2, -cube_size / 2, -cube_size / 2);
  glVertex3f(cube_size / 2, -cube_size / 2, cube_size / 2);
  glVertex3f(-cube_size / 2, -cube_size / 2, cube_size / 2);
  glEnd();

  glPopMatrix();

} // Draw cube function

// Draw function
void draw_func(void) {

  int x = -cube_size, y = -cube_size, z = -cube_size;

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  // Reset transformations
  glLoadIdentity();

  // Set camera position
  set_camera();

  // Apply visualization transformations
  glRotatef(rot_x, 1.0, 0.0, 0.0); // Rotate in y axis
  glRotatef(rot_y, 0.0, 1.0, 0.0); // Rotate in x axis

  for(int i = 0; i < 3; ++i)       // Step through x axis
    for(int j = 0; j < 3; ++j)     // Step through y axis
      for(int k = 0; k < 3; ++k) { // Step through z axis

        // Draw a single cube
        draw_cube(i, j, k);
      }

  // Flush opengl commands
  glutSwapBuffers();
}

// Init rendering parameters
void init_func(void) {

  // Init parameters
  cube_size = 30.0; // Cuboid size
  rot_x = 0.0;      // View rotation x
  rot_y = 0.0;      // View rotation y
  crement = 5;      // Rotation (in/de)crement
  gap = 5;
  gap_crement = 3;
  // Initialize cuboid rotations

  // Init lighting
  GLfloat ambient_lighte[4] = { 0.2, 0.2, 0.2, 1.0 };
  GLfloat diffuse_light[4] = { 0.7, 0.7, 0.7, 1.0 };  // Color
  GLfloat specular_light[4] = { 1.0, 1.0, 1.0, 1.0 }; // Brightness
  GLfloat light_position[4] = { 0.0, 50.0, 50.0, 1.0 };

  // Material brightness capacity
  GLfloat specularity[4] = { 1.0, 1.0, 1.0, 1.0 };
  GLint material_specularity = 60;

  // Black background
  glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

  // Gouraud colorization model
  glShadeModel(GL_SMOOTH);

  // Material reflectability
  glMaterialfv(GL_FRONT, GL_SPECULAR, specularity);
  // Brightness concentration
  glMateriali(GL_FRONT, GL_SHININESS, material_specularity);

  // Activate ambient light
  glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_lighte);

  // Define light parameters
  glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_lighte);
  glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
  glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);

  // Enable changing material color
  glEnable(GL_COLOR_MATERIAL);
  // Enable lighting
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  // Enable depth buffering
  glEnable(GL_DEPTH_TEST);

  angle = 45;
}

// Specify what's shown in the window
void load_visualization_parameters(void) {
  // Specify projection coordinate system
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();

  // Specify projection perspective
  gluPerspective(angle, fAspect, 0.4, 500);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();

  set_camera();
}

void reshape_func(GLsizei w, GLsizei h) {
  // Prevents division by zero
  if(h == 0) h = 1;
  // Viewport size
  glViewport(0, 0, w, h);
  // Aspect ratio
  fAspect = (GLfloat)w / (GLfloat)h;

  load_visualization_parameters();
}

// keyboard function callback
void keyboard_func(unsigned char key, int x, int y) {
  switch(key) {
    case '+': gap += gap_crement; break;
    case '-': gap -= gap_crement; break;
    // view rotation
    // INcrement or DEcrement
    case 'L': // R
    case 'l': rot_y = (rot_y - crement) % 360; break;

    case 'J': // L
    case 'j': rot_y = (rot_y + crement) % 360; break;

    case 'I': // D
    case 'i': rot_x = (rot_x + crement) % 360; break;

    case 'K': // U
    case 'k': rot_x = (rot_x - crement) % 360; break;

    // Cube movements
    // Select cube face
    // x-axis faces
    case 'Q':
    case 'q':
      reset_selected_face();
      x_0 = 0;
      x_k = 0;
      break;

    case 'W':
    case 'w':
      reset_selected_face();
      x_0 = 1;
      x_k = 1;
      break;

    case 'E':
    case 'e':
      reset_selected_face();
      x_0 = 2;
      x_k = 2;
      break;

    // y-axis faces
    case 'A':
    case 'a':
      reset_selected_face();
      y_0 = 0;
      y_k = 0;
      break;

    case 'S':
    case 's':
      reset_selected_face();
      y_0 = 1;
      y_k = 1;
      break;

    case 'D':
    case 'd':
      reset_selected_face();
      y_0 = 2;
      y_k = 2;
      break;

    // z-axis faces
    case 'C':
    case 'c':
      reset_selected_face();
      z_0 = 0;
      z_k = 0;
      break;

    case 'X':
    case 'x':
      reset_selected_face();
      z_0 = 1;
      z_k = 1;
      break;

    case 'Z':
    case 'z':
      reset_selected_face();
      z_0 = 2;
      z_k = 2;
      break;

    // Move selected face
    case 'U': // CC
    case 'u': apply_rotation(-90); break;

    case 'O': // Clockwise
    case 'o':
      apply_rotation(90);
      break;
      // End of cube movements
    default: break;
  }

  glutPostRedisplay();
}

// Mouse function callback
void mouse_func(int button, int state, int x, int y) {
  if(button == GLUT_LEFT_BUTTON)
    if(state == GLUT_DOWN) { // Zoom-in
      if(angle >= 10) angle -= 5;
    }
  if(button == GLUT_RIGHT_BUTTON)
    if(state == GLUT_DOWN) { // Zoom-out
      if(angle <= 130) angle += 5;
    }
  load_visualization_parameters();
  glutPostRedisplay();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(400, 350);
  glutCreateWindow("Visualizacao 3D");
  glutDisplayFunc(draw_func);
  glutReshapeFunc(reshape_func);
  glutMouseFunc(mouse_func);
  glutKeyboardFunc(keyboard_func);
  init_func();
  glutMainLoop();
}