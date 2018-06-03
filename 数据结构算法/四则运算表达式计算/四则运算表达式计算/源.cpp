#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool multiply(stack<int> &num) {
	int a, b;
	if (!num.empty()) {
		a = num.top();
		num.pop();
	}
	else {
		return false;
	}
	if (!num.empty()) {
		b = num.top();
		num.pop();
	}
	else {
		return false;
	}
	num.push(a*b);
	return true;
}
bool divide(stack<int> &num) {
	int a, b;
	if (!num.empty()) {
		a = num.top();
		num.pop();
	}
	else {
		return false;
	}
	if (!num.empty()) {
		b = num.top();
		num.pop();
	}
	else {
		return false;
	}
	if (a == 0) {
		return false;
	}
	num.push(b / a);
	return true;
}
bool add(stack<int> &num) {
	int a, b;
	if (!num.empty()) {
		a = num.top();
		num.pop();
	}
	else {
		return false;
	}
	if (!num.empty()) {
		b = num.top();
		num.pop();
	}
	else {
		return false;
	}
	num.push(a + b);
	return true;
}
bool sub(stack<int> &num) {
	int a, b;
	if (!num.empty()) {
		a = num.top();
		num.pop();
	}
	else {
		return false;
	}
	if (!num.empty()) {
		b = num.top();
		num.pop();
	}
	else {
		return false;
	}
	num.push(b - a);
	return true;
}
int get_num(int &i,string str) {
	int len = str.size();
	int num = 0;
	for (int j = i; j < len; j++) {
		if (str[j] >= '0'&&str[j] <= '9') {
			num = num * 10 + (str[j] - '0');
			i++;
		}
		else {
			break;
		}
	}
	i--;
	return num;
}
string get_substr(int &i, string str) {
	string temp = "";
	int len = str.size();
	int k = 0;
	for (int j = i + 1; j < len; j++) {
		if (str[j] == ')'&&k==0) {
			i++;
			break;
		}
		else if (str[j]=='(') {
			i++;
			k++;
			temp += str[j];
		}
		else if (str[j]==')') {
			k--;
			i++;
			temp += str[j];
		}
		else {
			temp += str[j];
			i++;
		}
	}
	return temp;
}
int level(char op) {
	if (op == '+' || op == '-') {
		return 1;
	}
	else {
		return 2;
	}
}
bool suanshu(string str,stack<int> &num) {
	stack<char> ope;
	int len = str.size();
	bool flag = true;
	int a;
	for (int i = 0; i < len; i++) {
		switch (str[i]) {
		case '+':
			ope.push('+');
			break;
		case '-':
			ope.push('-');
			break;
		case '*':
			ope.push('*');
			break;
		case '/':
			ope.push('/');
			break; 
		case '(':
			flag = suanshu(get_substr(i, str), num);
			break;
		default:
			num.push(get_num(i, str));
			break;
		}
		if (!flag) {
			return false;
		}
	}
	char op;
	while (!ope.empty()) {
		if (ope.top() == '*') {
			flag = multiply(num);
			ope.pop();
		}
		else if(ope.top()=='/'){
			flag =divide(num);
			ope.pop();
		}
		else if (ope.top()=='+') {
			op = ope.top();
			ope.pop();
			a = num.top();
			num.pop();
			while (!ope.empty()&&(level(ope.top()) > level(op))) {
				if (ope.top() == '*') {
					flag = multiply(num);
					ope.pop();
				}
				else if (ope.top() == '/') {
					flag = divide(num);
					ope.pop();
				}
				if (!flag) {
					cout << "error" << endl;
					return false;
				}
			}
			num.push(a);
			flag = add(num);
		}
		else if (ope.top()=='-') {
			op = ope.top();
			ope.pop();
			a = num.top();
			num.pop();
			while (!ope.empty()&&(level(ope.top()) > level(op))) {
				if (ope.top() == '*') {
					flag = multiply(num);
					ope.pop();
				}
				else if (ope.top() == '/') {
					flag = divide(num);
					ope.pop();
				}
				if (!flag) {
					return false;
				}
			}
			num.push(a);
			flag = sub(num);
		}
		if (!flag) {
			return false;
		}
	}
	return true;
}
int main() {
	string str;
	while (cin >> str) {
		stack<int> num;
		if (suanshu(str, num) && num.size() == 1) {
			cout << num.top() << endl;
		}
		else {
			cout << "error" << endl;
		}
	}
	system("pause");
	return 0;
}