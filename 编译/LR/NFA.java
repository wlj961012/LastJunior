package lr;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Queue;
import java.util.TreeSet;

public class NFA{
	
	private HashMap<Integer,TreeSet<NFA_node>> nfa_graph=new HashMap<Integer,TreeSet<NFA_node>>();
	private HashMap<Integer,TreeSet<Integer>> state_css=new HashMap<Integer,TreeSet<Integer>>();
	private HashMap<String,Integer> css_state=new HashMap<String,Integer>();
	private int state_num=0;
	private HashMap<Integer, ArrayList<String>> num_css;
	private HashMap<Integer,ArrayList<String>> num_new_css;
	public HashMap<Integer, TreeSet<Integer>> getState_css() {
		return state_css;
	}

	private HashMap<String,Integer> css_num;//每条产生式所对应的标号
	private TreeSet<String> nonterm_set;
	private TreeSet<String> term_set;
	private int num=0;
	Fileiostream fis=new Fileiostream("E:\\LR.txt");
	
	public HashMap<Integer, TreeSet<NFA_node>> getNfa_graph() {
		return nfa_graph;
	}

	public HashMap<Integer, ArrayList<String>> getNum_css() {
		return num_css;
	}

	public String arr_to_string(ArrayList<String> css){
		String str="";
		int len=css.size();
		for(int i=0;i<len;i++){
			str+=css.get(i);
			str+=",";
		}
		return str;
	}
	
	public String treeset_to_string(TreeSet<Integer> state_css){
		String str="";
		int len=state_css.size();
		for(Integer i:state_css){
			str+=i;
			str+=",";
		}
		return str;
	}
	
	public ArrayList<String> string_to_arr(String str){
		ArrayList<String> css=new ArrayList<String>();
		String[] str2=str.split(",");
		int len=str2.length;
		for(int i=0;i<len;i++){
			css.add(str2[i]);
		}
		return css;
	}
	
	public NFA(){
		nonterm_set=new TreeSet<String>();
		num_css=fis.getCss_num();
		nonterm_set=fis.getNonterm_set();
		css_num=new HashMap<String,Integer>();
		num_new_css=new HashMap<Integer,ArrayList<String>>();
		get_new_css();//得到每个状态所对应的状态
		get_first_state();
		//print();
	}
	
	public void get_new_css(){//遍历每一个产生式，得到带状态的产生式的集合
		for(Integer i:num_css.keySet()){
			ArrayList<String> temp=num_css.get(i);
			if(temp.size()>1){
				int len=temp.size();
				ArrayList tmp=new ArrayList<String>();
				for(int j=1;j<=len;j++){
					tmp=(ArrayList<String>)temp.clone();
					tmp.add(j,".");
					num++;
					num_new_css.put(num,tmp);
					css_num.put(arr_to_string(tmp),num);
				}	
			}
			else{//如果该产生式对应空集，去掉空集在其后面加上.
				ArrayList tmp=(ArrayList<String>)temp.clone();
				tmp.add(1,".");
				num++;
				num_new_css.put(num,tmp);
				css_num.put(arr_to_string(tmp),num);
			}
		}
	}
	
	public void print(){
		for(String i:css_num.keySet()){
			System.out.println(i+"  "+css_num.get(i));	
		}
		System.out.println("-------");
		for(Integer i:num_new_css.keySet()){
			System.out.print(i+" ");
			System.out.println(num_new_css.get(i));
		}
		System.out.println("----------");
		for(Integer i:state_css.keySet()){
			System.out.print(i+"   ");
			System.out.println(state_css.get(i));
		}
		System.out.println("--------");
		for(Integer i:nfa_graph.keySet()){
			System.out.print(i+"  ");
			for(NFA_node j:nfa_graph.get(i)){
				System.out.print("  "+j.edge+"  "+j.state);
			}
			System.out.println("  ");
		}
	}
	
	public HashMap<Integer, ArrayList<String>> getNum_new_css() {
		return num_new_css;
	}

	public void get_first_state(){
		int index=0;
		for(Integer i:num_css.keySet()){
			if(num_css.get(i).get(0).equals("start")){
				index=i;//找到开始产生式
				break;
			}
		}
		ArrayList<String> temp=(ArrayList<String>)num_css.get(index).clone();
		temp.add(1,".");
		int cssnum=css_num.get(arr_to_string(temp));
		state_num++;//找到第一个状态
		TreeSet<Integer> temp_set=new TreeSet<Integer>();
		temp_set.add(cssnum);
		state_css.put(state_num,temp_set);
		Queue<String> Q=new ArrayDeque<String>();
		if(nonterm_set.contains(temp.get(2))){
			Q.add(temp.get(2));
		}
		while(!Q.isEmpty()){
			String tmp=Q.poll();
			for(Integer i:num_css.keySet()){
				if(tmp.equals(num_css.get(i).get(0))){
					temp=(ArrayList<String>)num_css.get(i).clone();
					temp.add(1,".");
					if(temp.size()>2){
						if(nonterm_set.contains(temp.get(2))){
							Q.offer(temp.get(2));
						}
					}
					cssnum=css_num.get(arr_to_string(temp));
					state_css.get(state_num).add(cssnum);
					
				}
			}
		}
		TreeSet<Integer> state_css_num=(TreeSet<Integer>)state_css.get(state_num).clone();
		get_other_state(state_css_num,state_num);
		css_state.put(treeset_to_string(state_css_num),state_num);
	}
	
	public void get_other_state(TreeSet<Integer> csss,int nfa_num){//对应着每个状态的产生式
		//如果这个状态里的产生式状态的都是最后面
		Boolean flag=true;
		ArrayList<String> temp=new ArrayList<String>();
		int size=0;
		for(Integer i:csss){
			temp=(ArrayList<String>)num_new_css.get(i).clone();
			size=temp.size();
			if(!temp.get(size-1).equals(".")){
				flag=false;
			}
		}
		if(flag){//如果这个状态是终态 那么可以结束这个函数
			return;
		}
		//反之则要更新状态,通过一个状态集 产生新的函数
		String edge="";
		int index=0;
		for(Integer i:csss){
			//扫描它的一条产生式得到新的状态
			ArrayList<String> one_css=(ArrayList<String>)num_new_css.get(i).clone();
			int len=one_css.size();
			for(int j=0;j<len;j++){
				if(one_css.get(j).equals(".")){
					index=j;
					break;
				}
			}
			//空状态只能通过闭包产生 
			if(index!=len-1){//如果该点不是末尾
				edge=one_css.get(index+1);//得到边的信息
				one_css.remove(index);//删除点标记的位置
				one_css.add(index+1,".");
				String tmp=arr_to_string(one_css);//找到这条产生式所对应的状态
				TreeSet<Integer> tmp_set=new TreeSet<Integer>();//产生式的集合
				tmp_set.add(css_num.get(tmp));//将这条产生式的对应的产生式序号加入产生式集合
				//System.out.println(tmp_set);
				//闭包操作得到新的状态
				tmp_set.addAll(closure(one_css,index+1));
				if(!nfa_graph.containsKey(nfa_num)){
					nfa_graph.put(nfa_num,new TreeSet<NFA_node>());
				}
				if(css_state.containsKey(treeset_to_string(tmp_set))){
					nfa_graph.get(nfa_num).add(new NFA_node(edge,css_state.get(treeset_to_string(tmp_set))));
					if(nfa_num!=css_state.get(treeset_to_string(tmp_set))&&!nfa_graph.containsKey(css_state.get(treeset_to_string(tmp_set)))){
						get_other_state(tmp_set,css_state.get(treeset_to_string(tmp_set)));
					}
				}
				else{
					state_num++;
					state_css.put(state_num,tmp_set);
					css_state.put(treeset_to_string(tmp_set),state_num);
					nfa_graph.get(nfa_num).add(new NFA_node(edge,state_num));
					get_other_state(tmp_set,state_num);
				}
			}
		}
	}
	
	public TreeSet<Integer> closure(ArrayList<String> one_css,int index){
		TreeSet<Integer> state_css=new TreeSet<Integer>();//某个状态所包含的产生式集合
		int len=one_css.size();
		if(index!=len-1){
			Queue<String> Q=new ArrayDeque<String>();
			if(nonterm_set.contains(one_css.get(index+1))){
				Q.add(one_css.get(index+1));
			}
			ArrayList<String> temp=new ArrayList<String>();
			while(!Q.isEmpty()){
				String nonterm=Q.poll();
				for(Integer i:num_css.keySet()){//找到这个非终结符所对应的产生式
					if(nonterm.equals(num_css.get(i).get(0))){//将所有产生式存在一个数组里
						temp=(ArrayList<String>)num_css.get(i).clone();
						temp.add(1,".");
						if(temp.size()>2){
							if(nonterm_set.contains(temp.get(2))){//如果产生式后面还有值则继续
								Q.offer(temp.get(2));
							}
						}
						Integer cssnum=css_num.get(arr_to_string(temp));
						state_css.add(cssnum);//将该产生式的序号加入其中
					}
				}
			}
		}
		return state_css;
	}
	
	/*public static void main(String[] args){
		new NFA();
	}*/
	
}
