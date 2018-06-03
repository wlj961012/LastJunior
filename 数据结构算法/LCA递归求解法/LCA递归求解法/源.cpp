#include<iostream>
using namespace std;
struct treenode {
	int data;
	treenode *left;
	treenode *right;
	treenode(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};
class tree {
public:
	treenode * root;
	tree() {
		root = NULL;
	}
	void insert(int d) {
		treenode *p = root, *s,*cur=root;
		if (p == NULL) {
			root = new treenode(d);
			return;
		}
		while (p) {
			if (d < p->data) {
				cur = p;
				p = p->left;
			}
			else if (d == p->data) {
				return;
			}
			else {
				cur = p;
				p = p->right;
			}
		}
		if (d < cur->data) {
			s = new treenode(d);
			cur->left = s;
		}
		else {
			s = new treenode(d);
			cur->right = s;
		}
	}
	void preorder(treenode* p) {
		if (p != NULL) {
			cout << p->data << "  ";
			preorder(p->left);
			preorder(p->right);
		}
		return;
	}
	void inorder(treenode* p) {
		if (p == NULL) {
			return;
		}
		inorder(p->left);
		cout << p->data << "  ";
		inorder(p->right);
	}
	treenode* find(int d) {
		treenode* p = root;
		while (p) {
			if (p->data == d) {
				return p;
			}
			else if(d < p->data){
				p = p->left;
			}
			else {
				p = p->right;
			}
		}
		return p;
	}
};
treenode *LCA(treenode* root,treenode* node1,treenode* node2) {
	if (root == NULL) {
		return NULL;
	}
	if (root == node1 || root == node2) {
		return root;
	}

	treenode *left = LCA(root->left, node1, node2);
	treenode *right = LCA(root->right, node1, node2);

	if (left != NULL && right != NULL) {
		return root;
	}
	else if (left != NULL) {
		return left;
	}
	else if (right != NULL) {
		return right;
	}
	else {
		return NULL;
	}
}
int main() {
	tree t;
	t.insert(4);
	t.insert(2);
	t.insert(1);
	t.insert(3);
	t.insert(5);
	t.insert(7);
	t.insert(6);
	t.insert(9);
	t.insert(8);
	t.insert(10);
	t.preorder(t.root);
	cout << endl;
	t.inorder(t.root);
	cout << endl;
	int m = 6;
	int n = 8;
	treenode *node1 = t.find(m);
	treenode *node2 = t.find(n);
	treenode* node3 = LCA(t.root, node1, node2);
	cout << node1->data << endl;
	cout << node2->data << endl;
	cout << node3->data << endl;
	system("pause");
	return 0;
}