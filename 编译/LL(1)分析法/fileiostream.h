#ifndef FILEIOSTREAM_H
#define FILEIOSTREAM_H
#include<fstream>
#include<string>
#include<map>
#include<set>
#include<iostream>
class Fileiostream{
private:
	std::string get_nonterminal(std::string str){//得到左边的非终结符
		std::string temp = "";
		int len = str.length();
		for (int i = 0; i < len; i++){
			if (str[i] == '-'){
				break;
			}
			if (str[i] != ' '&&str[i] != '\t'){
				temp += str[i];
			}
		}
		return temp;
	}
	void get_G(std::map<std::string, std::set<std::string>>& G, std::string non_terminal, std::string line){//得到右边的产生式
		int len = line.length();
		int i = 0;
		for (; i < len; i++){
			if (line[i] == '>'){
				break;
			}
		}
		std::string temp = "";
		for (int j = i + 1; j < len; j++){
			if (line[j] != '|'){
				temp += line[j];
				if (j == len - 1){
					G[non_terminal].insert(temp);
				}
			}
			else{
				G[non_terminal].insert(temp);
				temp = "";
			}
		}
	}
public:
	void fileiostream(std::map<std::string,std::set<std::string>>& G){
		std::ifstream file;
		file.open("E:\\LL1_in.txt");
		std::string line;
		while (getline(file, line)){
			get_G(G, get_nonterminal(line), line);
		}
		file.close();
	}
};

#endif