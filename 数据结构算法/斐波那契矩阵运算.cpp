#include<iostream>
#include<map>
using namespace std;

class matrix{
public:
	int x11, x12, x21, x22;

	matrix(){
		x11 = 1;
		x12 = 0;
		x21 = 0;
		x22 = 1;
	}

	matrix(int tmp_x11,int tmp_x12,int tmp_x21,int tmp_x22){
		x11 = tmp_x11;
		x12 = tmp_x12;
		x21 = tmp_x21;
		x22 = tmp_x22;
	}
	matrix operator *(const matrix a){
		int tmp_x11 = this->x11*a.x11+this->x12*a.x21;
		int tmp_x12 = this->x11*a.x12 + this->x12*a.x22;
		int tmp_x21 = this->x21*a.x11 + this->x22*a.x21;
		int tmp_x22 = this->x21*a.x12 + this->x22*a.x22;
		return matrix(tmp_x11, tmp_x12, tmp_x21, tmp_x22);
	}
}; 

map<int, matrix> f_map;

matrix matrix_pow(matrix a,int n){
	matrix temp(1, 0, 0, 1);
	if (f_map[n].x11==temp.x11&&f_map[n].x12==temp.x12&&f_map[n].x21==temp.x21&&f_map[n].x22==temp.x22){
		if (n % 2 == 0){
			f_map[n] = matrix_pow(a,n/2) * matrix_pow(a,n/2);
			return f_map[n];
		}
		else{
			f_map[n] = matrix_pow(a,n/2) * matrix_pow(a,n/2) * matrix_pow(a,1);
			return f_map[n];
		}
	}
	else{
		return f_map[n];
	}
}

int f(int n){
	if (n == 1){
		return 1;
	}
	if (n == 2){
		return 1;
	}
	matrix a(0, 1, 1, 1);
	f_map[1] = a;
	f_map[2] = a*a;
	matrix sum = matrix_pow(a, n - 2);
	return sum.x21 + sum.x22;
}
int main(){
	int n=20;
	cout << f(n) << endl;
	system("pause");
	return 0;
}