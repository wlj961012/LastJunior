#include<iostream>
#include<string>
#include<map>
#include<set>
#include<stack>
using namespace std;
struct edge_node{
	int index;
	char dis;
	edge_node* next;
	edge_node(int i, char d){
		index = i;
		dis = d;
		next = nullptr;
	}
};
struct node{
	int begin;
	int end;
	char edge;
	node(char s,int b=-1,int e=-1){
		edge = s;
		begin = b;
		end = e;
	}
	node(int b, int e, char s = '$'){
		begin = b;
		end = e;
	}
};
bool operator <(const edge_node left, const edge_node right){
	return left.index < right.index;
}
class Graph{
public:
	map<int, set<edge_node>> mymap;
	void insert(int begin, int end, char dis = '#'){
		edge_node temp(end, dis);
		mymap[begin].insert(temp);
	}
	void traverse(int begin){
		cout << begin << "-->";
		set<edge_node> myset = mymap[begin];
		set<edge_node>::iterator it = myset.begin();
		for (; it != myset.end(); it++){
			cout << it->index << "("<<it->dis<<")" << " ";
		}
		cout << endl;
	}
};
bool Iszimu(char s){
	if (s >= 'a'&&s <= 'z')
		return true;
	else
		return false;
}
string add_lianjie(string str1){
	string str2;
	int len = str1.length();
	for (int i = 0; i < len-1; i++){
		if (Iszimu(str1[i])){
			if (Iszimu(str1[i+1]) || str1[i + 1] == '('){
				str2 += str1[i];
				str2 += '-';
			}
			else
				str2 += str1[i];
		}
		else if (str1[i] == '*'&&Iszimu(str1[i+1])){
			str2 += str1[i];
			str2 += '-';
		}
		else if (str1[i] == ')'&&Iszimu(str1[i + 1])){
			str2 += str1[i];
			str2 += '-';
		}
		else str2 += str1[i];
	}
	str2 += str1[len-1];
	return str2;
}
string get_substr(int& i, string str){
	int k = 1;
	int len = str.length();
	string substr;
	i++;
	for (int j = i; j < len; j++){
		if (str[j] == '('){
			k++;
			substr += str[j];
			i++;
		}
		else if (str[j] == ')'){
			k--;
			substr += str[j];
			i++;
		}
		else{
			substr += str[j];
			i++;
		}
		if (k == 0){
			break;
		}
	}
	i--;
	substr.erase(substr.end()-1);//end 表示\0
	return substr;
}
int ope_level(char s){
	if (s == '*') return 4;
	if (s == '-') return 3;
	if (s == '|') return 2;
}
void Bibao_operation(int& num,stack<node>& point,Graph& graph){
	node cur = point.top();
	point.pop();
	int begin1, end1, begin, end;
	begin1 = cur.begin;
	end1 = cur.end;
	if (begin1 == -1){
		num++;
		begin1 = num;
		num++;
		end1 = num;
		graph.insert(begin1, end1, cur.edge);
		graph.insert(end1, begin1);
		num++;
		begin = num;
		graph.insert(begin, begin1);
		num++;
		end = num;
		graph.insert(end1, end);
		graph.insert(begin, end);
		node temp(begin, end);
		point.push(temp);
	}
	else{
		graph.insert(end1, begin1);
		num++;
		begin = num;
		graph.insert(begin, begin1);
		num++;
		end = num;
		graph.insert(end1, end);
		graph.insert(begin, end);
		node temp(begin, end);
		point.push(temp);
	}
}
void Lianjie_operation(int& num, stack<node>& point, Graph& graph){
	node right = point.top();
	point.pop();
	node left = point.top();
	point.pop();
	int begin1, end1, begin2, end2,begin,end;
	begin1 = left.begin;
	end1 = left.end;
	begin2 = right.begin;
	end2 = right.end;
	if (begin1 == -1 && end1 == -1&&begin2==-1&&end2==-1){
		num++;
		begin1 = num;
		num++;
		end1 = num;
		graph.insert(begin1, end1, left.edge);
		begin2 = end1;
		num++;
		end2 = num;
		graph.insert(begin2, end2, right.edge);
		begin = begin1;
		end = end2;
		node temp(begin, end);
		point.push(temp);
	}
	else if (begin1 == -1 && end1 == -1 && begin2 != -1 && end2 != -1){
		num++;
		begin1 = num;
		end1 = begin2;
		graph.insert(begin1, end1, left.edge);
		begin = begin1;
		end = end2;
		node temp(begin, end);
		point.push(temp);
	}
	else if (begin1 != -1 && end1 != -1 && begin2 == -1 && end2 == -1){
		begin2 = end1;
		num++;
		end2 = num;
		graph.insert(begin2, end2, right.edge);
		begin = begin1;
		end = end2;
		node temp(begin, end);
		point.push(temp);
	}
	else{
		begin = begin1;
		end = end2;
		graph.insert(end1, begin2);
		node temp(begin, end);
		point.push(temp);
	}
}
void Alter_operation(int& num, stack<node>& point, Graph& graph){
	node right = point.top();
	point.pop();
	node left = point.top();
	point.pop();
	int begin,end, begin1, end1, begin2, end2;
	begin1 = left.begin;
	end1 = left.end;
	begin2 = right.begin;
	end2 = right.end;
	if (begin1 == -1 && begin2 == -1){
		num++;
		begin1 = num;
		num++;
		end1 = num;
		graph.insert(begin1, end1, left.edge);
		num++;
		begin2 = num;
		num++;
		end2 = num;
		graph.insert(begin2, end2, right.edge);
		num++;
		begin = num;
		graph.insert(begin, begin1);
		graph.insert(begin, begin2);
		num++;
		end = num;
		graph.insert(end1, end);
		graph.insert(end2, end);
		node temp(begin, end);
		point.push(temp);
	}
	else if (begin1 == -1 && begin2 != -1){
		num++;
		begin1 = num;
		num++;
		end1 = num;
		graph.insert(begin1, end1, left.edge);
		num++;
		begin = num;
		graph.insert(begin, begin1);
		graph.insert(begin, begin2);
		num++;
		end = num;
		graph.insert(end1, end);
		graph.insert(end2, end);
		node temp(begin, end);
		point.push(temp);
	}
	else if(begin1 != -1 && begin2 == -1){
		num++;
		begin2 = num;
		num++;
		end2 = num;
		graph.insert(begin2, end2, right.edge);
		num++;
		begin = num;
		graph.insert(begin, begin1);
		graph.insert(begin, begin2);
		num++;
		end = num;
		graph.insert(end1, end);
		graph.insert(end2, end);
		node temp(begin, end);
		point.push(temp);
	}
	else{
		num++;
		begin = num;
		graph.insert(begin, begin1);
		graph.insert(begin, begin2);
		num++;
		end = num;
		graph.insert(end1, end);
		graph.insert(end2, end);
		node temp(begin, end);
		point.push(temp);
	}
}
node NFA_expression(int& num, string str,Graph& graph){
	int len = str.length();
	stack<node> point;
	stack<char> ope;
	for (int i = 0; i < len; i++){
		switch (str[i]){
		case '*':
			ope.push('*');
			break;
		case '|':
			while (ope.empty() == false&&(ope_level('|') < ope_level(ope.top()))){
				if (ope_level(ope.top()) == 4){
					Bibao_operation(num, point, graph);
					ope.pop();
				}
				else{
					Lianjie_operation(num, point, graph);
					ope.pop();
				}
			}
			ope.push('|');
			break;
		case '-':
			while (ope.empty()==false&&(ope_level('-') < ope_level(ope.top()))){
				Bibao_operation(num, point, graph);
				ope.pop();
			}
			ope.push('-');
			break;
		case '('://遇到括号开始递归
			point.push(NFA_expression(num, get_substr(i, str), graph));
			break;
		default:
			node temp(str[i]);
			point.push(temp);
			break;
		}
	}
	while (ope.empty() != true){
		switch (ope.top()){
		case '*':
			Bibao_operation(num, point, graph);
			ope.pop();
			break;
		case '-':
			Lianjie_operation(num, point, graph);
			ope.pop();
			break;
		default:
			Alter_operation(num, point, graph);
			ope.pop();
			break;
		}
	}
	return point.top();
}
int main(){
	Graph A;
	string testcase = "(a|b)*a";
	int num = 0;//顶点数
	node temp=NFA_expression(num, add_lianjie(testcase), A);
	cout << temp.begin << " " << temp.end << endl;
	for (int j = 1; j <= num; j++){
		A.traverse(j);
	}
	system("pause");
	return 0;
}