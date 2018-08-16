
// 1、T=O(n^2) S=O(n^2)  解题思路是HashTable
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board)
    {
        // 记录某单元中是否出现过某数字的数组，第一维是位置，第二维是 数字值-1（HashTable）
        bool appearedInRow[9][9] = {false};
        bool appearedInCol[9][9] = {false};
        bool appearedInBox[9][9] = {false};

        for (int i = 0; i < 9; i++) {  // O(n)
            for (int j = 0; j < 9; j++) {  // O(n)
                char c = board[i][j];

                if (c != '.') {
                    int num = c - '0' - 1;  // num 的含义是 原数字值-1

                    if (appearedInRow[i][num]) {  // O(1)
                        return false;
                    }
                    if (appearedInCol[j][num]) {  // O(1)
                        return false;
                    }

                    int k = (i / 3) * 3 + (j / 3);  // 计算3*3的小9宫格的序号
                    if (appearedInBox[k][num]) {  // O(1)
                        return false;
                    }

                    appearedInRow[i][num] = true;
                    appearedInCol[j][num] = true;
                    appearedInBox[k][num] = true;
                }
            }
        }

        return true;
    }
};