
// 1、DP 3ms
class Solution {
public:
    int climbStairs(int n)
    {
        if (n <= 2) {
            return n;
        }

        int current = 0;

        for (int i = 3, last1 = 1, last2 = 2; i <= n; i++) {
            current = last1 + last2;
            last1 = last2;
            last2 = current;
        }

        return current;
    }
};

// 2、递归，写法简洁有助理解，但重复计算过多，超时
class Solution {
public:
   int climbStairs(int n)
   {
       if (n <= 2) {
           return n;
       }

       return climbStairs(n - 1) + climbStairs(n - 2);
   }
};

// 3、数学方法，6ms
class Solution {
public:
    int climbStairs(int n)
    {
        if (n == 0) {
            return 0;
        }

        int total = 0;

        for (int n2 = 0; n2 <= n / 2; n2++) {  // 确定有几个2步
            total += c(n - n2, n2);  // 确定这些2步分散在什么位置
        }

        return total;
    }

private:
    // 计算组合数
    int c(int n, int m)
    {
        if (m > n / 2) {
            m = n - m;
        }

        long long ret = 1;
        for (int i = 1; i <= m; i++) {
            ret *= (n - m + i);
            ret /= i;  // 如果乘除不同步进行，在n=44时会溢出
        }

        return (int)ret;
    }
};