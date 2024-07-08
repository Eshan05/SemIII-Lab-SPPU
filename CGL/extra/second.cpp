#include<graphics.h>
#include<bits/stdc++.h>

void bresenham(int x1, int y1, int x2, int y2) {
  int dx=abs(x2-x1);
  int dy=abs(y2-y1);
  int x,y; 
  if(dx>=dy) {
    int d = 2*dy-dx;
    int ds = 2*dy;
    int dt = 2*(dy-dx);
    if(x1<x2) {
      x=x1;
      y=y1;
    } else {
      x = x2;
      y = y2;
      x2 = x1;
      y2 = y1;
    }
    putpixel(x,y, 111);
    while(x<x2) {
      if(d<0)
        d+=ds;
      else {
        if(y<y2) {
          y++;
          d+=dt;
        } else {
          y--;
          d+=dt;
        }
      }
      x++;
      putpixel(x,y, 111);
    }
  } else {
    int d = 2*dx - dy;
    int ds = 2*dx;
    int dt = 2*(dx*dy);
    if(y1<y2) {
      x = x1;
      y = y2;
    } else {
      x = x2;
      y = y2;
      y2 = y1;
      x2 = x1;
    }
    putpixel(x,y, 111);
    while(y<y2) {
      if(d<0)
        d += ds;
      else {
        if(x>x2) {
          x--;
          d+=dt;
        } else {
          x++;
          d+=dt;
        }
      }
      y++;
      putpixel(x,y, 111);
    }
  }
}

void lineBres(int xa,int ya,int xb,int yb) {
  int dx=abs(xa-xb), dy=abs(ya-yb);
  int p = 2*dy-dx;
  int twoDy =2*dy;
  int twoDyDx = 2*(dy-dx);
  int x,y, xEnd;
  if(xa>xb) {
    x=xb;
    y=yb;
  }
  else {
    x=xa;
    y=ya;
    xEnd=xb;
  }
  putpixel(x,y,1);
  while(x<xEnd) {
    x++;
    if(p<0)
    p+=twoDy;
    else {
      y++;
      p+=twoDyDx;
    }
  putpixel(x,y,7);
  }
}

void drawline(int x0, int y0, int x1, int y1) {
  int dx, dy, p, x, y;
  dx = x1 - x0;
  dy = y1 - y0;
  x = x0;
  y = y0;
  p = 2 * dy - dx;
  while (x < x1) {
    if (p >= 0) {
      putpixel(x, y, WHITE);
      y = y + 1;
      p = p + 2 * dy - 2 * dx;
    } else {
      putpixel(x, y, WHITE);
      p = p + 2 * dy;
      }  
    x = x + 1;
    }
}

int main() {
  int gd = DETECT, gm;
  initgraph(&gd,&gm,NULL);
  bresenham(50, 50, 100, 25);
  getch();
  closegraph();
  return 0;
}