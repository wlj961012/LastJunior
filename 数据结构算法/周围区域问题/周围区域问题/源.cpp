#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct weizhi {
	int x;
	int y;
	weizhi(int i, int j) {
		x = i;
		y = j;
	}
};
bool is_valid(vector<vector<char>> board, int i, int j) {
	int m = board.size();
	int n = board[0].size();
	if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'o') {
		return false;
	}
	return true;
}
vector<weizhi> state_extend(vector<vector<char>> &board,weizhi start) {
	vector<weizhi> result;
	int i = start.x;
	int j = start.y;
	vector<weizhi> new_states = { {i + 1,j},{i - 1,j},{i,j + 1},{i,j - 1} };
	for (auto s : new_states) {
		if (is_valid(board, s.x,s.y)) {
			result.push_back(s);
			board[s.x][s.y] = '+';
		}
	}
	return result;
}
void bfs(vector<vector<char>> &board,int i,int j) {
	weizhi start(i, j);
	queue<weizhi> q;
	if (is_valid(board, i, j)) {
		q.push(start);
		board[i][j] = '+';
	}
	while (!q.empty()) {
		weizhi cur = q.front();
		q.pop();
		vector<weizhi> new_states=state_extend(board,cur);
		for (auto s:new_states) {
			q.push(s);
		}
	}
}
void solve(vector<vector<char>> &board) {
	int m = board.size();
	int n = board[0].size();
	for (int i = 0; i < n; i++) {
		bfs(board, i, 0);
		bfs(board, i, m - 1);
	}
	for (int j = 0; j < m; j++) {
		bfs(board, 0, j);
		bfs(board, n - 1, j);
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == '+') {
				board[i][j] = 'o';
			}
			else if (board[i][j] == 'o') {
				board[i][j] = 'x';
			}
		}
	}
}
int main() {
	vector<vector<char>> board;
	vector<char> k1;
	vector<char> k2;
	vector<char> k3;
	vector<char> k4;
	k1.push_back('x');
	k1.push_back('o');
	k1.push_back('x');
	k1.push_back('x');
	k2.push_back('x');
	k2.push_back('o');
	k2.push_back('o');
	k2.push_back('x');
	k3.push_back('x');
	k3.push_back('x');
	k3.push_back('o');
	k3.push_back('x');
	k4.push_back('x');
	k4.push_back('o');
	k4.push_back('x');
	k4.push_back('x');
	board.push_back(k1);
	board.push_back(k2);
	board.push_back(k3);
	board.push_back(k4);
	solve(board);
	int m = board.size();
	int n = board[0].size();
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << "  ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}