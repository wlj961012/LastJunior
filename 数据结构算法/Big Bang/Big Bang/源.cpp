#include<iostream>
#include<string>
using namespace std;
struct node {
	string elem;
	node* next;
	node() {
		next = NULL;
	}
	node(string s) {
		elem = s;
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
	void insert(int e, string str) {
		if (e <= 0||e>len+1) {
			return;
		}
		node* p = head;
		for (int i = 1; i < e; i++) {
			p = p->next;
		}
		node* s;
		s = new node(str);
		s->next = p->next;
		p->next = s;
		len++;
	}
	void linkdelete(string str) {
		if (len <= 0) {
			return;
		}
		node* p = head->next;
		node* cur = head;
		while (p) {
			if (p->elem == str) {
				cur->next = cur->next->next;
				len--;
				delete p;
				break;
			}
			cur = p;
			p = p->next;
		}
	}
	void search(string str) {
		int len = 1;
		node* p = head->next;
		while (p) {
			if (p->elem == str) {
				cout << len << endl;
				break;
			}
			p = p->next;
			len++;
		}
	}
	void show() {
		node* p = head->next;
		while (p) {
			cout << p->elem << " ";
			p = p->next;
		}
		cout << endl;
	}
};
int main() {
	LinkList L;
	string str,name;
	int d;
	while (cin >> str) {
		if (str == "insert") {
			cin >> d >> name;
			L.insert(d, name);
		}
		else if (str == "delete") {
			cin >> name;
			L.linkdelete(name);
		}
		else if (str == "show") {
			L.show();
		}
		else if (str == "search") {
			cin >> name;
			L.search(name);
		}
	}
	system("pause");
	return 0;
}