#include<iostream>
#include<stack>
using namespace std;
void conversion(int num,int n) {
	stack<int> s;
	while (num) {
		s.push(num%n);
		num = num / n;
	}
	int temp;
	while (!s.empty()) {
		temp = s.top();
		s.pop();
		cout << temp;
	}
	cout << endl;
}
int main() {
	int num;
	while (cin >> num) {
		conversion(num, 8);
	}
	system("pause");
	return 0;
}