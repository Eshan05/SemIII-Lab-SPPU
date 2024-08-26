#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;


/*
 *	1001 | 1000 | 1010
 *	------------------
 *	0001 | 0000 | 0010
 *	------------------
 *  0101 | 0100 | 0110
 *
 * Above : First bit
 * Below: Second bit
 * Right: Third bit
 * Left: Last bit
 */

static int LEFT=1, RIGHT=2, BOTTOM=4, TOP=8, xmin, ymin, xmax, ymax;
int getcode(int x, int y) {
	int code = 0;
	// OR
	if(y > ymax) code |= TOP;
	if(y < ymin) code |= BOTTOM;
	if(x < xmin) code |= LEFT;
	if(x > xmax) code |= RIGHT;
	return code;
}

int main() {
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	setcolor(WHITE);
	cout << "Enter top left coordinates of window";
	cin >> xmin >> ymin;
	cout << "Enter bottom right coordinates of window";
	cin >> xmax >> ymax;
	int x1, y1, x2, y2;
	cout << "Enter initial points of line";
	cin >> x1 >> y1;
	cout << "Enter final points of line";
	cin >> x2 >> y2;
	rectangle(xmin, ymin, xmax, ymax);
	line(x1, y1, x2, y2);
	delay(5000);
	int code1 = getcode(x1, y1);
	int code2 = getcode(x2, y2);
	int accept = 0;
	while(1) {
		float m = (float)(y2-y1)/(x2-x1);
		if(code1 == 0 && code2 == 0) { accept = 1; break; }
		else if ((code1 & code2) != 0) break;
		else {
			int x=0, y=0, temp;
			if(code1 != 0) temp = code1;
			else temp = code2;
			if (temp & TOP) {
				x = x1 + (1.0/m) * (ymax - y1);
				y = ymax;
		 	} else if(temp & BOTTOM) {
		 		x = x1 + (1.0/m) * (ymin - y1);
		 		y = ymin;
		 	} else if(temp & LEFT) {
		 		x = xmin;
		 		y = y1 + m * (xmin - x1);
		 	} else if(temp & RIGHT) {
		 		x = xmax;
		 		y = y1 + m * (xmax - x1);
		 	}
		 	
		 	if(temp == code1) {
		 		x1 = x;
		 		y1 = y;
		 		code1 = getcode(x1, y1);
		 	} else {
		 		x2 = x;
		 		y2 = y;
		 		code2 = getcode(x2, y2);
		 	}
		}
	}
	if(accept) {
		cleardevice();
		rectangle(xmin, ymin, xmax, ymax);
		setcolor(GREEN);
		line(x1, y1, x2, y2);
	} else {
		cleardevice();
		setcolor(WHITE);
		rectangle(xmin, ymin, xmax, ymax);
	}
	cout << "Accept value: " << accept;
	delay(2500);
	getch();
	closegraph();
	return 0;
}
