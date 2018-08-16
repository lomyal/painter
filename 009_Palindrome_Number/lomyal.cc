
// 1、131ms
/* 数值解法 */
class Solution {
public:
    bool isPalindrome(int x) {

        if (x < 0) {
            return false;
        }

        long upper = 10, lower = 1;  // long 类型很重要，否则可能溢出
        while (x / upper) {
            upper *= 10;
        }
        upper /= 10;

        while (upper > lower) {
            if (x / upper % 10 != x / lower % 10) {  // @@ key
                return false;
            }
            upper /= 10;
            lower *= 10;
        }

        return true;
    }
};


// 2、154ms
/* old 转换成字符串的解法  */
class Solution {
public:
    bool isPalindrome(int x) {

        stringstream buffer;

        buffer << x;
        string str = buffer.str();
        int len = (int)str.length();


        for (int i = 0; i < len / 2; i++) {
            if (str[i] != str[len - i - 1]) {
                return false;
            }
        }

        return true;

    }
};

// 3、反转数字 147ms

// 注意：
// 只需反转一半。
// 怎么知道已经达到了一半？同时缩小了x值即可。

/* 反转一半字符串的解法，没有溢出的问题 */
class Solution {
public:
    bool isPalindrome(int x) {
        int i = 0;;
        if ((x % 10 == 0 && x != 0) || x < 0) return false;
        while (i < x) {
            i = i * 10 + x % 10;
            x = x / 10;
        }
        return (i == x || i / 10 == x);  // @@ 前一种位数为偶数，后一种位数为奇数
    }
};