package fp_growth;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;

public class FP_tree {
	FP_tree_node root;
	boolean is_sibling=false;
	public FP_tree(){
		root=new FP_tree_node("#",1);	
	}
	
	public void insert(Tiaojian_node node,HashMap<String,Header_table_node> header_table){
		
		FP_tree_node cur=root;
		FP_tree_node cur_parent=root;//帮助兄弟结点找到父节点
		int len=node.f_items.size();
		for(int i=0;i<len;i++){
			if(cur.firstchild==null){//如果当前结点为空
				cur.firstchild=new FP_tree_node(node.f_items.get(i),node.frequency);
				cur.firstchild.parent=cur;
				cur_parent=cur.firstchild;
				cur=cur.firstchild;
				String tmp=node.f_items.get(i);
			    header_table.get(tmp).fp_link_next.add(cur);
			}
			else{
				if(cur.firstchild.data.equals(node.f_items.get(i))){//如果该结点和所插入的结点相同则数加一
					cur.firstchild.count=cur.firstchild.count+node.frequency;
					cur_parent=cur.firstchild;
					cur=cur.firstchild;
				}
				else{//如果不同则在兄弟结点上找是否有相同的
					cur=cur.firstchild;
					is_sibling=true;
					while(cur.nextbother!=null){
						if(cur.nextbother.data.equals(node.f_items.get(i))){
							//is_sibling=true;
							cur.nextbother.count=cur.nextbother.count+node.frequency;
							break;
						}
						else{
							//is_sibling=true;
							cur=cur.nextbother;
						}
					}
					if(cur.nextbother==null){
						cur.nextbother=new FP_tree_node(node.f_items.get(i),node.frequency);
						cur.nextbother.parent=cur_parent;
						cur=cur.nextbother;
						cur_parent=cur;
						header_table.get(node.f_items.get(i)).fp_link_next.add(cur);
					}
					else{
						cur=cur.nextbother;
						cur_parent=cur;
					}
				}
			}
		}
	}
	
	public ArrayList<String> find_parent(FP_tree_node node){
		ArrayList<String> parent_list=new ArrayList<String>();
		while(node.parent!=this.root){
			parent_list.add(node.parent.data);
			node=node.parent;
		}
		Collections.reverse(parent_list);
		return parent_list;
	}
	
}
