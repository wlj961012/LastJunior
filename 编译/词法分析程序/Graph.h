#ifndef GRAPH_H
#define GRAPH_H

#include<map>
#include<set>
#include<iostream>
#include<string>

struct edge_node{
	int index;//终点
	std::string dis;//距离
	edge_node* next;
	edge_node(int i, std::string d){//初始化
		index = i;//边的终点
		dis = d;//边的信息
		next = nullptr;//空指针
	}
};
bool operator <(const edge_node left, const edge_node right){//操作符重载
	if (left.index != right.index){
		return left.index < right.index;//边集合的信息按边的终点大小排列
	}
	else{
		return left.dis < right.dis;
	}
}
class Graph{
public:
	std::set<edge_node> find(int temp){
		return mymap[temp];
	}
	std::map<int, std::set<edge_node>> mymap;//graph的结构
	void insert(int begin, int end, std::string dis = "#"){//在图中插入一条边
		edge_node temp(end, dis);
		mymap[begin].insert(temp);
	}
	void traverse(int begin){//遍历
		std::cout << begin << "-->";
		std::set<edge_node> myset = mymap[begin];//value是一个set
		std::set<edge_node>::iterator it = myset.begin();//集合的指针
		for (; it != myset.end(); it++){
			std::cout << it->index << "(" << it->dis << ")" << " ";
		}
		std::cout << std::endl;
	}
};

#endif