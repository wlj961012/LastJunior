#include<iostream>
#include<algorithm>
using namespace std;
struct node{
	int data;
	node* leftchild;
	node* rightchild;
	node(){
		leftchild = rightchild = NULL;
	}
};
class AVL_tree{
public:
	node* root;
	AVL_tree(){
		root = NULL;
	}
	int height(node* cur_node){
		if (cur_node == NULL){
			return 0;
		}
		return max(height(cur_node->leftchild), height(cur_node->rightchild))+1;
	}
	void single_left(node*& k2){
		node* k1;
		k1 = k2->leftchild;
		k2->leftchild = k1->rightchild;
		k1->rightchild = k2;
		k2 = k1;
	}
	void single_right(node*& k2){
		node* k1;
		k1 = k2->rightchild;
		k2->rightchild = k1->leftchild;
		k1->leftchild = k2;
		k2 = k1;
	}
	void double_left_right(node*& k){
		single_right(k->leftchild);
		single_left(k);
	}
	void double_right_left(node*& k){
		single_left(k->rightchild);
		single_right(k);
	}
	void AVL_insert(node*& cur_node,int data){
		if (cur_node == NULL){
			cur_node = new node();
			cur_node->data = data;
			return;
		}
		else if (data < cur_node->data){
			AVL_insert(cur_node->leftchild, data);
			if (2 == height(cur_node->leftchild) - height(cur_node->rightchild)){
				if (data < cur_node->leftchild->data){
					single_left(cur_node);
				}
				else{
					double_left_right(cur_node);
				}
			}
		}
		else{
			AVL_insert(cur_node->rightchild, data);
			if (2 == height(cur_node->rightchild) - height(cur_node->leftchild)){
				if (data > cur_node->rightchild->data){
					single_right(cur_node);
				}
				else{
					double_right_left(cur_node);
				}
			}
		}
	}
	void midorder(node* cur_node){
		if (cur_node == NULL){
			return;
		}
		midorder(cur_node->leftchild);
		cout << cur_node->data << " ";
		midorder(cur_node->rightchild);
	}
	void preorder(node* cur_node){
		if (cur_node == NULL){
			return;
		}
		cout << cur_node->data << " ";
		preorder(cur_node->leftchild);
		preorder(cur_node->rightchild);
	}
};
int main(){
	AVL_tree t;
	int a[5] = { 1, 2, 3, 4, 5};
	for (int i = 0; i < 5; i++){
		t.AVL_insert(t.root, a[i]);
	}
	cout << endl;
	t.midorder(t.root);
	cout << endl;
	t.preorder(t.root);
	cout << endl;
	system("pause");
	return 0;
}