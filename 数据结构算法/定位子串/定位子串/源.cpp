#include<iostream>
#include<string>
using namespace std;
string get_substr(string str,int len,int i) {
	string temp = "";
	int j = i;
	while (len--) {
		temp += str[j];
		j++;
	}
	return temp;
}
int index(string str,string sub) {
	int pos;
	int i = 0;
	int m = str.size();
	int n = sub.size();
	while (i < (m - n)) {
		string substr = get_substr(str, n, i);
		if (substr == sub) {
			return i + 1;
		}
		else {
			i++;
		}
	}
	return 0;
}
int main() {
	string str;
	string sub;
	while (cin >> str >> sub) {
		cout << index(str, sub) << endl;
	}
	system("pause");
	return 0;
}