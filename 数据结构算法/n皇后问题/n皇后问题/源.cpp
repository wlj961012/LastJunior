#include<iostream>
#include<vector>
#include<string>
using namespace std;
void dfs(vector<vector<int>> &result,vector<int> &path,vector<int> &is_row,vector<int> &main_diag,vector<int> &anti_diag,int row) {
	int N = is_row.size();
	if (row == N) {
		result.push_back(path);
		return;
	}
	for (int i = 0; i < N; i++) {
		bool ok = is_row[i] == 0 && main_diag[i + row] == 0 && anti_diag[row - i + N]==0;
		if (!ok) continue;
		is_row[i] = 1;
		main_diag[i + row] = 1;
		anti_diag[row - i + N] = 1;
		path.push_back(i);
		dfs(result, path, is_row, main_diag, anti_diag, row + 1);
		is_row[i] = 0;
		main_diag[i + row] = 0;
		anti_diag[row - i + N] = 0;
		path.pop_back();
	}
}
vector<vector<int>> solution(int n) {
	vector<vector<int>> result;
	vector<int> path;
	vector<int> is_row =vector<int>(n,0);
	vector<int> main_diag = vector<int>(2 * n, 0);
	vector<int> anti_diag = vector<int>(2 * n, 0);
	dfs(result, path, is_row, main_diag, anti_diag, 0);
	return result;
}
int main() {
	int n = 8;
	vector<vector<int>> result;
	result=solution(n);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			for (int k = 0; k < n; k++) {
				if (result[i][j] == k) {
					cout << "X" << "   ";
				}
				else {
					cout << "O" << "   ";
				}
			}
			cout << endl;
		}
		cout << endl;
	}
	system("pause");
	return 0;
}