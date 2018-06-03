#include<iostream>
#include<string>
#include<stack>
using namespace std;
int longest(string str) {
	int maxleft = 0;
	int ansleft = 0;
	stack<char> s;
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (str[i] == '(') {
			s.push(str[i]);
		}
		else if (str[i] == ')'&&!s.empty()&&s.top()=='(') {
			s.pop();
			ansleft += 2;
			if (ansleft > maxleft) {
				maxleft = ansleft;
			}
		}
		else {
			ansleft = 0;
		}
	}
	int maxright=0;
	int ansright = 0;
	for (int i = len - 1; i >= 0; i--) {
		if (str[i] == ')') {
			s.push(')');
		}
		else if (str[i] == '('&&!s.empty()&&s.top() == ')') {
			s.pop();
			ansright += 2;
			if (ansright > maxright) {
				maxright = ansright;
			}
		}
		else {
			ansright = 0;
		}
	}
	if (maxleft < maxright) {
		return maxleft;
	}
	else {
		return maxright;
	}
}
int main() {
	string str = "(((()())";
	int len = longest(str);
	cout << len << endl;
	system("pause");
	return 0;
}