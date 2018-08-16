
class Solution {
public:
    void merge(int A[], int m, int B[], int n) {

        // 倒着来，避免了A中已有元素的“避让”操作
        int i = m - 1, j = n - 1, k = m + n - 1;

        while (i != -1 && j != -1) {
            if (A[i] > B[j]) {
                A[k--] = A[i--];
            } else {
                A[k--] = B[j--];
            }
        }

        while (i != -1) {
            A[k--] = A[i--];
        }
        while (j != -1) {
            A[k--] = B[j--];
        }
    }
};