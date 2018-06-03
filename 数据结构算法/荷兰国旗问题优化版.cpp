#include<iostream>
using namespace std;
void Holland(int* a, int len){
	int begin = 0, cur = 0, end = len - 1;
	while (cur < end){
		if (a[cur] == 2){
			swap(a[cur], a[end]);
			end--;
		}
		if (a[cur] == 1){
			cur++;
		}
		if (a[cur] == 0){
			swap(a[cur], a[begin]);
			cur++;
			begin++;
		}
	}
	for (int i = 0; i < len; i++)
		cout << a[i] << " ";
	cout << endl;
}
int main(){
	int a[100], len;
	cout << "请输入数组的长度：" << endl;
	cin >> len;
	cout << "请输入数组的值（仅限输入0，1，2）：" << endl;
	for (int i = 0; i < len; i++)
		cin >> a[i];
	Holland(a, len);
	system("pause");
	return 0;
}