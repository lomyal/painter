
// 1、每次移动都是一击命中 T=O(n) S=O(1)
class Solution {
public:
    void rotate(int nums[], int n, int k)
    {
        if (!n || !k) {
            return;
        }

        k = k % n;

        int start = 0;
        int next = 0;
        int tmp = nums[next];

        // 每个循环移动一个元素到正确的位置上，循环变量i并不参加运算
        for (int i = 0; i < n; ++i) {
            next = (next + k) % n;
            swap(nums[next], tmp);

            // 若回到了原位，则next后移一位（next++后不会踩到以前的start位置，这是由for循环次数保证的）
            if (next == start) {
                ++next;
                start = next;
                tmp = nums[next];
            }
        }
    }

private:
    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
};

// 2、元素被多移动了一次，但写起来比较简洁。O(n) O(1)
class Solution {
public:
    void rotate(int nums[], int n, int k) {
        k = k % n;
        reverse(nums, 0, n);
        reverse(nums, 0, k);
        reverse(nums, k, n);
    }

private:
    void reverse(int nums[], int n, int m) {
        for (int i = n, j = m - 1; i < j; ++i, --j) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
        }
    }
};