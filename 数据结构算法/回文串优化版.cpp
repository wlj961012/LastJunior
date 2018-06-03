#include<iostream>
#include<string>
using namespace std;
int Odd(string str,int* a, int b){
	int k,max=0;
	for (int i = 0; i < b; i++){
		k = 1;
		while (i - k >= 0 && i + k < b){
			if (str[i - k] == str[i + k]){
				a[i] = k * 2;
				k++;
			}
			else{
				break;
			}
		}
		a[i]++;
	}
	for (int i = 0; i < b; i++){
		if (a[i]>max)
			max = a[i];
	}
	return max;
}
int Even(string str,int* a, int b){
	int k, max = 0;
	for (int i = 0; i < b - 1; i++){
		k = 1;
		while (i - k + 1 >= 0 && i + k < b){
			if (str[i - k + 1] == str[i + k]){
				a[i] = k * 2;
				k++;
			}
			else{
				break;
			}
		}
	}
	for (int i = 0; i < b - 1; i++){
		if (a[i]>max){
			max = a[i];
		}
	}
	return max;
}
int main(){
	string a;
	cout << "ÇëÊäÈë×Ö·û´®£º" << endl;
	cin >> a;
	int odd[100] = { 0 }, even[100] = { 0 };
	int max1, max2,max;
	int len = a.length();
	max1 = Odd(a,odd, len);
	max2 = Even(a,even, len);
	if (max1 > max2){
		max = max1 / 2 + 1;
	}
	else{
		max = max2 / 2;
	}
	cout << endl << max << endl;
	system("pause");
	return 0;
}