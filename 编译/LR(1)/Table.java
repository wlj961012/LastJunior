package lr_1;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.TreeSet;

public class Table {
	
	private HashMap<Integer,TreeSet<Table_Node>> action_table;
	private HashMap<Integer,TreeSet<Table_Node>> goto_table;
	private HashMap<Integer,TreeSet<DFA_Node>> DFA_Graph;
	private HashMap<Integer,ArrayList<String>> num_css;
	private HashMap<String,Integer> css_num;
	private HashMap<Integer,ArrayList<String>> num_dfacss;
	private HashMap<Integer,TreeSet<State_Node>> state;
	private TreeSet<String> nonterm_set;
	private DFA dfa=new DFA();
	
	public String arr_to_string(ArrayList<String> css){
		String temp="";
		for(String i:css){
			temp+=i;
			i+=",";
		}
		return temp;
	}
	
	public void get_css_num(){
		for(Integer i:num_css.keySet()){
			css_num.put(arr_to_string(num_css.get(i)),i);
		}
	}
	
	public Table(){
		DFA_Graph=dfa.getDFA_Graph();
		num_css=dfa.getNum_css();
		css_num=new HashMap<String,Integer>();
		get_css_num();
		num_dfacss=dfa.getNum_dfacss();
		state=dfa.getState();
		action_table=new HashMap<Integer,TreeSet<Table_Node>>();
		goto_table=new HashMap<Integer,TreeSet<Table_Node>>();
		nonterm_set=dfa.getNonterm_set();
		get_table();
	}
	
	public void get_table(){
		for(Integer i:state.keySet()){//遍历状态表  
			if(!DFA_Graph.containsKey(i)){//如果该状态并未在DFA中的key出现代表该状态为终态
				for(State_Node j:state.get(i)){//找到该状态所对应的产生式
					ArrayList<String> temp=(ArrayList<String>) num_dfacss.get(j.getDfacss_num()).clone();
					if(temp.indexOf(".")==(temp.size()-1)){
						temp.remove(".");
						Integer num=css_num.get(arr_to_string(temp));
						if(!action_table.containsKey(i)){
							action_table.put(i,new TreeSet<Table_Node>());
						}
						String tempr="r";
						tempr+=num.toString();
						action_table.get(i).add(new Table_Node(j.getFollow_node(),tempr));
					}
				}
			}
			else{
				for(State_Node j:state.get(i)){
					ArrayList<String> temp=(ArrayList<String>) num_dfacss.get(j.getDfacss_num()).clone();
					if(temp.indexOf(".")==(temp.size()-1)){
						temp.remove(".");
						Integer num=css_num.get(arr_to_string(temp));
						if(!action_table.containsKey(i)){
							action_table.put(i,new TreeSet<Table_Node>());
						}
						String tempr="r";
						tempr+=num.toString();
						action_table.get(i).add(new Table_Node(j.getFollow_node(),tempr));
					}
					else{
						int index=temp.indexOf(".");
						if(nonterm_set.contains(temp.get(index+1))){//如果所对应的是非终结符 则应放在goto表上
							if(!goto_table.containsKey(i)){
								goto_table.put(i, new TreeSet<Table_Node>());
							}
							for(DFA_Node k:DFA_Graph.get(i)){
								if(k.getEdge().equals(temp.get(index+1))){
									goto_table.get(i).add(new Table_Node(k.getEdge(),new Integer(k.getState()).toString()));
								}
							}
						}
						else{
							if(!action_table.containsKey(i)){
								action_table.put(i,new TreeSet<Table_Node>());
							}
							for(DFA_Node k:DFA_Graph.get(i)){
								if(k.getEdge().equals(temp.get(index+1))){
									String temps="s";
									temps+=new Integer(k.getState()).toString();
									action_table.get(i).add(new Table_Node(k.getEdge(),temps));
								}
								
							}
						}
					}
				}
			}
		}
	}
	
	public static void main(String[] args){
		new Table();
	}
	
}
