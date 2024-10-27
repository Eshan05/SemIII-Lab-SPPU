// * Eshan Nahar
// Design and implement game / animation clip / Graphics Editor using open
// source graphics library. Make use of maximum features of Object Oriented
// Programming

// Rubik Cube in OpenGL 3 x 3 x 3

#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>
using namespace std;

struct cube_rotate {
  GLfloat angle, x, y, z;
};

class Cube {
 public:
  GLfloat size;
  vector<cube_rotate> rotations;

  Cube(GLfloat size) : size(size) {}

  void draw(int x, int y, int z, GLfloat gap) {
    glPushMatrix();
    glTranslatef((x - 1) * size + x * gap, (y - 1) * size + y * gap,
                 (z - 1) * size + z * gap);

    for(int i = rotations.size() - 1; i >= 0; --i)
      glRotatef(rotations[i].angle, rotations[i].x, rotations[i].y,
                rotations[i].z);

    drawFaces();
    glPopMatrix();
  }

  void addRotation(cube_rotate rotation) { rotations.push_back(rotation); }

 private:
  void drawFaces() {
    glColor3f(1.0f, 0.0f, 0.0f); // Front
    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, 1.0);
    glVertex3f(size / 2, size / 2, size / 2);
    glVertex3f(-size / 2, size / 2, size / 2);
    glVertex3f(-size / 2, -size / 2, size / 2);
    glVertex3f(size / 2, -size / 2, size / 2);
    glEnd();

    glColor3f(1.0f, 0.5f, 0.0f); // Back
    glBegin(GL_QUADS);
    glNormal3f(0.0, 0.0, -1.0);
    glVertex3f(size / 2, size / 2, -size / 2);
    glVertex3f(size / 2, -size / 2, -size / 2);
    glVertex3f(-size / 2, -size / 2, -size / 2);
    glVertex3f(-size / 2, size / 2, -size / 2);
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f); // Left
    glBegin(GL_QUADS);
    glNormal3f(-1.0, 0.0, 0.0);
    glVertex3f(-size / 2, size / 2, size / 2);
    glVertex3f(-size / 2, size / 2, -size / 2);
    glVertex3f(-size / 2, -size / 2, -size / 2);
    glVertex3f(-size / 2, -size / 2, size / 2);
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f); // Right
    glBegin(GL_QUADS);
    glNormal3f(1.0, 0.0, 0.0);
    glVertex3f(size / 2, size / 2, size / 2);
    glVertex3f(size / 2, -size / 2, size / 2);
    glVertex3f(size / 2, -size / 2, -size / 2);
    glVertex3f(size / 2, size / 2, -size / 2);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f); // Top
    glBegin(GL_QUADS);
    glNormal3f(0.0, 1.0, 0.0);
    glVertex3f(-size / 2, size / 2, -size / 2);
    glVertex3f(-size / 2, size / 2, size / 2);
    glVertex3f(size / 2, size / 2, size / 2);
    glVertex3f(size / 2, size / 2, -size / 2);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f); // Bottom
    glBegin(GL_QUADS);
    glNormal3f(0.0, -1.0, 0.0);
    glVertex3f(-size / 2, -size / 2, -size / 2);
    glVertex3f(size / 2, -size / 2, -size / 2);
    glVertex3f(size / 2, -size / 2, size / 2);
    glVertex3f(-size / 2, -size / 2, size / 2);
    glEnd();
  }
};

class RubiksCube {
 public:
  static const int SIZE = 3;
  Cube *cubes[SIZE][SIZE][SIZE];
  vector<cube_rotate> cube_rotations[SIZE][SIZE][SIZE];

  RubiksCube(GLfloat cubeSize) {
    for(int i = 0; i < SIZE; ++i)
      for(int j = 0; j < SIZE; ++j)
        for(int k = 0; k < SIZE; ++k) cubes[i][j][k] = new Cube(cubeSize);
  }

  ~RubiksCube() {
    for(int i = 0; i < SIZE; ++i)
      for(int j = 0; j < SIZE; ++j)
        for(int k = 0; k < SIZE; ++k) delete cubes[i][j][k];
  }

  void draw(GLfloat gap, GLint rot_x, GLint rot_y) {
    for(int i = 0; i < SIZE; ++i)
      for(int j = 0; j < SIZE; ++j)
        for(int k = 0; k < SIZE; ++k) { cubes[i][j][k]->draw(i, j, k, gap); }
  }

  void applyRotation(int x_0, int x_k, int y_0, int y_k, int z_0, int z_k,
                     GLfloat angle) {
    vector<cube_rotate> face[3][3];
    int index;
    cube_rotate rotation;

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

    for(int i = 0; i < 3; ++i)
      for(int j = 0; j < 3; ++j) {
        if(x_0 == x_k) cube_rotations[x_k][i][j] = face[i][j];
        if(y_0 == y_k) cube_rotations[j][y_k][i] = face[i][j];
        if(z_0 == z_k) cube_rotations[j][i][z_k] = face[i][j];
      }
  }

  void resetSelectedFace(GLint &x_0, GLint &x_k, GLint &y_0, GLint &y_k,
                         GLint &z_0, GLint &z_k) {
    x_0 = 0;
    x_k = 2;
    y_0 = 0;
    y_k = 2;
    z_0 = 0;
    z_k = 2;
  }
};

class Camera {
 public:
  void setCamera() { gluLookAt(0, 80, 200, 0, 0, 0, 0, 1, 0); }
};

class Renderer {
 public:
  GLfloat angle, fAspect, cube_size;
  GLint rot_x, rot_y, crement, gap, gap_crement;
  RubiksCube *rubiksCube;
  Camera *camera;

  Renderer() {
    cube_size = 30.0;
    rot_x = 0;
    rot_y = 0;
    crement = 5;
    gap = 5;
    gap_crement = 3;
    rubiksCube = new RubiksCube(cube_size);
    camera = new Camera();
    angle = 45;
  }

  ~Renderer() {
    delete rubiksCube;
    delete camera;
  }

  void initGL() {
    GLfloat ambient_light[4] = { 0.2, 0.2, 0.2, 1.0 };
    GLfloat diffuse_light[4] = { 0.7, 0.7, 0.7, 1.0 };
    GLfloat specular_light[4] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[4] = { 0.0, 50.0, 50.0, 1.0 };
    GLfloat specularity[4] = { 1.0, 1.0, 1.0, 1.0 };
    GLint material_specularity = 60;

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularity);
    glMateriali(GL_FRONT, GL_SHININESS, material_specularity);
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
  }

  void loadVisualizationParameters() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(angle, fAspect, 0.4, 500);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    camera->setCamera();
  }

  void draw() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    loadVisualizationParameters();
    glRotatef(rot_x, 1.0, 0.0, 0.0);
    glRotatef(rot_y, 0.0, 1.0, 0.0);
    rubiksCube->draw(gap, rot_x, rot_y);
    glutSwapBuffers();
  }

  void reshape(GLsizei w, GLsizei h) {
    if(h == 0) h = 1;
    glViewport(0, 0, w, h);
    fAspect = (GLfloat)w / (GLfloat)h;
    loadVisualizationParameters();
  }

  void applyKeyboard(unsigned char key, int x, int y) {
    switch(key) {
      case '+': gap += gap_crement; break;
      case '-': gap -= gap_crement; break;
      case 'L': rot_y = (rot_y - crement) % 360; break;
      case 'J': rot_y = (rot_y + crement) % 360; break;
      case 'I': rot_x = (rot_x + crement) % 360; break;
      case 'K':
        rot_x = (rot_x - crement) % 360;
        break;
        // Cube movements
        handleCubeMovement(key);
      default: break;
    }
    glutPostRedisplay();
  }

  void handleCubeMovement(unsigned char key) {
    static GLint x_0, x_k, y_0, y_k, z_0, z_k;

    // Reset face selection
    rubiksCube->resetSelectedFace(x_0, x_k, y_0, y_k, z_0, z_k);

    switch(key) {
      // X-axis faces
      case 'Q':
      case 'q':
        x_0 = 0;
        x_k = 0;
        break;
      case 'W':
      case 'w':
        x_0 = 1;
        x_k = 1;
        break;
      case 'E':
      case 'e':
        x_0 = 2;
        x_k = 2;
        break;

      // Y-axis faces
      case 'A':
      case 'a':
        y_0 = 0;
        y_k = 0;
        break;
      case 'S':
      case 's':
        y_0 = 1;
        y_k = 1;
        break;
      case 'D':
      case 'd':
        y_0 = 2;
        y_k = 2;
        break;

      // Z-axis faces
      case 'C':
      case 'c':
        z_0 = 0;
        z_k = 0;
        break;
      case 'X':
      case 'x':
        z_0 = 1;
        z_k = 1;
        break;
      case 'Z':
      case 'z':
        z_0 = 2;
        z_k = 2;
        break;

      // Move selected face
      case 'U': // CC
      case 'u':
        rubiksCube->applyRotation(x_0, x_k, y_0, y_k, z_0, z_k, -90);
        break;
      case 'O': // Clockwise
      case 'o':
        rubiksCube->applyRotation(x_0, x_k, y_0, y_k, z_0, z_k, 90);
        break;

      default: break;
    }
  }
  void handleMouse(int button, int state) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
      if(angle >= 10) angle -= 5;
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
      if(angle <= 130) angle += 5;
    }
    loadVisualizationParameters();
    glutPostRedisplay();
  }
};

Renderer *renderer;

void draw_func() { renderer->draw(); }

void reshape_func(GLsizei w, GLsizei h) { renderer->reshape(w, h); }

void keyboard_func(unsigned char key, int x, int y) {
  renderer->applyKeyboard(key, x, y);
}

void mouse_func(int button, int state, int x, int y) {
  renderer->handleMouse(button, state);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(400, 350);
  glutCreateWindow("Visualizacao 3D");
  renderer = new Renderer();
  renderer->initGL();
  glutDisplayFunc(draw_func);
  glutReshapeFunc(reshape_func);
  glutMouseFunc(mouse_func);
  glutKeyboardFunc(keyboard_func);
  glutMainLoop();
  delete renderer;
  return 0;
}
