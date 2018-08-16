
// 1、字符串解法：17ms (不简洁)

class Solution {
public:
    int reverse(int x) {

        stringstream buffer;
        buffer << x;

        string in = buffer.str();
        int len = (int)in.length();
        string rev(in);

        // 反转字符串
        int ibegin;
        if (x < 0) {
            ibegin = 1;  // 处理负号
        } else {
            ibegin = 0;
        }

        for (int i = ibegin, j = len - 1; i < len; i++, j--) {
            rev[i] = in[j];
        }

        // 处理可能的溢出情况
        buffer.str(string());
        buffer.clear();
        buffer << 0x7fffffff;
        string boundOFU = buffer.str();

        buffer.str(string());
        buffer.clear();
        buffer << (int)(0x80000000);
        string boundOFD = buffer.str();

        if (x >= 1000000000) {  // 位数为10位才有与上下界比较的必要（而且位数不足10位，使用字符串比较会出错）
            if (rev > boundOFU) {
                return 0;
            }
        } else if (x <= -1000000000) {
            if (rev > boundOFD) {  // 负数字符串比较，小的为大
                return 0;
            }
        }

        // 转成 int 并返回值
        buffer.str(string());
        buffer.clear();
        buffer << rev;

        int out;
        buffer >> out;
        return out;
    }
};


// 2、数值计算解法 13ms-17ms

class Solution {
public:
    int reverse(int x) {

        bool neg = (x < 0);
        if (neg) {
            if (x == 0x80000000) {  // @@ 负数不溢出，但此负数去掉正号就会溢出
                return 0;
            }
            x = -x;
        }

        int rev = 0;
        while (x / 10) {  // @@ 留一位不反转，先做溢出检测
            rev = rev * 10 + x % 10;
            x = x / 10;
        }

        // 在最后一乘前检查是否溢出 (其实本题不必验证这么多条件，只需验证是否 rev > 214748364 即可，
        // 因为若反转前不溢出且是10位数，则反转后最后一位只可能是 1 或 2)
        // if (rev > 214748364 || (rev == 214748364 && ((!neg && x > 7) || (neg && x > 8)))) {
        if (rev > 214748364) {
            return 0;
        }

        rev = rev * 10 + x;

        if (neg) {
            return -rev;
        } else {
            return rev;
        }

    }
};
