
// 1、14ms
class Solution {
public:
    bool isPalindrome(string s) {

        if ("" == s) {
            return true;
        }

        int len = (int)s.length();

        int i = 0, j = len - 1;
        while (i < j) {
            while (!isAlphanumeric(s[i])) i++;
            while (!isAlphanumeric(s[j])) j--;

            if (i < j && toLowerCase(s[i]) != toLowerCase(s[j])) {
                return false;
            }
            i++;
            j--;
        }

        return true;
    }

private:
    bool isAlphanumeric(char c) {

        if (c >= '0' && c <= '9') {
            return true;
        } else if (c >= 'a' && c <= 'z') {
            return true;
        } else if (c >= 'A' && c <= 'Z') {
            return true;
        } else {
            return false;
        }
    }

    char toLowerCase(char c) {
        if (c >= 'A' && c <= 'Z') {
            return c + ('a' - 'A');
        } else {
            return c;
        }
    }
};



// 2、15ms

class Solution {
public:
    bool isPalindrome(string s) {

        for (int i = 0, j = (int)s.length() - 1; i < j; i++, j--) {
            while (!isalnum(s[i])) i++;
            while (!isalnum(s[j])) j--;

            if (i < j && tolower(s[i]) != tolower(s[j])) {
                return false;
            }
        }

        return true;
    }
};

// 有现成的isalnum() 和 tolower() 函数可用（#include <cctype>）
// 且字符串判空操作没有必要，最后的return true恰好可以包含这种情况。

