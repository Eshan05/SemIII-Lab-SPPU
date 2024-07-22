#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
/* 8 Way Symmetry Points
 * (x,y)
 * (-x,y)
 * (x,-y)
 * (-x,-y)
 * (y,x)
 * (-y,x)
 * (y,-x)
 * (-y,-x)
 */
class Circle {
public:
	int cx, cy, r;
	void input() {
		cout<<"Enter coordinates of center:";
		cin>>cx>>cy;
		cout<<"Enter radius";
		cin>>r;
	}
	void draw() {
		int x=0, y=r, d;
		d = 3-2*r;
		while(x<=y) {
			putpixel(cx+x, cy+y, 1);
			putpixel(cx-x, cy+y, 1);
			putpixel(cx+x, cy-y, 1);
			putpixel(cx-x, cy-y, 1);
			putpixel(cx+y, cy+x, WHITE);
			putpixel(cx-y, cy+x, 1);
			putpixel(cx+y, cy-x, 1);
			putpixel(cx-y, cy-x, 1);
			if(d<=0) d += 4*x+6;
			else {
				d += 4*(x-y)+10;
				y--;
			} x++;
		}
	}
};

int main() {
	Circle circle;	
	circle.input();
	int gd = DETECT, gm;
	initgraph(&gd, &gm, NULL);
	
	circle.draw();
	getch();
	closegraph();
	return 0;
}
