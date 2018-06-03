#include<iostream>
#include<string>
#include<stack>
using namespace std;
bool kuohaopipei(string str) {
	stack<char> s;
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			s.push(str[i]);
		}
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
			if (str[i] ==')'&&s.top()=='(') {
				s.pop();
			}
			else if (str[i]==']'&&s.top()=='[') {
				s.pop();
			}
			else if (str[i]=='}'&&s.top()=='{') {
				s.pop();
			}
			else {
				return false;
			}
		}
		else {
			return false;
		}
	}
	return true;
}
int main() {
	string str="{[]}[]";
	if (kuohaopipei(str) == true) {
		cout << "À¨ºÅÆ¥Åä³É¹¦" << endl;
	}
	else {
		cout << "À¨ºÅÆ¥ÅäÊ§°Ü" << endl;
	}
	system("pause");
	return 0;
}