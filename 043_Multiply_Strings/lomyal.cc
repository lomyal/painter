
// 1、注意res是算出一个“个位乘法”就把这个积加到对应的位上，然后直接把进位加到前一位上
class Solution {
public:
    string multiply(string num1, string num2) {
        int l1 = (int)num1.size();
        int l2 = (int)num2.size();

        if (!l1 || !l2) {
            return "0";
        }

        // res保存中间结果，为计算方便，左边是最低位
        vector<int> res(l1 + l2, 0);

        for (int i = 0; i < l1; ++i) {
            int x = num1[l1 - i - 1] - '0';

            for (int j = 0; j < l2; ++j) {
                int y = num2[l2 - j - 1] - '0';

                // 直接将进位加到前一位上，溢出的问题交由下一循环解决
                int sum = res[i + j] + x * y;
                res[i + j] = sum % 10;
                res[i + j + 1] += sum / 10;
            }
        }

        string result("");
        int start = (int)res.size() - 1;

        // 从后向前寻找第一个不是0的位
        while (start >= 0 && !res[start]) {
            --start;
        }

        if (start == -1) {
            return "0";
        }

        // 反转res
        for (int i = start; i >= 0; --i) {
            result += ('0' + res[i]);
        }

        return result;
    }
};