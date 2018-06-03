#include<iostream>
#include<string>
using namespace std;
int huiwen_bruteforce(string str,int i){
	int k=1,len=str.length();
	while (i + k < len){
		if (str[i - k] == str[i + k]){
			k++;
		}
		else{
			break;
		}
	}
	return k;
}
int huiwen_bruteforce(string str,int i, int pianyi){
	int k = pianyi, len = str.length();
	while (i +k < len){
		if (str[i - k] == str[i + k]){
			k++;
		}
		else{
			break;
		}
	}
	return k;
}
void Manacher(string str, int* p){
	int len = str.length();
	int mx = -1,id=-1;
	int j;
	for (int i = 1; i < len; i++){
		if (i>mx){
			p[i]=huiwen_bruteforce(str,i);
		}
		else{
			j = 2 * id - i;
			if (i+p[j]-1<=mx){
				p[i] = p[j];
			}
			else{
				p[i] = huiwen_bruteforce(str,i, mx-i);
			}
		}
		if (p[i]+i -1> mx){
			mx = p[i]+i-1;
			id = i;
		}
	}
	cout << endl;
	for (int i = 0; i < len; i++){
		cout << p[i] << " ";
	}
	cout << endl;
}
int main(){
	string str="$#", a;
	cout << "ÇëÊäÈë×Ö·û´®£º" << endl;
	cin >> a;
	int n = a.length();
	for (int i = 0; i < n; i++){
		str += a[i];
		str += '#';
	}
	cout << endl;
	for (int i = 0; i < str.length(); i++){
		cout << str[i] << " ";
	}
	cout << endl;
	int p[100];
	memset(p, 0, sizeof(p));
	Manacher(str,p);
	system("pause");
	return 0;
}