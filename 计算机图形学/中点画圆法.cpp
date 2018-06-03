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

void CirclePoint(int x,int y){
	drawpixel(x + 250, y + 250);
	drawpixel(y + 250, x + 250);
	drawpixel(-x + 250, y + 250);
	drawpixel(y + 250, -x + 250);
	drawpixel(x + 250, -y + 250);
	drawpixel(-y + 250, x + 250);
	drawpixel(-x + 250, -y + 250);
	drawpixel(-y + 250, -x + 250);
}

void MidPointCircle(int r){
	int x, y;
	float d;
	x = 0;
	y = r;
	d = 1 - r;
	int deltax, deltay;
	deltax = 3;
	deltay = 2 - r-r;
	CirclePoint(x, y);
	while (x <= y){
		if (d < 0){//m在园内 则取上面的点
			d = d + deltax;
			deltax += 2;
		}
		else{
			d = d + deltax+deltay;
			deltax += 2;
			deltay += 2;
			y--;
		}
		x++;
		CirclePoint(x, y);
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
	int r = 100;
	MidPointCircle(r);
	glutDisplayFunc(&mydraw);

	glutMainLoop();
	return 0;
}