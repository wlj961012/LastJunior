#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<set>
using namespace std;
set<char> get_letter(vector<string> dict) {
	set<char> letters;
	int len = dict.size();
	for (int i = 0; i < len; i++) {
		string temp = dict[i];
		int len2 = temp.size();
		for (int j = 0; j < len2; j++) {
			letters.insert(temp[j]);
		}
	}
	return letters;
}
set<string> get_words(string letter,set<char> letters,set<string> dict) {
	set<string> words;
	int len = letter.size();
	int len2 = letters.size();
	for (int i = 0; i < len; i++) {
		char temp = letter[i];
		for (int j = 0; j < len2; j++) {
			if()
		}
	}
}
map<string, string> get_map(set<char> letters,set<string> dict) {
	map<string, string> letter_map;
	int len = dict.size();
	for (int i = 0; i < len; i++) {
		
	}
}
int main() {
	set<string> dict;
	string start, end;
	dict.insert("hot");
	dict.insert("dot");
	dict.insert("dog");
	dict.insert("lot");
	dict.insert("log");
	dict.insert("cog");
	start = "hit";
	end = "cog";

}
