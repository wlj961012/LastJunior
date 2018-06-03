package fp_growth;

public class Item_node implements Comparable<Item_node>{
	
	String item;
	Integer frequency;
	
	public Item_node(String i,Integer f){
		item=i;
		frequency=f;
	}

	@Override
	public int compareTo(Item_node o) {
		// TODO 自动生成的方法存根
		return this.frequency-o.frequency;
	}
}
