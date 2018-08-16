
// 1、一步到位 T=O(n^2) S=O(1)
class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        int n = (int)matrix.size();

        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < n - 2 * i - 1; j++) {
                int tmp = matrix[i][i + j];                                           // top -> temp
                matrix[i][i + j]                 = matrix[n - 1 - i - j][i];          // left -> top
                matrix[n - 1 - i - j][i]         = matrix[n - 1 - i][n - 1 - i - j];  // bottom -> left
                matrix[n - 1 - i][n - 1 - i - j] = matrix[i + j][n - 1 - i];          // right -> bottom
                matrix[i + j][n - 1 - i]         = tmp;                               // temp -> right
            }
        }
    }
};


// 2、两步到位 (a common method to solve the image rotation problems)  T=O(n^2) S=O(1) 程序更容易写出，推荐此法

/** clockwise rotate
 * first reverse up to down, then swap the symmetry
 * 1 2 3     7 8 9     7 4 1
 * 4 5 6  => 4 5 6  => 8 5 2
 * 7 8 9     1 2 3     9 6 3
 */
void rotate(vector<vector<int> > &matrix) {
    reverse(matrix.begin(), matrix.end());  // O(n^2)
    for (int i = 0; i < matrix.size(); ++i) {  // O(n^2) 只将对角线之上的元素作为“主换元素”
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
        }
    }

/** anticlockwise rotate
 * first reverse left to right, then swap the symmetry
 * 1 2 3     3 2 1     3 6 9
 * 4 5 6  => 6 5 4  => 2 5 8
 * 7 8 9     9 8 7     1 4 7
 */
void anti_rotate(vector<vector<int> > &matrix) {
    for (auto vi : matrix) reverse(vi.begin(), vi.end());  // O(n^2)
    for (int i = 0; i < matrix.size(); ++i) {  // O(n^2)
        for (int j = i + 1; j < matrix[i].size(); ++j)
            swap(matrix[i][j], matrix[j][i]);
    }
}