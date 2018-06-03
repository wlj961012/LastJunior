#include<iostream>
using namespace std;
struct node {
	int xishu;
	int zhishu;
	node* next;
	node() {
		next = NULL;
	}
	node(int x, int z) {
		xishu = x;
		zhishu = z;
		next = NULL;
	}
};
class LinkList {
private:
	node * head;
	int len;
public:
	LinkList() {
		head = new node();
		len = 0;
	}
	node* gethead() {
		return head;
	}
	void insert(int x, int z) {
		if (z < 0||x==0) {
			return;
		}
		node* p = head;
		if (len == 0) {
			p->next = new node(x, z);
			len++;
			return;
		}
		while (p->next) {
			if (p->next->zhishu == z) {
				p->next->xishu += x;
				return;
			}
			p = p->next;
		}
		p->next = new node(x, z);
		len++;
	}
	void linkdelete(int data) {
		node* p = head;
		node* cur;
		while (p->next) {
			if (p->next->xishu == data) {
				cur = p->next;
				p->next = p->next->next;
				delete cur;
			}
		}
	}
	void print() {
		node* p = head->next;
		while (p) {
			cout << p->xishu << " " << p->zhishu << " ";
			p = p->next;
		}
		cout << endl;
	}
	void paixu() {
		node* L = head->next;
		node* p;
		node* q;
		int a, b;
		for (int i = 0; i < len; i++) {
			L = head->next;
			for (int j = 0; j < len - 1; j++) {
				p = L;
				q = L->next;
				if (p->zhishu < q->zhishu) {
					a = p->xishu;
					b = p->zhishu;
					p->xishu = q->xishu;
					p->zhishu = q->zhishu;
					q->xishu = a;
					q->zhishu = b;
				}
				L = L->next;
			}
		}
	}
};
void linkadd(LinkList L1,LinkList L2) {
	LinkList L3;
	node* p = L1.gethead()->next;
	node* q = L2.gethead()->next;
	while (p) {
		L3.insert(p->xishu, p->zhishu);
		p = p->next;
	}
	while (q) {
		L3.insert(q->xishu, q->zhishu);
		q = q->next;
	}
	L3.linkdelete(0);
	if (L3.gethead()->next==NULL) {
		cout << 0 << endl;
		return;
	}
	L3.paixu();
	L3.print();
}
int main() {
	int a, b,c,d;
	LinkList L1, L2;
	while (cin >> a >> b) {
		if (a == -1 && b == -1) {
			break;
		}
		L1.insert(a, b);
	}
	while (cin >> c >> d) {
		if (c == -1 && d == -1) {
			break;
		}
		L2.insert(c, d);
	}
	linkadd(L1, L2);
	system("pause");
	return 0;
}