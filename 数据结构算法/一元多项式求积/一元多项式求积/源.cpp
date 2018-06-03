#include<iostream>
using namespace std;
struct node {
	int xishu;
	int zhishu;
	node* next;
	node() {
		next = NULL;
	}
	node(int x,int z) {
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
	node* get_head() {
		return head;
	}
	void insert(int x,int z) {
		if (z < 0) {
			return;
		}
		node *p = head;
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
	void print() {
		node *p = head->next;
		while (p) {
			cout << p->xishu << " " << p->zhishu << " ";
			p = p->next;
		}
		cout << endl;
	}
	void paixu() {
		node *L = head->next;
		node *p;
		node *q;
		int a, b;
		for (int i = 0; i < len; i++) {
			L = head->next;
			for (int j = 0; j < len-1; j++) {
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
void linkplus(LinkList L1,LinkList L2) {
	LinkList L3;
	node* p = L1.get_head()->next;
	int a, b;
	while (p != NULL) {
		node* q = L2.get_head()->next;
		while (q != NULL) {
			a = (p->xishu)*(q->xishu);
			b = (p->zhishu) + (q->zhishu);
			if (a != 0) {
				L3.insert(a, b);
			}
			q = q->next;
		}
		p = p->next;
	}
	if (L3.get_head()->next == NULL) {
		cout << 0 << endl;
	}
	L3.paixu();
	L3.print();
}
int main() {
	int a, b;
	LinkList L1;
	while (cin >> a >> b) {
		if (a == -1 && b == -1) {
			break;
		}
		L1.insert(a, b);
	}
	int c, d;
	LinkList L2;
	while (cin >> c >> d) {
		if (c == -1 && d == -1)
			break;
		L2.insert(c, d);
	}
	linkplus(L1, L2);
	system("pause");
	return 0;
}