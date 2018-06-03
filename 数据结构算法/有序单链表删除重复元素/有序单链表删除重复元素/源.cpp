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
	void insert(int d) {
		node* p = head;
		while (p->next) {
			p = p->next;
		}
		p->next = new node(d);
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
	void linkdelete() {
		if (head->data == 1) {
			return;
		}
		node* p=head->next,*cur;
		while (p->next) {
			if (p->data == p->next->data) {
				cur = p->next;
				p->next = p->next->next;
				delete cur;
			}
			else {
				p = p->next;
			}
		}
	}
};
int main() {
	int len, a;
	while (cin >> len) {
		if (len == 0) {
			cout << "list is empty" << endl;
			continue;
		}
		LinkList L;
		for (int i = 0; i < len; i++) {
			cin >> a;
			L.insert(a);
		}
		L.print();
		L.linkdelete();
		L.print();
	}
	system("pause");
	return 0;
}