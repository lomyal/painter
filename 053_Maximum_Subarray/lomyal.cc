
// 1、我写的DP。T=O(n) S=O(n)

class Solution {
public:
    int maxSubArray(int A[], int n) {
        vector<int> maxSumWithEnd(n);
        vector<int> startPoint(n);

        maxSumWithEnd[0] = A[0];
        startPoint[0] = 0;
        int max = maxSumWithEnd[0];
        int pos = 0;

        for (int i = 1; i < n; ++i) {
            if (maxSumWithEnd[i - 1] >= 0) {
                maxSumWithEnd[i] = maxSumWithEnd[i - 1] + A[i];
                startPoint[i] = startPoint[i - 1];
            } else {
                maxSumWithEnd[i] = A[i];
                startPoint[i] = i;
            }

            if (maxSumWithEnd[i] > max) {
                max = maxSumWithEnd[i];
                pos = i;
            }
        }

        // 此题仅返回最大和，但须知：
        // pos是所求序列最后一个元素位置，startPoint[pos]是所求序列第一个元素位置
        return max;
    }
};


// 2、更简单的DP（只针对本题求解）。T=O(n) S=O(1)

// Idea is very simple. Basically, keep adding each integer to the sequence until the sum
// drops below 0. If sum is negative, then should reset the sequence.
class Solution {
public:
    int maxSubArray(int A[], int n)
    {
        int ans=A[0],i,j,sum=0;
        for(i=0;i<n;i++){
            sum+=A[i];
            ans=max(sum,ans);
            sum=max(sum,0);
        }
        return ans;
    }
};


// 3、分治法 T=O(nlogn) 有些信息重复计算了




