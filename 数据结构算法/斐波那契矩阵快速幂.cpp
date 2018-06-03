#include<iostream>
using namespace std;
class matrix{
public:
	int x11;
	int x12;
	int x21;
	int x22;
	matrix(){
		x11 = 1;
		x12 = 0;
		x21 = 0;
		x22 = 1;
	}
	matrix(int tmp_x11, int tmp_x12, int tmp_x21, int tmp_x22){
		x11 = tmp_x11;
		x12 = tmp_x12;
		x21 = tmp_x21;
		x22 = tmp_x22;
	}
	matrix operator *(const matrix a){
		int tmp_x11 = this->x11*a.x11 + this->x12*a.x12;
		int tmp_x12 = this->x11*a.x21 + this->x12*a.x22;
		int tmp_x21 = this->x21*a.x11 + this->x22*a.x12;
		int tmp_x22 = this->x21*a.x21 + this->x22*a.x22;
		return matrix(tmp_x11, tmp_x12, tmp_x21, tmp_x22);
	}
};
int f(int n){
	if (n == 1){
		return 1;
	}
	if (n == 2){
		return 1;
	}
	int temp = n - 2;
	matrix a(0, 1, 1, 1);
	matrix sum(1, 0, 0, 1);
	do{
		if (temp & 1 == 1){
			sum = sum*a;
		}
		a = a*a;
		temp = temp >> 1;
	} while (temp);
	return sum.x21 + sum.x22;
}
int main(){
	int n = 20;
	cout << f(n) << endl;
	system("pause");
	return 0;
}