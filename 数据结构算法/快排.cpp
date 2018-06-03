#include<iostream>
using namespace std;
int len;
void Qsort(int* a, int begin, int end){
	if (begin >= end){
		return;
	}
	int i = begin, j = end;
	int key = a[begin];
	while (i < j){
		while (a[j] > key&&i<j){
			j--;
		}
		a[i] = a[j];
		while (a[i] <= key&&i<j){
			i++;
		}
		a[j] = a[i];	
	}
	a[i] = key;
	Qsort(a, begin, i-1);
	Qsort(a, i + 1,end);
}
int main(){
	int a[100];
	cout << "请输入数组长度：" << endl;
	cin >> len;
	cout << "请输入数组的值：" << endl;
	for (int i = 0; i < len; i++)
		cin >> a[i];
	Qsort(a, 0, len - 1);
	cout << endl;
	for (int i = 0; i < len; i++){
		cout << a[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}