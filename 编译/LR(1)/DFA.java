package lr_1;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Queue;
import java.util.TreeSet;

public class DFA {
	
	private HashMap<Integer,TreeSet<DFA_Node>> DFA_Graph;
	private HashMap<Integer,ArrayList<String>> num_dfacss;
	private HashMap<String,Integer> dfacss_num;
	private HashMap<Integer,TreeSet<State_Node>> state;
	private int state_num=0;
	DFA_css dfa_css=new DFA_css();
	Fileiostream fis=new Fileiostream("E:\\IN\\LR1_input.txt");
	private TreeSet<String> nonterm_set;
	public TreeSet<String> getNonterm_set() {
		return nonterm_set;
	}

	private TreeSet<String> term_set;
	private HashMap<Integer,ArrayList<String>> num_css;
	

	public HashMap<Integer, ArrayList<String>> getNum_dfacss() {
		return num_dfacss;
	}

	public HashMap<Integer, TreeSet<DFA_Node>> getDFA_Graph() {
		return DFA_Graph;
	}

	public HashMap<Integer, TreeSet<State_Node>> getState() {
		return state;
	}

	public HashMap<Integer, ArrayList<String>> getNum_css() {
		return num_css;
	}

	public DFA(){
		num_dfacss=dfa_css.getNum_dfacss();
		dfacss_num=dfa_css.getDfacss_num();
		state=new HashMap<Integer,TreeSet<State_Node>>();
		DFA_Graph=new HashMap<Integer,TreeSet<DFA_Node>>();
		nonterm_set=fis.getNonterm_set();
		term_set=fis.getTerm_set();
		num_css=fis.getCss_num();
		for(String i:dfacss_num.keySet()){
			System.out.println(dfacss_num.get(i)+"  "+i);
		}
		get_first_dfastate();
	}
	
	public String arr_to_string(ArrayList<String> css){
		String temp="";
		for(String i:css){
			temp+=i;
			temp+=",";
		}
		return temp;
	}
	
	public void get_first_dfastate(){//得到第一个状态
		state_num++;
		TreeSet<State_Node> statenodes=new TreeSet<State_Node>();
		statenodes.add(new State_Node(1,"$"));
		closure(statenodes);
		state.put(state_num,statenodes);
		DFA_Graph.put(state_num,new TreeSet<DFA_Node>());//在DFA图上建立第一个状态
		get_other_state(state_num);
		for(Integer i:state.keySet()){
			System.out.print(i+"   ");
			for(State_Node j:state.get(i)){
				System.out.print(j.getDfacss_num()+"  "+j.getFollow_node()+"  ");
			}
			System.out.println("  ");
		}
		for(Integer i:DFA_Graph.keySet()){
			System.out.print(i+"   ");
			for(DFA_Node j:DFA_Graph.get(i)){
				System.out.print(j.getEdge()+"   "+j.getState()+"   ");
			}
			System.out.println(" ");
		}
	}
	
	public void closure(TreeSet<State_Node> statenodes){
		Queue<State_Node> Q=new ArrayDeque<State_Node>();
		TreeSet<State_Node> visited=new TreeSet<State_Node>();
		for(State_Node i:statenodes){//找到可以闭包的产生式
			ArrayList<String> temp=num_dfacss.get(i.getDfacss_num());
			int index=temp.indexOf(".");
			int len=temp.size();
			if(index<len-1){//当前状态不为归约项目时 获取点后面的符号 如果是非终结符则产生初始项
				if(nonterm_set.contains(temp.get(index+1))){
					Q.offer(i);
				}
			}
		}
		while(!Q.isEmpty()){//如果队列非空
			//找到其所对应的非终结符 
		    State_Node temp=Q.poll();
		    visited.add(temp);
		    ArrayList<String> arrtemp=num_dfacss.get(temp.getDfacss_num());
		    int index=arrtemp.indexOf(".");
		    String nonterm=arrtemp.get(index+1);
		    String follownode=get_follow_node(arrtemp,temp.getFollow_node());
		    for(Integer i:num_css.keySet()){
		    	if(nonterm.equals(num_css.get(i).get(0))){
		    		ArrayList<String> csstemp=(ArrayList<String>) num_css.get(i).clone();
		    		csstemp.add(1,".");
		    		String dfacss=arr_to_string(csstemp);
		    		Integer dfanum=dfacss_num.get(dfacss);
		    		statenodes.add(new State_Node(dfanum.intValue(),follownode));
		    		if(nonterm_set.contains(csstemp.get(2))){
		    			if(!visited.contains(new State_Node(dfanum,follownode))){
		    				Q.add(new State_Node(dfanum,follownode));
		    			}
		    		}
		    	}
		    }
		}
	}
	
	public String get_follow_node(ArrayList<String> arrtemp,String follow){
		String temp="";
		int index=arrtemp.indexOf(".");
		String nonterm=arrtemp.get(index+1);
		int len=arrtemp.size();
		if((len-1)==(index+1)){
			temp=follow;
		}
		else{
			temp=arrtemp.get(index+2);
		}
		return temp;
	}
	
	public void get_other_state(int snum){
		Boolean flag=true;
		TreeSet<State_Node> statenodes=state.get(snum);
		TreeSet<State_Node> newstate=new TreeSet<State_Node>();
		TreeSet<String> edge_set=new TreeSet<String>();
		for(State_Node i:statenodes){
			ArrayList<String> dfacss=(ArrayList<String>) num_dfacss.get(i.getDfacss_num()).clone();
			if(dfacss.indexOf(".")!=(dfacss.size()-1)){
				flag=false;
				edge_set.add(dfacss.get(dfacss.indexOf(".")+1));//所有边的集合
				newstate.add(i);//将所对应的边表加入其中
			}
		}
		if(flag){//如果flag为true则证明该状态集都为终态 不必再操作以下步骤
			return;
		}
		for(String i:edge_set){
			TreeSet<State_Node> temp=new TreeSet<State_Node>();
			for(State_Node j:newstate){
				ArrayList<String> dfacss=(ArrayList<String>)num_dfacss.get(j.getDfacss_num()).clone();
				if(i.equals(dfacss.get(dfacss.indexOf(".")+1))){
					int index=dfacss.indexOf(".");
					dfacss.remove(".");
					dfacss.add(index+1,".");
					temp.add(new State_Node(dfacss_num.get(arr_to_string(dfacss)),j.getFollow_node()));
				}
			}
			closure(temp);
			int num=-1;
			for(Integer k:state.keySet()){
				if(Treeset_equal(temp,state.get(k))){//如果产生的状态不为新状态 则 将其状态号记录下来
					num=k;
				}
			}
			if(num!=-1){//该状态不为新状态时则将其的状态号保留下来
				if(!DFA_Graph.containsKey(snum)){
					DFA_Graph.put(snum,new TreeSet<DFA_Node>());
				}
				DFA_Graph.get(snum).add(new DFA_Node(i,num));
				if(!DFA_Graph.containsKey(num)){
					get_other_state(num);
				}
			}
			else{
				state_num++;
				state.put(state_num,temp);
				if(!DFA_Graph.containsKey(snum)){
					DFA_Graph.put(snum,new TreeSet<DFA_Node>());
				}
				DFA_Graph.get(snum).add(new DFA_Node(i,state_num));
				get_other_state(state_num);
			}
		}
	}
	
	public Boolean Treeset_equal(TreeSet<State_Node> set1,TreeSet<State_Node> set2){
		Boolean flag=true;
		if(set1.size()!=set2.size()){
			flag=false;
		}
		else{
			for(State_Node i:set1){
				if(!set2.contains(i)){
					flag=false;
				}
			}
		}
		return flag;
	}
	
}
