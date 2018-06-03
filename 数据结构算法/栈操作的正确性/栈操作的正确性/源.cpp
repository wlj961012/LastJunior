#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool caozuo(string str) {
	int len = str.size();
	stack<char> s;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'P') {
			s.push(str[i]);
		}
		else if (str[i] == 'Q' && !s.empty()) {
			s.pop();
		}
		else {
			return false;
		}
	}
	if (s.empty()) {
		return true;
	}
	else {
		return false;
	}
}
int main() {
	string str;
	while (cin >> str) {
		if (caozuo(str)) {
			cout << "Y" << endl;
		}
		else {
			cout << "N" << endl;
		}
	}
	system("pause");
	return 0;
}