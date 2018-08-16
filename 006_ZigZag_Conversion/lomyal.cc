
// 1、逻辑写起来复杂，就是人工计算序号的映射，但好处是计算速度快(常数倍时间)，节省空间  T=O(n) S=O(1)
class Solution {
public:
    string convert(string s, int nRows) {

        int len = (int)s.length();  // 总字符数
        if (len == 0 || nRows == 1) {
            return s;
        }

        int res = len % (2 * nRows - 2);  // 最后一块中的字符数
        int nBlock = len / (2 * nRows - 2);  // 总块数(只计算完整的块)
        string result(s);

        for (int i = 0; i < len; i++) {
            int block = i / (2 * nRows - 2);  // 当前字符所在块
            int position = i % (2 * nRows - 2);  // 当前字符在块中的位置
            int row;  // 当前字符所在行数
            int col;  // 当前字符在块中的列数（0或1）
            int j;  // 当前字符在新字符串中的位置

            if (position < nRows) {
                row = position;
                col = 0;
            } else {
                row = 2 * nRows - 2 - position;
                col = 1;
            }

            // 首先不考虑最右侧的残块
            if (row == 0) {
                j = block;
            } else if (row == nRows - 1) {
                j = nBlock * ( 2 * nRows - 3) + block;
            } else {
                j = nBlock * ( 2 * row - 1) + 2 * block + col;
            }

            // 加入最对右侧的残块的考虑
            if (res < row) {
                j += res;
            } else if (res <= nRows) {
                j += row;
            } else {
                int tmp = res - 2 * nRows + row + 1;  // 此处很难计算
                j += row + (tmp > 0 ? tmp : 0);
            }

            // 给新字符串对应位置赋值
            result[j] = s[i];
        }

        return result;
    }
};


// 2、编程负担小，但耗时间： T=O(n) S=O(n)

class Solution {
public:
    string convert(string s, int nRows) {

        int len = (int)s.length();
        if (len == 0 || nRows == 1) {  // 注意空串、或单行的情况
            return s;
        }
        string result(s);

        vector<vector<char>> container(nRows);

        // int groupLen = nRows == 2 ? 2 : 2 * nRows - 2;  // 注意两行的情况
        int groupLen = 2 * (nRows - 1);  // 两行的情况并不特殊
        for (int i = 0; i < len; i++) {
            int pos = i % groupLen;
            // int row = pos < nRows ? pos : nRows - (pos - nRows) - 2;
            int row = pos < nRows ? pos : groupLen - pos;  // 更简洁的写法

            container[row].push_back(s[i]);
        }

        for (int i = 0, j = 0; i < nRows; i++) {  // i 指向行，j 指向结果result的下一个空位
            int iLen = (int)container[i].size();
            for (int k = 0; k < iLen; j++, k++) {
                result[j] = container[i][k];
            }
        }

        return result;
    }
};

// 3、网上的解法 T=O(n) S=O(n)

string convert(string s, int nRows) {

    if (nRows <= 1)
        return s;

    const int len = (int)s.length();
    string *str = new string[nRows];  // string 和 vector<char> 是类似的

    int row = 0, step = 1;
    for (int i = 0; i < len; ++i)
    {
        str[row].push_back(s[i]);

        if (row == 0)  // 上转折点
            step = 1;
        else if (row == nRows - 1)  // 下转折点
            step = -1;

        row += step;
    }

    s.clear();
    for (int j = 0; j < nRows; ++j)
    {
        s.append(str[j]);
    }

    delete[] str;
    return s;
}
