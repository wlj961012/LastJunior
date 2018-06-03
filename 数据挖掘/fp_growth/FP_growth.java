package fp_growth;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.TreeSet;

public class FP_growth {

	Double support=0.05;
	Integer support_count;
	HashSet<TreeSet<String>> result=new HashSet<TreeSet<String>>();
	
	public String arr_to_string(ArrayList<String> f_item){
		String str="";
		int len=f_item.size();
		for(int i=0;i<len;i++){
			str+=f_item.get(i);
			str+=",";
		}
		return str;
	}
	
	public ArrayList<String> string_to_arr(String str){
		ArrayList<String> f_items=new ArrayList<String>();
		String[] items=str.split(",");
		int len=items.length;
		for(int i=0;i<len;i++){
			f_items.add(items[i]);
		}
		return f_items;
	}

	public FP_growth(){
		String pathname="E:\\retail.dat";
		Fileiostream fis=new Fileiostream(pathname);
		support_count=(int)(support*fis.getSet_num()+1);
		ArrayList<Tiaojian_node> datas=fis.getData_set();
		result=get_result(datas);
		for(TreeSet<String> it:result){
			System.out.println(it);
		}
	}
	
	public HashSet<TreeSet<String>> get_result(ArrayList<Tiaojian_node> L){
		HashMap<String,Integer> L_map=new HashMap<String,Integer>();//统计每项出现的次数
		ArrayList<Item_node> L1=new ArrayList<Item_node>();//频繁一项集
		HashMap<String,Header_table_node> head_table=new HashMap<String,Header_table_node>();
		for(Tiaojian_node i:L){//得到L_map
			for(String j:i.f_items){
				if(L_map.containsKey(j)){
					L_map.put(j, L_map.get(j)+i.frequency);
				}
				else{
					L_map.put(j,i.frequency);
				}
			}
		}
		for(String i:L_map.keySet()){//根据L_map得到频繁一项集 并且得到头表
			if(L_map.get(i)>=support_count){
				L1.add(new Item_node(i,L_map.get(i)));
				head_table.put(i, new Header_table_node(L_map.get(i)));
			}
		}
		//再扫一遍数据库根据所得的频繁一项集得到不重复插入树的结点集
		Collections.sort(L1,Collections.reverseOrder());//将得到的频繁一项集按从大到小的顺序排列
		HashMap<String,Integer> data_map=new HashMap<String,Integer>();//表示要插入树中的数据集
		int len=L1.size();
		for(Tiaojian_node i:L){
			ArrayList<String> f_item=new ArrayList<String>();
			for(int j=0;j<len;j++){
				for(String k:i.f_items){
					if(k.equals(L1.get(j).item)){
						f_item.add(k);
					}
				}
			}
			if(!f_item.isEmpty()){
				if(data_map.containsKey(arr_to_string(f_item))){
					data_map.put(arr_to_string(f_item),i.frequency+data_map.get(arr_to_string(f_item)));
				}
				else{
					data_map.put(arr_to_string(f_item),i.frequency);
				}
			}
		}
		FP_tree fp_tree=new FP_tree();
		for(String i:data_map.keySet()){
			fp_tree.insert(new Tiaojian_node(i,data_map.get(i)), head_table);//依次插入数据集
		}
		HashSet<TreeSet<String>> empty=new HashSet<TreeSet<String>>();
	    if(data_map.isEmpty()){//如果没有满足条件的 则不能建树 返回为空
	    	return empty;
	    }
	    if(fp_tree.is_sibling==false){//如果没有分支的话 返回所有子集的集合
	    	return get_subset(L1);
	    }
	    else{//如果有分支的话
	    	HashSet<TreeSet<String>> temp=new HashSet<TreeSet<String>>();
		    for(String i:head_table.keySet()){
				ArrayList<Tiaojian_node> tj_L=new ArrayList<Tiaojian_node>();
				for(FP_tree_node j:head_table.get(i).fp_link_next){
					tj_L.add(new Tiaojian_node(fp_tree.find_parent(j),j.count));
				}
				TreeSet<String> tmp=new TreeSet<String>();
				tmp.add(i);
				temp.add(tmp);
				for(TreeSet<String> it:get_result(tj_L)){
					it.add(i);
					temp.add(it);
				}
		    }
		    return temp;
		}
	}
	
	public HashSet<TreeSet<String>> get_subset(ArrayList<Item_node> L1){
		HashSet<TreeSet<String>> subset=new HashSet<TreeSet<String>>();
		HashMap<Integer,String> item_map=new HashMap<Integer,String>();
		int len=L1.size();
		for(int i=0;i<len;i++){
			int temp=i;
			item_map.put(temp+1,L1.get(i).item);
		}
		for(int j=1;j<Math.pow(2, len);j++){
			TreeSet<String> temp_set=new TreeSet<String>();
			int tmp=j;
			for(int k=1;k<=len;k++){
				if((tmp&1)==1){
					temp_set.add(item_map.get(k));
				}
				tmp=tmp>>1;
			}
			subset.add(temp_set);
		}
		return subset;
	}
	
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		new FP_growth();
	}

}
