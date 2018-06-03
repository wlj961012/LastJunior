#include<iostream>
using namespace std;
struct node {
	int data;
	node* next;
	node(int d) {
		data = d;
		next = NULL;
	}
};
class LinkList {
private:
	node * head;
public:
	LinkList() {
		head = new node(0);
	}
	node* get_head() {
		return head;
	}
	void insert(int d) {
		if (head->data == 0) {
			head->next = new node(d);
			head->data++;
			return;
		}
		node* p = head->next;
		node* cur = p;
		while (p) {
			cur = p;
			if (p->data > d) {
				return;
			}
			p = p->next;
		}
		cur->next = new node(d);
		head->data++;
	}
	void print() {
		node* p = head->next;
		while (p) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
};
void inter(LinkList L1,LinkList L2){
	LinkList L3;
	node* p = L1.get_head()->next;
	node* q = L2.get_head()->next;
	while (p!=NULL&&q!=NULL) {
		if (p->data < q->data) {
			L3.insert(p->data);
			p = p->next;
		}
		else {
			L3.insert(q->data);
			q = q->next;
		}
	}
	while (p) {
		L3.insert(p->data);
		p = p->next;
	}
	while (q) {
		L3.insert(q->data);
		q = q->next;
	}
	L3.print();
}
int main() {
	int len1, len2, a, b;
	while (cin >> len1) {
		LinkList L1, L2;
		for (int i = 0; i < len1; i++) {
			cin >> a;
			L1.insert(a);
		}
		cin >> len2;
		for (int i = 0; i < len2; i++) {
			cin >> b;
			L2.insert(b);
		}
		inter(L1, L2);
	}
	system("pause");
	return 0;
}
