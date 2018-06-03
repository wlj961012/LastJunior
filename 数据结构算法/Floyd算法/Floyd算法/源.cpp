#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct edge {
	int vertex;
	int weight;
	edge* next;
	edge() {
		next = NULL;
	}
	edge(int v,int w) {
		vertex = v;
		weight = w;
		next = NULL;
	}
};
struct vertex {
	string data;
	edge* firstedge;
	vertex() {
		firstedge = new edge();
	}
	vertex(string s) {
		data = s;
		firstedge = new edge();
	}
};
class graph {
private:
	vector<vertex> v;
	int vex_num;
public:
	vector<vector<int>> path;
	vector<vector<int>> result;
	graph() {
		vex_num = 0;
	}
	void insert(string v1, string v2, int w) {
		if (vex_num == 0) {
			v.push_back(vertex(v1));
			v[vex_num].firstedge->next = new edge(1, w);
			vex_num++;
			v.push_back(vertex(v2));
			vex_num++;
			return;
		}
		bool flag = false;
		int j;
		for (int i = 0; i < vex_num; i++) {
			if (v[i].data == v2) {
				j = i;
				flag = true;
				break;
			}
		}
		for (int i = 0; i < vex_num; i++) {
			if (v[i].data == v1) {
				edge *p = v[i].firstedge;
				edge *cur = p;
				while (p) {
					cur = p;
					p = p->next;
				}
				if (flag) {
					cur->next = new edge(j, w);
				}
				else {
					v.push_back(vertex(v2));
					cur->next = new edge(vex_num, w);
					vex_num++;
				}
				return;
			}
		}
		v.push_back(vertex(v1));
		edge *p = v[vex_num].firstedge;
		edge *cur = p;
		while (p) {
			cur = p;
			p = p->next;
		}
		vex_num++;
		if (flag) {
			cur->next = new edge(j, w);
		}
		else {
			v.push_back(vertex(v2));
			cur->next = new edge(vex_num, w);
			vex_num++;
		}
	}
	void traverse() {
		for (int i = 0; i < vex_num; i++) {
			cout << v[i].data << "->";
			edge *p = v[i].firstedge->next;
			while (p) {
				cout << v[p->vertex].data << "  " << p->weight << "  ";
				p = p->next;
			}
			cout << endl;
		}
	}
	void floyd() {
		for (int i = 0; i < vex_num; i++) {
			vector<int> k;
			vector<int> w;
			for (int j = 0; j < vex_num; j++) {
				w.push_back(-1);
				k.push_back(10000);
			}
			result.push_back(k);
		}
		for (int i = 0; i < vex_num; i++) {
			edge *p = v[i].firstedge->next;
			while (p) {
				result[i][p->vertex] = p->weight;
				p = p->next;
			}
		}
		for (int k = 0; k < vex_num; k++) {
			for (int i = 0; i < vex_num; i++) {
				for (int j = 0; j < vex_num; j++) {
					if ((result[i][k] + result[k][j]) < result[i][j]) {
						result[i][j] = result[i][k] + result[k][j];
						//path[i][j] = path[i][k];
					}
				}
			}
		}
		for (int i = 0; i < result.size(); i++) {
			for (int j = 0; j < result[i].size(); j++) {
				cout << result[i][j] << "\t";
			}
			cout << endl;
		}
	}
};
int main() {
	graph g;
	g.insert("v1", "v2", 12);
	g.insert("v2", "v1", 12);
	g.insert("v1", "v6", 16);
	g.insert("v6", "v1", 16);
	g.insert("v1", "v7", 14);
	g.insert("v7", "v1", 14);
	g.insert("v2", "v3", 10);
	g.insert("v3", "v2", 10);
	g.insert("v2", "v6", 7);
	g.insert("v6", "v2", 7);
	g.insert("v3", "v4", 3);
	g.insert("v4", "v3", 3);
	g.insert("v3", "v5", 5);
	g.insert("v5", "v3", 5);
	g.insert("v3", "v6", 6);
	g.insert("v6", "v3", 6);
	g.insert("v4", "v5", 4);
	g.insert("v5", "v4", 4);
	g.insert("v5", "v6", 2);
	g.insert("v6", "v5", 2);
	g.insert("v5", "v7", 8);
	g.insert("v7", "v5", 8);
	g.insert("v6", "v7", 9);
	g.insert("v7", "v6", 9);
	g.traverse();
	g.floyd();
	system("pause");
	return 0;
}
