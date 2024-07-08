#include<bits/stdc++.h>
#include<graphics.h>

void DDA(int x0, int y0, int x1, int y1) {
  int dx = x1-x0;
  int dy = y1-y0;
  int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

  float Xinc = dx / (float)steps;
  float Yinc = dy / (float)steps;
  float X = x0;
  float Y = y0;
  for(int i=0; i<=steps; i++) {
    putpixel(round(X), round(Y), 111);
    X += Xinc;
    Y += Yinc;
  }
}

int main() {
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);
  DDA(100, 100, 200, 200);
  getch();
  closegraph();
  return 0;
}