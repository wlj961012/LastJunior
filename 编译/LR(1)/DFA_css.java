package lr_1;

import java.util.ArrayList;
import java.util.HashMap;

public class DFA_css {//由于DFA中的css只用到点的模式因此只要将原来的css改变即可
	
	private Fileiostream fis=new Fileiostream("E:\\IN\\LR1_input.txt");
	private HashMap<Integer,ArrayList<String>> num_css;
	private HashMap<Integer,ArrayList<String>> num_dfacss;
	private HashMap<String,Integer> dfacss_num;
	int num=0;

	public DFA_css(){
		num_css=fis.getCss_num();
		num_dfacss=new HashMap<Integer,ArrayList<String>>();
		dfacss_num=new HashMap<String,Integer>();
		get_num_dfacss();
	}
	
	public HashMap<Integer, ArrayList<String>> getNum_css() {
		return num_css;
	}

	public HashMap<Integer, ArrayList<String>> getNum_dfacss() {
		return num_dfacss;
	}

	public HashMap<String, Integer> getDfacss_num() {
		return dfacss_num;
	}

	public String arr_to_string(ArrayList<String> dfacss){
		String temp="";
		for(String i:dfacss){
			temp+=i;
			temp+=",";
		}
		return temp;
	}
	
	public void get_num_dfacss(){
		for(Integer i:num_css.keySet()){//遍历每一个产生式 由每一个产生式得到它所对应的
			ArrayList<String> temp=(ArrayList<String>) num_css.get(i).clone();
			int len=temp.size();
			for(int j=1;j<=len;j++){
				ArrayList<String>  temp2=(ArrayList<String>) temp.clone();
				temp2.add(j, ".");
				num++;
				num_dfacss.put(num,temp2);
				dfacss_num.put(arr_to_string(temp2),num);
			}
		}
	}
	
	private void print(){
		for(Integer i:num_dfacss.keySet()){
			System.out.println(i+"   ");
			System.out.println(num_dfacss.get(i));
		}
		System.out.println("--------------------");
		for(String i:dfacss_num.keySet()){
			System.out.println(i+"   ");
			System.out.println(dfacss_num.get(i));
		}
	}
	
}
