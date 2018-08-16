
// 1、6ms
class Solution {
public:
    string countAndSay(int n) {
        string s = "1";

        for (; n > 1; --n) {
            s = helper(s);
        }

        return s;
    }
private:
    string helper(string s) {
        int len = (int)s.length();
        char buffer[len * 2 + 1];  // 防止溢出，考虑最长情况：没有相邻的数字，123456->111213141516

        int cur = 0;

        for (int i = 0, count = 0; i < len; ++i) {
            if (s[i] == s[i + 1]) {  // 覆盖了最后一个元素的处理（string类型也有最后的'\0'）
                ++count;

            } else {  // 在连续字符结束时（当前字符仍是其结尾），向buffer输出“个数”和“数字”
                for (char c : to_string(count + 1)) {  // 应对“个数”超过9的情况 （to_string 是 C++11 的新函数）
                    buffer[cur++] = c;
                }
                count = 0;
                buffer[cur++] = s[i];
            }
        }
        buffer[cur] = '\0';

        return buffer;  // 直接返回buffer，char[]自动转型成string
    }
};