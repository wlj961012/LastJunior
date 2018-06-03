#include<GL/glut.h>
#include<iostream>
using namespace std;
int width = 500;
int height = 500;
unsigned char* pixels;

void drawpixel(int x, int y){
	int index;
	index = y*width + x;
	pixels[index * 3 + 0] = 255;
	pixels[index * 3 + 1] = 0;
	pixels[index * 3 + 2] = 0;
}

void Bresenham_init(int x1, int y1, int x2, int y2){
	int x, y, dx, dy;
	int k;
	int e;
	dy = y2 - y1;
	dx = x2 - x1;
	k = dy*2.0;
	e = -dx;
	x = x1;
	y = y1;
	while (x <= x2){
		drawpixel(x, y);
		e = e + k;
		x++;
		if (e >= 0){
			y++;
			e = e - 2*dx;
		}
	}
}

void mydraw() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	glFlush();
}

int main(int argc, char *argv[]){

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(300, 200);
	glutInitWindowSize(width, height);
	glutCreateWindow("DDA画线");
	pixels = new unsigned char[width*height * 3];
	int x1, x2, y1, y2;
	cout << "请输入两点的坐标：" << endl;
	cin >> x1 >> y1 >> x2 >> y2;
	//DDA_init(x1, y1, x2, y2);
	Bresenham_init(x1, y1, x2, y2);
	glutDisplayFunc(&mydraw);

	glutMainLoop();
	return 0;
}
