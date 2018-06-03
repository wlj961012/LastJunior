#include<iostream>
#include<vector>
using namespace std;
bool is_valid(vector<vector<int>> board,int x,int y) {
	for (int i = 0; i < 9; i++)
		if (i != x && board[i][y] == board[x][y])
			return false;
	for (int j = 0; j < 9; j++)
		if (j != y && board[x][j] == board[x][y])
			return false;
	for (int i = 3*(x / 3); i < 3*(x / 3) + 3; i++) {
		for (int j = 3*(y / 3); j < 3*(y / 3) + 3; j++) {
			if ((i != x && j != y) && board[i][j] == board[x][y]) {
				return false;
			}
		}
	}
	return true;
}
bool solution(vector<vector<int>> &board) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == 0) {
				for (int k = 1; k <=9; k++) {
					board[i][j] = k;
					if (is_valid(board, i, j) && solution(board)) {
						return true;
					}
					board[i][j] = 0;
				}
				return false;
			}
		}
	}
	return true;
}
int main() {
	vector<vector<int>> board;
	for (int i = 0; i < 9; i++) {
		vector<int> k = vector<int>(9, 0);
		board.push_back(k);
	}
	board[0][0] = 5;
	board[0][1] = 3;
	board[0][4] = 7;
	board[1][0] = 6;
	board[1][3] = 1;
	board[1][4] = 9;
	board[1][5] = 5;
	board[2][1] = 9;
	board[2][2] = 8;
	board[2][7] = 6;
	board[3][0] = 8;
	board[3][4] = 6;
	board[3][8] = 3;
	board[4][0] = 4;
	board[4][3] = 8;
	board[4][5] = 3;
	board[4][8] = 1;
	board[5][0] = 7;
	board[5][4] = 2;
	board[5][8] =6;
	board[6][1] = 6;
	board[6][6] = 2;
	board[6][7] = 8;
	board[7][3] = 4;
	board[7][4] = 1;
	board[7][5] = 9;
	board[7][8] = 5;
	board[8][4] = 8;
	board[8][7] = 7;
	board[8][8] = 9;
	if (solution(board)) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << "  ";
			}
			cout << endl;
		}
	}
	system("pause");
	return 0;
}