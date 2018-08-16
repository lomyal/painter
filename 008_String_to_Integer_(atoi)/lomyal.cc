
// 1、
class Solution {
public:
    int atoi(const char *str) {

        // 空白处理
        while (*str == ' ') {
            str++;
        }

        // 正负号处理
        bool neg;
        if (*str == '-') {
            neg = true;
            str++;
        } else {
            neg = false;
            if (*str == '+') {
                str++;
            }
        }

        // 非数字处理
        if (*str < '0' || *str > '9') {
            return 0;
        }

        // 转换
        int n = 0;
        while (*str >= '0' && *str <= '9') {
            if (n == 214748364) {  // @@ 溢出处理，在可能溢出的前一位就下手
                if (neg && *str > '8') {
                    return INT_MIN;
                } else if (!neg && *str > '7') {
                    return INT_MAX;
                }
            } else if (n > 214748364) {
                if (neg) {
                    return INT_MIN;
                } else {
                    return INT_MAX;
                }
            }
            n = n * 10 + (*str - '0');
            str++;
        }

        return neg ? -n : n;
    }
};

// 2、在此题中，由于overflow时要求返回INT_MAX或INT_MIN，所以溢出处理部分可以简化：（同样的答案，一次24ms，一次15ms。。。）

class Solution {
public:
    int atoi(const char *str) {
        int sign = 1, base = 0, i = 0;
        while (str[i] == ' ') { i++; }
        if (str[i] == '-' || str[i] == '+') {
            sign = 1 - 2 * (str[i++] == '-');
        }
        while (str[i] >= '0' && str[i] <= '9') {
            if (base >  INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {  // @@ 注意 INT_MAX / 10 的用法，不必手写 214748364
                if (sign == 1) return INT_MAX;
                else return INT_MIN;  // 当数值恰好为INT_MIN时，虽然是按溢出处理的（实际不溢出），但返回值恰好是正确的。
            }
            base  = 10 * base + (str[i++] - '0');
        }
        return base * sign;
    }
};