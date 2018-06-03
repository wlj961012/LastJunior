#include<iostream>
#include<vector>
using namespace std;
vector<bool> visited;
void dfs(int (*a)[4],int v,int len) {
	visited[v] = true;
	cout << v << " ";
	for (int i = 0; i < len; i++) {
		if (a[v][i] != 0&&!visited[i]) {
			dfs(a, i, len);
		}
	}
}
void dfstraver(int (*a)[4],int len) {
	for (int i = 0; i < len; i++) {
		visited.push_back(false);
	}
	for (int i = 0; i < len; i++) {
		if(!visited[i])
		dfs(a,i,len);
	}
}
int main() {
	int len = 4;
	int a[4][4] = {
		{0,1,0,1},
		{1,0,0,0},
		{ 0,0,0,1 },
		{ 1,0,1,0 }
	};
	dfstraver(a, len);
	system("pause");
	return 0;
}