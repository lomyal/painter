// 原理：若存在主元素，则主元素和另一个非主元素对消，主元素仍是主元素

// 1、算法速度仍没有最佳（30ms > 24ms），虽然渐进复杂度已经是O(n)了
class Solution {
public:
    int majorityElement(vector<int> &num) {

        /* 时间复杂度O(n)，空间复杂度O(1) */
        auto it = num.cbegin();
        int theOne = *(it++), count = 1;

        for (; it != num.cend(); it++) {
            if (count == 0) {
                theOne = *it;
                count = 1;
            } else {
                if (*it == theOne) {
                    count++;
                } else {
                    count--;
                }
            }
        }

        return theOne;
    }
};


// 2、改成下标访问，还是30ms...
class Solution {
public:
    int majorityElement(vector<int> &num) {
        int theOne = num[0], count = 1, size = num.size();

        for (int i = 1; i < size; i++) {
            if (count == 0) {
                theOne = num[i];
                count = 1;
            } else {
                if (num[i] == theOne) {
                    count++;
                } else {
                    count--;
                }
            }
        }

        return theOne;
    }
};
