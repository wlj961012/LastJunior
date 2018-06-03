#ifndef NFA_H
#define NFA_H

#include<iostream>
#include<string>
#include<stack>
#include"Graph.h"

struct node{
	int begin;
	int end;
	std::string edge;
	node(std::string s, int b = -1, int e = -1){
		edge = s;
		begin = b;
		end = e;
	}
	node(int b, int e, std::string s = "$"){
		begin = b;
		end = e;
	}
};

class NFA{
private:
	bool Iszimu(char s){//判断是否为字母
		if (s >= 'a'&&s <= 'z')
			return true;//是字母返回真，否则返回假
		else
			return false;
	}
	std::string get_substr(int& i, std::string str){//得到与左括号相匹配右括号之间的所有字符
		int k = 1;//k遇到左括号加一，遇到右括号减一
		int len = str.length();
		std::string substr;
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
		i--;//由于k=0时，i加了一因此要减去一
		substr.erase(substr.end() - 1);//由于k=0时，字符串多加了一个字符
		return substr;
	}
	std::string get_point(int& i, std::string str){
		std::string str2 = "";
		int len = str.length();
		for (; i < len; i++){
			if ((str[i] >= 'a'&&str[i] <= 'z') || (str[i] >= 'A'&&str[i] <= 'Z')){
				str2 += str[i];
			}
			else{
				break;
			}
		}
		i--;
		return str2;
	}
	int ope_level(char s){//各操作符的优先级
		if (s == '*') return 4;
		if (s == '-') return 3;
		if (s == '|') return 2;
	}
	void Bibao_operation(int& num, std::stack<node>& point, Graph& graph){//闭包操作
		node cur = point.top();//由于闭包是单目运算符因此只取一个操作数
		point.pop();
		int begin1, end1, begin, end;
		begin1 = cur.begin;//操作数的开始结点
		end1 = cur.end;//操作数的终点
		if (begin1 == -1){//如果操作数没有在图中，则需要将操作数放入图中
			num++;
			begin1 = num;
			num++;
			end1 = num;
			graph.insert(begin1, end1, cur.edge);//将操作数放入图中
			graph.insert(end1, begin1);
			num++;
			begin = num;//闭包操作后的起点
			graph.insert(begin, begin1);//起点与操作数的起点插一条空边
			num++;
			end = num;//闭包操作后的终点
			graph.insert(end1, end);//终点与操作数的终点插一条空边
			graph.insert(begin, end);//操作数的起点与操作数的终点插一条空边
			node temp(begin, end);
			point.push(temp);//将闭包操作完后的起点和终点压入操作数栈中
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
	void Lianjie_operation(int& num, std::stack<node>& point, Graph& graph){//连接操作
		node right = point.top();//取出链接操作的右运算符
		point.pop();
		node left = point.top();//取出连接操作的左运算符
		point.pop();
		int begin1, end1, begin2, end2, begin, end;
		begin1 = left.begin;//左操作数的起点
		end1 = left.end;
		begin2 = right.begin;//右操作数的起点
		end2 = right.end;
		if (begin1 == -1 && end1 == -1 && begin2 == -1 && end2 == -1){//如果左右操作数都没有在图中
			num++;
			begin1 = num;
			num++;
			end1 = num;
			graph.insert(begin1, end1, left.edge);//将左操作数插入图中
			begin2 = end1;//右操作数的起点为左操作数的终点
			num++;
			end2 = num;
			graph.insert(begin2, end2, right.edge);//将右操作数插入图中
			begin = begin1;
			end = end2;
			node temp(begin, end);
			point.push(temp);//将结果压入栈中
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
	void Alter_operation(int& num, std::stack<node>& point, Graph& graph){
		node right = point.top();//取右操作数
		point.pop();
		node left = point.top();//做操作数
		point.pop();
		int begin, end, begin1, end1, begin2, end2;
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
			begin = num;//连接操作的起点
			graph.insert(begin, begin1);
			graph.insert(begin, begin2);
			num++;
			end = num;//连接操作的终点
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
		else if (begin1 != -1 && begin2 == -1){
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
public:
	node NFA_expression(int& num, std::string str, Graph& graph){
		int len = str.length();
		std::stack<node> point;
		std::stack<char> ope;
		for (int i = 0; i < len; i++){//优先级操作
			switch (str[i]){
			case '*':
				ope.push('*');
				break;
			case '|'://选择操作符的优先级小于闭包和连接，压入符号栈时要考虑之前的操作符时闭包还是连接
				while (ope.empty() == false && (ope_level('|') < ope_level(ope.top()))){
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
				while (ope.empty() == false && (ope_level('-') < ope_level(ope.top()))){
					Bibao_operation(num, point, graph);
					ope.pop();
				}
				ope.push('-');
				break;
			case '('://遇到括号开始递归
				point.push(NFA_expression(num, get_substr(i, str), graph));
				break;
			default://遇到操作数压入栈中
				node temp(get_point(i,str));
				point.push(temp);
				break;
			}
		}
		while (ope.empty() != true){//取出操作符栈，进行操作
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
	std::string add_lianjie(std::string str1){//添加连接符号
		std::string str2;
		int len = str1.length();
		for (int i = 0; i < len - 1; i++){
			if (Iszimu(str1[i])){
				if (str1[i + 1] == '('){
					str2 += str1[i];
					str2 += '-';
				}
				else
					str2 += str1[i];
			}
			else if (str1[i] == '*'&&Iszimu(str1[i + 1])){
				str2 += str1[i];
				str2 += '-';
			}
			else if (str1[i] == ')'&&Iszimu(str1[i + 1])){
				str2 += str1[i];
				str2 += '-';
			}
			else str2 += str1[i];
		}
		str2 += str1[len - 1];
		return str2;
	}
};

#endif