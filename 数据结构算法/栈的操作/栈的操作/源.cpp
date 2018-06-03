#include<iostream>
#include<string>
using namespace std;
struct node{
	int data;
	node* next;
	node(int d) {
		data = d;
		next = NULL;
	}
};
class Stack {
private:
	node * head;
	node *tail;
public:
	Stack() {
		head = new node(0);
		tail = head;
	}
	void push(int d) {
		node *s;
		s = new node(d);
		tail->next = s;
		tail = s;
		tail->next = NULL;
		head->data++;
	}
	void pop() {
		if (head->data == 0) {
			return;
		}
		node *p = head;
		while (p->next != tail) {
			p = p->next;
		}
		node *cur = tail;
		cout << tail->data << " ";
		tail = p;
		tail->next = NULL;
		head->data--;
		delete cur;
	}
	int top() {
		return tail->data;
	}
	bool is_empty() {
		return head->data == 0;
	}
};
bool operation(string str) {
	Stack s;
	int len = str.size();
	int a = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == 'P') {
			a++;
			s.push(a);
		}
		else if (str[i] == 'Q') {
			if (s.is_empty()) {
				return false;
			}
			else {
				s.pop();
			}
		}
	}
	return true;
}
int main() {
	string str;
	while (cin >> str) {
		if (!operation(str)) {
			cout << "error" << endl;
		}
		else {
			cout << endl;
		}
	}
	system("pause");
	return 0;
}