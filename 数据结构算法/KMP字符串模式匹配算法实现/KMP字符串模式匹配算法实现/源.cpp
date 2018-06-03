#include<iostream>
#include<string>
#include<vector>
using namespace std;
 void get_next(string substr,int next[]) {
	int  i = 0;
	int j = -1;
	next[0]=-1;
	int len = substr.size();
	while (i < len) {
		if (j == -1 || substr[i] == substr[j]) {
			j++;
			i++;
			next[i]=j;
		}
		else {
			j = next[j];
		}
	}
}
int index_KMP(string str,string substr) {
	int next[100];
	int i = 0;
	int j = 0;
	int m = str.size();
	int n = substr.size();
	get_next(substr, next);
	while (i <m&&j<n) {
		if (j==-1||str[i] == substr[j]) {
			i++;
			j++;
		}
		else {
			j = next[j];
		}
	}
	if (j >= n) {
		return i - n+1;
	}
	else {
		return 0;
	}
}
int main() {
	string str, substr;
	while (cin >> str >> substr) {
		cout << index_KMP(str, substr) << endl;
	}
	system("pause");
	return 0;
}