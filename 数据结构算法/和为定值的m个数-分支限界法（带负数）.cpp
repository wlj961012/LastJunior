#include<iostream>
using namespace std;
int cmp(const void* a, const void* b){
	int *c = (int *)a;
	int *d = (int *)b;
	return *c - *d;
}
int Sum_Positive(int* a,int len){
	int Sum = 0;
	for (int i = 0; i < len; i++){
		if (a[i]>0){
			Sum += a[i];
		}
	}
	return Sum;
}
int All_Sum(int* a,int len){
	int Sum = 0;
	for (int i = 0; i < len; i++){
		Sum += a[i];
	}
	return Sum;
}
void FindNumber(int* a, int* hash, int i, int has, int res, int positive,int sum,int len){
	if (i >= len){
		return;
	}
	if ((has + a[i]) == sum){
		hash[i] = 1;
		cout << endl;
		for (int j = 0; j < len; j++){
			if (hash[j] == 1){
				cout << a[j] << "  ";
			}
		}
		cout << endl;
		hash[i] = 0;
		return;
	}
	if (a[i]>0){
			if (has + a[i] <= sum&&has + res >= sum){
				hash[i] = 1;

				FindNumber(a, hash, i + 1, has + a[i], res - a[i], positive, sum, len);
			}
			if (has + (res - a[i]) >= sum){
				hash[i] = 0;
				FindNumber(a, hash, i + 1, has, res - a[i], positive, sum, len);
			}
		}
	else{
		if (has + a[i] + positive < sum){
			hash[i] = 0;
			FindNumber(a, hash, i + 1, has, res - a[i], positive, sum, len);
		}
		else{
			hash[i] = 1;
			FindNumber(a, hash, i + 1, has + a[i], res - a[i], positive, sum, len);
			hash[i] = 0;
			FindNumber(a, hash, i + 1, has, res - a[i], positive, sum, len);
		}
	}
}
int main(){
	int a[100], len, sum;
	cout << "请输入数组长度：" << endl;
	cin >> len;
	cout << "请输入数组的值：" << endl;
	for (int i = 0; i < len; i++){
		cin >> a[i];
	}
	cout << "请输入sum的值：" << endl;
	cin >> sum;
	qsort(a, len, sizeof(a[0]), cmp);
	int hash[100];
	memset(hash, 0, sizeof(hash));
	int positive = Sum_Positive(a,len);
	int ans = All_Sum(a, len);
	FindNumber(a, hash, 0, 0,ans,positive,sum,len);
	system("pause");
	return  0;
}