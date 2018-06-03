package fp_growth;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class Fileiostream {
   
	private ArrayList<Tiaojian_node> data_set=new ArrayList<Tiaojian_node>();
	private int set_num;
	
	public ArrayList<Tiaojian_node> getData_set() {
		return data_set;
	}

	public int getSet_num() {
		return set_num;
	}

	public Fileiostream(String pathname){
    	try {
			BufferedReader br=new BufferedReader(new FileReader(pathname));
			String str="";
			try {
				while((str=br.readLine())!=null){
					set_num++;
					String[] str2=str.split(" ");
					int len=str2.length;
					ArrayList<String> temp=new ArrayList<String>();
					for(int i=0;i<len;i++){
						temp.add(str2[i]);
					}
					data_set.add(new Tiaojian_node(temp,1));
				}
			} catch (IOException e) {
				// TODO 自动生成的 catch 块
				e.printStackTrace();
			}
		} catch (FileNotFoundException e) {
			// TODO 自动生成的 catch 块
			e.printStackTrace();
		}
    }

	
}
