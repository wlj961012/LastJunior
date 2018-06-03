#ifndef MIN_DFA_H
#define MIN_DFA_H

#include<iostream>
#include"Graph.h"
#include"NFA.h"
#include"DFA.h"
#include<map>
#include<set>
#include<string>

class Min_Dfa{
private:
	bool set_equals(std::set<int> set1, std::set<int> set2){//判断两个集合的大小是否相等
		if (set1.size() != set2.size()){
			return false;
		}
		return true;
	}
	bool set_equals(std::set<edge_node> set1, std::set<edge_node> set2, std::map<int, int> state_to_qu){
		//判断两个集合是否相等
		std::set<edge_node> new_set1, new_set2;
		for (auto it1 : set1){
			edge_node temp(state_to_qu[it1.index], it1.dis);
			new_set1.insert(temp);
		}
		for (auto it2 : set2){
			edge_node temp(state_to_qu[it2.index], it2.dis);
			new_set2.insert(temp);
		}
		std::set<edge_node>::iterator it1 = new_set1.begin(), it2 = new_set2.begin();
		while (it1 != new_set1.end() && it2 != new_set2.end()){
			if (it1->index == it2->index&&it1->dis == it2->dis){
				it1++;
				it2++;
			}
			else{
				return false;
			}
		}
		if (it1 == new_set1.end() && it2 == new_set2.end()){
			return true;
		}
		else{
			return false;
		}
	}
	std::set<int> set_divide(std::set<int> set1, std::set<int> set2){
		//去除集合一中与集合二相同的元素
		std::set<int>::iterator it = set1.begin();
		std::set<int> divide_set;
		for (; it != set1.end(); it++){
			if (!set2.count(*it)){
				divide_set.insert(*it);
			}
		}
		return divide_set;
	}
	std::map<int, std::set<int>> first_partition(Graph dfa_graph, std::set<int> dfa_states, std::set<int> final_states, int& qu_num){
		//第一次划分终态和非终态 返回区号和状态号所对应的图
		std::map<int, std::set<int>> first_graph;
		if (final_states.size() == dfa_states.size()){//如果所有状态都是终态，不必继续再分
			qu_num = 1;
			for (auto it : dfa_states){
				first_graph[1].insert(it);
			}
		}
		else{
			for (auto it : dfa_states){
				if (final_states.count(it)){
					first_graph[2].insert(it);
				}
				else{
					first_graph[1].insert(it);
				}
			}
			qu_num = 2;
		}
		return first_graph;
	}
	std::map<int, int> state_to_qu(std::map<int, std::set<int>> upper_graph, int qu_num){
		//由区号所对应的状态图 得到状态所对应的区号图
		std::map<int, int> state_to_qu_graph;
		for (int i = 1; i <= qu_num; i++){
			std::set<int>::iterator it = upper_graph[i].begin();
			for (; it != upper_graph[i].end(); it++){
				state_to_qu_graph[*it] = i;
			}
		}
		return state_to_qu_graph;
	}
	std::set<int> get_new_qus(Graph dfa_graph, std::map<int, int> state_to_qu, std::set<int> qu_states){
		//如果状态得到的其他状态与区的一个元素相同则把他们放入一个集合
		std::set<int> new_qu;
		new_qu.insert(*qu_states.begin());
		std::set<int>::iterator it = qu_states.begin();
		it++;
		while (it != qu_states.end()){
			if (set_equals(dfa_graph.mymap[*qu_states.begin()], dfa_graph.mymap[*it], state_to_qu)){
				new_qu.insert(*it);
			}
			it++;
		}
		return new_qu;
	}
	std::map<int, std::set<int>> other_partition(Graph dfa_graph, std::map<int, std::set<int>> upper_graph, int& qu_num){
		//得到其他的区
		int num = 0;
		std::map<int, int> state_to_qu_graph = state_to_qu(upper_graph, qu_num);
		std::map<int, std::set<int>> new_graph;
		int i;
		for (i = 1; i <= qu_num; i++){
			std::set<int> qu_states = upper_graph[i];
			std::set<int> new_qu_states;
			for (auto it : qu_states){
				new_qu_states = get_new_qus(dfa_graph, state_to_qu_graph, qu_states);
			}
			if (new_qu_states.size() != qu_states.size()){
				std::set<int> other_new_qu_states = set_divide(qu_states, new_qu_states);
				num++;
				new_graph[num] = new_qu_states;
				num++;
				new_graph[num] = other_new_qu_states;
				break;
			}
			else{
				num++;
				new_graph[num] = qu_states;
			}
		}
		while (i < qu_num){
			num++;
			i++;
			new_graph[num] = upper_graph[i];
		}
		qu_num = num;
		return new_graph;
	}
	std::map<int, std::set<int>> minimize_dfa(Graph dfa_graph, std::set<int> dfa_states, std::set<int> final_states, int& qu_num){
		int upper_qu_num = 1;
		std::map<int, std::set<int>> init_graph = first_partition(dfa_graph, dfa_states, final_states, qu_num);
		std::map<int, std::set<int>> upper_graph = init_graph;
		while (qu_num != upper_qu_num){
				upper_qu_num = qu_num;
				std::map<int, std::set<int>> new_graph = other_partition(dfa_graph, upper_graph, qu_num);
				upper_graph = new_graph;
		}
		std::cout << std::endl;
		for (int i = 1; i <= qu_num; i++){
			std::cout << i << "--->";
			for (auto it : upper_graph[i]){
				std::cout << it << "  ";
			}
			std::cout << std::endl;
		}
		return upper_graph;
	}
public:
	void quhao_daiti_statehao(Graph dfa_graph, std::set<int> dfa_states, std::set<int> final_states){
		int qu_num = 1;
		std::map<int, std::set<int>> qu_to_state = minimize_dfa(dfa_graph, dfa_states, final_states, qu_num);
		std::map<int, int> state_to_qu_graph = state_to_qu(qu_to_state, qu_num);
		std::cout << qu_num;
		Graph min_graph;
		for (int i = 1; i <= qu_num; i++){
			std::set<int> qu_states = qu_to_state[i];
			std::set<edge_node> edge = dfa_graph.mymap[*qu_states.begin()];
			std::set<edge_node>::iterator it = edge.begin();
			for (; it != edge.end(); it++){
				min_graph.insert(i, state_to_qu_graph[it->index], it->dis);
			}
		}
		std::cout << std::endl;
		for (int i = 1; i <= qu_num; i++){
			min_graph.traverse(i);
		}
	}
};

#endif