package fp_growth;

import java.util.ArrayList;

public class Tiaojian_node {
	
	ArrayList<String> f_items=new ArrayList<String>();
	Integer frequency;
	
	public ArrayList<String> string_to_arr(String str){
		ArrayList<String> f_items=new ArrayList<String>();
		String[] items=str.split(",");
		int len=items.length;
		for(int i=0;i<len;i++){
			f_items.add(items[i]);
		}
		return f_items;
	}
	
	public Tiaojian_node(String str,Integer c){
		f_items=string_to_arr(str);
		frequency=c;
	}
	
	public Tiaojian_node(ArrayList<String> f,Integer c){
		f_items=f;
		frequency=c;
	}

}
