#include<iostream>
using namespace std;
struct treenode {
	int data;
	treenode *parent;
	treenode *left;
	treenode *right;
	treenode() {
		parent = NULL;
		left = NULL;
		right = NULL;
	}
	treenode(int d) {
		data = d;
		parent = NULL;
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
		treenode *p = root, *s, *cur = root;
		if (root == NULL) {
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
			s->parent = cur;
		}
		if (d > cur->data) {
			s = new treenode(d);
			cur->right = s;
			s->parent = cur;
		}
	}
	void inorder(treenode *p) {
		if (p != NULL) {
			inorder(p->left);
			cout << p->data << "   ";
			if (p->parent != NULL) {
				cout << p->parent->data;
			}
			cout << endl;
			inorder(p->right);
		}
	}
	void preorder(treenode *p) {
		if (p != NULL) {
			cout << p->data << "  ";
			if (p->parent != NULL) {
				cout << p->parent->data;
			}
			cout << endl;
			preorder(p->left);
			preorder(p->right);
		}
	}
	treenode* find(int d) {
		treenode *p = root;
		while (p!=NULL) {
			if (d == p->data) {
				return p;
			}
			else if (d < p->data) {
				p = p->left;
			}
			else {
				p = p->right;
			}
		}
	}
};
int LCA(tree t,int m,int n) {
	treenode *node1, *node2;
	node1 = t.find(m);
	node2 = t.find(n);
	int len1=0, len2=0;
	treenode *cur1, *cur2;
	cur1 = node1;
	cur2 = node2;
	while (cur1) {
		len1++;
		cur1 = cur1->parent;
	}
	while (cur2) {
		len2++;
		cur2 = cur2->parent;
	}
	if (len1 < len2) {
		int i = len2 - len1;
		while (i--) {
			node2 = node2->parent;
		}
		while (len1--) {
			if (node1->data == node2->data) {
				break;
			}
			node1 = node1->parent;
			node2 = node2->parent;
		}
	}
	else {
		int i = len1 - len2;
		while (i--) {
			node1 = node1->parent;
		}
		while (len2--) {
			if (node1->data == node2->data) {
				break;
			}
			node1 = node1->parent;
			node2 = node2->parent;
		}
	}
	cout << node1->data << endl;
	return 0;
}
int main() {
	tree t;
	t.insert(4);
	t.insert(5);
	t.insert(2);
	t.insert(3);
	t.insert(1);
	t.insert(7);
	t.insert(6);
	t.insert(9);
	t.insert(8);
	t.insert(10);
	t.inorder(t.root);
	cout << endl;
	t.preorder(t.root);
	int m = 9, n = 8;
	LCA(t, m, n);
	system("pause");
	return 0;
}