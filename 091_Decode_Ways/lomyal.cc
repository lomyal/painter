
// DP。每步只需要前两步的值，因此不必保存每一步的值
// 原理是
// 乘法原理（“1：我这关你过去了，0：我这关你没过去，啥也别想了！”）
// 和加法原理（这一关有2种可能）

class Solution {
public:
    int numDecodings(string s) {
        int n = (int)s.length();

        if (n == 0) {
            return 0;  // 注意这里与 result1 初始值的微妙差别
        }

        if (s[0] == '0') {  // 如果第一位是“0”，则最后的结果永远是0
            return 0;
        }

        // 初始值
        int result1 = 1;  // 空字符串可译码的结果是1，表示后边可接任意一种组合（喊道：“我这关你过去了！”）
        int result2 = 1;  // 第1位数字不是“0”，可译码的结果是1

        for (int i = 1; i < n; i++) {

            // 0 ~ i 位合起来看的总可译码数
            int result =

                    // 若当前位置（1位数）可译码，则增加result2种结果（严格来说是... ? 1*result2 : 0*result2，1或0 是“这一关”，result2是“前面所有的关”）
                    ((s[i] != '0') ? result2 : 0) +

                    // 若当前位置和前一位置合起来（2位数）可译码，则增加result1种结果
                    ((s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '0' && s[i] <= '6')) ? result1 : 0);

            // 更新“前两步”的结果
            result1 = result2;
            result2 = result;
        }

        return result2;
    }
};