#include<iostream>
#include<string>
using namespace std;
bool isinter(string s1,string s2,string s3) {
	int m = s1.size();
	int n = s2.size();
	int k = s3.size();
	if ((m + n) != k) {
		return false;
	}
	bool dp[100][100];
	dp[0][0] = true;
	for (int i = 0; i < m+1; i++) {
		for (int j = 0; j < n+1; j++) {
			if ((i > 0 && dp[i - 1][j] && s3[i + j-1] == s1[i-1])||(j>0&&dp[i][j-1]&&s3[i+j-1]==s2[j-1])) {
				dp[i][j] = true;
			}
			else {
				dp[i][j] = false;
			}
		}
	}
	return dp[m][n];
}
int main() {
	string s1="aabcc";
	string s2="dbbca";
	string s3="aaebbcbccc";
	cout << isinter(s1, s2, s3) << endl;
	system("pause");
	return 0;
}