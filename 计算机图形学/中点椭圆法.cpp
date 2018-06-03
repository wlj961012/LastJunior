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

void EllipsePoint(int x, int y){
	drawpixel(x + 250, y + 250);
	drawpixel(-x + 250, y + 250);
	drawpixel(-x + 250, -y + 250);
	drawpixel(x + 250, -y + 250);
}

void MidPointEllipse(int a,int b){
	int x = 0;
	int y = b;
	double d1 = b*b*(x + 1)*(x + 1) + a*a*(y - 0.5)*(y - 0.5) - a*a*b*b;
	EllipsePoint(x, y);
	double vector1 = 2 * b*b*(x + 1) - 2 * a*a*(y - 0.5);
	while(vector1 < 0){//在椭圆上半部分
		if (d1 < 0){//如果中点在椭圆里面 则选取上一点
			d1 += b*b*(2 * x + 3);
			x++;
		}
		else{
			d1 += b*b*(2 * x + 3) + a*a*(-2 * y + 2);
			x++;
			y--;
		}
		EllipsePoint(x, y);
		vector1 = 2 * b*b*(x + 1) - 2 * a*a*(y - 0.5);
	}
	double d2 = b*b*(x+0.5)*(x+0.5) + a*a*(y - 1)*(y - 1) - a*a*b*b;
	while (y >= 0){
		if (d2 < 0){//如果中点在椭圆的里面则取左边的一点
			d2 += b*b*(2 * x + 2) + a*a*(3 - 2 * y);
			x++;
			y--;
		}
		else{
			d2 += a*a*(3 - 2 * y);
			y--;
		}
		EllipsePoint(x, y);
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
	glutCreateWindow("中点画圆法");
	pixels = new unsigned char[width*height * 3];
	int a=200;
	int b = 100;
	MidPointEllipse(a,b);
	glutDisplayFunc(&mydraw);

	glutMainLoop();
	return 0;
}