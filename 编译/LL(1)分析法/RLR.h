#ifndef RLR_H
#define RLR_H
#include<string>
#include<map>
#include<set>
#include<vector>
#include<queue>
#include"fileiostream.h"

class remove_left{
private:
	std::vector<std::string> get_csselement(std::string str){
		std::vector<std::string> css_element;
		int len = str.length();
		std::string temp = "";
		for (int i = 0; i < len; i++){
			if (str[i] != ' '&&str[i] != '\t'){
				temp += str[i];
				if (i == len - 1){
					css_element.push_back(temp);
				}
			}
			else{
				if (temp != ""){
					css_element.push_back(temp);
				}
				temp = "";
			}
		}
		return css_element;
	}

	std::string get_substr_left_recursion(std::vector<std::string> elems){
		std::string new_chanshengshi;
		elems.erase(elems.begin());
		for (auto it : elems){
			std::string temp = it;
			temp += " ";
			new_chanshengshi += temp;
		}
		return new_chanshengshi;
	}

	void remove_immediate_left_recursion(std::string nonterminal, std::map<std::string, std::set<std::string>>& G){
		std::set<std::string> chanshengshi = G[nonterminal];
		std::map<std::string, std::vector<std::string>> css_element;//每个产生式中所对应的元素
		std::set<std::string> left_recursion;//包含非终结符的左递归文法产生式
		std::set<std::string> no_left_recursion;//不包含非终结符的左递归文法产生式
		for (std::string it : chanshengshi){
			css_element[it] = get_csselement(it);
			if (get_csselement(it)[0] == nonterminal){
				left_recursion.insert(it);
			}
			else{
				no_left_recursion.insert(it);
			}
		}
		if (left_recursion.empty()){//如果不存在左递归式则返回空
			return;
		}
		else{//如果存在左递归则要加入a'的产生式 并且改变a在map中的情况
			std::string nonterminal2 = nonterminal;
			nonterminal2 += "'";
			std::set<std::string> set1;//存放βA'
			for (std::string it : no_left_recursion){//遍历β式在其后面加上nonterminal2
				std::string temp = it;
				temp += " ";
				temp += nonterminal2;
				set1.insert(temp);
			}//改变A下的产生式
			G[nonterminal] = set1;
			std::set<std::string> set2;
			set2.insert("#");//用#表示空集
			for (std::string it : left_recursion){//遍历Aα式得到A'所对应的产生式
				std::string temp = get_substr_left_recursion(css_element[it]);
				temp += nonterminal2;
				set2.insert(temp);
			}
			G[nonterminal2] = set2;
		}
	}

	void change_css(std::string css, std::set<std::string> change_elem_css, std::set<std::string>& new_set){
		std::vector<std::string> css_vector = get_csselement(css);
		css_vector.erase(css_vector.begin());
		std::string temp = " ";
		for (auto it : css_vector){
			temp += it;
			temp += " ";//以空格分割每一个产生式中的元素
		}
		for (auto it : change_elem_css){
			std::string tmp = it;
			tmp += temp;
			new_set.insert(tmp);
		}
	}
	void replace_grammar_rule(std::string nonterminal, std::map<std::string, std::set<std::string>>& G, std::string change_elem){
		std::set<std::string> css = G[nonterminal];//得到所有的产生式
		std::set<std::string> need_change_css;
		std::set<std::string> no_need_change_css;
		std::map<std::string, std::vector<std::string>> css_elems;
		for (auto it : css){//遍历某个非终结符所有产生式  找到首符 与num_nonterminal 相同的产生式
			css_elems[it] = get_csselement(it);
			if (css_elems[it][0] == change_elem){//如果首符与需要改变的非终结符相同则需要替换
				need_change_css.insert(it);
			}
			else{
				no_need_change_css.insert(it);
			}
		}
		if (need_change_css.empty()){//如果没有需要改变的产生式则返回
			return;
		}
		std::set<std::string> new_set;//根据得到的两个集合改变相应的产生式
		for (auto it : css){
			if (need_change_css.count(it)){//如果需要改变则改变相应表达式
				change_css(it, G[change_elem], new_set);
			}
			else{//如果这条表达式不需要改变则直接加入它
				new_set.insert(it);
			}
		}
		G[nonterminal] = new_set;
	}

	void general_left_recursion(std::map<std::string, std::set<std::string>>& G){
		std::map<int, std::string> num_nonterm;
		std::map<std::string, int> nonterm_num;
		int m = 0;//遍历产生式 得到所有非终结符的个数
		for (auto it : G){
			m++;
			num_nonterm[m] = it.first;//得到所有非终结符所对应的序号
			nonterm_num[it.first] = m;
		}
		for (int i = 1; i <= m; i++){
			for (int j = 1; j <= i - 1; j++){//替换所有句首的非终结符
				replace_grammar_rule(num_nonterm[i], G, num_nonterm[j]);
			}
			remove_immediate_left_recursion(num_nonterm[i], G);
		}
	}

	bool is_nonterm(std::string css, std::map<std::string, std::set<std::string>> G){
		std::vector<std::string> csselems = get_csselement(css);
		if (G[csselems[0]].empty()){//如果在文法中不存在产生式则是终结符
			return false;
		}
		else{
			return true;
		}
	}

	int get_min_length(std::set<std::string> common_css){
		int min = 99999999;
		int len;
		for (auto it : common_css){
			len = get_csselement(it).size();
			if (len < min){
				min = len;
			}
		}
		return min;
	}


	void get_new_css(std::set<std::string>& css, std::queue<std::string>& Q, std::string now_css, std::map<std::string, std::set<std::string>> G){//得到新的产生式并且新的产生式加入队列中
		std::vector<std::string> csselems = get_csselement(now_css);
		std::set<std::string> other_css = G[csselems[0]];
		csselems.erase(csselems.begin());
		std::string temp = " ";
		for (auto it : csselems){//得到去除首符后的产生式
			temp += it;
			temp += " ";
		}
		for (auto it : other_css){//得到新的产生式
			std::string tmp = it;
			tmp += temp;
			css.insert(tmp);
			Q.push(tmp);//将新产生的产生式加入队列中
		}
		css.erase(now_css);//去除原来的产生式
	}

	std::string partition_css(std::string last, std::string css){
		std::string substring = "";
		std::vector<std::string> last_elems = get_csselement(last);
		std::vector<std::string> css_elems = get_csselement(css);
		int len1 = last_elems.size();
		int i = 0;
		for (; i < len1; i++){
			if (last_elems[i] != css_elems[i]){
				break;
			}
		}
		int len2 = css_elems.size();
		for (int j = i; j < len2; j++){
			substring += css_elems[j];
			substring += " ";
		}
		return substring;
	}

	bool get_max_length(std::map<std::string, std::set<std::string>>& G, std::string nonterm, std::queue<std::string>& Q1){//得到最大的匹配长度
		std::set<std::string> css = G[nonterm];
		//对产生式进行一遍扫描将所有所有含非终结符首符的式子化为终结符
		std::queue<std::string> Q2;
		for (auto it : css){
			Q2.push(it);
		}
		while (!Q2.empty()){
			std::string now_css = Q2.front();//当前所处理的产生式
			if (!is_nonterm(now_css, G)){//如果它的首符是终结符则不用替换
				Q2.pop();
			}
			else{
				get_new_css(css, Q2, now_css, G);
				Q2.pop();//新的产生式得到了，也代表着该条产生式的消亡
			}
		}
		G[nonterm] = css;//G所对应的产生式发生了改变
		//在改变产生式的情况下，找到其所对应的最长子串
		std::map<std::string, std::vector<std::string>> css_elems;//产生式中的元素
		for (auto it : css){//首先找首符相同的串
			css_elems[it] = get_csselement(it);
		}
		std::map<std::string, std::set<std::string>> common_map;
		std::string key;
		int max = 0;
		for (auto i : css){
			for (auto j : css){
				if (css_elems[i][0] == css_elems[j][0]){
					common_map[i].insert(j);//如果首符相同则放入一个集合中
					if (common_map[i].size() > max){
						key = i;
						max = common_map[i].size();
					}
				}
			}
		}
		if (max == 1){//如果首符都不相同 则无需做任何改变
			return false;
		}
		//如果存在相同的首符集 改变 产生式 找到相同集合中最长的匹配子串
		std::set<std::string> common_css = common_map[key];
		std::string last = " ";
		int index = 0;
		bool flag = true;
		int len = get_min_length(common_css);
		while (flag){
			std::string temp = css_elems[key][index];
			for (auto it : common_css){// 如果有一个子串不相同 则跳出当前循环
				if (css_elems[it][index] != temp){
					flag = false;
				}
			}
			if (flag){
				last += " ";
				last += css_elems[key][index];
				index++;
			}
			if (index == len){
				flag = false;
			}
		}
		//改变产生式 将相同的左因子合并
		std::string temp = nonterm;
		temp += "'";
		while (!G[temp].empty()){
			temp += "'";
		}
		std::set<std::string> new_css2;
		std::set<std::string> new_css3;
		for (auto it : css){
			if (!common_css.count(it)){//如果它不在相同的集合中出现 则直接将其加入nonterm的新的产生式中
				new_css2.insert(it);
			}
			else{
				std::string temp2 = last;
				temp2 += " ";
				temp2 += temp;
				new_css2.insert(temp2);
				std::string temp3 = partition_css(last, it);
				if (temp3 == ""){
					temp3 += "#";
				}
				temp3 += " ";
				new_css3.insert(temp3);
			}
		}
		G[nonterm] = new_css2;
		G[temp] = new_css3;
		Q1.push(temp);
		return true;
	}

	void get_left_factoring(std::map<std::string, std::set<std::string>>& G){
		std::queue<std::string> Q1;//遍历一遍map 将所有的非终结符放入队列中
		for (auto it : G){
			Q1.push(it.first);
		}
		while (!Q1.empty()){//当队列非空时 找出非终结符所对应的产生式
			std::string now_nt = Q1.front();//当前非终结符
			bool change = true;
			while (change){
				bool tmp = get_max_length(G, now_nt, Q1);
				if (!tmp){
					change = false;
				}
			}
			Q1.pop();
		}
	}
public:
	std::map<std::string, std::set<std::string>> rlr(){
		std::map<std::string, std::set<std::string>> G;
		Fileiostream filestream;
		filestream.fileiostream(G);
		general_left_recursion(G);
		get_left_factoring(G);
		return G;
	}
};


#endif