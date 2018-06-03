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

void Midpoint_init(int x1, int y1, int x2, int y2){
	int a, b, d, d1, d2, x, y;
	x = x1;
	y = y1;
	a = y2-y1;
	b = x1-x2;
	d = 2 * a + b;
	d1 = 2 * a;
	d2 = 2 * (a + b);
	drawpixel(x, y);
	while (x < x2){
		if (d < 0){//m在直线的上方则取yp
			x++;
			d = d + d1;
		}
		else{
			x++;
			y++;
			d = d + d2;
		}
		drawpixel(x, y);
	}
}

void mydraw(){
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawPixels(width, height, GL_RGB, GL_UNSIGNED_BYTE, pixels);
	glFlush();
}

int main(int argc, char* argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowPosition(300, 200);
	glutInitWindowSize(width, height);
	glutCreateWindow("中点画线");
	pixels = new unsigned char[width*height * 3];
	int x1, y1, x2, y2;
	cout << "请输入两点坐标：" << endl;
	cin >> x1 >> y1 >> x2 >> y2;
	Midpoint_init(x1, y1, x2, y2);

	glutDisplayFunc(&mydraw);
	glutMainLoop();
	system("pause");
	return 0;
}