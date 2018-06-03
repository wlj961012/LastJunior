#include<iostream>
using namespace std;
struct node {
	int data;
	node *next;
	node(int d) {
		data = d;
		next = NULL;
	}
	node() {
		next = NULL;
	}
};
class LinkList {
private:
	node *tail;
public:
	node * head;
	LinkList() {
		head = new node();
		tail = head;
	}
	void insert(int d) {
		node *s;
		s = new node(d);
		tail->next = s;
		tail = s;
		tail->next = NULL;
	}
	void print() {
		node *p = head->next;
		while (p!=NULL) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
};
void linkdelete(LinkList &L) {
	if (L.head->next->next == NULL) {
		return;
	}
	node *p = L.head, *cur;
	while (p->next != NULL) {
		if (p->next->next != NULL) {
			if (p->next->data == p->next->next->data) {
				cur = p->next;
				p->next = p->next->next;
				delete cur;
			}
			else {
				p = p->next;
			}
		}
		else {
			p = p->next;
		}
	}
}
int main() {
	int len, data;
	while (cin >> len) {
		LinkList L;
		while (len--) {
			cin >> data;
			L.insert(data);
		}
		if (L.head->next!=NULL) {
			L.print();
			linkdelete(L);
			L.print();
		}
		else {
			cout << "list is empty" << endl;
		}
	}
	system("pause");
	return 0;
}