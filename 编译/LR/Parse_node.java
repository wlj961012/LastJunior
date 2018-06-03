package lr;

public class Parse_node {

	Integer state;
	String term;

	public Parse_node(Integer s,String t){
		state=s;
		term=t;
	}
	
	public Parse_node(){
		state=0;
		term="";
	}
	
}
