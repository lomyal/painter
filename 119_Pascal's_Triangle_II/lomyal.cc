
// 1、2ms T=O(n^2) S=O(1)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vi(rowIndex + 1);  // 初始化为0，后面计算中会利用到
        vi[0] = 1;
        for (int i = 0; i <= rowIndex ; ++i)
        {
            for (int j = i; j > 0; --j)  // 不考虑对称性，直接暴力计算 (反而比利用对称性更快？)
            {
                vi[j] = vi[j] + vi[j-1];  // @@ key，从后向前计算，不需额外空间
            }
        }
        return vi;
    }
};


// 2、3ms T=O(n^2) S=O(1)
class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> row = {1};
        if (rowIndex == 0) {
            return row;
        }

        row.push_back(1);
        if (rowIndex == 1) {
            return row;
        }

        for (int i = 2; i <= rowIndex; i++) {
            for (int j = i / 2; j > 0; j--) {
                row[j] = row[j] + row [j - 1];
            }
            row.push_back(1);

            // 根据对称性，后半部分不必做加法运算
            for (int j = 1, k = i - 1; j < k; j++, k--) {
                row[k] = row[j];
            }
        }

        return row;
    }
};