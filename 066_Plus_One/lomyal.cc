
// 1、
class Solution {
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int size = (int)digits.size();
        if (!size) {
            return digits;
        }

        vector<int> result(size, 0);
        int carry = 1;  // 将题目要求的 +1 作为 carry 可使代码整洁
        int n = size - 1;

        while (carry && n >= 0) {  // 没有进位或最高位已处理完毕都会导致进入下一阶段
            if (digits[n] == 9) {
                carry = 1;
                result[n] = 0;
            } else {
                carry = 0;
                result[n] = digits[n] + 1;
            }
            --n;
        }

        if (carry && n < 0) {  // 最高位已处理完毕且最高位有进位

            // 处理需要增加一位的情况(目前所有位都是0，只需将第一位变成1，再在最后加一位0即可)
            result[0] = 1;
            result.push_back(0);

        } else {  // 其他

            // 不需要增加一位的情况，将可能存在的剩余digits高位直接原样写入results的高位
            while (n >= 0) {
                result[n] = digits[n];
                --n;
            }
        }

        return result;
    }
};


// 2、判断是否需要增加一位时过于拖沓，可像1中一样最后再判断是否需要增加一位
class Solution {
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int size = (int)digits.size();
        if (!size) {
            return digits;
        }

        vector<int> result(size, 0);
        int count9 = 0;

        // 检查是否需要增加一位（如999->1000）
        for (; count9 < size; count9++) {
            if (digits[count9] != 9) {
                break;
            }
        }

        // 处理需要增加一位的情况
        if (count9 == size) {
            result[0] = 1;
            result.push_back(0);

            return result;
        }

        // 不需要增加一位的情况
        int carry = 1;
        int n = size - 1;

        while (carry) {
            carry = (digits[n] + 1) / 10;
            result[n] = (digits[n] + 1) % 10;
            n--;
        }
        while (n >= 0) {
            result[n] = digits[n];
            n--;
        }

        return result;
    }
};