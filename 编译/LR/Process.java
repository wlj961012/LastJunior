package lr;

import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Queue;
import java.util.Stack;
import java.util.TreeSet;

public class Process {
	
	private Stack<Parse_node> parse_stack;
	private ArrayList<String> input=new ArrayList<String>();
	private HashMap<Integer,TreeSet<NFA_node>> action_table;//lr分析表
	private HashMap<Integer,TreeSet<NFA_node>> goto_table;
	private HashMap<Integer, ArrayList<String>> num_css;
	private TreeSet<Integer> final_state;
	
	public Process(){
		Lr_table lr_table=new Lr_table();
		action_table=lr_table.getAction_table();
		goto_table=lr_table.getGoto_table();
		num_css=lr_table.getNum_css();
		final_state=lr_table.getFinal_state();
		parse_stack=new Stack<Parse_node>();
		InputString is=new InputString("E:\\LR_input.txt");
		input=is.getInput();
		parse_stack.push(new Parse_node(1,"$"));//把初始状态和压入分析栈中
		int len=input.size();
		int i=0;
		System.out.println(input);
		while(i<len){
			String temp=input.get(i);
			if(!shift(temp)){
				System.out.println("shift,error");
				break;
			}
			if(final_state.contains(parse_stack.peek().state)){//如果此时栈顶元素的状态为终态则要进行规约
				int flag2=reduce();
				if(flag2==2){
					System.out.println("accept!");
					break;
				}
				if(flag2==0){
					System.out.println("reduce error!");
					break;
				}
			}
			i++;
		}
	}
	
	public Boolean shift(String temp){
		Boolean flag=false;
		Parse_node top=parse_stack.peek();
		Integer state=top.state;
		Integer next_state=0;
		for(NFA_node j:action_table.get(state)){
			if(j.edge.equals(temp)){
				next_state=j.state;
				parse_stack.push(new Parse_node(next_state,temp));
				flag=true;
			}
		}
		return flag;
	}
	
	public int reduce(){
		int flag=1;
		Queue<Integer> q=new ArrayDeque<Integer>();
		Integer state=parse_stack.peek().state;
		q.offer(state);
		while(!q.isEmpty()){
			String temp=parse_stack.peek().term;
			state=q.poll();
			Integer next_css_num=action_table.get(state).first().state;
			ArrayList<String> css=new ArrayList<String>();
			if(next_css_num!=-1){
				css=(ArrayList<String>)num_css.get(next_css_num).clone();
				int len=css.size();
				css.remove(len-1);
				len=css.size();
				for(int j=len-1;j>=1;j--){
					if(css.get(j).equals(parse_stack.peek().term)){
						parse_stack.pop();
					}
					else{
						flag=0;
						break;
					}
				}
				if(flag==1){//如果消除正确
					if(parse_stack.peek().term.equals("$")&&css.get(0).equals("start")){
						flag=2;
						return flag;
					}
					Integer temp_state=parse_stack.peek().state;
					Integer new_state=0;
					for(NFA_node k:goto_table.get(temp_state)){
						if(k.edge.equals(css.get(0))){
							new_state=k.state;
						}
					}
					parse_stack.push(new Parse_node(new_state,css.get(0)));
					if(final_state.contains(parse_stack.peek().state)){
						q.offer(parse_stack.peek().state);
					}
				}
			}
		}
		return flag;
	}

	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		new Process();
	}

}
