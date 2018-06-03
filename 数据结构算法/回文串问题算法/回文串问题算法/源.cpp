#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool is_huiwen(string &s, int start, int end) {
	while (start <= end&&s[start] == s[end]) {
		start++;
		end--;
	}
	return start >= end;
}
void DFS(string &s, vector<vector<string>> &result, vector<string> &path, int start) {
	if (start == s.size()) {
		result.push_back(path);
		return;
	}
	for (int i = start; i < s.size(); i++) {
		if (is_huiwen(s, start, i)) {
			path.push_back(s.substr(start, i - start + 1));
			DFS(s, result, path,i+1);
			path.pop_back();
		}
	}
}
vector<vector<string>> solution(string s) {
	vector<vector<string>> result;
	vector<string> path;
	DFS(s, result, path, 0);
	return result;
}


int main() {
	string str="aab";
	vector<vector<string>> result;
	result=solution(str);
	int m = result.size();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << "  ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}