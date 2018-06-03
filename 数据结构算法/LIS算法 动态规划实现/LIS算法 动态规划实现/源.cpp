#include<iostream>
#include<vector>
using namespace std;
vector<int> get_lis(vector<int> array) {
	vector<int> result;
	vector<int> pre;
	vector<int> longest;
	int len = array.size();
	for (int i = 0; i < len; i++) {
		longest.push_back(1);
		pre.push_back(-1);
	}
	for (int i = 1; i < len; i++) {
		for (int j = 0; j < i; j++) {
			if (array[i] > array[j]) {
				if (longest[j] + 1 > longest[i]) {
					longest[i] = longest[j] + 1;
					pre[i] = j;
				}
			}
		}
	}
	int max = 1;
	int r;
	for (int i = 0; i < len; i++) {
		if (longest[i] > max) {
			max = longest[i];
			r = i;
		}
	}
	while (r >= 0) {
		result.push_back(array[r]);
		r = pre[r];
	}
	return result;
}
int main() {
	vector<int> array = { 1,4,0,2,5,7 };
	vector<int> result= get_lis(array);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << "   ";
	}
	system("pause");
	return 0;
}