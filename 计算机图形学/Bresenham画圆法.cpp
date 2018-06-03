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

void CirclePoint(int x, int y){
	drawpixel(x+250, y+250);
	drawpixel(-x+250, y+250);
	drawpixel(x + 250, -y + 250);
	drawpixel(-x + 250, -y + 250);
	drawpixel(y + 250, x + 250);
	drawpixel(y + 250, -x + 250);
	drawpixel(-y + 250, x + 250);
	drawpixel(-y + 250, -x + 250);
}

void BresenhamCircle(int r){
	int x = 0, y = r;
	int deltad = 2 - 2 * r;
	int delta1, delta2, direction;
	CirclePoint(x, y);
	while (y >= x){
		if (deltad < 0){//说明d在园内
			delta1 = 2 * y+2*deltad - 1;
			if (delta1 <= 0){//此时H到圆的距离小于D到圆的距离
				x++;
				deltad +=2*x+1;
			}
			else{
				x++;
				y--;
				deltad += 2 * x - 2 * y + 1;
			}
		}
		else if (deltad>0){
			delta2 = 2 * x + 1-2*deltad;
			if (delta2 >=0 ){
				y--;
				deltad += 1 - 2 * y;
			}
			else{
				x++;
				y--;
				deltad += 2 * x - 2 * y + 1;
			}
		}
		else{
			x++;
			y--;
			deltad += 2 * x - 2 * y + 1;
		}
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
	BresenhamCircle(r);
	glutDisplayFunc(&mydraw);

	glutMainLoop();
	return 0;
}