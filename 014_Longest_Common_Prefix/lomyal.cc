
// 1、注意越界问题
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {

        int len = (int)strs.size();
        if (len == 0) {
            return "";
        }

        int max = -1;
        char c;

        while ('\0' != strs[0][++max]) {  // 利用string类型变量最后的’\0’位不与任何字符串相等，不必事先计算出数组中最短字符串的长度
            c = strs[0][max];

            for (int i = 1; i < len; i++) {
                if (strs[i][max] != c) {  // 利用string类型变量最后的’\0’位不与任何字符串相等，不必事先计算出数组中最短字符串的长度
                    return strs[0].substr(0, max);
                }
            }
        }

//        cout << "it happened!" << endl;
        return strs[0].substr(0, max);  // @@ substr 第二个参数的含义是：截取的字符串长度

    }
};


