#include<iostream>
#include"Graph.h"
#include"NFA.h"
#include"DFA.h"
#include"MIN_DFA.h"
#include<string>
#define Start 0
#define Done 9999999
using namespace std;

void DFA2(Graph& DFA2_Graph,int num){
	Graph A;
	NFA nfa;
	string testcase = "letter(letter)*";
	node temp = nfa.NFA_expression(num, nfa.add_lianjie(testcase), A);
	Dfa dfa;
	Graph final_dfa_graph;
	set<int> dfa_states;
	set<int> final_states;
	dfa.graph_conversion(A, temp, final_dfa_graph, dfa_states, final_states);
	Min_Dfa min_dfa;
	min_dfa.quhao_daiti_statehao(final_dfa_graph, dfa_states, final_states);
}

int main(){
	Graph DFA2_Graph;
	int num = 0;
	system("pause");
	return 0;
}