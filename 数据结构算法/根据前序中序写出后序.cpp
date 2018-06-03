#include<iostream>
#include<string>
using namespace std;
void preorder(string midorder, string postorder){
	if (postorder.empty() == true){
		return;
	}
	char a = postorder[0];
	string left = "";
	string right="";
	int i,len=midorder.length();
	for (i = 0; i < len; i++){
		if (midorder[i] == postorder[0]){
			break;
		}
	}
	for (int j = 0; j < i; j++){
		left += midorder[j];
	}
	for (int j = i + 1; j < len; j++){
		right += midorder[j];
	}
	postorder.erase(postorder.begin());
	string str1 = "";
	string str2 = "";
	int len2 = postorder.length();
	for (int j = 0; j < len2 - i; j++){
		str1 += postorder[j];
	}
	for (int j = len2 - i; j < len2; j++){
		str2 += postorder[j];
	}
	cout << a << " ";
	preorder(left, str2);
	preorder(right, str1);
}
int main(){
	string midorder, postorder;
	midorder = "ADEFGHMZ";
	postorder = "AEFDHZMG";
	reverse(postorder.begin(),postorder.end());
	preorder(midorder, postorder);
	system("pause");
	return 0;
};