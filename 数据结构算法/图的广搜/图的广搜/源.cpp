#include<iostream>
#include<queue>
using namespace std;
void bfs(int (*a)[4],int len) {
	queue<int> q;
	q.push(0);
	vector<bool> visited;
	for (int i = 0; i < len; i++) {
		visited.push_back(false);
	}
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		if (!visited[t]) {
			cout << t << " ";
		}
		visited[t] = true;
		for (int i = 0; i < len; i++) {
			if (a[t][i] != 0 && !visited[i]) {
				q.push(i);
			}
		}
	}
}
int main() {
	int a[4][4] = {
		{0,0,0,1},
	{0,0,1,1},
	{0,1,0,1},
	{1,1,1,0}
	};
	int len=4;
	bfs(a, len);
	system("pause");
	return 0;
}