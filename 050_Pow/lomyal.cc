
// 1、迭代版本，个人认为最好 7ms T=O(log n) S=O(1)
class Solution {
public:
    double pow(double x, int n)
    {
        double ans = 1;
        bool flag = true;
        if (n < 0) {
            flag = false;  // 先做乘法最后再取倒数，貌似比一开始就取倒数更精确？
            n = -n;  // 若n为-2147483648，则-n仍是-2147483648。但不影响结果。事实上，此行可去掉。
        }
        while (n) {
            if (n % 2 != 0) {  // 若 n 不是偶数，则提前在结果上乘一个 x (最后一次 n==1，ans 一定会最后乘上 x)
                ans *= x;
            }
            x *= x;  // x 变为 x^2
            n /= 2;  // n 变为 n/2
        }
        if (flag) {
            return ans;
        } else {
            return 1.0 / ans;
        }
    }
};

// 2、递归版本 9ms T=O(log n) S=O(log n)
class Solution {
public:
    double pow(double x, int n)
    {
        if (n == 0) {
            return 1;
        }
        if (n < 0) {
            n = -n;
            x = 1 / x;
        }
        double y = pow(x * x, n / 2);
        return (n % 2 == 0) ? y : x * y;
    }
};

// 3、写法奇怪的递归版本 6ms
class Solution {
public:
    double pow(double x, int n) {
        if (n == -2147483648) {
            return pow(1 / x, 1 - n) / x;

        } else if (n < 0) {
            return pow(1 / x, -n);

        } else if (n == 0) {
            return 1.0;

        } else if (n == 1) {
            return x;

        } else if (n == n / 2 * 2) {
            double mul = pow(x, n / 2);
            return mul * mul;

        } else {
            int m = n / 2 * 2;
            return pow(x, m) * pow(x, n - m);
        }
    }
};