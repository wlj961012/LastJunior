package lr_1;

public class State_Node implements Comparable<State_Node>{
	
	private int dfacss_num;
	private String follow_node;
	
	public State_Node(){
		dfacss_num=-1;
		follow_node=null;
	}
	
	public State_Node(int d,String f){
		dfacss_num=d;
		follow_node=f;
	}
	
	public Integer getDfacss_num() {
		return dfacss_num;
	}
	public void setDfacss_num(Integer dfacss_num) {
		this.dfacss_num = dfacss_num;
	}
	public String getFollow_node() {
		return follow_node;
	}
	public void setFollow_node(String follow_node) {
		this.follow_node = follow_node;
	}

	@Override
	public int compareTo(State_Node o) {
		// TODO 自动生成的方法存根
		/*if(this.dfacss_num==o.dfacss_num){
			return this.dfacss_num-o.dfacss_num;
		}
		else{
			return this.follow_node.compareTo(o.follow_node);
		}*/
		
		if(!this.follow_node.equals(o.follow_node)){
			return this.follow_node.compareTo(o.follow_node);
		}
		else{
			return this.dfacss_num-o.dfacss_num;
		}

	}
	
}
