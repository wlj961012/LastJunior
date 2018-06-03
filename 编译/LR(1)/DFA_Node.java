package lr_1;

public class DFA_Node implements Comparable<DFA_Node>{
	
	private Integer state;
	private String edge;
	
	public Integer getState() {
		return state;
	}
	public void setState(Integer state) {
		this.state = state;
	}
	public String getEdge() {
		return edge;
	}
	public void setEdge(String edge) {
		this.edge = edge;
	}
	
	public DFA_Node(){
		edge=null;
		state=-1;
	}
	
	public DFA_Node(String e,Integer s){
		edge=e;
		state=s;
	}
	@Override
	public int compareTo(DFA_Node o) {
		// TODO 自动生成的方法存根
		if(!this.edge.equals(o.edge)){
			return this.edge.compareTo(o.edge);
		}
		else{
			return this.state-o.state;
		}
	}

}
