#include<iostream>
#include<string>
using namespace std;
struct node {
	int len;
	char elem;
	node* next;
	node(int l,int e) {
		len = l;
		elem = e;
		next = NULL;
	}
	node() {
		next = NULL;
	}
};
class Stack {
private:
	node * head;
	node * tail;
	int length;
public:
	Stack() {
		head = new node();
		tail = head;
		length = 0;
	}
	bool is_empty() {
		return length == 0;
	}
	void insert(int len,char elem) {
		node* s = new node(len, elem);
		tail->next = s;
		tail = s;
		tail->next = NULL;
		length++;
	}
	void stack_delete() {
		if (length <= 0) {
			return;
		}
		node* p = head;
		while (p->next!=tail) {
			p = p->next;
		}
		node* cur = tail;
		cout << tail->len << " ";
		tail = p;
		p->next = NULL;
		length--;
		delete cur;
	}
	void add() {
		node* p = head->next;
		while (p) {
			p->len++;
			p = p->next;
		}
	}
};
void kuohao(string str) {
	Stack s;
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (str[i] == '(') {
			s.insert(1, '(');
		}
		else if (str[i] == ')') {
			if (!s.is_empty()) {
				s.stack_delete();
				s.add();
			}
		}
	}
	cout << endl;
}
int main() {
	string str;
	while (cin >> str) {
		kuohao(str);
	}
	system("pause");
	return 0;
}