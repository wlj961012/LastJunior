#include<iostream>
using namespace std;
int a[46];
int f(int n) {
	if (a[n] >= 0) {
		return a[n];
	}
	a[n] = f(n - 1) + f(n - 2);
	return a[n];
}
int main() {
	int n;
	for (int i = 0; i < 46; i++) {
		a[i] = -1;
	}
	a[0] = 0;
	a[1] = 1;
	int len;
	cin >> len;
	for (int i = 0; i < len; i++) {
		cin >> n;
		cout << f(n) << endl;
	}
	system("pause");
	return 0;
}