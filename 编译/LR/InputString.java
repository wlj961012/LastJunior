package lr;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class InputString {

	private ArrayList<String> input;
	
	public ArrayList<String> getInput() {
		return input;
	}

	public InputString(String pathname){
		input=new ArrayList<String>();
		try {
			BufferedReader br=new BufferedReader(new FileReader(pathname));
			String str="";
			try {
				while((str=br.readLine())!=null){
					if(str.equals("")){
						continue;
					}
					String[] str2=str.split("\\s+|\\t");
					int len=str2.length;
					for(int i=0;i<len;i++){
						input.add(str2[i]);
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
	}
	
}
