class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        if (m == 0) {
            return false;
        }
        int n = board[0].size();
        if (n == 0) {
            return false;
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                std::vector<std::vector<int>> visited(m, std::vector<int>(n, 0));  // 如果board可修改，则此数组可省
                if (board[i][j] == word[0] && search(board, visited, word, 0, i, j)) {
                    return true;
                }
            }
        }
        return false;
    }
private:
    bool search(const std::vector<std::vector<char>>& board,
            std::vector<std::vector<int>>& visited,
            const std::string& word,
            int letter_pos, int i, int j) {
        if (letter_pos >= word.size()) {
            return true;
        }
        int m = board.size();
        int n = board[0].size();
        if (i >= m || j >= n || i < 0 || j < 0 ||
                visited[i][j] == 1 ||
                word[letter_pos] != board[i][j]) {
            return false;
        }
        visited[i][j] = 1;
        if (search(board, visited, word, letter_pos + 1, i + 1, j) ||
                search(board, visited, word, letter_pos + 1, i - 1, j) ||
                search(board, visited, word, letter_pos + 1, i, j + 1) ||
                search(board, visited, word, letter_pos + 1, i, j - 1)) {
            return true;
        } else {
            visited[i][j] = 0;
            return false;
        }
    }
};
