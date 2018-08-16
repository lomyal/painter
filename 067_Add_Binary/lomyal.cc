
// 1、7ms。没有使用字符串拼接（不知道C++中拼接效率如何？），而是使用了固定长度的char数组作为buffer。
// 注意：数组使用变量作为初始化长度在一些（？）C++编译器中是允许的，但此时数组是不进行默认初始化的！

class Solution {  // T=O(n) S=O(n)
public:
    string addBinary(string a, string b)
    {
        int lenA = (int)a.length();
        int lenB = (int)b.length();
        int lenS = max(lenA, lenB) + 1;  // 这个 +1 是考虑了可能的最高进位
        int pa = lenA - 1;
        int pb = lenB - 1;
        int ps = lenS - 1;

        // 选择用字符数组而不是string或vector<char>，是因为字符数组在最后处理最高位是否有进位的问题时比较方便
        char sum[lenS + 1];  // 这个 +1 是考虑了最后一位 '\0'。
        int carry = 0;

        sum[lenS] = '\0';  // 初始化结尾标定（非常重要）
        while (ps) {  // 新字符串的第0位在循环之后再特殊处理
            int x = pa < 0 ? 0 : a[pa--] - '0';  // 个人感觉这个写法不错
            int y = pb < 0 ? 0 : b[pb--] - '0';
            int s = x + y + carry;

            carry = s / 2;
            sum[ps--] = s % 2 + '0';
        }

        if (carry) {  // 原最高位需要进位
            sum[0] = 1 + '0';
            return sum;
        } else {
            return sum + 1;  // 跳过第一个字符
        }
    }
};