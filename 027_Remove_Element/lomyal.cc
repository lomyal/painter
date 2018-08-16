
// 1、类似26题，向后遍历和移动，简单易写，无陷阱。 5ms（与leetcode的测试用例有关，这个方案反而最快……）
// 缺点：当要删除的值很少且靠近数组头部时，做了过多无谓的移动。（数组无序）
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int pos = 0;  // 下一个赋值位置（同时表示新数组长度）
        for (int i = 0; i < n; i++) {
            if (A[i] != elem) {
                A[pos++] = A[i];
            }
        }
        return pos;
    }
};

// 2、tricky 9ms (不够好)
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int i = 0;
        while (i < n) {
            if (A[i] == elem) {
                A[i] = A[n - 1];
                n--;
            }  // 注意if中没有i++，因为从尾部直接调过来的数是信不过的，需要在下一循环重新检查
            else
                i++;
        }
        return n;
    }
};

// 3、与2的区别：2是无脑把尾部的数往前调，调完重新在该位置检查；3是确保从尾部调过去的数是好的。 6ms
class Solution {
public:
    int removeElement(int A[], int n, int elem)
    {
        int front = 0, back = n - 1;

        while (front <= back) {  //   一定要等号，否则不能处理最后一刻back指向elem的情况
            if (A[front] == elem) {  // 在头部找到可覆盖的空位

                while (A[back] == elem) {  // 在尾部找到可先前填补空缺的值
                    back--;
                }

                if (front > back) {  // 找到的back已越过front（此时back是非elem，front是elem，二者不可能重叠）
                    return back + 1;
                }

                A[front] = A[back--];  // 填空
            }

            front++;  // 向后遍历
        }

        return back + 1;
    }
};