
// 1、57ms
class Solution {
public:
    int romanToInt(string s) {

        // I(1), V(5), X(10), L(50), C(100), D(500), M(1000).

        int len = (int)s.length();
        int lastWord = 0;
        int value = 0;

        for (int i = len - 1; i > -1; i--) {
            int curruntWord = this->charToInt(s[i]);

            if (curruntWord >= lastWord) {  // @@ key
                value += curruntWord;
            } else {
                value -= curruntWord;
            }
            lastWord = curruntWord;
        }

        return value;
    }

private:
    int charToInt(char c) {
        if ('I' == c) {
            return 1;
        } else if ('V' == c) {
            return 5;
        } else if ('X' == c) {
            return 10;
        } else if ('L' == c) {
            return 50;
        } else if ('C' == c) {
            return 100;
        } else if ('D' == c) {
            return 500;
        } else if ('M' == c) {
            return 1000;
        } else {
            return 0;
        }
    }
};

// 从后向前走比较容易，比较容易保存lastWord，当前位置数字的符号是根据“比后一位数字大、小”确定的。

// 改进方向：
// 1、不记录lastWord（记录需要赋值），当前位置字符直接与后一位置的字符比较。（缺点是需要多次执行chatToInt的转换）
