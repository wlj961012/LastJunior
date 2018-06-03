#include<iostream>
#include<queue>
using namespace std;
//有向无环图
struct edge {
	int vertex;
	edge *next;
	edge() {
		next = NULL;
	}
	edge(int v) {
		vertex = v;
		next = NULL;
	}
};
struct vertex {
	int data;
	edge *firstedge;
	vertex() {
		firstedge = new edge();
	}
	vertex(int d) {
		data = d;
		firstedge = new edge();
	}
};
class graph {
private:
	vertex *v[100];
	bool is_visited[100] = { false };
	int vex_num;
public:
	graph() {
		for (int i = 0; i < 100; i++) {
			v[i] = new vertex();
		}
		vex_num = 0;
	}
	void insert(int v1,int v2) {
		if (vex_num == 0) {
			v[0] = new vertex(v1);
			vex_num++;
			v[1] = new vertex(v2);
			vex_num++;
			v[0]->firstedge->next = new edge(1);
			return;
		}
		bool flag = false;
		int j;
		for (int i = 0; i < vex_num; i++) {
			if (v[i]->data == v2) {
				j = i;
				flag = true;
			}
		}
		for (int i = 0; i < vex_num; i++) {
			if (v[i]->data == v1) {
				edge *p = v[i]->firstedge;
				edge *cur = p;
				while (p) {
					cur = p;
					p = p->next;
				}
				if (flag) {
					cur->next = new edge(j);
				}
				else {
					v[vex_num] = new vertex(v2);
					cur->next = new edge(vex_num);
					vex_num++;
				}
				return;
			}
		}
		v[vex_num] = new vertex(v1);
		int temp = vex_num;
		vex_num++;
		edge *p = v[temp]->firstedge;
		edge *cur = p;
		while (p) {
			cur = p;
			p = p->next;
		}
		if (flag) {
			cur->next = new edge(j);
		}
		else {
			v[vex_num] = new vertex(v2);
			cur->next = new edge(vex_num);
			vex_num++;
		}
	}
	void dfs(int i) {//图的深搜
		cout << v[i]->data << "  ";
		is_visited[i] = true;
		edge *p = v[i]->firstedge->next;
		while (p) {
			if (!is_visited[p->vertex]) {
				dfs(p->vertex);
			}
			p = p->next;
		}
	}
	void traverse() {
		for (int i = 0; i < 4; i++) {
			cout << v[i]->data << "->";
			edge *p = v[i]->firstedge->next;
			while (p) {
				cout << v[p->vertex]->data << "   ";
				p = p->next;
			}
			cout << endl;
		}
		cout << endl;
	}
	void bfs() {//图的广搜
		queue<int> q;
		q.push(0);
		while (!q.empty()) {
			cout << v[q.front()]->data << "  ";
			is_visited[q.front()] = true;
			edge *p = v[q.front()]->firstedge->next;
			q.pop();
			while (p) {
				if (!is_visited[p->vertex]) {
					q.push(p->vertex);
				}
				p = p->next;
			}
		}
	}
};
int main() {
	graph g;
	g.insert(1, 3);
	g.insert(1, 2);
	g.insert(2, 1);
	g.insert(2, 4);
	g.insert(3, 1);
	g.insert(4, 2);
	g.traverse();
	g.bfs();
	system("pause");
	return 0;
}