
// 1、递归 10ms T=O(log n) S=O(log n)
class Solution {
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n / 5 + trailingZeroes(n / 5);
    }
};

// 2、8ms T=O(log n) S=O(1)
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while(n) {
            n /= 5;
            res += n;
        }
        return res;
    }
};


// 3、8ms
class Solution {
public:
    int trailingZeroes(int n)
    {
        if (n == 0) {
            return 0;
        }

        int maxLog5 = log(n) / log(5.0);
        int numOf5 = 0;

        for (int i = 1; i <= maxLog5; i++) {
            numOf5 += n / (int)pow(5, i);
        }

        return numOf5;
    }
};