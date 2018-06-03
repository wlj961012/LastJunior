#include<GL/glut.h>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
int width = 500;
int height = 500;
unsigned char* pixels;

struct vertex_node{
	int x;
	int y;
	vertex_node(int xx,int yy){
		x = xx;
		y = yy;
	}
};

struct vertex_node2{
	int x;
	int y;
	int index;
	vertex_node2(int xx,int yy,int i){
		x = xx;
		y = yy;
		index = i;
	}
};

bool operator <(const vertex_node node1, const vertex_node node2){
	if (node1.x != node2.x){
		return node1.x < node2.x;
	}
	else{
		return node1.y < node2.y;
	}
}

class polygon{
private:
	vector<vertex_node> vertexs;
	void polygen_drawpixel(int x, int y){
		int index;
		index = y*width + x;
		pixels[index * 3 + 0] = 0;
		pixels[index * 3 + 1] = 0;
		pixels[index * 3 + 2] = 0;
	}
	void drawedge(vertex_node node1, vertex_node node2){
		if (node1.x == node2.x){//为一根竖线
			int temp = node2.y - node1.y;
			if (temp >= 0){
				for (int i = node1.y; i <= node2.y; i++){
					polygen_drawpixel(node1.x, i);
				}
			}
			else{
				for (int i = node2.y; i <= node1.y; i++){
					polygen_drawpixel(node1.x, i);
				}
			}
		}
		else if (abs(node1.x - node2.x) >= abs(node1.y - node2.y)){//斜率小于一
			double k = (node1.y - node2.y)*1.0 / (node1.x - node2.x);
			if (node1.x <= node2.x){
				double y = node1.y;
				for (int x = node1.x; x <= node2.x; x++){
					polygen_drawpixel(x, int(y + 0.5));
					y += k;
				}
			}
			else{
				double y = node2.y;
				for (int x = node2.x; x <= node1.x; x++){
					polygen_drawpixel(x, int(y + 0.5));
					y += k;
				}
			}
		}
		else{
			double k = (node1.y - node2.y)*1.0 / (node1.x - node2.x);
			if (node1.y < node2.y){
				double x = node1.x;
				for (int y = node1.y; y <= node2.y; y++){
					polygen_drawpixel((int)(x + 0.5), y);
					x += k;
				}
			}
			else{
				double x = node2.x;
				for (int y = node2.y; y <= node1.y; y++){
					polygen_drawpixel(int(x + 0.5), y);
					x += k;
				}
			}
		}
	}
public:
	polygon(queue<vertex_node> q){
		while (!q.empty()){
			vertexs.push_back(q.front());
			q.pop();
		}
	}
	void drawpolygon(){
		int len = vertexs.size();
		for (int i = 1; i < len; i++){
			drawedge(vertexs[i - 1], vertexs[i]);
		}
		drawedge(vertexs[len - 1], vertexs[0]);
	}
	vector<vertex_node> Get_vertexs(){
		return vertexs;
	}
};

struct net_node{
	double x;
	double deltax;
	int ymax;
	net_node(double xx,double dx,int y){
		x = xx;
		deltax = dx;
		ymax = y;
	}
};

bool operator <(const net_node node1, const net_node node2){
	if (node1.x != node2.x){
		return node1.x < node2.x;
	}
	else{
		if (node1.deltax != node2.deltax){
			return node1.deltax < node2.deltax;
		}
		else{
			return node1.ymax < node2.ymax;
		}
	}
}

bool cmp(const vertex_node2 &node1,const vertex_node2 &node2){
	if (node1.y != node2.y){
		return node1.y < node2.y;
	}
	else{
		return node1.x < node2.x;
	}
}
bool cmp2(const net_node node1, const net_node node2){
	return node1.x < node2.x;
}

void drawpixel(int x, int y){
	int index;
	index = y*width + x;
	pixels[index * 3 + 0] = 255;
	pixels[index * 3 + 1] = 0;
	pixels[index * 3 + 2] = 0;
}

void AET_drawline(double x1,double x2,int y){
	for (int i = int(x1+0.5)+1; i < int(x2+0.5); i++){
		drawpixel(i, y);
	}
}

map<int,set<net_node>> get_net(polygon p,int& ymin,int& ymax){
	vector<vertex_node> vertexs = p.Get_vertexs();
	int len = vertexs.size();
	vector<vertex_node2> sort_vertexs;
	for (int i = 0; i < len; i++){
		sort_vertexs.push_back(vertex_node2(vertexs[i].x, vertexs[i].y, i));
	}
	sort(sort_vertexs.begin(), sort_vertexs.end(), cmp);
	ymin = sort_vertexs[0].y;
	ymax = sort_vertexs[len - 1].y;
	map<int, set<net_node>> NET;
	int index1, index2, index3;
	for (int i = 0; i < len; i++){
		index1 = sort_vertexs[i].index;
		index2 = (index1 + 1) % len;
		index3 = (index1 - 1) % len;
		if (index2 < 0){
			index2 += len;
		}
		if (index3 < 0){
			index3 += len;
		}
		double k;
		if (vertexs[index2].y >= vertexs[index1].y){
			k = (vertexs[index2].x - vertexs[index1].x)*1.00 / (vertexs[index2].y - vertexs[index1].y)*1.00;
			NET[vertexs[index1].y].insert(net_node(vertexs[index1].x, k, vertexs[index2].y));
		}
		if (vertexs[index3].y >= vertexs[index1].y){
			k = (vertexs[index3].x - vertexs[index1].x)*1.00 / (vertexs[index3].y - vertexs[index1].y)*1.00;
			NET[vertexs[index1].y].insert(net_node(vertexs[index1].x, k, vertexs[index3].y));
		}
	}
	return NET;
}

void saomiaoxian(polygon p){
	int ymin, ymax;
	map<int, set<net_node>> NET = get_net(p,ymin,ymax);
	vector<net_node> AET;
	for (int y = ymin; y <= ymax; y++){
		if (!AET.empty()){//如果活性边表非空
			int len2 = AET.size();
			for (int i = 0; i < len2; i++){
				net_node temp = AET[i];
				net_node tmp(temp);
				tmp.x += temp.deltax;
				AET[i] = tmp;
			}
			sort(AET.begin(), AET.end(), cmp2);//排序
			int len = AET.size();
			for (int i = 0; i < len; i += 2){//填色
				AET_drawline(AET[i].x, AET[i + 1].x, y);
			}
			vector<net_node>::iterator it=AET.begin();
			while(it != AET.end()){
				if (it->ymax == y){
					it=AET.erase(it);
				}
				else{
					it++;
				}
			}
		}
		for (auto it : NET){//新增活性边表
			if (it.first == y){//这时候应该把它加入到活性边表中
				for (auto j : it.second){
					AET.push_back(j);
				}
			}
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
	glutCreateWindow("扫描转换法");
	pixels = new unsigned char[width*height * 3];
	queue<vertex_node> Q;
	Q.push(vertex_node(20+200, 20+200));
	Q.push(vertex_node(20+200, 70+200));
	Q.push(vertex_node(50+200, 50+200));
	Q.push(vertex_node(110+200, 80+200));
	Q.push(vertex_node(110+200, 30+200));
	Q.push(vertex_node(50+200, 10+200));
	polygon p(Q);
	p.drawpolygon();
	saomiaoxian(p);
	glutDisplayFunc(&mydraw);

	glutMainLoop();
	return 0;
}
