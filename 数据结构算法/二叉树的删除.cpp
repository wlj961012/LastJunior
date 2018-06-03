#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct node{
	int data;
	bool visited;
	node* leftchild;
	node* rightchild;
	node(){
		leftchild = rightchild = NULL;
		visited = false;
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
			return;
		}
		else if (data < cur_node->data){
			insert(cur_node->leftchild, data);
		}
		else{
			insert(cur_node->rightchild, data);
		}
	}
	void traverse(node* cur_node){
		if (cur_node == NULL){
			return;
		}
		traverse(cur_node->leftchild);
		traverse(cur_node->rightchild);
		cout << cur_node->data << " ";
	}

	node* find_parent(node* cur_node, node* tmp){
		if (tmp == cur_node->leftchild || tmp == cur_node->rightchild){
			return cur_node;
		}
		else if (tmp->data < cur_node->data){
			find_parent(cur_node->leftchild, tmp);
		}
		else{
			find_parent(cur_node->rightchild, tmp);
		}
	}
	void delete_BST(node*& cur_node, int data){
		//首先找到cur_node 的位置；
		node* ptr=cur_node;
		while (ptr != NULL&&ptr->data != data){
			if (data < ptr->data){
				ptr = ptr->leftchild;;
			}
			else{
				ptr = ptr->rightchild;
			}
		}
		if (ptr->leftchild == NULL&&ptr->rightchild == NULL){
			node* temp = find_parent(root, ptr);
			if (temp->leftchild == ptr){
				temp->leftchild = NULL;
				delete(ptr);
			}
			else{
				temp->rightchild = NULL;
				delete(ptr);
			}
		}
		else if (ptr->leftchild == NULL || ptr->rightchild == NULL){
			node* temp = find_parent(root, ptr);
			if (ptr->leftchild != NULL){
				if (temp->leftchild = ptr){
					temp->leftchild = ptr->leftchild;
					delete(ptr);
				}
				else{
					temp->rightchild = ptr->leftchild;
					delete(ptr);
				}
			}
			else{
				if (temp->leftchild = ptr){
					temp->leftchild = ptr->rightchild;
					delete(ptr);
				}
				else{
					temp->rightchild = ptr->rightchild;
					delete(ptr);
				}
			}
		}
		else{
			node* temp = ptr->leftchild;
			while (temp->rightchild != NULL){
				temp = temp->rightchild;
			}
			node* temp_parent = find_parent(root, temp);
			ptr->data = temp->data;
			if (ptr->leftchild == temp){
				if (temp->leftchild != NULL){
					temp_parent->leftchild = temp->leftchild;
					delete(temp);
				}
				else{
					temp_parent->leftchild = NULL;
					delete(temp);
				}
			}
			else{
				if (temp->leftchild != NULL){
					temp_parent->rightchild = temp->leftchild;
					delete(temp);
				}
				else{
					temp_parent->rightchild = NULL;
					delete(temp);
				}
			}
		}
	}
	void levelorder(queue<node*> Q){
		while (Q.empty() == false){
			node* tmp = Q.front();
			if (tmp->leftchild != NULL){
				Q.push(tmp->leftchild);
			}
			if (tmp->rightchild != NULL){
				Q.push(tmp->rightchild);
			}
			cout << tmp->data << " ";
			Q.pop();
		}
	}
	void no_digui_midorder(stack<node*> S){
		while (S.empty() == false){
			if (S.top()->leftchild != NULL&&S.top()->leftchild->visited==false){
				S.push(S.top()->leftchild);
			}
			else{
				node* tmp = S.top();
				cout << tmp->data<<" ";
				tmp->visited = true;
				S.pop();
				if (tmp->rightchild != NULL&&tmp->rightchild->visited == false){
					S.push(tmp->rightchild);
				}
			}
		}
	}
	void no_digui_postorder(stack<node*> S){
		node* tmp = S.top();
		while (tmp->leftchild != NULL){
			tmp = tmp->leftchild;
			S.push(tmp);
		}
		char back='L';
		while (S.empty() == false){
			switch (back){
			case 'L':
				S.push(S.top()->rightchild);
				break;
			
			case 'R':
				back = 'L';
				cout << S.top()->data<<" ";
				S.pop();
			
			}
		}
		
	}
};
int main(){
	binary_tree t;
	int a[12] = { 15, 5, 16, 3, 12, 20, 10, 13, 18, 23, 6, 7 };
	for (int i = 0; i < 12; i++){
		t.insert(t.root, a[i]);
	}
	//queue<node*> Q;
	//Q.push(t.root);

	stack<node*> S;
	S.push(t.root);
	t.no_digui_postorder(S);
	cout << endl;
	//t.levelorder(Q);
	//t.delete_BST(t.root, 15);
	t.traverse(t.root);
	system("pause");
	return 0;
}