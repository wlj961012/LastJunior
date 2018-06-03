#include<iostream>
using namespace std;
int i = 0;
void move(int n,char from,char to) {
	printf("%2d. Move disk %d from %c to %c\n",++i,n,from,to);
}
void hanio(int n,char from,char dep,char to) {
	if (n == 1) {
		move(1, from, to);
	}
	else {
		hanio(n - 1, from, to, dep);
		move(n, from, to);
		hanio(n - 1, dep, from, to);
	}
}
int main() {
	int n;
	while (cin >> n) {
		hanio(n, 'X', 'Y', 'Z');
		cout << endl;
	}
	system("pause");
	return 0;
}