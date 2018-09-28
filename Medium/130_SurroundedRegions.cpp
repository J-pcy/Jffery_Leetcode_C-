/*
Given a 2D board containing 'X' and 'O' (the letter O), capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

Example:

X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
Explanation:

Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'. Any 'O' that is not on the border and it is not connected to an 'O' on the border will be flipped to 'X'. Two cells are connected if they are adjacent cells connected horizontally or vertically.
*/

class Solution {
public:
/*
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if ((i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1) && board[i][j] == 'O') {
                    dfs(board, i, j);
                }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }
    void dfs(vector<vector<char>> &board, int x, int y) {
        if (board[x][y] == 'O') {
            board[x][y] = '$';
            for (int i = 0; i < 4; i++) {
                int cur_x = x + dir_x[i];
                int cur_y = y + dir_y[i];
                if (cur_x >= 0 && cur_x < board.size() && cur_y >= 0 && cur_y < board[cur_x].size()) {
                    dfs(board, cur_x, cur_y);
                }
            }
        }
    }
private:
    vector<int> dir_x{0, 0, -1, 1};
    vector<int> dir_y{-1, 1, 0, 0};*/
    void solve(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if ((i == 0 || i == board.size() - 1 || j == 0 || j == board[i].size() - 1) && board[i][j] == 'O') {
                    bfs(board, i, j);
                }
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == '$') board[i][j] = 'O';
            }
        }
    }
    void bfs(vector<vector<char>>& board, int x, int y) {
        queue<pair<int, int>> que;
        board[x][y] = '$';
        que.push({x, y});
        while (!que.empty()) {
            int cur_x = que.front().first;
            int cur_y = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++) {
                int new_x = cur_x + dir_x[i];
                int new_y = cur_y + dir_y[i];
                if (new_x >= 0 && new_x < board.size() && new_y >= 0 && new_y < board[new_x].size() && board[new_x][new_y] == 'O') {
                    board[new_x][new_y] = '$';
                    que.push({new_x, new_y});
                }
            }
        }
    }
private:
    vector<int> dir_x{0, 0, -1, 1};
    vector<int> dir_y{-1, 1, 0, 0};
};