#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <vector>

using namespace std;

struct CubeRotation {
  GLfloat angle, x, y, z;
};

class Camera {
 public:
  void setCamera() { gluLookAt(0, 80, 200, 0, 0, 0, 0, 1, 0); }
};

class Cube {
 public:
  GLfloat size;
  vector<CubeRotation> rotations;

  Cube(GLfloat size) : size(size) {}

  void draw(int x, int y, int z, GLfloat gap) {
    glPushMatrix();
    glTranslatef((x - 1) * size + x * gap, (y - 1) * size + y * gap,
                 (z - 1) * size + z * gap);

    // Apply rotations in reverse order to achieve correct visual output
    for(auto it = rotations.rbegin(); it != rotations.rend(); ++it) {
      glRotatef(it->angle, it->x, it->y, it->z);
    }

    drawFaces();
    glPopMatrix();
  }

  void addRotation(const CubeRotation &rotation) {
    rotations.push_back(rotation);
  }

 private:
  void drawFaces() {
    GLfloat colors[6][3] = {
      { 1.0f, 0.0f, 0.0f }, // Front
      { 1.0f, 0.5f, 0.0f }, // Back
      { 0.0f, 0.0f, 1.0f }, // Left
      { 0.0f, 1.0f, 0.0f }, // Right
      { 1.0f, 1.0f, 0.0f }, // Top
      { 1.0f, 1.0f, 1.0f }  // Bottom
    };

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

class RubiksCubeRenderer {
 public:
  static const int SIZE = 3;
  Cube *cubes[SIZE][SIZE][SIZE];
  vector<CubeRotation> cube_rotations[SIZE][SIZE][SIZE];

  GLfloat angle;
  GLfloat fAspect;
  GLfloat cube_size;
  Camera *camera;
  GLint rot_x, rot_y, x_0, x_k, y_0, y_k, z_0, z_k;
  GLint gap;
  GLint gap_increment;

  RubiksCubeRenderer(GLfloat cubeSize) {
    cube_size = cubeSize;
    rot_x = rot_y = 0;
    gap = 3;
    gap_increment = 2;
    camera = new Camera();
    angle = 45;
    resetSelectedFace();

    // Initialize cubes
    for(int i = 0; i < SIZE; ++i)
      for(int j = 0; j < SIZE; ++j)
        for(int k = 0; k < SIZE; ++k) cubes[i][j][k] = new Cube(cubeSize);
  }

  ~RubiksCubeRenderer() {
    for(int i = 0; i < SIZE; ++i)
      for(int j = 0; j < SIZE; ++j)
        for(int k = 0; k < SIZE; ++k) delete cubes[i][j][k];
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
    camera->setCamera();
    glRotatef(rot_x, 1.0, 0.0, 0.0);
    glRotatef(rot_y, 0.0, 1.0, 0.0);

    // Draw each cube
    for(int i = 0; i < SIZE; ++i)
      for(int j = 0; j < SIZE; ++j)
        for(int k = 0; k < SIZE; ++k) cubes[i][j][k]->draw(i, j, k, gap);

    glutSwapBuffers();
  }

  void applyRotation(GLfloat angle) {
    vector<CubeRotation> faceRotations;

    cout << "Rotating face: " << x_0 << " " << x_k << " " << y_0 << " " << y_k
         << " " << z_0 << " " << z_k << endl;

    if(x_0 == x_k) {
      for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
          CubeRotation rotation = { angle, 1.0, 0.0, 0.0 }; // Rotate around X
          cubes[x_k][i][j]->addRotation(rotation);
        }
      }
    } else if(y_0 == y_k) {
      for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
          CubeRotation rotation = { angle, 0.0, 1.0, 0.0 }; // Rotate around Y
          cubes[j][y_k][i]->addRotation(rotation);
        }
      }
    } else if(z_0 == z_k) {
      for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
          CubeRotation rotation = { -angle, 0.0, 0.0, 1.0 }; // Rotate around Z
          cubes[j][i][z_k]->addRotation(rotation);
        }
      }
    }

    // Print out cube_rotations for debugging
    for(int i = 0; i < SIZE; ++i) {
      for(int j = 0; j < SIZE; ++j) {
        for(int k = 0; k < SIZE; ++k) {
          cout << "Cube at (" << i << ", " << j << ", " << k << "): ";
          for(const auto &rot : cubes[i][j][k]->rotations) {
            cout << "[" << rot.angle << ", " << rot.x << ", " << rot.y << ", "
                 << rot.z << "] ";
          }
          cout << endl;
        }
      }
    }
  }

  void applyKeyboard(unsigned char key, int x, int y) {
    switch(key) {
      case '+': gap += gap_increment; break;
      case '-': gap -= gap_increment; break;
      case 'L': rot_y = (rot_y - 5) % 360; break;
      case 'J': rot_y = (rot_y + 5) % 360; break;
      case 'I': rot_x = (rot_x + 5) % 360; break;
      case 'K': rot_x = (rot_x - 5) % 360; break;
      case 'Q': selectFace(0, 0); break;
      case 'W': selectFace(1, 1); break;
      case 'E': selectFace(2, 2); break;
      case 'A': selectFace(0, 0, true); break;
      case 'S': selectFace(1, 1, true); break;
      case 'D': selectFace(2, 2, true); break;
      case 'C': selectFace(0, 0, false, true); break;
      case 'X': selectFace(1, 1, false, true); break;
      case 'Z': selectFace(2, 2, false, true); break;
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
    x_0 = 0;
    x_k = 2;
    y_0 = 0;
    y_k = 2;
    z_0 = 0;
    z_k = 2;
  }

  void handleMouse(int button, int state, int x, int y) {
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

RubiksCubeRenderer *renderer;

void draw_func() { renderer->draw(); }

void reshape_func(GLsizei w, GLsizei h) {
  if(h == 0) h = 1;
  glViewport(0, 0, w, h);
  renderer->fAspect = (GLfloat)w / (GLfloat)h;
  renderer->loadVisualizationParameters();
}

void keyboard_func(unsigned char key, int x, int y) {
  renderer->applyKeyboard(key, x, y);
}

void mouse_func(int button, int state, int x, int y) {
  renderer->handleMouse(button, state, x, y);
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
  glutInitWindowSize(800, 600);
  glutCreateWindow("Rubik's Cube 3D Visualization");
  renderer = new RubiksCubeRenderer(30.0f);
  renderer->initGL();
  glutDisplayFunc(draw_func);
  glutReshapeFunc(reshape_func);
  glutMouseFunc(mouse_func);
  glutKeyboardFunc(keyboard_func);
  glutMainLoop();
  delete renderer;
  return 0;
}
