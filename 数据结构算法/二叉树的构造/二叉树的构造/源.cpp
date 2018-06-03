#include<iostream>
#include<string>
#include<queue>
using namespace std;
struct node {
	char data;
	node* leftchild;
	node* rightchild;
	node(char d) {
		data = d;
		leftchild = NULL;
		rightchild = NULL;
	}
};
node* rebulid(string preorder, string inorder) {
	node* t = NULL;
	if (preorder.size() > 0) {
		t = new node(preorder[0]);
	}
	if (inorder.size() > 1) {
		int len = inorder.size();
		int index = 0;
		for (int i = 0; i < len; i++) {
			if (inorder[i] == preorder[0]) {
				index = i;
				break;
			}
		}
		string leftinorder = inorder.substr(0, index);
		string rightinorder = inorder.substr(index + 1);
		int leftlen = leftinorder.size();
		int rightlen = rightinorder.size();
		string leftpreorder = preorder.substr(1, leftlen);
		string rightpreorder = preorder.substr(leftlen+1);
		t->leftchild = rebulid(leftpreorder, leftinorder);
		t->rightchild = rebulid(rightpreorder, rightinorder);
	}
	return t;
}
class tree {
public:
	node * root;
	tree() {
		root = NULL;
	}
	void get_tree(string str1,string str2) {
		root = rebulid(str1,str2);
	}
	void preorder(node* root) {
		if (root == NULL) {
			return;
		}
		cout << root->data;
		preorder(root->leftchild);
		preorder(root->rightchild);
	}
	void inorder(node* root) {
		if (root == NULL) {
			return;
		}
		inorder(root->leftchild);
		cout << root->data;
		inorder(root->rightchild);
	}
	void postorder(node* root) {
		if (root == NULL) {
			return;
		}
		postorder(root->leftchild);
		postorder(root->rightchild);
		cout << root->data;
	}
	void deeporder() {
		queue<node*> q;
		q.push(root);
		while (!q.empty()) {
			node* t = q.front();
			q.pop();
			cout << t->data;
			if (t->leftchild != NULL) {
				q.push(t->leftchild);
			}
			if (t->rightchild != NULL) {
				q.push(t->rightchild);
			}
		}
	}
};
int main() {
	string str1, str2;
	while (cin >> str1 >> str2) {
		tree t;
		t.get_tree(str1, str2);
		t.postorder(t.root);
		cout << " ";
		t.deeporder();
		cout << endl;
	}
	system("pause");
	return 0;
}