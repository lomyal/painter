
// 递归（回溯）、非递归的计算量是一样的，递归并没有重复计算。
// 递归看似没有额外定义vector，但递归栈的空间要比非递归中一个vector更占空间。


// 1、非递归 18ms O(n^(n+2)) (和O(n^n)一样吗?)
class Solution {
public:
    vector<vector<int>> permute(vector<int> &num) {
        vector<vector<int>> res{num};
        int n = (int)num.size();

        // 在循环开始时对res的大小进行快照，不考虑在循环内新push进去的元素
        for (int i = 1; i < n; ++i) {   // O(n)
            int sizeRes = (int)res.size();

            // 选取res中所有旧元素，将其第i位和第j位交换，得到一个新的排列并保存
            // 在此前第i位上的数从未在第i位之前出现过，因此“新鲜性”得到了保证
            for (int k = 0; k < sizeRes; ++k) {  // O(n^n)
                for (int j = 0; j < i; ++j) {  // O(n)
                    vector<int> newNum{res[k]};
                    swap(newNum, i, j);
                    res.push_back(newNum);
                }
            }
        }

        return res;
    }
private:
    void swap(vector<int> &num, int i, int j) {
        int tmp = num[i];
        num[i] = num[j];
        num[j] = tmp;
    }
};

// 2、递归 15ms (过程完全模拟朴素的组合数计算过程，逐步确定每一位上的数)
class Solution {
public:
    vector<vector<int>> permute(vector<int> &num) {
        vector<vector<int>> result;
        permute(num, 0, result);
        return result;
    }
private:
    void permute(vector<int> &num, size_t start, vector<vector<int>> &result) {
        if (start == num.size() - 1) {
            result.push_back(num);
        } else {
            for (size_t i = start; i < num.size(); i++) {  // 如果 i == start，则不交换
                swap(num, start, i);  // 决定第 start 位上是什么数
                permute(num, start + 1, result);  // 递归决定第 start+1 到末尾的数，在末尾的数决定后输出此排列
                swap(num, start, i);  // 还原第 start 位上的数，在下一循环对第 start 位做出新的选择（不与之前的选择重复）
            }
        }
    }
    void swap(vector<int> &num, int i, int j) {
        if (i == j) {
            return;
        }
        int tmp = num[i];
        num[i] = num[j];
        num[j] = tmp;
    }
};
