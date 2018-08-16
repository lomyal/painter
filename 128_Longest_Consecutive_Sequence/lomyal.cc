// DFS O(n) ，直观排序解法是 O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }

        // 数组元素可重复，但对解法无影响
        std::unordered_set<int> num_set(nums.begin(), nums.end());  // 很多情况都是，如果想O(n)，一定要用set
        int len = 0;
        int max_len = 0;

        for (int i = 0; !num_set.empty() && i < nums.size(); ++i) {
            if (num_set.count(nums[i]) == 0) {
                continue;
            }
            num_set.erase(nums[i]);  // 每种数字只有一次机会（左右数是谁是固定的），用过可大胆抛弃
            ++len;

            // 向左探索
            int left = nums[i] - 1;
            while (num_set.count(left) != 0) {
                num_set.erase(left--);  // 每种数字只有一次机会（左右数是谁是固定的），用过可大胆抛弃
                ++len;
            }

            // 向右探索
            int right = nums[i] + 1;
            while (num_set.count(right) != 0) {
                num_set.erase(right++);  // 每种数字只有一次机会（左右数是谁是固定的），用过可大胆抛弃
                ++len;
            }

            if (len > max_len) {
                max_len = len;
            }
            len = 0;
        }
        return max_len;
    }
};
