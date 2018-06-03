package fp_growth;

public class FP_tree_node {
	
	String data;
	Integer count;
	FP_tree_node firstchild;
	FP_tree_node nextbother;
	FP_tree_node parent;
	
	public FP_tree_node(){
		data=null;
		count=null;
		firstchild=null;
		nextbother=null;
		parent=null;
	}
	
	public FP_tree_node(String d,Integer c){
		data=d;
		count=c;
		firstchild=null;
		nextbother=null;
		parent=null;
	}

}
