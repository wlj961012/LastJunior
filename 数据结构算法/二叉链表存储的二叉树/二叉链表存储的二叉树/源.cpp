#include<iostream>
#include<string>
#include<stack>
#include<set>
using namespace std;
struct node {
	char data;
	node* left;
	node* right;
	node(char d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};
class tree {
public:
	node * root;
	tree() {
		root = NULL;
	}
	void create(node* &t,string str,int& i) {
		if (i >= str.size()) {
			return;
		}
		if (str[i] != ' ') {
			t = new node(str[i]);
			i++;
			create(t->left, str, i);
			i++;
			create(t->right, str, i);
		}
		else {
			t = NULL;
		}
	}
	void preorder(node* root) {
		if (root == NULL) {
			return;
		}
		cout << root->data;
		preorder(root->left);
		preorder(root->right);
	}
	void inorder1(node* root) {
		if (root == NULL) {
			return;
		}
		inorder1(root->left);
		cout << root->data;
		inorder1(root->right);
	}
	void inorder() {
		stack<node*> s;
		node* t = root;
		while (t!=NULL || !s.empty()) {
			if (t) {
				s.push(t);
				t = t->left;
			}
			else {
				if (!s.empty()) {
					t = s.top();
					s.pop();
					cout << t->data;
					t = t->right;
				}
			}
		}
	}
	void inorder2() {
		if (root == NULL) {
			return;
		}
		stack<node*> s;
		node* t = root;
		s.push(t);
		while (!s.empty()) {
			while (t->left) {
				s.push(t->left);
				t = t->left;
			}
			t= s.top();
			s.pop();
			cout << t->data;
			if (t->right) {
				s.push(t->right);
				t = t->right;
			}
		}
	}
};
int main() {
	tree t;
	int i = 0;
	t.create(t.root, "ABC  DE G  F   ", i);
	t.preorder(t.root);
	cout << endl;
	t.inorder1(t.root);
	cout << endl;
	t.inorder();
	cout << endl;
	t.inorder2();
	system("pause");
	return 0;
}