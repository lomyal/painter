
// 1、不使用库函数计算字符串长度，从前向后遍历 4ms
class Solution {
public:
    int lengthOfLastWord(const char *s)
    {
        int n = 0;

        while (*s) {
            if (*s++ != ' ') {  // 当前位置不是空格，闷头自加即可
                ++n;
            } else if (*s && *s != ' ') {  // 当前位置是空格，下一位置不是空格（前提是存在下一位置），则重置计数
                n = 0;
            }

            // 当前位置是空格，下一位置也是空格，或下一位置是结束位'\0'，则不做动作
        }

        return n;
    }
};

// 2、使用库函数计算字符串长度，从后向前遍历 4ms
class Solution {
public:
    int lengthOfLastWord(const char *s) {

        int n = 0;
        for (int i = (int)strlen(s) - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                if (n != 0) {
                    return n;
                }
            } else {
                n++;
            }
        }

        return n;
    }
};