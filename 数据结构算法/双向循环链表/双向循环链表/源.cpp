#include<iostream>
using namespace std;
struct node {
	int data;
	node *next;
	node *prior;
	node() {
		next = NULL;
		prior = NULL;
	}
	node(int d) {
		data = d;
		next = NULL;
		prior = NULL;
	}
};
class DulLinkList {
private:
	node * head;
	int length;
public:
	DulLinkList() {
		head = new node();
		head->prior = head;
		head->next = head;
		length = 0;
	}
	void insert(int i,int d) {
		node *p = head,*s;
		int j = 1;
		p = p->next;
		while (j < i&&p!=head) {
			p = p->next;
			j++;
		}
		if (p == head&&j<i) {
			return;
		}
		s = new node(d);
		s->prior = p->prior;
		p->prior->next = s;
		s->next = p;
		p->prior = s;
		length++;
	}
	void print() {
		node *p = head->next;
		while (p != head) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	void linkdelete(int i) {
		node *p = head->next;
		if (p == head||i<1||i>length) {
			return;
		}
		int j = 1;
		while (p != head && j < i) {
			p = p->next;
			j++;
		}
		if (p == head && j < i) {
			return;
		}
		p->prior->next = p->next;
		p->next->prior = p->prior;
		delete p;
	}
};
int main() {
	DulLinkList L;
	int ope;
	while (cin >> ope) {
		int data1, data2;
		switch (ope)
		{
		case 1:
			cin >> data1 >> data2;
			L.insert(data1, data2);
			break;
		case 2:
			cin >> data1;
			L.linkdelete(data1);
			break;
		case 0:
			L.print();
			break;
		default:
			break;
		}
	}
	system("pause");
	return 0;
}