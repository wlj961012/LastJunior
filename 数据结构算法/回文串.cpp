#include<iostream>
#include<string>
using namespace std;
int main(){
	string a;
	cout << "ÇëÊäÈë×Ö·û´®£º" << endl;
	cin >> a;
	int odd[100] = { 0 }, even[100] = { 0 };
	int len;
	len = a.length();
	int k;
	for (int i = 0; i < len; i++){
		k = 1;
		while (i - k >= 0 && i + k < len){
			if (a[i - k] == a[i + k]){
				odd[i] = k*2;
				k++;
			}
			else{
				break;
			}
		}
	}
	for (int i = 0; i < len; i++){
		odd[i]++;
	}
	for (int i = 0; i < len-1; i++){
		k = 1;
		while (i - k + 1 >= 0 && i + k < len){
			if (a[i - k + 1] == a[i + k]){
				even[i] = k * 2;
				k++;
			}
			else{
				break;
			}
		}
	}
	int max1=0,max2=0,max;
	for (int i = 0; i < len; i++){
		if (odd[i]>max1)
			max1 = odd[i];
	}
	for (int i = 0; i < len; i++){
		if (even[i]>max2)
			max2 = even[i];
	}
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