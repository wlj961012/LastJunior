#include<iostream>
using namespace std;
void FindNumber(int* a, bool* hash,int has,int res,int len,int sum,int i){
	if (i >= len){
		return;
	}
	if (a[i] + has == sum){
		hash[i] = true;
		for (int j = 0; j < len; j++){
			if (hash[j] == true){
				cout << a[j] << " ";
			}
		}
		hash[i] = false;
		cout << endl;
		return;
	}
	if (has + a[i] <= sum&&has + res >= sum){
		hash[i] = true;
		FindNumber(a, hash, has + a[i], res - a[i], len, sum, i + 1);
	}
	if (has + (res - a[i]) >= sum){
		hash[i] = false;
		FindNumber(a, hash, has, res - a[i], len, sum, i + 1);
	}
}
int main(){
	int A[100];
	int len, sum;
	cout << "please input len:" << endl;
	cin >> len;
	cout << "please input sum:" << endl;
	cin >> sum;
	cout << "please input a[i]:" << endl;
	for (int i = 0; i < len; i++)
		cin >> A[i];
	bool Hash[100];
	memset(Hash, 0, sizeof(Hash));
	int ans = 0;
	for (int i = 0; i < len; i++){
		ans += A[i];
	}
	FindNumber(A,Hash,0,ans,len,sum,0);
	system("pause");
	return 0;
}