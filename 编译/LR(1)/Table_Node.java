package lr_1;

public class Table_Node implements Comparable<Table_Node>{
	
	private String edge;
	private String num;
	
	public Table_Node(){
		edge=null;
		num=null;
	}
	
	public Table_Node(String e,String n){
		edge=e;
		num=n;
	}

	public String getEdge() {
		return edge;
	}

	public String getNum() {
		return num;
	}

	@Override
	public int compareTo(Table_Node o) {
		// TODO 自动生成的方法存根
		if(!this.edge.equals(o.edge)){
			return this.edge.compareTo(o.edge);
		}
		else{
			return this.num.compareTo(o.num);
		}
	}
}
