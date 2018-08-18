// 找到和和边缘相连的O区域（DFS，也可BFS），这些区域不变，其他的O全变X
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ((i == 0 || i == m - 1 || j == 0 || j == n - 1) &&
                        board[i][j] == 'O') {
                    mark(board, i, j);  // 标记和边缘相连的不需要改变的O区域
                }
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';  // 改变需要翻转的区域
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';  // 恢复被标记的区域
                }
            }
        }
    }
private:
    // 能进mark函数的，都是要标记的不变区域（与边缘相连），DFS
    void mark(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()) {
            return;
        }
        if (board[i][j] == 'O') {
            board[i][j] = '#';
            mark(board, i + 1, j);
            mark(board, i - 1, j);
            mark(board, i, j + 1);
            mark(board, i, j - 1);
        }
    }
};