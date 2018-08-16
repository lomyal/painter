
// 1、朴素解法：6ms T=O(mn)（在leetcode的测试用例下反而比高效的KMP或BM算法快）
class Solution {
public:
    int strStr(char *haystack, char *needle)
    {
        int len_haystack = (int)strlen(haystack);
        int len_needle = (int)strlen(needle);

        if (len_haystack < len_needle) {
            return -1;
        }

        for (int begin = 0; begin <= len_haystack - len_needle; begin++) {  // 若使用len_haystack - 1作为结束条件，会导致超时
            int i = 0;

            while (i < len_needle && haystack[begin + i] == needle[i]) {
                ++i;
            }

            if (i == len_needle) {
                return begin;
            }
        }

        return -1;
    }
};


// 2、Boyer-Moore

// 3、KMP