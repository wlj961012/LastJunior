#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<vector<string>> partition(string s) {
	int n = s.size();
	bool p[100][100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			p[i][j] = false;
		}
	}
	for (int i = n - 1; i >= 0; i--) {//´ò±í
		for (int j = i; j < n; j++) {
			p[i][j] = s[i] == s[j] && ((j - i) < 2 || p[i + 1][j - 1]);
		}
	}
	vector<vector<string>> result[100];
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j < n; j++) {
			if (p[i][j]) {
				string path = s.substr(i, j - i + 1);
				if (j + 1 < n) {
					for (auto v : result[j + 1]) {
						v.insert(v.begin(), path);
						result[i].push_back(v);
					}
				}
				else {
					result[i].push_back(vector<string>{path});
				}
			}
		}
	}
	return result[0];
}
int main() {
	string str="aab";
	vector<vector<string>> result = partition(str);
	for (int i = 0; i < result.size(); i++) {
		for (int j = 0; j < result[i].size(); j++) {
			cout << result[i][j] << "  ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}