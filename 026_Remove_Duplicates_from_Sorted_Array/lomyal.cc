
// 注意边界的处理（n=0时）

class Solution {  // T=O(n)
public:
    int removeDuplicates(int A[], int n)
    {
        if (0 == n) {
            return 0;
        }

        int j = 1; // 下一个赋值位置（同时表示新数组的长度）

        for (int i = 1; i < n; i++){
            if (A[i] != A[i - 1]) {  // 出现新元素时，赋值，并将赋值位置后移
                A[j++] = A[i];
            }
        }

        return j;
    }
};