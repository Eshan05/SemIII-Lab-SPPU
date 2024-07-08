#include<graphics.h>
#include<bits/stdc++.h>
using namespace std;

void DDA(int x0, int y0, int x1, int y1, char color) {
  int dx = x1-x0;
  int dy = y1-y0;
  int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
  float Xinc = dx / (float)steps;
  float Yinc = dy / (float)steps;
  float X = x0;
  float Y = y0;
  for(int i=0; i<=steps; i++) {
    putpixel(round(X), round(Y), color);
    X += Xinc;
    Y += Yinc;
  }
}

int main() {
  int tx, ty, bx, by;
  cout<<"Top Coordinates";
  cin>>tx>>ty;
  cout<<"Bottom Coordinates";
  cin>>bx>>by;
  int gd = DETECT, gm;
  initgraph(&gd, &gm, NULL);
  // 50, 50, 150, 150
  int midy = (ty+by)/2;
  int midx = (tx+bx)/2;
  int innerBx = (midx+tx)/2; //innerbLx
  int innerBy = (midy+by)/2; 
  int innerTx = (midx+bx)/2; //innerbRx
  int innerTy = (midy+ty)/2;
  //--
  DDA(tx,ty, bx,by, 111); // Top left
  DDA(bx,ty, bx,by, 111); // Top right
  DDA(bx,by, tx,by, 111); // Bottom right
  DDA(tx,by, tx,ty, 111); // Bottom left
  //
  DDA(tx,midy, midx,by, 111); //Mid of left
  DDA(midx,by, bx,midy, 111); //Mid of bottom
  DDA(bx,midy, midx,ty, 111); //Mid of right
  DDA(midx,ty, tx,midy, 111);
  //
  DDA(innerBx,innerBy, innerTx,innerBy, 111); //South west (Bottom)
  DDA(innerTx,innerBy, innerTx,innerTy, 111); //South east (Right)
  DDA(innerTx,innerTy, innerBx,innerTy, 111);
  DDA(innerBx,innerTy, innerBx,innerBy, 111);
  getch();
  closegraph();
  return 0;
}