package apriori;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;

public class Apriori {

	Double support=0.05;
	ArrayList<TreeSet<Integer>> datas;//数据集
	int support_count;
	HashSet<TreeSet<Integer>> result=new HashSet<TreeSet<Integer>>();
	
	public Apriori(){
		String pathname="E:\\retail.dat";
		Fileiostream fis=new Fileiostream(pathname);
		datas=fis.getData_set();
		support_count=(int)(support*fis.getSet_num());
		get_result_set();
		for(TreeSet<Integer> i:result){
			System.out.println(i);
		}
	}
	
	public void get_result_set(){
		HashSet<TreeSet<Integer>> L_set=new HashSet<TreeSet<Integer>>();//频繁k项集
		L_set=get_L1();
		int k=2;//此时生成的候选项集为2项集
		while(!L_set.isEmpty()){
			 HashSet<TreeSet<Integer>> c_set=new HashSet<TreeSet<Integer>>();
		     int c_count=k*(k-1);//满足为候选项时出现的次数
		     HashMap<String,Integer> c_map=new HashMap<String,Integer>();//用c_map表示候选项集出现的次数
		     for(TreeSet<Integer> i:L_set){//自连接
		    	 for(TreeSet<Integer> j:L_set){
		    		 TreeSet<Integer> temp=new TreeSet<Integer>();
		    		 temp.addAll(i);
		    		 temp.addAll(j);
		    		 if(temp.size()==k){
		    			 if(c_map.containsKey(temp.toString())){
		    				 c_map.put(temp.toString(),c_map.get(temp.toString())+1);
		    				 if(c_map.get(temp.toString())==c_count){//只有满足子集项出现次数为ck2才能加入候选项集
		    					 c_set.add(temp);
		    				 }
		    			 }
		    			 else{
		    				 c_map.put(temp.toString(),1);
		    			 }
		    		 }
		    	 }
		     }
		     //用所得的候选项集得到下一个频繁项集
		     L_set=new HashSet<TreeSet<Integer>>();
		     HashMap<String,Integer> L_map=new HashMap<String,Integer>();
		     for(TreeSet<Integer> i:c_set){//根据候选集得到 L集合
		    	 for(TreeSet<Integer> j:datas){//遍历数据库
		    		 if(judge_contain(i,j)){//如果j行包括i则将i放入map 记录i出现的次数
		    			 if(L_map.containsKey(i.toString())){
		    				 L_map.put(i.toString(),L_map.get(i.toString())+1);
		    				 if(L_map.get(i.toString())>=support_count){
		    					 TreeSet<Integer> temp=new TreeSet<Integer>();
		 						 temp.addAll(i);
		 						 L_set.add(temp);
		    				 }
				    	 }
		    			 else{
	    					 L_map.put(i.toString(),1);
	    				 }
		    		 }
		    	 }
		     }
		     result.addAll(L_set);
		     k++;
		}
	}
	
	public boolean judge_contain(TreeSet<Integer>set1,TreeSet<Integer>set2){//判断集合一是否在集合2中
		int len1=set2.size();
		Set<Integer> tmp_set=new HashSet<Integer>();
		tmp_set.addAll(set1);
		tmp_set.addAll(set2);
		int len2=tmp_set.size();
		if(len1==len2)return true;
		return false;
		
	}

	public HashSet<TreeSet<Integer>> get_L1(){
		HashSet<TreeSet<Integer>> L1=new HashSet<TreeSet<Integer>>();
		Map<String,Integer> L1_map =new HashMap<String,Integer>();//用来表示数据集中每一项出现的次数
		for(TreeSet<Integer> i:datas){
			for(Integer j:i){
				if(L1_map.containsKey(j.toString())){
					L1_map.put(j.toString(),L1_map.get(j.toString())+1);
					if(L1_map.get(j.toString())>=support_count){//如果该数统计到大于等于支持度则将其加入频繁一项集
						TreeSet<Integer> temp=new TreeSet<Integer>();
						temp.add(j);
						L1.add(temp);
					}
				}
				else{
					L1_map.put(j.toString(), 1);
				}
			}
		}
		result.addAll(L1);//将频繁一项集加入结果集合中
		return L1;
	}
	
	public static void main(String[] args) {
		// TODO 自动生成的方法存根
		new Apriori();
	}

}
