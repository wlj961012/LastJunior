#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;
struct edge {
	int vertex;
	int weight;
	edge* next;
	edge() {
		next = NULL;
	}
	edge(int v, int w) {
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
	vertex(string d) {
		data = d;
		firstedge = new edge();
	}
};
class graph {
private:
	vector<vertex> v;
	int vex_num;
public:
	graph() {
		vex_num = 0;
	}
	int get_vexnum() {
		return vex_num;
	}
	void insert(string v1,string v2,int w) {
		if (vex_num == 0) {
			v.push_back(vertex(v1));
			v[vex_num].firstedge->next= new edge(1,w);
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
					cur->next = new edge(j,w);
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
				cout << v[p->vertex].data << "  "<<p->weight<<"  ";
				p = p->next;
			}
			cout << endl;
		}
	}
	vector<int> Dijkstra(int vex) {
		vector<int> result;
		set<int> visited;
		for (int i = 0; i < vex_num; i++) {
			result.push_back(10000);
		}
		int cur = vex;
		result[vex] = 0;
		visited.insert(cur);
		while (visited.size() < vex_num) {
			edge *p = v[cur].firstedge->next;
			while (p) {
				if ((p->weight + result[cur]) < result[p->vertex]) {
					result[p->vertex] = p->weight + result[cur];
				}
				p = p->next;
			}
			int min=100000;
			for (int i = 0; i < vex_num; i++) {
				if (visited.count(i) == 0) {
					if (result[i] < min) {
						min = result[i];
						cur = i;
					}
				}
			}
			visited.insert(cur);
		}
		return result;
	}
};
int main() {
	graph g;
	g.insert("v1", "v2", 20);
	g.insert("v1", "v3", 50);
	g.insert("v1", "v4", 30);
	g.insert("v2", "v3", 25);
	g.insert("v2", "v6", 70);
	g.insert("v3", "v4", 40);
	g.insert("v3", "v5", 25);
	g.insert("v3", "v6", 50);
	g.insert("v4", "v5", 55);
	g.insert("v5", "v6", 10);
	g.insert("v5", "v7", 70);
	g.insert("v6", "v7", 50);
	g.traverse();
	vector<int> result=g.Dijkstra(0);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "  ";
	}
	
	system("pause");
	return 0;
}