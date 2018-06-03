#include<iostream>
#include<string>
using namespace std;
struct node {
	char data;
	node* left;
	node* right;
	node() {
		left = NULL;
		right = NULL;
	}
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
		root =new node(' ');
	}
	node* find(node* p,node *q) {
		if (q == p->left || q == p->right) {
			return p;
		}
		find(q->left,q);
		find(q->right,q);
	}
	void insert(node *p,string str,int& i) {
		if (i>str.size()||str[i] == '#') {
			return;
		}
		if (root->data == ' ') {
			root->data = str[i];
			i++;
			insert(root->left, str, i);
			i++;
			insert(root->right, str, i);
			return;
		}
		node* q = find(root, p);
		if (p == q->left) {
			p= new node(str[i]);
			q->left = p;
		}
		else {
			p = new node(str[i]);
			q->right = p;
		}
		i++;
		insert(p->left, str, i);
		i++;
		insert(p->right, str,i);
	}
	void preorder(node* root) {
		if (root == NULL||root->data==' ') {
			return;
		}
		cout << root->data;
		preorder(root->left);
		preorder(root->right);
	}
	void inorder(node* root) {
		if (root == NULL||root->data==' ') {
			return;
		}
		inorder(root->left);
		cout << root->data;
		inorder(root->right);
	}
	void postorder(node* root) {
		if (root == NULL||root->data==' ') {
			return;
		}
		postorder(root->left);
		postorder(root->right);
		cout << root->data ;
	}
};
int main() {
	string str;
	while (cin >> str) {
		tree t;
		int i = 0;
		t.insert(t.root,str, i);
		if (t.root->data != ' ') {
			t.inorder(t.root);
			cout << " ";
			t.postorder(t.root);
			cout << " ";
			t.preorder(t.root);
			cout << endl;
		}
		else {
			cout << " " << endl;
		}
	}
	system("pause");
	return 0;
}