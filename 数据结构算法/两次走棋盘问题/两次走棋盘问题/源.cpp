#include<iostream>
#include<vector>
using namespace std;
int dp[100][100][100];
bool is_valid(int step,int i,int j,int n) {
	int x = step - i;
	int y = step - j;
	return (x >= 0) && (x < n) && (y >= 0) && (y < n) && (i >= 0) &&(i < n) && (j >= 0) && (j < n);
}
int get_value(int step,int i,int j,int n) {
	return is_valid(step, i, j, n) ? dp[step][i][j] : -10000;
}
int get_longestpath(vector<vector<int>> a){
	int len = a.size();
	int p = len * 2 - 1;
	for (int i = 0; i < p; i++) {
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < p; k++) {
				dp[i][j][k] = -100000;
			}
		}
	}
	dp[0][0][0] = a[0][0];
	for (int step = 1; step < p; step++) {
		for (int i = 0; i < len; i++) {
			for (int j = i; j < len; j++) {
				if (!is_valid(step, i, j, len) ){
					continue;
				}
				if (i != j) {
					if (dp[step][i][j] < get_value(step - 1, i - 1, j, len)) {
						dp[step][i][j] =get_value(step-1,i-1,j,len);
					}
					if (dp[step][i][j] < get_value(step - 1, i - 1, j-1, len)) {
						dp[step][i][j] = get_value(step - 1, i - 1, j-1, len);
					}
					if (dp[step][i][j] < get_value(step - 1, i, j, len)) {
						dp[step][i][j] = get_value(step - 1, i, j, len);
					}
					if (dp[step][i][j] < get_value(step - 1, i, j-1, len)) {
						dp[step][i][j] = get_value(step - 1, i, j-1, len);
					}
					dp[step][i][j] += a[i][step - i] + a[j][step - j];
				}
				else {
					if (dp[step][i][j] < get_value(step - 1, i - 1, j, len)) {
						dp[step][i][j] = get_value(step - 1, i - 1, j, len);
					}
					if (dp[step][i][j] < get_value(step - 1, i - 1, j-1, len)) {
						dp[step][i][j] = get_value(step - 1, i - 1, j-1, len);
					}
					if (dp[step][i][j] < get_value(step - 1, i, j, len)) {
						dp[step][i][j] = get_value(step - 1, i, j, len);
					}
					dp[step][i][j] += a[i][step - i];
				}
			}
		}
	}
	return dp[p - 1][len - 1][len - 1];
}
int main() {
	vector<vector<int>> array;
	vector<int> k1;
	vector<int> k2;
	vector<int> k3;
	k1.push_back(0);
	k1.push_back(3);
	k1.push_back(2);
	k2.push_back(0);
	k2.push_back(0);
	k2.push_back(0);
	k3.push_back(0);
	k3.push_back(1);
	k3.push_back(0);
	array.push_back(k1);
	array.push_back(k2);
	array.push_back(k3);
	cout << get_longestpath(array) << endl;
	system("pause");
	return 0;
}