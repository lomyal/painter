// 把给的数值n减去1，就完全是10进制转成26进制的玩法

class Solution {
public:
    string convertToTitle(int n) {

        /* 原来转成char就能拼接了…… */
        return 0 == n ? "" : convertToTitle((n - 1) / 26) + (char)((n - 1) % 26 + 'A');
    }
};