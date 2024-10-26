#include <GL/glut.h>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

// Base class for the puzzle
class Puzzle {
 public:
  virtual void display() = 0; // Pure virtual function for displaying the puzzle
  virtual bool move(int tile) = 0; // Pure virtual function for moving tiles
  virtual bool isSolved() = 0;     // Pure virtual function to check if solved
  virtual int getTile(int x, int y) = 0; // Method to get tile value
};

// Derived class for the 8-puzzle
class EightPuzzle : public Puzzle {
 private:
  vector<vector<int>> board; // 3x3 grid for the puzzle
  int emptyX, emptyY;        // Position of the empty space

 public:
  EightPuzzle(vector<vector<int>> initial) : board(initial) {
    // Find the position of the empty space
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        if(board[i][j] == 0) {
          emptyX = i;
          emptyY = j;
        }
      }
    }
  }

  void display() override {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    float tileSize = 0.3f;
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        float x = j * tileSize - 0.5f;
        float y = 0.5f - i * tileSize;

        if(board[i][j] != 0) {
          glColor3f(0.0f, 0.5f, 0.8f); // Tile color
          glBegin(GL_QUADS);
          glVertex2f(x, y);
          glVertex2f(x + tileSize, y);
          glVertex2f(x + tileSize, y - tileSize);
          glVertex2f(x, y - tileSize);
          glEnd();

          glColor3f(1.0f, 1.0f, 1.0f); // Text color
          glRasterPos2f(x + 0.1f, y - 0.2f);
          glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, '0' + board[i][j]);
        }
      }
    }

    glFlush();
  }

  bool move(int tile) override {
    // Find the position of the tile to move
    int tileX, tileY;
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        if(board[i][j] == tile) {
          tileX = i;
          tileY = j;
        }
      }
    }

    // Check if the move is valid
    if((abs(tileX - emptyX) == 1 && tileY == emptyY) ||
       (abs(tileY - emptyY) == 1 && tileX == emptyX)) {
      // Move the tile
      swap(board[emptyX][emptyY], board[tileX][tileY]);
      emptyX = tileX;
      emptyY = tileY;
      return true;
    }
    return false;
  }

  bool isSolved() override {
    int count = 1;
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
        if(i == 2 && j == 2) {
          // Last tile should be 0 (empty space)
          if(board[i][j] != 0) return false;
        } else {
          if(board[i][j] != count) return false;
          count++;
        }
      }
    }
    return true;
  }

  int getTile(int x, int y) override {
    return board[x][y]; // Get the tile value
  }
};

// Global instance of the puzzle
EightPuzzle *puzzle;

// Function to handle mouse clicks
void mouse(int button, int state, int x, int y) {
  if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    int tileX = y / 100; // Convert mouse position to grid coordinates
    int tileY = x / 100;

    if(tileX < 3 && tileY < 3) {
      puzzle->move(puzzle->getTile(tileX, tileY)); // Move the tile
      if(puzzle->isSolved()) {
        cout << "Congratulations! You've solved the puzzle!" << endl;
      }
    }
    puzzle->display(); // Update display
  }
}

// Initialize OpenGL
void initOpenGL() {
  glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
  glColor3f(0.0f, 0.0f, 0.0f);
}

// Main function
int main(int argc, char **argv) {
  // Initial configuration of the 8-puzzle
  vector<vector<int>> initial = { { 1, 2, 3 }, { 4, 0, 5 }, { 7, 8, 6 } };

  puzzle = new EightPuzzle(initial);

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(300, 300);
  glutCreateWindow("8-Puzzle Game");
  initOpenGL();
  glutDisplayFunc([]() { puzzle->display(); });
  glutMouseFunc(mouse);
  glutMainLoop();

  delete puzzle; // Clean up
  return 0;
}
