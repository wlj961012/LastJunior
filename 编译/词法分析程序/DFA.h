#ifndef DFA_H
#define DFA_H

#include<iostream>
#include"Graph.h"
#include"NFA.h"
#include<queue>
#include<string>

struct dfa_edge_node{
	std::string end_state;//dfa的终态
	std::string edge;//dfa图边的信息
	dfa_edge_node* next;
	dfa_edge_node(std::string e, std::string ed){
		end_state = e;
		edge = ed;
		next = nullptr;
	}
};
bool operator <(const dfa_edge_node left, const dfa_edge_node right){//操作符重载
	return left.edge < right.edge;
}
class DFA_Graph{
public:
	std::map<std::string, std::set<dfa_edge_node>> dfa_graph;
	void dfagraph_insert(std::string beginstate, std::string endstate,std::string edge){//插入函数
		dfa_edge_node temp(endstate, edge);
		dfa_graph[beginstate].insert(temp);
	}
	void dfagraph_traverse(std::string beginstate){//遍历dfa图
		std::cout << beginstate << "---->";
		std::set<dfa_edge_node> dfa_tuple = dfa_graph[beginstate];
		std::set<dfa_edge_node>::iterator it = dfa_tuple.begin();
		for (; it != dfa_tuple.end(); it++){
			std::cout << it->end_state << "(" << it->edge << ")" << " ";
		}
		std::cout << std::endl;
	}
};

struct dfa_node{//dfa结点表示dfa图结点所表示的状态以及状态所产生的顺序
	std::string sta;//状态
	int sta_num;//状态所产生的顺序
	dfa_node(std::string s, int sn){
		sta = s;
		sta_num = sn;
	}
};
bool operator <(const dfa_node left, const dfa_node right){
	return left.sta_num < right.sta_num;
}


class Dfa{
private:
	std::string set_to_string(std::set<int> point_set){//将集合转换成字符串型
		std::string state = "";
		std::set<int>::iterator it = point_set.begin();
		for (; it != point_set.end(); it++){
			state += std::to_string(*it);//将整型转换成字符串类型
			state += ",";
		}
		return state;
	}
	std::set<int> string_to_set(std::string str){//将字符串型转换成整型的集合 返回nfa中状态集合的子集
		int len = str.length();
		std::set<int> state_nums;
		int num = 0;
		for (int i = 0; i < len; i++){
			if (str[i] == ','){
				state_nums.insert(num);
				num = 0;
			}
			else{
				num = num * 10 + (str[i] - '0');
			}
		}
		return state_nums;
	}
	std::set<int> set_union(std::set<int> set1, std::set<int> set2){//对两个整数集合求并集返回并集
		std::set<int>::iterator it = set2.begin();
		for (; it != set2.end(); it++){
			if (set1.count(*it) == false){
				set1.insert(*it);
			}
		}
		return set1;
	}
	std::set<dfa_node> set_union(std::set<dfa_node> set1, std::set<dfa_node> set2){
		//去除set1集合中与set2集合相同的元素 返回set1
		std::set<dfa_node>::iterator it1;
		std::set<dfa_node>::iterator it2;
		for (it1 = set1.begin(); it1 != set1.end(); it1++){
			for (it2 = set2.begin(); it2 != set2.end(); it2++){
				if (it1->sta != it2->sta){
					set1.insert(*it2);
				}
			}
		}
		return set1;
	}
	std::set<dfa_node> set_divide(std::set<dfa_node> set1, std::set<dfa_node> set2){//集合的差
		std::set<dfa_node> divide_set = set1;
		std::set<dfa_node>::iterator it1, it2;
		for (it1 = set1.begin(); it1 != set1.end(); it1++){
			for (it2 = set2.begin(); it2 != set2.end(); it2++){
				if (it1->sta == it2->sta){
					divide_set.erase(*it1);
				}
			}
		}
		return divide_set;
	}
	std::set<int> e_closure(Graph graph, int tmp){
		//对点进行e合并
		//采用bfs方法来找到点通过任意空边所能到达地点集
		std::queue<int> q;
		q.push(tmp);//将点放入队列
		std::set<int> visited;//通过集合判断点是否被访问过，同时得到这些点集
		while (q.empty() == false){
			if (visited.count(q.front())){//如果这个点被访问过
				q.pop();
				continue;
			}
			else{
				int temp = q.front();
				visited.insert(temp);
				std::set<edge_node> find_point = graph.find(temp);
				std::set<edge_node>::iterator it = find_point.begin();
				for (; it != find_point.end(); it++){
					if (it->dis == "#"){//如果通过是空边放入队列中
						q.push(it->index);
					}
				}
				q.pop();
			}
		}
		return visited;
	}
	std::set<int> e_closure(Graph graph, std::set<int> point_set){//状态集地e合并 返回状态集
		std::set<int> get_point_set;
		std::set<int> visited;
		std::queue<int> Q;
		std::set<int>::iterator it_point = point_set.begin();
		for (; it_point != point_set.end(); it_point++){
			Q.push(*it_point);
		}
		while (!Q.empty()){
			if (visited.count(Q.front())){
				Q.pop();
				continue;
			}
			else{
				int temp = Q.front();
				get_point_set = set_union(e_closure(graph, temp), get_point_set);
				std::set<int>::iterator it = get_point_set.begin();
				for (; it != get_point_set.end(); it++){
					Q.push(*it);
				}
				visited.insert(temp);
				Q.pop();
			}
		}
		return get_point_set;
	}
	std::set<std::string> get_nfa_edge(Graph graph, int begin){
		//得到nfa中除了空边所有边地信息
		std::set<std::string> all_edge;//返回所有边的信息集合 
		//采用bfs方法得到所有边的信息
		std::queue<int> Q;
		Q.push(begin);
		std::set<int> visited;
		while (Q.empty() == false){
			if (visited.count(Q.front())){
				Q.pop();
				continue;
			}
			else{
				visited.insert(Q.front());
				std::set<edge_node> point_edge = graph.mymap[Q.front()];
				std::set<edge_node>::iterator it = point_edge.begin();
				for (; it != point_edge.end(); it++){
					Q.push(it->index);
					if (it->dis != "#"){
						all_edge.insert(it->dis);
					}
				}
				Q.pop();
			}
		}
		return all_edge;
	}
	std::set<int> state_conversion(std::set<int> cur_beginstate, std::string cur_edge, Graph graph){
		//NFA状态经过输入符号后产生地状态
		std::set<int>::iterator it_state = cur_beginstate.begin();
		std::set<int> cur_endstate;
		for (; it_state != cur_beginstate.end(); it_state++){
			std::set<edge_node> nfa_edge = graph.mymap[*it_state];//取出当前点所对应边的集合
			std::set<edge_node>::iterator it = nfa_edge.begin();
			for (; it != nfa_edge.end(); it++){
				if (it->dis == cur_edge){
					cur_endstate.insert(it->index);
				}
			}
		}
		cur_endstate = e_closure(graph, cur_endstate);
		return cur_endstate;
	}
	std::set<dfa_node> DFA(Graph graph, node temp, DFA_Graph& dfa_graph){
		int dfa_num = 0;
		std::set<dfa_node> state, dfa_state;//新产生地状态集 dfa当前所有状态集
		std::set<int> init_set = e_closure(graph, temp.begin);//初始状态集合
		std::string s = set_to_string(init_set);
		dfa_num++;
		dfa_node dfa_temp(s, dfa_num);//放入初态
		state.insert(dfa_temp);
		dfa_state.insert(dfa_temp);
		std::queue<std::string> Q;
		Q.push(s);
		std::set<std::string> visited;
		std::set<std::string> all_edge = get_nfa_edge(graph, temp.begin);
		while (Q.empty() == false){
			if (visited.count(Q.front())){
				Q.pop();
				continue;
			}
			else{
				std::set<std::string>::iterator it_edge = all_edge.begin();
				for (; it_edge != all_edge.end(); it_edge++){//某状态通过边得到所有状态
					std::set<int> cur_state = string_to_set(Q.front());//当前状态所包含地nfa状态
					std::set<int> new_set = state_conversion(cur_state, *it_edge, graph);
					std::string new_state = set_to_string(e_closure(graph, new_set));
					if (!new_state.empty()){
						dfa_graph.dfagraph_insert(Q.front(), new_state, *it_edge);
						dfa_num++;
						dfa_node dfa_temp(new_state, dfa_num);
						state.insert(dfa_temp);
					}
				}
				state = set_divide(state, dfa_state);
				dfa_state = set_union(dfa_state, state);
				visited.insert(Q.front());
				std::set<dfa_node>::iterator it_state = state.begin();
				for (; it_state != state.end(); it_state++){
					Q.push(it_state->sta);
				}
				Q.pop();
			}
		}
		int num = 0;//所产生地状态可能通过差集操作去掉 因此dfa_num可能不具连续性 通过num构造连续性
		std::set<dfa_node>::iterator it = dfa_state.begin();
		std::set<dfa_node> new_dfa_state;
		for (; it != dfa_state.end(); it++){
			num++;
			dfa_node tmp(it->sta, num);
			new_dfa_state.insert(tmp);
		}
		return new_dfa_state;
	}
public:
	//将原来产生状态集为string化为int型
	void graph_conversion(Graph A, node temp, Graph& final_dfa_graph,std::set<int>& dfa_states,std::set<int>& final_states){
		DFA_Graph Dfa_graph;
		std::set<dfa_node> dfa_state = DFA(A, temp, Dfa_graph);
		std::set<std::string> all_edge = get_nfa_edge(A, temp.begin);
		std::queue<dfa_node> Q;
		Q.push(*dfa_state.begin());
		std::set<dfa_node> visited;
		while (!Q.empty()){
			if (visited.count(Q.front())){
				Q.pop();
				continue;
			}
			else{
				int begin = Q.front().sta_num;
				std::set<dfa_edge_node> dfa_point_edge = Dfa_graph.dfa_graph[Q.front().sta];
				std::set<dfa_edge_node>::iterator it1 = dfa_point_edge.begin();
				std::set<dfa_node>::iterator it2;
				for (; it1 != dfa_point_edge.end(); it1++){
					for (it2 = dfa_state.begin(); it2 != dfa_state.end(); it2++){
						if (it1->end_state == it2->sta){
							final_dfa_graph.insert(begin, it2->sta_num, it1->edge);
							Q.push(*it2);
						}
					}
				}
				visited.insert(Q.front());
				Q.pop();
			}
		}
		std::set<dfa_node>::iterator it3 = dfa_state.begin();
		for (; it3 != dfa_state.end(); it3++){
			final_dfa_graph.traverse(it3->sta_num);
		}
		for (auto it : dfa_state){
			std::set<int> visited =string_to_set(it.sta);
			if (visited.count(temp.end)){
				final_states.insert(it.sta_num);
			}
			dfa_states.insert(it.sta_num);
		}
	}

};

#endif