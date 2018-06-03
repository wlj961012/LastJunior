#include<iostream>
#include<vector>
#include<string>
using namespace std;
int mincut(string s) {
	int n = s.size();
	bool p[100][100];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			p[i][j] = false;
	int f[100];
	for (int i = 0; i <= n; i++) {
		f[i] = n - 1 - i;
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i; j < n; j++) {
			if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1])) {
				p[i][j] = true;
				f[i] = f[i]<(f[j+1] + 1)?f[i]:(f[j+1]+1);
			}
		}
	}
	return f[0];
}
int main() {
	string str = "aab";
	int result=mincut(str);
	cout << result << endl;
	system("pause");
	return 0;
}