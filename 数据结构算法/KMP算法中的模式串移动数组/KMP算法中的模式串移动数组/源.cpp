#include<iostream>
#include<string>
using namespace std;
void get_next(string str) {
	int next[100];
	int i=0;
	int j=-1;
	int len = str.size();
	next[0] = -1;
	while (i < len) {
		if (j == -1 || str[i] == str[j]) {
			j++;
			i++;
			next[i] = j;
		}
		else {
			j = next[j];
		}
	}
	for (int k = 0; k < len; k++) {
		cout << next[k] << " ";
	}
	cout << endl;
}
int main() {
	string str="abaabcac";
	get_next(str);
	system("pause");
	return 0;
}