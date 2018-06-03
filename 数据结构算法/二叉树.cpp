#include<iostream>
#include<queue>
#include<stack>
using namespace std;
struct  node{
	int data;
	bool visit;
	node* leftchild;
	node* rightchild;
	node(){
		visit = false;
		leftchild = rightchild = NULL;
	}
	node(int d){
		data = d;
		leftchild = rightchild = NULL;
		visit = false;
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
			cur_node->leftchild = cur_node->rightchild = NULL;
			return;
		}
		else if (data < cur_node->data){
			insert(cur_node->leftchild, data);
		}
		else{
			insert(cur_node->rightchild, data);
		}
	}
	node* find_parent(node* cur_node, node* point){
		if (cur_node->leftchild == point || cur_node->rightchild==point){
			return cur_node;
		}
		else if (cur_node->data > point->data){
			find_parent(cur_node->leftchild, point);
		}
		else{
			find_parent(cur_node->rightchild, point);
		}
	}
	void delete_BST(node*& cur_node, node* point){
		//首先应找到要删除的点
		node* ptr=cur_node;
		while (ptr != NULL&&!(ptr->data== point->data)){
			if (point->data<ptr->data){
				ptr = ptr->leftchild;
			}
			else{
				ptr = ptr->rightchild;
			}
		}
		if (ptr->leftchild == NULL&&ptr->rightchild == NULL){
			node* temp=find_parent(root,ptr);
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
			if (temp->leftchild == ptr){
				if (ptr->leftchild != NULL){
					temp->leftchild = ptr->leftchild;
					delete(ptr);
				}
				else{
					temp->leftchild = ptr->rightchild;
					delete(ptr);
				}
			}
			else{
				if (ptr->leftchild != NULL){
					temp->rightchild = ptr->leftchild;
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
			if (temp == ptr->leftchild){
				if (temp->leftchild != NULL){
					ptr->leftchild = temp->leftchild;
					ptr->data = temp->data;
					delete(temp);
				}
				else{
					ptr->data = temp->data;
					delete(temp);
				}
			}
			else{
				node* temp_parent = find_parent(root, temp);
				if (temp->leftchild == NULL){
					ptr->data = temp->data;
					temp_parent->rightchild = NULL;
					delete(temp);
				}
				else{
					ptr->data = temp->data;
					temp_parent->rightchild = temp->leftchild;
					delete(temp);
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
	void levelorder(queue<node*> q){
		while (q.empty()==false){
			node* temp = q.front();
			if (temp->leftchild != NULL){
				q.push(temp->leftchild);
			}
			if (temp->rightchild != NULL){
				q.push(temp->rightchild);
			}
			cout << temp->data << " ";
			q.pop();
		}
	}
	void nodigui_midorder(stack<node*> s){
		while (s.empty() == false){
			if (s.top()->leftchild != NULL&&s.top()->leftchild->visit == false){
				s.push(s.top()->leftchild);
			}
			else{
				node* temp = s.top();
				cout << temp->data << " ";
				temp->visit = true;
				s.pop();
				if (temp->rightchild != NULL&&temp->rightchild->visit == false){
					s.push(temp->rightchild);
				}
			}
		}
	}
};
int main(){
	binary_tree t1;
	int a[12] = { 15, 5, 16, 3, 12, 20, 10, 13, 18, 23, 6, 7 };
	for (int i = 0; i < 12; i++){
		t1.insert(t1.root, a[i]);
	}
	//t1.midorder(t1.root);
	/*int d;
	cout << endl;
	cout << "请输入你想删除的数字：" << endl;
	cin >> d;
	node* temp=new node(d);
	t1.delete_BST(t1.root, temp);*/
	/*queue<node*> Q;
	Q.push(t1.root);
	cout <<endl<< "层次序遍历:" << endl;
	t1.levelorder(Q, t1.root);
	cout << endl;*/
	stack<node*> S;
	S.push(t1.root);
	cout << endl << "非递归的中序遍历：" << endl;
	t1.nodigui_midorder(S);
	cout <<endl<< "中序遍历：" << endl;
	t1.midorder(t1.root);
	system("pause");
	return 0;
}