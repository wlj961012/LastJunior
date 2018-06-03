#include<iostream>
#include<string>
#include<stack>
#include<cmath>
#include<fstream>
using namespace std;
double mid_expression(string expression);
double  get_num(string expression, int& i){
	int k=0,flag=0,temp;
	double num = 0.0;
	while ((expression[i] >= '0'&&expression[i] <= '9') || expression[i] == '.'){
		if (expression[i] >= '0'&&expression[i] <= '9'&&flag == 0){
			temp = expression[i] - '0';
			num = num * 10 + temp;
			i++;
		}
		else if (expression[i] == '.'){
			flag = 1;
			i++;
		}
		else{
			k++;
			temp = expression[i] - '0';
			num += temp*pow(10, -k);
			i++;
		}
	}
	i--;
	return num;
}
string get_substr(string expression, int& i){
	int num_bracket = 0;
	int len = expression.length();
	string substr;
	for (int j = i; j < len; j++){
		if (expression[j] == '('){
			num_bracket++;
		}
		if (expression[j] == ')'){
			num_bracket--;
		}
		if (expression[j] == ')'&&num_bracket == 0){
			break;
		}
		substr += expression[j];
		i++;
	}
	substr.erase(substr.begin());
	substr.erase(substr.end());
	return substr;
}
void multiply_operation(string expression, int& i, stack<double>& number){
	i++;
	double a, b, sum;
	if (expression[i] >= '0'&&expression[i] <= '9'){
		b=get_num(expression, i);
		a = number.top();
		number.pop();
		sum = a*b;
		number.push(sum);
	}
	else{
		string substr;
		substr=get_substr(expression, i);
		b=mid_expression(substr);
		a = number.top();
		number.pop();
		sum = a*b;
		number.push(sum);
	}
}
void divide_operation(string expression, int& i, stack<double>& number){
	i++;
	double a, b, sum;
	if (expression[i] >= '0'&&expression[i] <= '9'){
		b = get_num(expression, i);
		a = number.top();
		number.pop();
		sum = a / b;
		number.push(sum);
	}
	else{
		i++;
		string substr;
		substr = get_substr(expression, i);
		b = mid_expression(substr);
		a = number.top();
		sum = a / b;
		number.push(sum);
	}
}
stack<string> stack_reverse(stack<string> a){
	stack<string> b;
	string temp;
	while (a.empty() == false){
		temp = a.top();
		b.push(temp);
		a.pop();
	}
	return b;
}
stack<double> stack_reverse(stack<double> a){
	stack<double> b;
	double temp;
	while (a.empty() == false){
		temp = a.top();
		b.push(temp);
		a.pop();
	}
	return b;
}
double final_plus_minus(stack<double>& number,stack<string>& operation){
	double a, b, sum;
	string ope;
	while (operation.empty() == false){
		ope = operation.top();
		a = number.top();
		number.pop();
		b = number.top();
		number.pop();
		if (ope == "+"){
			sum = a + b;
			number.push(sum);
		}
		else{
			sum = a - b;
			number.push(sum);
		}
		operation.pop();
	}
	return number.top();
}
double mid_expression(string expression){
	stack<string> operation;
	stack<double> number;
	//number.push(0);
	int len = expression.length();
	double temp;
	string substr;
	int i = 0;
	if (expression[0] == '-'){
		i++;
		temp=get_num(expression, i);
		i++;
		number.push(-temp);
	}
	for (; i < len; i++){
		switch (expression[i]){
		case '+':
			operation.push("+");
			break;
		case '-':
			operation.push("-");
			break;
		case '*':
			multiply_operation(expression, i, number);
			break;
		case '/':
			divide_operation(expression, i, number);
			break;
		case '(':
			substr = get_substr(expression, i);
			temp=mid_expression(substr);
			number.push(temp);
			break;
		default:
			temp=get_num(expression, i);
			number.push(temp);
			break;
		}
	}
	number=stack_reverse(number);
	operation=stack_reverse(operation);
	temp=final_plus_minus(number, operation);
	return temp;
}
int main(){
	/*string expression;
	cout << "请输入表达式：" << endl;
	cin >> expression;
	double ans;
	ans=mid_expression(expression);
	cout << ans << endl;*/
	string ex;
	ifstream infile;
	infile.open("1.in");
	while (getline(infile, ex)){}
	cout << ex;
	
	
	
	
	
	/*ofstream file;
	int ans = mid_expression(expression);
	file.open("1.out");
	file << ans;
	file.close();*/
	system("pause");
	return 0;
}