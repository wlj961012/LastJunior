package lr_1;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.TreeSet;

public class Fileiostream {

	private HashMap<Integer,ArrayList<String>> css_num=new HashMap<Integer,ArrayList<String>>();
	private TreeSet<String> nonterm_set;//非终结符的集合
	private TreeSet<String> term_set;
	private int num=0;
	
	public HashMap<Integer,ArrayList<String>> getCss_num() {
		return css_num;
	}

	public Fileiostream(String pathname){
		try {
			nonterm_set=new TreeSet<String>();
			term_set=new TreeSet<String>();
			BufferedReader br=new BufferedReader(new FileReader(pathname));
			String str="";
			try {
				while((str=br.readLine())!=null){
					if(str.equals(""))continue;
					int len=str.length();
					String nonterm="";
					int index=0;
					for(int i=0;i<len;i++){
						if(str.charAt(i)=='-'){
							
							index=i;
							break;
						}
						if(str.charAt(i)!=' '&&str.charAt(i)!='\t'){
							nonterm+=str.charAt(i);
						}
					}
					nonterm_set.add(nonterm);
					String str3=str.substring(index+2);
					String[] str2=str3.split("\\|");
					int len2=str2.length;
					for(int i=0;i<len2;i++){
						get_css(nonterm,str2[i]);
					}
				}
			} catch (IOException e) {
				// TODO 自动生成的 catch 块
				e.printStackTrace();
			}
		} catch (FileNotFoundException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
		for(Integer i:css_num.keySet()){
			for(String j:css_num.get(i)){
				if(!nonterm_set.contains(j)&&!j.equals("#")){
					term_set.add(j);
				}
			}
		}
	}
	
	public TreeSet<String> getTerm_set() {
		return term_set;
	}

	public TreeSet<String> getNonterm_set() {
		return nonterm_set;
	}

	public void get_css(String nonterm,String css){
		num++;
		ArrayList<String> temp=new ArrayList<String>();
		String tmp=nonterm;
		temp.add(tmp);
		String[] css_tmp=css.trim().split("\\s+|\\t");
		int len=css_tmp.length;
		for(int i=0;i<len;i++){
			tmp=css_tmp[i];
			if(!tmp.equals("#")){
				temp.add(tmp);
			}
		}
		css_num.put(num,temp);
	}
	
	public void print(){
		for(String i:nonterm_set){
			System.out.println(i);
		}
		for(Integer i:css_num.keySet()){
			System.out.print(i+" ");
			for(String j:css_num.get(i)){
				System.out.print(j+"  ");
			}
			System.out.println("");
		}
		for(String i:term_set){
			System.out.println(i);
		}
	}
		
}

