
// 1、T=O(n) S=O(n)
// 开始想了用map，记录每个数字出现的次数，最后看一遍出现次数，把次数为1的key返回。
// 因为用map，所以单次访问时间是O(1)。
class Solution {
public:
    int singleNumber(int A[], int n) {
        int theOne;
        map<int, int> count;

        for (int i = 0; i < n; i++) {
            if (0 == count.count(A[i])) {
                count[A[i]] = 1;
            } else {
                count[A[i]]++;
            }
        }

        for (auto it = count.cbegin(); it != count.cend(); ++it) {
            if (1 == it->second) {
                theOne = it->first;
            }
        }

        return theOne;
    }
};


// 2、T=O(n) S=O(1)
// 高明解法：利用异或的性质（不进位加法）
// 占用一个额外空间
class Solution {
public:
    int singleNumber(int A[], int n) {
        int result = 0;
        for (int i = 0; i<n; i++) {
            result ^=A[i];
        }
        return result;
    }
};


// 3、T=O(n) S=O(1)
// 如果可以破坏数组A，还可以不利用额外空间：
class Solution {
public:
    int singleNumber(int A[], int n) {
        for (int i = 1; i<n; i++) {
            A[0] ^=A[i];
        }
        return A[0];
    }
};


// 4、
// 使用python有一种解法，是把数组集合化，之后对其求和再乘2。这个值减去原有数组的总和便是所求。

