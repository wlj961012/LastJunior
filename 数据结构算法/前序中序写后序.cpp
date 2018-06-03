#include<iostream>
#include<string>
using namespace std;
void postorder(string& preorder, string midorder,int index,int len){
	if (len <= 0){
		return;
		//preoder.erase(preoder.begin());
	}
	char a = preorder[index];
	int nroot = 0;
	for (nroot = 0; nroot < len; nroot++){
		if (preorder[index] == midorder[nroot]){
			break;
		}
	}
	postorder(preorder, midorder, index+1, nroot);
	postorder(preorder, midorder, index + nroot + 1, len - nroot-1);
	cout << a << " ";
}
int main(){
	string preorder = "GDAFEMHZ";
	string midorder = "ADEFGHMZ";
	//cout << "请输入前序遍历结果：" << endl;
	//cin >> preorder;
	//cout << "请输入中序遍历结果：" << endl;
	//cin >> midorder;
	int len = preorder.length();
	postorder(preorder, midorder, 0, len);
	system("pause");
	return 0;
}