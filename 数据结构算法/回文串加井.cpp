#include<iostream>
#include<string>
using namespace std;
int Max(string Str, int* a){
	int k,len=Str.length(),max=-1;
	for (int i = 0; i < len; i++){
		k = 1;
		while (i-k>=0&&i+k<len){
			if (Str[i - k] == Str[i + k]){
				a[i] = k;
				k++;
			}
			else{
				break;
			}
		}
		if (i % 2 == 0){
			a[i]++;
		}
		if (a[i] > max){
			max = a[i];
		}
	}
	return max/2;
}
int main(){
	string a,str="$#";
	cout << "ÇëÊäÈë×Ö·û´®£º" << endl;
	cin >> a;
	int n = a.length();
	for (int i = 0; i < n; i++){
		str += a[i];
		str += '#';
	}
	int len = str.length();
	int p[100] = { 0 };
	int max;
	max=Max(str, p);
	cout << endl << max << endl;
	system("pause");
	return 0;
}