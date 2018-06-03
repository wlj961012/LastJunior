#include<iostream>
using namespace std;
struct node{
	int data;
	node* leftchild;
	node* rightchild;
	node(){
		leftchild = rightchild = NULL;
	}
	
};
class binary_tree{
public:
	node* root;
	binary_tree(){
		root = NULL;
	}
	void insert(node*& cur_node, int data){
		if (cur_node == NULL){
			cur_node = new node();
			cur_node->data = data;
			//cur_node->leftchild = cur_node->rightchild = NULL;
			return;
		}
		else if (data < cur_node->data){
			insert(cur_node->leftchild, data);
		}
		else{
			insert(cur_node->rightchild, data);
		}
	}
	void tranver(node* cur_node){
		if (cur_node == NULL){
			return;
		}
		tranver(cur_node->leftchild);
		cout << cur_node->data << " ";
		tranver(cur_node->rightchild);
	}
};
int main(){
	binary_tree t1;
	int a[7] = { 2, 5, 6, 7, 9, 10, 8 };
	for (int i = 0; i < 7; i++){
		t1.insert(t1.root, a[i]);
	}
	t1.tranver(t1.root);
	system("pause");
	return 0;
}