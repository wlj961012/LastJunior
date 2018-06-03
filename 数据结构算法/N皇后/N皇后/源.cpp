#include<iostream>
#include<vector>
using namespace std;
int m[100] = { 0 };
int c[100] = { 0 };
int d[100] = { 0 };
int sum = 0;
void print(vector<int> path) {
	sum++;
	if (sum <= 3) {
		int len = path.size();
		for (int i = 0; i < len; i++) {
			cout << path[i]+1 << " ";
		}
		cout << endl;
	}
}
void dfs(int n,vector<int> &path,int s) {
	if (s == n) {
		print(path);
		return;
	}
	for (int i = 0; i < n; i++) {
		if (m[i] == 0 && c[i + s] == 0 && d[i - s + n]==0) {
			m[i] = 1;
			c[i + s] = 1;
			d[i - s + n] = 1;
			path.push_back(i);
			dfs(n, path, s + 1);
			m[i] = 0;
			c[i + s] = 0;
			d[i - s + n] = 0;
			path.pop_back();
		}
	}
}
int main() {
	int n=8;
	vector<int> path;
	dfs(n, path, 0);
	cout << sum << endl;
	system("pause");
	return 0;
}