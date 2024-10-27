// * Eshan Nahar
// Design and implement game / animation clip / Graphics Editor using open
// source graphics library. Make use of maximum features of Object Oriented
// Programming

// Rubik Cube in OpenGL 3 x 3 x 3

#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>

using namespace std;

struct CubeRotation {
  GLfloat angle, x, y, z;
};

vector<CubeRotation> cube_rotations[3][3][3];
class Cube {
 public:
  GLfloat size;
  vector<CubeRotation> rotations;

  Cube(GLfloat size) : size(size) {}

  void draw(int x, int y, int z, GLfloat gap) {
    glPushMatrix();
    glTranslatef((x - 1) * size + x * gap, (y - 1) * size + y * gap,
                 (z - 1) * size + z * gap);
    for(const auto &rotation : rotations) {
      glRotatef(rotation.angle, rotation.x, rotation.y, rotation.z);
    }
    drawFaces();
    glPopMatrix();
  }

  void addRotation(const CubeRotation &rotation) {
    rotations.push_back(rotation);
  }

 private:
  void drawFaces() {
    // Define colors for each face of the cube
    GLfloat colors[6][3] = {
      { 1.0f, 0.0f, 0.0f }, // Front
      { 1.0f, 0.5f, 0.0f }, // Back
      { 0.0f, 0.0f, 1.0f }, // Left
      { 0.0f, 1.0f, 0.0f }, // Right
      { 1.0f, 1.0f, 0.0f }, // Top
      { 1.0f, 1.0f, 1.0f }  // Bottom
    };

    // Draw the six faces of the cube
    const GLfloat vertices[6][4][3] = {
      { { size / 2, size / 2, size / 2 },
        { -size / 2, size / 2, size / 2 },
        { -size / 2, -size / 2, size / 2 },
        { size / 2, -size / 2, size / 2 } }, // Front
      { { size / 2, size / 2, -size / 2 },
        { size / 2, -size / 2, -size / 2 },
        { -size / 2, -size / 2, -size / 2 },
        { -size / 2, size / 2, -size / 2 } }, // Back
      { { -size / 2, size / 2, size / 2 },
        { -size / 2, size / 2, -size / 2 },
        { -size / 2, -size / 2, -size / 2 },
        { -size / 2, -size / 2, size / 2 } }, // Left
      { { size / 2, size / 2, size / 2 },
        { size / 2, -size / 2, size / 2 },
        { size / 2, -size / 2, -size / 2 },
        { size / 2, size / 2, -size / 2 } }, // Right
      { { -size / 2, size / 2, -size / 2 },
        { -size / 2, size / 2, size / 2 },
        { size / 2, size / 2, size / 2 },
        { size / 2, size / 2, -size / 2 } }, // Top
      { { -size / 2, -size / 2, -size / 2 },
        { size / 2, -size / 2, -size / 2 },
        { size / 2, -size / 2, size / 2 },
        { -size / 2, -size / 2, size / 2 } } // Bottom
    };

    for(int i = 0; i < 6; i++) {
      glColor3f(colors[i][0], colors[i][1], colors[i][2]);
      glBegin(GL_QUADS);
      for(int j = 0; j < 4; j++) {
        glVertex3f(vertices[i][j][0], vertices[i][j][1], vertices[i][j][2]);
      }
      glEnd();
    }
  }
};

class RubiksCube {
 public:
  static const int SIZE = 3;
  Cube *cubes[SIZE][SIZE][SIZE];
  // vector<CubeRotation> cube_rotations[SIZE][SIZE][SIZE];

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
        for(int k = 0; k < SIZE; ++k) cubes[i][j][k]->draw(i, j, k, gap);
  }

  void applyRotation(int x_0, int x_k, int y_0, int y_k, int z_0, int z_k,
                     GLfloat angle) {
    vector<CubeRotation> face[3][3];
    int index;
    CubeRotation rotation;

    cout << "Applying rotation with angle: " << angle << endl;
    cout << "x_0: " << x_0 << ", x_k: " << x_k << ", y_0: " << y_0
         << ", y_k: " << y_k << ", z_0: " << z_0 << ", z_k: " << z_k << endl;

    for(int i = 0; i < 3; ++i)
      for(int j = 0; j < 3; ++j) {
        index = 2 - j % 3;
        cout << "Processing face at i: " << i << ", j: " << j
             << ", index: " << index << endl;

        if(x_0 == x_k) {
          rotation = { angle, 1.0f, 0.0f, 0.0f };
          face[index][i] = cube_rotations[x_k][i][j];
          cout << "Rotating around X axis. Adding rotation: (" << rotation.angle
               << ", " << rotation.x << ", " << rotation.y << ", " << rotation.z
               << ")" << endl;
        }

        if(y_0 == y_k) {
          rotation = { angle, 0.0f, 1.0f, 0.0f };
          face[index][i] = cube_rotations[j][y_k][i];
        }

        if(z_0 == z_k) {
          rotation = { -angle, 0.0f, 0.0f, 1.0f };
          face[index][i] = cube_rotations[j][i][z_k];
        }

        face[index][i].push_back(rotation);
      }

    for(int i = 0; i < 3; ++i)
      for(int j = 0; j < 3; ++j) {
        if(x_0 == x_k) {
          cube_rotations[x_k][i][j] = face[i][j];
          cout << "Updated cube_rotations for X face at (" << x_k << ", " << i
               << ", " << j << ")" << endl;
        }
        if(y_0 == y_k) cube_rotations[j][y_k][i] = face[i][j];
        if(z_0 == z_k) cube_rotations[j][i][z_k] = face[i][j];
      }
  }
};

class Camera {
 public:
  void setCamera() { gluLookAt(0, 80, 200, 0, 0, 0, 0, 1, 0); }
};

class Renderer {
 public:
  GLfloat angle, fAspect, cube_size;
  RubiksCube *rubiksCube;
  Camera *camera;

  GLint rot_x, rot_y, gap, gap_increment;
  int x_0, x_k, y_0, y_k, z_0, z_k;

  Renderer() {
    cube_size = 30.0f;
    rot_x = rot_y = 0;
    gap = 5;
    gap_increment = 3;
    rubiksCube = new RubiksCube(cube_size);
    camera = new Camera();
    angle = 45;
    resetSelectedFace();
  }

  ~Renderer() {
    delete rubiksCube;
    delete camera;
  }

  void initGL() {
    GLfloat ambient_light[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat diffuse_light[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    GLfloat specular_light[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat light_position[] = { 0.0f, 50.0f, 50.0f, 1.0f };
    GLfloat specularity[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specularity);
    glMateriali(GL_FRONT, GL_SHININESS, 60);
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
    glRotatef(rot_x, 1.0f, 0.0f, 0.0f);
    glRotatef(rot_y, 0.0f, 1.0f, 0.0f);
    rubiksCube->draw(gap, rot_x, rot_y);
    glutSwapBuffers();
  }

  void applyRotation(GLfloat angle) {
    rubiksCube->applyRotation(x_0, x_k, y_0, y_k, z_0, z_k, angle);
  }

  void reshape(GLsizei w, GLsizei h) {
    if(h == 0) h = 1;
    glViewport(0, 0, w, h);
    fAspect = (GLfloat)w / (GLfloat)h;
    loadVisualizationParameters();
  }

  void applyKeyboard(unsigned char key, int x, int y) {
    switch(key) {
      case '+': gap += gap_increment; break;
      case '-': gap -= gap_increment; break;
      case 'L': rot_y = (rot_y - 5) % 360; break;
      case 'J': rot_y = (rot_y + 5) % 360; break;
      case 'I': rot_x = (rot_x + 5) % 360; break;
      case 'K': rot_x = (rot_x - 5) % 360; break;

      // Face selection
      case 'Q': selectFace(0, 0); break;
      case 'W': selectFace(1, 1); break;
      case 'E': selectFace(2, 2); break;
      case 'A': selectFace(0, 0, true); break;
      case 'S': selectFace(1, 1, true); break;
      case 'D': selectFace(2, 2, true); break;
      case 'C': selectFace(0, 0, false, true); break;
      case 'X': selectFace(1, 1, false, true); break;
      case 'Z': selectFace(2, 2, false, true); break;

      // Rotation commands
      case 'U': applyRotation(-90); break; // Counter-clockwise
      case 'O': applyRotation(90); break;  // Clockwise
    }
    glutPostRedisplay();
  }

  void selectFace(int face, int index, bool isY = false, bool isZ = false) {
    resetSelectedFace();
    if(isY) {
      y_0 = y_k = index;
      cout << "Selected Y face at index: " << index << endl;
    } else if(isZ) {
      z_0 = z_k = index;
      cout << "Selected Z face at index: " << index << endl;
    } else {
      x_0 = x_k = index;
      cout << "Selected X face at index: " << index << endl;
    }
  }

  void resetSelectedFace() {
    x_0 = x_k = 0;
    y_0 = y_k = 0;
    z_0 = z_k = 0;
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
  glutInitWindowSize(800, 600);
  glutCreateWindow("Rubik's Cube 3D Visualization");
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
