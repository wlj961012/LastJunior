package fp_growth;

import java.util.ArrayList;

public class Header_table_node implements Comparable<Header_table_node>{
	
	Integer frequency;
	ArrayList<FP_tree_node> fp_link_next;//用一个数组存放头表所对应的树的结点
	
	public Header_table_node(Integer f){
		frequency=f;
		fp_link_next=new ArrayList<FP_tree_node>();
	}

	
	@Override
	public int compareTo(Header_table_node o) {
		// TODO 自动生成的方法存根
		return this.frequency-o.frequency;
	}
}
